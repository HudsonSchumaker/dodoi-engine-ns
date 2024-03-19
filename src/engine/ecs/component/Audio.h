
#include "../../Common.h"
#include "Component.h"

class Audio final : public Component {
private:
	bool paused = false;

public:
	std::string audioId;
	int loops = 0;
	bool playOnAwake = false;
	int channel = -1;
	int delay = 0;

	Audio(std::string audioId) {
		this->audioId = audioId;
	}

	Audio(std::string audioId, bool playOnAwake, int loop) {
		this->audioId = audioId;
		this->playOnAwake = playOnAwake;
		this->loops = loop;

		if (playOnAwake) { play(); }
	}

	~Audio() {
		if (delay != 0) {
			stop(delay);
		}
		else {
			stop();
		}
	}

	void play() {
		channel = AudioManager::getInstance()->playSound(audioId, loops);
	}

	void play(int loop) {
		channel = AudioManager::getInstance()->playSound(audioId, loop);
	}

	void pause() {
		paused = paused == false ? true : false;

		if (paused) {
			AudioManager::getInstance()->pauseSound(channel);
		}
		else {
			AudioManager::getInstance()->unPauseSound(channel);
		}
	}

	void stop() {
		if (channel != -1) {
			AudioManager::getInstance()->stopSound(channel);
		}
	}

	void stop(int delay) {
		AudioManager::getInstance()->stopSound(channel, delay);
	}
};
