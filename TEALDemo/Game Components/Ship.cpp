// Ship
// Andre Berthiaume, Aug 2012

#include "Ship.h"
#include "Bullet.h"
#include "GameController.h"
#include "ShipExplosion.h"
#include "Widget.h"
#include "Asteroid.h"

Ship::Ship()
{
	bitmap = ResourceManager::GetTextureBitmap("ship");
	MainSprite.setTexture(ResourceManager::GetTexture("ship"));
	MainSprite.setOrigin(MainSprite.getTextureRect().width / 2.0f, MainSprite.getTextureRect().height / 2.0f);
	MainSprite.setScale(1, 1);
	MainSprite.setPosition(Pos);

	Pos = sf::Vector2f(WindowManager::MainWindow.getView().getSize().x / 2.0f, WindowManager::MainWindow.getView().getSize().y - MainSprite.getTextureRect().height);
	SetDrawOrder(1000);

	SetCollider(MainSprite, bitmap, true);
	RegisterCollision<Ship>(*this);
}

void Ship::Destroy()
{
	DeregisterInput();
	DeregisterCollision<Ship>(*this);
}

void Ship::Update()
{
	// Testing for player input
	/*if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && fireReady)
	{
		Bullet* bullet;
		bullet = new Bullet(Pos, this);
		fireReady = false;
	}*/
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) Impulse = sf::Vector2f(-5, 0);
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) Impulse = sf::Vector2f(5, 0);
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) Impulse = sf::Vector2f(0, -5);
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) Impulse = sf::Vector2f(0, 5);
	else Impulse = sf::Vector2f(0, 0);
	//prevPos = Pos;
	Pos += Impulse;
	Tools::Clamp<float>(Pos.x, MainSprite.getTextureRect().width / (float)2, WindowManager::MainWindow.getView().getSize().x - (MainSprite.getTextureRect().width / (float)2));
	Tools::Clamp<float>(Pos.y, 400, WindowManager::MainWindow.getView().getSize().y - MainSprite.getTextureRect().height);
	MainSprite.setPosition(Pos);

}

void Ship::KeyPressed(sf::Keyboard::Key k, bool altKey, bool ctrlKey, bool shiftKey, bool systemKey)
{
	if ( k == sf::Keyboard::Return )
	{
		Bullet* bullet;

		ConsoleMsg::WriteLine("Pew! Pew!");

		bullet = new Bullet(Pos + GunOffset_top); 
		bullet = new Bullet(Pos + GunOffset_bot); 

		FireSnd.play();
	}
}

void Ship::Collision(Widget *other)
{
	GameController::Instance().AddScore( other->GetValue() );
	other->MarkForDestroy();
}

void Ship::Collision(Asteroid *other)
{
	other->Explode();
	new ShipExplosion(Pos);
	MarkForDestroy();
}

void Ship::Draw()
{
	WindowManager::MainWindow.draw(MainSprite);
}

