// LoadAllResources.cpp
// Andre Berthiaume, June 2012
//
// The user fills the method with all resources that need loading

#include "ResourceManager.h"
#include "..\..\Centipede_Menu.h"

void ResourceManager::LoadAllResources()
{
	/*Starting Scene*/
	SetStartScene( new Centipede_Menu() );

	/*Textures for the GameObjects*/
	AddTexture("playerShip", "../resources/blaster.png");					//Player sprite
	AddTexture("bullet", "../resources/bullet.png");						//Bullet sprite
	AddTexture("mushroom", "../resources/mushroom.png");					//Mushroom sprite
	AddTexture("centipede_head", "../resources/centipede_head.png");		//Centipde Head sprite
	AddTexture("centipede_segment", "../resources/centipede_segment.png");  //Centipede Body sprite
	AddTexture("flea", "../resources/flea.png");							//Flea sprite
	AddTexture("spider", "../resources/spider.png");						//Spider sprite
	AddTexture("scorpion", "../resources/scorpion.png");					//Scorpion Sprite
	AddTexture("deathPNG", "../resources/death.png");						//Player death explosion
	AddTexture("spawn", "../resources/spawn.png");							//Enemy death explosion
	AddTexture("SpiderScore", "../resources/SpiderScore.png");				//spider score sprites
	AddTexture("Block", "../resources/Block.png");							//black square for covering text areas

	AddTexture("Master_bmp", "../resources/SPRITES.bmp");					//Bitmap for mastersprite grid
	AddTexture("Master", "../resources/SPRITES.png");						//Master grid containing all sprites

	/*Font*/
	AddTexture("Alphabet", "../resources/FONTwPLAYER.bmp");		//Texture containing the font characters

	/*Sounds for the Game*/
	AddSound("kill", "../resources/kill.wav");					//Enemy death
	AddSound("fire1", "../resources/fire1.wav");				//Player firing bullet
	AddSound("beat", "../resources/newBeat.wav");				//Centipede "footstep"
	AddSound("deathWAV", "../resources/death.wav");				//Player death
	AddSound("spiderloop", "../resources/spiderloop.wav");		//Spider tune
	AddSound("scorpion_new", "../resources/scorpion_new.wav");  //Scorpion spawn
	AddSound("flea_new", "../resources/flea_new.wav");			//Flea falling
}

