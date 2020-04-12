#include "EnemyPlane.h"
#include "Sky.h"

EnemyPlane::EnemyPlane(Sky * l_sky):
	Plane(l_sky)
{
	this->setTexture(texture);
	direction.x = 0;
	direction.y = 1;
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_real_distribution<double> dist(1, (double)sky->window->getSize().x);
	this->setPosition(dist(mt), 10);
	this->life = 50;
}

EnemyPlane::~EnemyPlane()
{
}

void EnemyPlane::fire()
{
}

void EnemyPlane::moveRandomly()
{
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_real_distribution<double> dist(1, 5);

	switch ((int)dist(mt))
	{
	case 0:
		direction.x = 1.0;
		direction.y = 0;
	case 1:
		direction.x = -1.0;
		direction.y = 0;
	case 2:
		direction.x = 0;
		direction.y = 1;
	case 3:
		direction.x = 0;
		direction.y = 1;
	case 4:
		direction.x = 0;
		direction.y = 1;
	default:
		break;
	}
}

void EnemyPlane::update(sf::Time elapsed)
{
	this->moveRandomly();
	this->move(direction*elapsed.asSeconds());
}
