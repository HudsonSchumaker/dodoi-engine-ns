/**
* @file Defs.h
* @author Hudson Schumaker
* @brief Defs includes and definitions for the Dodoi-Engine.
* @version 1.0.0
* 
* Dodoi-Engine-NS is a game engine developed by Dodoi-Lab.
* This file includes the necessary C++ and SDL2 libraries that are used throughout the dodoi-engine-ns.
* It also defines constants for the paths to various types of assets.
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
// C++ includes
#include <set>
#include <map>
#include <list>
#include <array>
#include <cmath>
#include <limits>
#include <vector>
#include <random>
#include <chrono>
#include <future>
#include <string>
#include <thread>
#include <utility>
#include <fstream>
#include <sstream>
#include <iostream>
#include <typeindex>
#include <algorithm>
#include <filesystem>
#include <functional>
#include <unordered_map>

// SDL2 includes
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <SDL_mixer.h>

// Switch includes
#include <switch.h>
#include <unistd.h>
#include <sys/stat.h>

/**
* @def AUDIO_FOLDER
* @brief The path to the folder containing audio assets.
*/
#define AUDIO_FOLDER "./assets/audios/"

/**
* @def FONT_FOLDER
* @brief The path to the folder containing font assets.
*/
#define FONT_FOLDER "./assets/fonts/"

/**
* @def IMAGE_FOLDER
* @brief The path to the folder containing image assets.
*/
#define IMAGE_FOLDER "./assets/images/"

/**
* @def MAP_FOLDER
* @brief The path to the folder containing map assets.
*/
#define MAP_FOLDER "./assets/maps/"

/**
* @def SCREEN_WIDTH
* @brief The width of the game screen in pixels.
*/
#define SCREEN_WIDTH 1280

/**
* @def SCREEN_H_WIDTH
* @brief Half of the width of the game screen in pixels.
*/
#define SCREEN_H_WIDTH SCREEN_WIDTH/2

/**
* @def SCREEN_HEIGHT
* @brief The height of the game screen in pixels.
*/
#define SCREEN_HEIGHT 720

/**
* @def SCREEN_H_HEIGHT
* @brief Half of the height of the game screen in pixels.
*/
#define SCREEN_H_HEIGHT SCREEN_HEIGHT/2 

/**
* @class Defs
* @brief Contains common constants and definitions for the Dodoi-Engine.
*/
class Defs final {
public:
    /**
    * @brief The name of the engine.
    */
    inline static const char NAME[] = "dodoi-engine v.0.0.0-ns";

    /**
    * @brief The target frames per second for the game.
    */
    static const int FPS = 60;

    /**
    * @brief The number of milliseconds per frame at the target FPS.
    */
    static const int MILLISECS_PER_FRAME = 1000 / FPS;

    /**
    * @brief The value of Pi.
    */
    constexpr static float PI = 3.141592653589793f;
};
