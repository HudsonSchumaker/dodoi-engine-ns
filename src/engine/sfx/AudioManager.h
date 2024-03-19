/**
 * @file AudioManager.h
 * @author Hudson Schumaker
 * @brief AudioManager class for the Dodoi-Engine-NS.
 * @version 1.0
 * @date 2022-03-01
 * 
 * Dodoi-Engine-NS is a game engine developed by Dodoi-Lab.
 * This file contains the AudioManager class, which is responsible for managing audio assets.
 * 
 * @copyright Copyright (c) 2022, Dodoi-Lab
 * 
 */
#pragma once
#include "../Common.h"

class AudioManager final {
private:
    inline static AudioManager* instance = nullptr;
    std::map<std::string, Mix_Chunk*> sounds;

    AudioManager();

public:
    ~AudioManager();
    static AudioManager* getInstance();

    void load();
    void addSound(const std::string& name, const std::string& filePath);

    int playSound(const std::string& name) const;
    int playSound(const std::string& name, int loop) const;
    void stopSound(int channel);
    void stopSound(int channel, int delay);
    void pauseSound(int channel);
    void unPauseSound(int channel);

    int playMusic(const std::string& filePath) const;
    void stopMusic(int channel);
    void stopMusic(int channel, int delay);
    void pauseMusic(int channel);
    void unPauseMusic(int channel);

    int audioCount() const;
    void clearAssets();
};
