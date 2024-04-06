/**
* @file AssetManager.h
* @author Hudson Schumaker
* @brief Defines the AssetManager class.
* @version 1.0.0
* 
* Dodoi-Engine-NS is a game engine developed by Dodoi-Lab.
* 
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

using texture_t = std::map<std::string, std::pair<short, SDL_Texture*>>;

/**
* @class AssetManager
* @brief The AssetManager class encapsulates the functionality of managing game assets.
* 
* This class is responsible for loading, adding, retrieving, and clearing game assets.
*/
class AssetManager final {
private:
    inline static AssetManager* instance = nullptr;
    texture_t textures;

    AssetManager();

public:
    ~AssetManager();

    /**
    * @brief Gets the singleton instance of the AssetManager.
    * 
    * @return A pointer to the AssetManager instance.
    */
    static AssetManager* getInstance();

    /**
    * @brief Loads the assets.
    */
    void load();

    /**
    * @brief Adds a texture to the AssetManager.
    * 
    * @param name The name of the texture.
    * @param filePath The file path of the texture.
    */
    void addTexture(const std::string& name, const short value, const std::string& filePath);
    
    /**
    * @brief Gets a texture by name.
    * 
    * @param name The name of the texture.
    * @return A pointer to the SDL_Texture object.
    */
    SDL_Texture* getTexture(const std::string& name);
    int textureCount() const;

    /**
    * @brief Clears the assets.
    */ 
    void clearAssets();
};
