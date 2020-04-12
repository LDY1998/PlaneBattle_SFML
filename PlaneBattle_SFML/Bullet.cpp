#include "Bullet.h"


Bullet::Bullet(sf::Texture l_texture, sf::Vector2f l_direction, sf::Vector2f position):
	texture(l_texture)
{
	this->direction = l_direction;
	this->setTexture(texture);
	this->setPosition(position);
	this->speed = 3.0;
}
