#include "FlyingObject.h"

FlyingObject::FlyingObject()
{
	direction.x = 0;
	direction.y = 0;
}

FlyingObject::FlyingObject(Sky* l_sky):
	sky(l_sky)
{
}

FlyingObject::~FlyingObject()
{
}

void FlyingObject::move()
{
	sf::Vector2f velocity = this->direction * speed;
	this->setPosition(this->getPosition() + velocity);
}

void FlyingObject::move(sf::Vector2f direction)
{
	this->direction = direction;
	sf::Vector2f velocity = this->direction * speed;
	this->setPosition(this->getPosition() + velocity);
}

void FlyingObject::setSpeed(float l_speed)
{
	this->speed = l_speed;
}

float FlyingObject::getSpeed()
{
	return speed;
}
