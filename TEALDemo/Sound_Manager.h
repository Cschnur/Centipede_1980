#ifndef _SOUND_MANGER
#define _SOUND_MANAGER

#include "Game Components\TEAL\CommonElements.h"

class Sound_Manager
{
public:
	////Set Volume////
	static void SetVolume(float vol) { Instance().privSetVolume(vol); };

	////Play Sounds////
	//Loops
	static void playScorpion() { Instance().privPlayScorpion(); };
	static void playSpider() { Instance().privPlaySpider(); };
	static void playFlea() { Instance().privPlayFlea(); };
	static void playCentipede() { Instance().privPlayCentipede(); };
	//Non-Loops
	static void playFire() { Instance().privPlayFire(); };
	static void playShipDeath() { Instance().privPlayShipDeath(); };
	static void playCritterDeath() { Instance().privPlayCritterDeath(); };


	////Stop Sounds////
	//Loops
	static void stopScorpion() { Instance().privStopScorpion(); };
	static void stopSpider() { Instance().privStopSpider(); };
	static void stopFlea() { Instance().privStopFlea(); };
	static void stopCentipede() { Instance().privStopCentipede(); };

	static void Terminate();

private:
	static Sound_Manager* ptrInstance;

	Sound_Manager();
	Sound_Manager(const Sound_Manager&) = delete;
	Sound_Manager& operator=(const Sound_Manager&) = delete;
	~Sound_Manager();

	static Sound_Manager& Instance()
	{
		if (!ptrInstance)
			ptrInstance = new Sound_Manager;
		return *ptrInstance;
	};

	sf::Sound scorpionSound;
	sf::Sound spiderSound;
	sf::Sound fleaSound;
	sf::Sound centipedeSound;
	sf::Sound fireSound;
	sf::Sound shipDeath;
	sf::Sound critterDeath;

	////Play Sounds////
	//Loops
	void privPlayScorpion();
	void privPlaySpider();
	void privPlayFlea();
	void privPlayCentipede();
	//Non-Loops
	void privPlayFire();
	void privPlayShipDeath();
	void privPlayCritterDeath();

	////Stop Loops////
	//Loops
	void privStopScorpion();
	void privStopSpider();
	void privStopFlea();
	void privStopCentipede();
	void privSetVolume(float vol);

	float SOUND = 15.0f;

};

#endif
