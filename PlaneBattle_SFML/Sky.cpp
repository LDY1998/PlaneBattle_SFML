#include "Sky.h"

Sky::Sky(sf::RenderWindow* l_window):
	window(l_window)
{
	this->setTexture(texture);
	this->setScale(1.0*window->getSize().x / texture.getSize().x, 1.0*window->getSize().y / texture.getSize().y);

}

Sky::~Sky()
{
}

void Sky::addPlayer(PlayerPlane* l_player)
{
	player = l_player;
}

void Sky::update(sf::Time elapsed)
{
	checkCollision();
	player->Update(elapsed);
	for (auto e = enemies.begin(); e != enemies.end(); e++)
	{
		(*e)->Update(elapsed);
	}
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
	//window->draw(*player);
}

void Sky::checkCollision()
{
}


