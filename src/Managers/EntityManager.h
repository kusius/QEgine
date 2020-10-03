#ifndef ENTITY_MANAGER_H
#define ENTITY_MANAGER_H

#include <Objects/GameObjects.h>

using namespace std;

class EntityManager
{
public:
    // Structure of arrays describing all gameobjects.
    static GameObjects gameObjects;

    //The total objects stored in the gameObjects array
    static unsigned int objectCount;

    // Initialize the EntityManager class.
    static void Init();

    /**
     * @brief Import a model from path, give a new ID and store in gameObjects
     * 
     * @param path The full or relative path to the model resource file.S
     */
    static void ImportModelFromFile(const char *path);

    /**
     * @brief Transform one of the models stored in EntityManager::gameObjects SOA
     * 
     * @param id The unique id given to the object on import ( @ref EntityManager::ImportModelFromFile ) 
     * @param move the amount of units to translate in x, y, z 
     * @param rotation the amount of degrees to rotate around x, y, z axes
     * @param scale the amount to scale as a percentage of the original scale in x, y, z
     */
    static void TransformModel(unsigned int id, glm::vec3 position = glm::vec3(0.0),
                               glm::vec3 rotation = glm::vec3(0.0),
                               glm::vec3 scale = glm::vec3(1.0));

    static void Translate(unsigned int id, glm::vec3 translation);

    static void Rotate(unsigned int id, glm::vec3 rotation);

    static void Scale(unsigned int id, glm::vec3 scale);

private:
    EntityManager() {}
};
#endif //ENTITY_MANAGER_H