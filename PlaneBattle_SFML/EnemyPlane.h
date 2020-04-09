#pragma once
#include "Plane.h"
#include <random>

class EnemyPlane :
	public Plane
{
public:
	EnemyPlane(Sky* l_sky);
	~EnemyPlane();

	void fire();
	void moveRandomly();



private:
	sf::Texture texture = GTexture::ENEMY_NORMAL;
	sf::Texture boomTexture = GTexture::ENEMY_BOOM1;
	sf::Vector2f direction;



};

