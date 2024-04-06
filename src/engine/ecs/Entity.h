/**
* @file Entity.h
* @author Hudson Schumaker
* @brief Defines the Entity class.
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
#include "Tags.h"
#include "Groups.h"
#include "component/Component.h"

/**
* @class Entity
* @brief The GameObject of the engine.
*/
class Entity final {
private:
    std::unordered_map<const std::type_info*, Component*> components;
	static Groups g;

public:
	short zIndex = 0;
    unsigned long id = 0;
	std::pair<Tag, Tag> tags = { Tags::getInstance()->getTagByName("default"), Tags::getInstance()->getTagByName("default") };
	std::unordered_set<GroupType> groups;

    Entity(unsigned long id) : id(id) {}
	~Entity() {
		deleteComponents();
	}

	template<typename T>
	T* getComponent() {
		auto it = components.find(&typeid(T));
		if (it != components.end()) {
			return (T*)(it->second);
		}
		return nullptr;
	}

	template<typename T>
	T* addComponent(T* component) {
		components[&typeid(T)] = component;
		component->parentId = id;
		groups.insert(g.typeToGroup[&typeid(*component)]);
		return component;
	}

	void deleteComponents() {
		for (const auto& entry : components) {
			delete entry.second;
		}
		components.clear();
	}
};
