#pragma once
#include "FlyingObject.h"
class Bullet :
	public FlyingObject
{
public:
	Bullet(sf::Texture l_texture, sf::Vector2f l_direction, sf::Vector2f position);

private:
	sf::Texture texture;

};

