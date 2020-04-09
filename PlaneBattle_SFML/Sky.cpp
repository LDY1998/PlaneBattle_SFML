#include "Sky.h"


Sky::Sky(sf::RenderWindow* l_window):
	window(l_window)
{
	this->setTexture(texture);
	this->setScale(1.0*window->getSize().x / texture.getSize().x, 1.0*window->getSize().y / texture.getSize().y);
	player = new PlayerPlane(this);
}

Sky::~Sky()
{
}

void Sky::addPlayer(PlayerPlane* l_player)
{
	player = l_player;
}

void Sky::update()
{
	
}

void Sky::addEnemy(EnemyPlane * enemy)
{
	enemies.insert(enemy);
}

void Sky::setEnemyCreationRate(int rate)
{
	createEnemyRate = rate;
}

void Sky::render()
{
	window->draw(*this);
	window->draw(*player);
	for (auto enemy = enemies.begin(); enemy != enemies.end(); enemy++) {
		window->draw(**enemy);
	}
}

void Sky::checkCollision()
{
}

void Sky::createEnemies()
{
	static int count = 0;

	if (count > createEnemyRate) {
		EnemyPlane* enemy1 = new EnemyPlane(this);
		EnemyPlane* enemy2 = new EnemyPlane(this);
		enemy1->setSpeed(20);
		enemy2->setSpeed(20);
		//this->addEnemy(enemy1);
		//this->addEnemy(enemy2);
		this->enemies.insert(enemy1);
		this->enemies.insert(enemy2);
		count = 0;
	}
	else {
		count++;
		return;
	}
}


