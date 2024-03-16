
#pragma one
#include "../Common.h"
#include "Component.h"

struct GameObject {
    std::unordered_map<const std::type_info*, Component*> components;
    unsigned long id = 0;

    GameObject() {}
	~GameObject() {
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
		return component;
	}

	void deleteComponents() {
		for (const auto& entry : components) {
			delete entry.second;
		}
		components.clear();
	}
};
