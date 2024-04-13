#pragma once

class AudioManager
{
public:
	~AudioManager();
	
	void SetupDevice();

	void LoadSound(const char* filePath);
	void UnloadSound(const char* filePath);

	void PlaySound();
	void StopSound();

private:
	SDL_AudioDeviceID m_Device;
	SDL_AudioSpec m_AudioSpec;
	Uint8*	m_waveStart = nullptr;
	Uint32  m_waveLength;
};
