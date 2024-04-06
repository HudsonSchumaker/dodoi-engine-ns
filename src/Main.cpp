/**
* @file Main.cpp
* @author Hudson Schumaker
* @brief Defines main function.
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
#include "engine/Defs.h"
#include "engine/gfx/Gfx.h"
#include "engine/ecs/Tags.h"
#include "engine/core/Hardware.h"
#include "engine/gfx/AssetManager.h"
#include "engine/sfx/AudioManager.h"
#include "engine/ecs/EntityManager.h"
#include "engine/core/SceneManager.h"
#include "engine/ecs/component/Music.h"
#include "SplashScreen.h"
#include "TitleScreen.h"

void init();
void end();

int main(void) {
    init();
    
    SceneManager::getInstance()->addScene("SplashScreen", std::make_unique<SplashScreen>());
    SceneManager::getInstance()->addScene("TitleScreen", std::make_unique<TitleScreen>());
    SceneManager::getInstance()->loadSceneAsync("SplashScreen");
   
    end();
    return 0;
}

void init() {
    romfsInit();
    chdir("romfs:/");

    Gfx::getInstance()->setGfxContext();
    AssetManager::getInstance()->load();
    AudioManager::getInstance()->load();
    Tags::getInstance();
    EntityManager::getInstance();    
}

void end() {
    IMG_Quit();
    Mix_CloseAudio();
    TTF_Quit();
    Mix_Quit();
    SDL_Quit();  
    romfsExit();
}
