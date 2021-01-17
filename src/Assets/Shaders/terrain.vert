#version 330 core
layout(location = 0) in vec3 aPos;
layout(location = 1) in vec3 aNormal;
layout(location = 2) in vec2 aTexCoords;
layout(location = 3) in vec3 aTangent;
layout(location = 4) in mat4 aInstanceModelMatrix; // 4,5,6,7

out vec3 FragPos;
out vec2 TexCoords;
out mat3 TBN;

uniform mat4 view;
uniform mat4 projection;

void main()
{
  FragPos =
      vec3(aInstanceModelMatrix *
           vec4(aPos, 1.0)); // get the vertex position in world coordinates

  TexCoords = aTexCoords;
  vec3 T = normalize(vec3(aInstanceModelMatrix * vec4(aTangent, 0.0)));
  vec3 N = normalize(vec3(aInstanceModelMatrix * vec4(aNormal, 0.0)));
  T = normalize(T - dot(T, N) * N);
  vec3 B = cross(N, T);
  TBN = mat3(T, B, N);

  gl_Position = projection * view * aInstanceModelMatrix * vec4(aPos, 1.0f);
}