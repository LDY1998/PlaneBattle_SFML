#pragma once
#include <SFML/Graphics.hpp>
#include "PlayerPlane.h"
#include "GTexture.h"
#include "EnemyPlane.h"
#include <unordered_set>
class Sky :
	public sf::Sprite
{
public:
	Sky(sf::RenderWindow* l_window);
	virtual ~Sky();
	//void initialize();

	void addPlayer(PlayerPlane* player);
	void update(sf::Time elapsed);
	void addEnemy(EnemyPlane* enemy);
	void setEnemyCreationRate(int rate);
	void render();

private:
	void checkCollision();

	sf::RenderWindow* window;
	sf::Texture texture = GTexture::SKY;
	int createEnemyRate = 10;

	//std::unordered_set<Bullet*> bullets;

};

