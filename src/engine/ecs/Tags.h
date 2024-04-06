/**
* @file Tags.h
* @author Hudson Schumaker
* @brief Defines Tag and Tag classes
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

/**
* @class Tag
* @brief A class that represents a tag.
* 
* Each tag has a name and a layer.
*/
class Tag final {
private:
    std::string name;

public:
    /**
    * @brief Construct a new Tag object.
    * 
    * @param name The name of the tag.
    */
    Tag(const std::string& name) : name(name) {}
    std::string getName() const { return name; }
};

/**
* @class Tags
* @brief A singleton class that manages all tags.
* 
* This class provides methods to add, remove, and retrieve tags.
*/
class Tags final {
private:
    std::vector<Tag> tags;
    inline static Tags* instance = nullptr;

    Tags() {}

public:
    ~Tags() {
        tags.clear();
    }

    /**
    * @brief Get the singleton instance of the Tags class.
    * If the instance doesn't exist, it's created and initialized with default values.
    * 
    * @return Tags* The singleton instance of the Tags class.
    */
    static Tags* getInstance() {
        if (instance == nullptr) {
            instance = new Tags();
            
            // Initialize with default values
            instance->addTag("default");
            instance->addTag("killByTime");
            instance->addTag("background");
            instance->addTag("tile");
            instance->addTag("enemy");
            instance->addTag("player");
            instance->addTag("shield");
            instance->addTag("bullet");
            instance->addTag("blade");
            instance->addTag("coin");
        }
        return instance;
    }

    /**
    * @brief Add a new tag.
    * 
    * @param name The name of the tag.
    * @param layer The layer of the tag.
    */
    void addTag(const std::string& name) {
        tags.push_back(Tag(name));
    }

    /**
    * @brief Remove a tag.
    * @param name The name of the tag to remove.
    */
    void removeTag(const std::string& name) {
        tags.erase(std::remove_if(tags.begin(), tags.end(),
            [&name](const Tag& tag) { return tag.getName() == name; }), tags.end());
    }

    /**
    * @brief Get a tag by name.
    * 
    * @param name The name of the tag.
    * @return Tag The tag. Returns a tag with an empty name if the tag is not found.
    */
    Tag getTagByName(const std::string& name) const {
        auto it = std::find_if(tags.begin(), tags.end(),
            [&name](const Tag& tag) { return tag.getName() == name; });
        if (it != tags.end()) {
            return *it;
        }
        return Tag("");
    }
};
