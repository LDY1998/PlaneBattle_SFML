#pragma once
#include "Plane.h"

class PlayerPlane :
	public Plane
{
public:
	PlayerPlane();
	PlayerPlane(sf::RenderWindow* l_window);
	~PlayerPlane();
	void ProcessEvent();
	void HandlePlayerInput(sf::Keyboard::Key key, bool isPressed);
	void Move(sf::Time l_elapsed);
	void Update(sf::Time l_elapsed);
	void Shoot();
};

