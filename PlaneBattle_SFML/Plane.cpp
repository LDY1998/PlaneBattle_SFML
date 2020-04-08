#include "Plane.h"

Plane::Plane(Sky * l_sky):
	sky(l_sky)
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

