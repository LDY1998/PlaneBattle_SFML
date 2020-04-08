#pragma once
#include <SFML/Graphics.hpp>
#include "GTexture.h"
#include "Sky.h"
class FlyingObject : public sf::Sprite
{
public:
	FlyingObject();
	FlyingObject(Sky* l_window);
	virtual ~FlyingObject();
	virtual void update(sf::Time elapsed) = 0;
	virtual void render() = 0;
	void move();
	void move(sf::Vector2f direction);
	void setSpeed(float l_speed);
	float getSpeed();

protected:
	sf::Vector2f direction;
	float speed;
	Sky* sky;
	

};

