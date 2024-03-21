/**
* @file Main.cpp
* @author Hudson Schumaker
* @brief Defines main function.
* @version 1.0.0
* 
* Dodoi-Engine-NS is a game engine developed by Dodoi-Lab.
* @copyright Copyright (c) 2024, Dodoi-Lab
*/
#include "engine/Common.h"
#include "engine/gfx/Gfx.h"
#include "engine/sfx/AudioManager.h"
#include "engine/ecs/component/Music.h"

void init();
void end();

int main(void) {

    init();

    auto filePath = AUDIO_FOLDER + std::string("GoNinjaGo.mp3"); 
    Music* audio = new Music(filePath, true, -1);
    audio->delay = 200;

    bool isRunning = true;
    while (isRunning) {
		SDL_Event sdlEvent;
	    while (SDL_PollEvent(&sdlEvent)) {
		    switch (sdlEvent.type) {
		    case SDL_QUIT:
			    isRunning = false;
			    break;
		    }
	    }
	}
    
    end();
    return 0;
}

void init() {
    romfsInit();
    chdir("romfs:/");

    Gfx::getInstance()->setGfxContext();
    // AssetManager::getInstance()->load();
    AudioManager::getInstance()->load();
    
}

void end() {
    IMG_Quit();
    Mix_CloseAudio();
    TTF_Quit();
    Mix_Quit();
    SDL_Quit();  
    romfsExit();
}
