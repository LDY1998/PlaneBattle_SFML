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
	void damage(int damage);
	virtual void fire() = 0;
	bool isDead();

protected:
	int fireSpeed;
	int life;
	int fireDensity;

	sf::Texture texture;
	sf::Texture boomTexture;
};

