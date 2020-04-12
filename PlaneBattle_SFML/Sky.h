#pragma once
#include <SFML/Graphics.hpp>
#include "PlayerPlane.h"
#include "GTexture.h"
#include "EnemyPlane.h"
#include <unordered_set>
#include "Bullet.h"

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
	sf::Vector2f getPlayerPosition();
	void movePlayer(sf::Vector2f);
	sf::RenderWindow* window;
	void addBullet(Bullet*);
	PlayerPlane* player;



private:
	void checkCollision();
	void createEnemies();
	sf::Texture texture = GTexture::SKY;
	int createEnemyRate = 100;
	std::unordered_set<Bullet*> bullets;
	std::unordered_set<EnemyPlane*> enemies;

};

