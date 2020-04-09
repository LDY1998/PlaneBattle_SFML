#pragma once
#include <SFML/Graphics.hpp>
#include "FlyingObject.h"

class Plane :
	public FlyingObject
{
public:
	Plane(Sky* l_sky);
	virtual ~Plane();

	void setFireSpeed(int speed);
	int getFireSpeed();
	virtual void fire() = 0;

protected:
	int fireSpeed;
	int life;
	int fireDensity;

	sf::Texture texture;
	sf::Texture boomTexture;
};

