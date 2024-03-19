/**
 * @file AudioManager.h
 * @author Hudson Schumaker
 * @brief AudioManager class for the Dodoi-Engine-NS.
 * @version 1.0.0
 * @date 2024-03-01
 * 
 * Dodoi-Engine-NS is a game engine developed by Dodoi-Lab.
 * This file contains the AudioManager class, which is responsible for managing audio assets.
 * 
 * @copyright Copyright (c) 2024, Dodoi-Lab
 * 
 */
#pragma once
#include "../Common.h"

class AudioManager final {
private:
    inline static AudioManager* instance = nullptr;
    std::map<std::string, Mix_Chunk*> sounds;

    /**
     * @brief Private constructor for the AudioManager class.
     *
     * This constructor is private because AudioManager is a singleton class.
     */
    AudioManager();

public:
    ~AudioManager();
    /**
     * @brief Destructor for the AudioManager class.
     */
    ~AudioManager();

    /**
     * @brief Get the instance of the AudioManager class.
     *
     * Since AudioManager is a singleton class, this function provides the global point of access to the instance.
     *
     * @return A pointer to the instance of the AudioManager class.
     */
    static AudioManager* getInstance();

    /**
     * @brief Load audio assets.
     */
    void load();

    /**
     * @brief Add a sound to the AudioManager.
     *
     * @param name The name of the sound.
     * @param filePath The file path of the sound.
     */
    void addSound(const std::string& name, const std::string& filePath);

    /**
     * @brief Play a sound.
     *
     * @param name The name of the sound.
     * @return The channel on which the sound is played.
     */
    int playSound(const std::string& name);

    /**
     * @brief Play a sound with looping.
     *
     * @param name The name of the sound.
     * @param loop The number of times to loop the sound. -1 for infinite loop.
     * @return The channel on which the sound is played.
     */
    int playSound(const std::string& name, int loop);

    /**
     * @brief Stop a sound.
     *
     * @param channel The channel on which the sound is playing.
     */
    void stopSound(int channel);

    /**
     * @brief Stop a sound after a delay.
     *
     * @param channel The channel on which the sound is playing.
     * @param delay The delay in milliseconds before the sound is stopped.
     */
    void stopSound(int channel, int delay);

    /**
     * @brief Pause a sound.
     *
     * @param channel The channel on which the sound is playing.
     */
    void pauseSound(int channel);

    /**
     * @brief Unpause a sound.
     *
     * @param channel The channel on which the sound is paused.
     */
    void unPauseSound(int channel);

    /**
     * @brief Play music.
     *
     * @param filePath The file path of the music.
     */
    void playMusic(const std::string& filePath);

    /**
     * @brief Stop the music.
     */
    void stopMusic();

    /**
     * @brief Stop the music after a delay.
     *
     * @param delay The delay in milliseconds before the music is stopped.
     */
    void stopMusic(int delay);

    /**
     * @brief Pause the music.
     */
    void pauseMusic();

    /**
     * @brief Unpause the music.
     */
    void unPauseMusic();

    /**
     * @brief Get the count of audio assets.
     *
     * @return The count of audio assets.
     */
    int audioCount() const;

    /**
     * @brief Clear all audio assets.
     */
    void clearAssets();
};
