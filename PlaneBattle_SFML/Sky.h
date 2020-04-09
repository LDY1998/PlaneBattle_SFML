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
	void update();
	void addEnemy(EnemyPlane* enemy);
	void setEnemyCreationRate(int rate);
	void render();
	sf::RenderWindow* window;


private:
	void checkCollision();
	void createEnemies();
	sf::Texture texture = GTexture::SKY;
	int createEnemyRate = 10;
	PlayerPlane* player;
	//std::unordered_set<Bullet*> bullets;
	std::unordered_set<EnemyPlane*> enemies;

};

