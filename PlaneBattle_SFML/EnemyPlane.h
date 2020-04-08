#pragma once
#include "Plane.h"
#include <random>

class EnemyPlane :
	public Plane
{
public:
	EnemyPlane();
	EnemyPlane(sf::RenderWindow* l_window);
	~EnemyPlane();
	void Shoot();
	void Move(sf::Time l_elapsed);
	void Update(sf::Time l_elapsed);
	void Render();
	void InitializeTexture();

private:
	sf::Vector2f m_Velocity;

};

