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

