#include "AudioManager.h"

AudioManager::AudioManager() {}

AudioManager::~AudioManager() {
	clearAssets();
}

AudioManager* AudioManager::getInstance() {
	if (instance == nullptr) {
		instance = new AudioManager();
	}

	return instance;
} 

void AudioManager::addSound(const std::string& name, const std::string& filePath) {
	this->sounds.emplace(name, Mix_LoadWAV(filePath.c_str()));
}

int AudioManager::playSound(const std::string&name) {
	return playSound(name, 0);
}

int AudioManager::playSound(const std::string& name, int loop) {
	return Mix_PlayChannel(-1, this->sounds[name], loop);
}

void AudioManager::stopSound(int channel) {
	Mix_HaltChannel(channel);
}

void AudioManager::stopSound(int channel, int delay) {
	Mix_FadeOutChannel(channel, delay);
}

void AudioManager::pauseSound(int channel) {
	Mix_Pause(channel);
}

void AudioManager::unPauseSound(int channel) {
	Mix_Resume(channel);
}

void AudioManager::playMusic(const std::string& filePath) {
    std::async(std::launch::async, [&]() {
        Mix_Music* music = Mix_LoadMUS(filePath.c_str());
        Mix_PlayMusic(music, 0);
        Mix_FreeMusic(music);
    });
}

void AudioManager::stopMusic() {
    Mix_HaltMusic();
}

void AudioManager::stopMusic(int delay) {
    Mix_FadeOutMusic(delay);
}

void AudioManager::pauseMusic() {
    Mix_PauseMusic();
}

void AudioManager::unPauseMusic() {
    Mix_ResumeMusic();
}

void AudioManager::load() {
	auto files = FileUtils::listAudioFilesInFolder();
    for (auto& file : files) {
        auto filePath = AUDIO_FOLDER + file;
        addSound(FileUtils::getClearName(filePath), filePath);
    }
}

int AudioManager::audioCount() const {
	return (int)sounds.size();
}

void AudioManager::clearAssets() {
	for (auto& sound : sounds) {
		Mix_FreeChunk(sound.second);
	}
	sounds.clear();
}

