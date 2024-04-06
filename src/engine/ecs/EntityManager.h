/**
* @file EntityManager.h
* @author Hudson Schumaker
* @brief Defines EntityManager, EntityComparator classes
* @version 1.0.0
* 
* Dodoi-Engine-NS is a game engine developed by Dodoi-Lab.
* @copyright Copyright (c) 2024, Dodoi-Lab
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
* 
*     http://www.apache.org/licenses/LICENSE-2.0
* 
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/
#pragma once
#include "../Defs.h"
#include "Entity.h"

/**
* @struct EntityComparator
* @brief A comparator for sorting entities based on their IDs.
*/
struct EntityComparator {
    bool operator()(const Entity* a, const Entity* b) const {
        return a->id < b->id;
    }
};

/**
* @class EntityManager
* @brief Singleton class responsible for managing entities in the game engine.
*/
class EntityManager final {
private:
    unsigned long index = 0;
    inline static EntityManager* instance = nullptr;

    std::vector<Entity*> entities;
    std::set<Entity*, EntityComparator> entitiesToBeKilled;

    EntityManager();
    ~EntityManager();

    /**
    * @brief Compares two entities based on their IDs in ascending order.
    * @param e1 First entity to compare.
    * @param e2 Second entity to compare.
    * @return True if the ID of the first entity is less than the ID of the second entity, false otherwise.
    */
    static bool compareAsc(const Entity* e1, const Entity* e2);

public:
    /**
    * @brief Returns the singleton instance of the EntityManager class.
    * @return Pointer to the singleton instance.
    */
    static EntityManager* getInstance();

    /**
    * @brief Creates a new entity with default parameters.
    * @return Pointer to the newly created entity.
    */
    Entity* createEntity();

    /**
    * @brief Creates a new entity with specified position.
    * @param x The x-coordinate of the entity.
    * @param y The y-coordinate of the entity.
    * @return Pointer to the newly created entity.
    */
    Entity* createEntity(float x, float y);

    /**
    * @brief Creates a new entity with specified position and tag.
    * @param x The x-coordinate of the entity.
    * @param y The y-coordinate of the entity.
    * @param tag The tag of the entity.
    * @return Pointer to the newly created entity.
    */
    Entity* createEntity(float x, float y, Tag tag);

    /**
    * @brief Returns the entity with the specified ID.
    * @param id The ID of the entity.
    * @return Pointer to the entity if it exists, nullptr otherwise.
    */
    Entity* getEntity(unsigned long id);

    /**
    * @brief Returns a constant reference to the vector of entities.
    * @return Constant reference to the vector of entities.
    */
    const std::vector<Entity*>& getEntities() const;
    
    /**
    * @brief Removes the specified entity.
    * @param entity Pointer to the entity to remove.
    */
    void removeEntity(Entity* entity);
    
    /**
    * @brief Returns a vector of entities that have the specified component.
    * @return Vector of entities that have the specified component.
    */
    template<typename T>
    std::vector<Entity*> getEntitiesWithComponent() {
        std::vector<Entity*> list;
        for (auto& e : entities) {
            if (e->getComponent<T>()) {
                list.push_back(e);
            }
        }
        return list; 
    }

    /**
    * @brief Returns a vector of entities that have the specified tag.
    * @param tag The tag to search for.
    * @return Vector of entities that have the specified tag.
    */
    std::vector<Entity*> getEntitiesWithTag(Tag tag);

    /**
    * @brief Returns a vector of entities that have the specified group.
    * @param group The group type to search for.
    * @return Vector of entities that have the specified group.
    */
    std::vector<Entity*> getEntitiesByGroup(GroupType type);

    /**
    * @brief Updates the state of the EntityManager.
    */
    void update();

    /**
    * @brief Marks the specified entity for deletion.
    * @param entity Pointer to the entity to mark for deletion.
    */
    void killEntity(Entity* entity);

    /**
    * @brief Clears all entities.
    */
    void clear();

    /**
    * @brief Clears the specified entity.
    * @param entity Pointer to the entity to clear.
    */
    void clear(Entity* entity);
};
