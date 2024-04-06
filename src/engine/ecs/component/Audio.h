/**
* @file Audio.h
* @author Hudson Schumaker
* @brief Defines the Audio class.
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
#include "Defs.h"
#include "Component.h"
#include "../../sfx/AudioManager.h"

/**
* @class Audio
* @brief The audio component.
* 
* This class represents an audio component that can be attached to a game object.
* It uses the AudioManager to play, pause, and stop sounds.
*/
class Audio final : public Component {
private:
    bool paused = false;

public:
    std::string audioId;
    int loops = 0;
    bool playOnAwake = false;
    int channel = -1;
    int delay = 0;

    /**
    * @brief Constructor that initializes the audioId.
    * @param audioId The ID of the audio to play.
    */
    Audio(std::string audioId);

    /**
    * @brief Constructor that initializes the audioId, playOnAwake, and loops. If playOnAwake is true, the audio will start playing immediately.
    * @param audioId The ID of the audio to play.
    * @param playOnAwake Whether the audio should start playing immediately.
    * @param loop The number of times the audio should loop. If loop is -1, the audio will loop indefinitely. 
    */
    Audio(std::string audioId, bool playOnAwake, int loop);

    /**
    * @brief Destructor that stops the audio. If delay is non-zero, the audio will fade out over the specified delay.
    */
    ~Audio();

    /**
    * @brief Starts playing the audio on the specified channel with the specified number of loops.
    */
    void play();

    /**
    * @brief Starts playing the audio on the specified channel with the specified number of loops.
    * @param loop The number of times the audio should loop. If loop is -1, the audio will loop indefinitely.
    */
    void play(int loop);

    /**
    * @brief Toggles the paused state of the audio. If the audio is currently playing, it will be paused. If it's currently paused, it will be resumed.
    */
    void pause();

    /**
    * @brief Stops the audio immediately.
    */
    void stop();

    /**
    * @brief Stops the audio with a fade out over the specified delay.
    */
    void stop(int delay);
};
