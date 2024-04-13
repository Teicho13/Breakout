#include <SDL.h>
#include "./Managers/AudioManager.h"


void AudioManager::LoadSound(const char* filePath)
{
	SDL_LoadWAV(filePath, &m_AudioSpec, &m_waveStart, &m_waveLength);
}

void AudioManager::UnloadSound(const char* filePath)
{
	SDL_FreeWAV(m_waveStart);
}

void AudioManager::PlaySound()
{
	SetupDevice();
	int status = SDL_QueueAudio(m_Device, m_waveStart, m_waveLength);
	SDL_PauseAudioDevice(m_Device, 0);
}

void AudioManager::StopSound()
{
	SDL_PauseAudioDevice(m_Device, 1);
}

AudioManager::~AudioManager()
{
	SDL_CloseAudioDevice(m_Device);
}

void AudioManager::SetupDevice()
{
	m_Device = SDL_OpenAudioDevice(nullptr, 0, &m_AudioSpec, nullptr, 0);
}
