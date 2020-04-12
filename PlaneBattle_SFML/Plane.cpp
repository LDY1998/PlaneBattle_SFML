#include "Plane.h"


Plane::Plane(Sky * l_sky):
	FlyingObject(l_sky)
{
}

Plane::~Plane()
{
}

void Plane::setFireSpeed(int speed)
{
	fireSpeed = speed;
}

int Plane::getFireSpeed()
{
	return fireSpeed;
}

void Plane::damage(int damage)
{
	life -= damage;
}

bool Plane::isDead()
{
	return life <= 0;
}

