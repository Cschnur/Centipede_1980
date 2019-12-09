#include "Game Components\TEAL\CommonElements.h"

#include "Centipede_Menu.h"

#include "Mushroom.h"
#include "Block.h"
#include "Bullet.h"
#include "Centipede_Head.h"
#include "Scorpion.h"
#include "Centipede.h"
#include "Flea.h"
#include "Spider.h"
#include "Centipede_Body.h"

#include "Game_Manager.h"

//Singeltons//
#include "Scorpion_Factory.h"
#include "Spider_Factory.h"
#include "Bullet_Factory.h"
#include "Flea_Factory.h"
#include "Centipede_Factory.h"
#include "Ship_Factory.h"
#include "BlasterKB.h"
#include "BlasterAI.h"
#include "MushroomManager.h"
#include "HUD.h"
#include "Sound_Manager.h"
#include "Score_Manager.h"
#include "Explosion_Factory.h"
#include "Critter_Manager.h"
#include "Centipede_Manager.h"
#include "SpiderScore_Factory.h"
#include "Block_Factory.h"

void Centipede_Menu::Initialize()
{
	//This is top dog, starts everything else
	Game_Manager::Initialize(SCENE_MENU);


	//----------Collision pairs----------------//
	CollisionTestPair<BlasterKB, Mushroom>(); 
	CollisionTestPair<BlasterKB, Centipede_Head>();
	CollisionTestPair<BlasterKB, Centipede_Body>();
	CollisionTestPair<BlasterKB, Spider>();
	CollisionTestPair<BlasterKB, Flea>();

	CollisionTestPair<BlasterAI, Mushroom>();
	CollisionTestPair<BlasterAI, Centipede_Head>();
	CollisionTestPair<BlasterAI, Centipede_Body>();
	CollisionTestPair<BlasterAI, Spider>();
	CollisionTestPair<BlasterAI, Flea>();

	CollisionTestPair<Bullet, Mushroom>();
	CollisionTestPair<Bullet, Block>();
	CollisionTestPair<Bullet, Centipede_Head>();
	CollisionTestPair<Bullet, Centipede_Body>();
	CollisionTestPair<Bullet, Scorpion>();
	CollisionTestPair<Bullet, Flea>();
	CollisionTestPair<Bullet, Spider>();
	//---------------------------------------//
};

void Centipede_Menu::Terminate()
{
	//-------Terminate Singletons-----------//
	Scorpion_Factory::Terminate();
	Spider_Factory:: Terminate();
	Bullet_Factory::Terminate();
	Flea_Factory::Terminate();
	Centipede_Factory::Terminate();
	Ship_Factory::Terminate();
	MushroomManager::Terminate();
	Game_Manager::Terminate();
	HUD::Terminate();
	Score_Manager::Terminate();
	Sound_Manager::Terminate();
	Explosion_Factory::Terminate();
	Centipede_Manager::Terminate();
	//Critter_Manager::Terminate();
	SpiderScore_Factory::Terminate();
	Block_Factory::Terminate();
	//---------------------------------------//
}

