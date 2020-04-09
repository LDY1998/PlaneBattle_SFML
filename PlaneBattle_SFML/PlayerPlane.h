#pragma once
#include "Plane.h"

class PlayerPlane :
	public Plane
{
public:
	PlayerPlane(Sky* l_sky);
	~PlayerPlane();

	void fire();
	bool isDead();
	void damageAnimation();

private:

	sf::Texture texture = GTexture::PLAYER_NORMAL;

};

