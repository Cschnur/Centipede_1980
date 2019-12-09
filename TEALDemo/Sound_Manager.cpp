
#include "Sound_Manager.h"

Sound_Manager* Sound_Manager::ptrInstance = NULL;

Sound_Manager::Sound_Manager()
{
	scorpionSound.setBuffer(ResourceManager::GetSound("scorpion_new"));
	scorpionSound.setLoop(true);

	fleaSound.setBuffer(ResourceManager::GetSound("flea_new"));
	fleaSound.setLoop(true);

	spiderSound.setBuffer(ResourceManager::GetSound("spiderloop"));
	spiderSound.setLoop(true);

	critterDeath.setBuffer(ResourceManager::GetSound("kill"));
	

	shipDeath.setBuffer(ResourceManager::GetSound("deathWAV"));
	

	fireSound.setBuffer(ResourceManager::GetSound("fire1"));
	

	centipedeSound.setBuffer(ResourceManager::GetSound("beat"));
	centipedeSound.setLoop(true);
}

void Sound_Manager::privSetVolume(float vol)
{
	scorpionSound.setVolume(vol);
	fleaSound.setVolume(vol);
	spiderSound.setVolume(vol);
	critterDeath.setVolume(vol);
	shipDeath.setVolume(vol);
	fireSound.setVolume(vol);
	centipedeSound.setVolume(vol);
}

////Play Sounds////
void Sound_Manager::privPlaySpider()
{
	spiderSound.play();
}

void Sound_Manager::privPlayScorpion()
{
	scorpionSound.play();
}

void Sound_Manager::privPlayFlea()
{
	fleaSound.play();
}

void Sound_Manager::privPlayCentipede()
{
	centipedeSound.play();
}

void Sound_Manager::privPlayFire()
{
	fireSound.play();
}

void Sound_Manager::privPlayShipDeath()
{
	shipDeath.play();
}

void Sound_Manager::privPlayCritterDeath()
{
	critterDeath.play();
}

////Stop Sounds////
void Sound_Manager::privStopScorpion()
{
	scorpionSound.stop();
}
void Sound_Manager::privStopSpider()
{
	spiderSound.stop();
}
void Sound_Manager::privStopFlea()
{
	fleaSound.stop();
}
void Sound_Manager::privStopCentipede()
{
	centipedeSound.stop();
}

void Sound_Manager::Terminate()
{
	delete ptrInstance;
	ptrInstance = nullptr;
}

Sound_Manager::~Sound_Manager()
{
}