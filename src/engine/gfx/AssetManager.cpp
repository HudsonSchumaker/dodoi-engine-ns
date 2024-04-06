/**
* @file AssetManager.cpp
* @author Hudson Schumaker
* @brief Implements the AssetManager class.
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
#include "Gfx.h"
#include "AssetManager.h"
#include "../io/FileUtils.h"

AssetManager::AssetManager() {}
AssetManager::~AssetManager() {
    clearAssets();
}

AssetManager* AssetManager::getInstance() {
    if (instance == nullptr) {
        instance = new AssetManager();
    }

    return instance;
}

void AssetManager::addTexture(const std::string& name, const short value, const std::string& filePath) {
    SDL_Texture* texture = Gfx::getInstance()->loadTexture(filePath);

    std::pair pair = { value, texture };
    this->textures.emplace(name, pair);
}

SDL_Texture* AssetManager::getTexture(const std::string& name) {
    return textures[name].second;
}

int AssetManager::textureCount() const {
    return (int)textures.size();
}

void AssetManager::load() {
    auto files = FileUtils::listImageFilesInFolder();
    for (auto& file : files) {
        auto filePath = IMAGE_FOLDER + file;
        addTexture(FileUtils::getClearName(filePath), 0, file);
    }
}

void AssetManager::clearAssets() {
    for (auto& texture : textures) {
        SDL_DestroyTexture(texture.second.second);
    }

    this->textures.clear();
}
