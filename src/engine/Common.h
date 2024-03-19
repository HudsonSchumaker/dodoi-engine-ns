/**
 * @file Common.h
 * @author Hudson Schumaker
 * @brief Common includes and definitions for the Dodoi-Engine.
 * @version 1.0.0
 * @date 2024-03-01
 * 
 * Dodoi-Engine-NS is a game engine developed by Dodoi-Lab.
 * This file includes the necessary C++ and SDL2 libraries that are used throughout the dodoi-engine-ns.
 * It also defines constants for the paths to various types of assets.
 * 
 * @copyright Copyright (c) 2024, Dodoi-Lab
 * 
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

