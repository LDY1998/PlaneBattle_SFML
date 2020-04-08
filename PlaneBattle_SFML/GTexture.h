#pragma once
#include <SFML/Graphics.hpp>
class GTexture
{
public:
	GTexture();
	virtual ~GTexture();

	static sf::Texture PLAYER_NORMAL;
	static sf::Texture PLAYER_BOOM1;
	static sf::Texture PLAYER_BOOM2;
	static sf::Texture PLAYER_BOOM3;
	static sf::Texture PLAYER_NULL;

	static sf::Texture ENEMY_NORMAL;
	static sf::Texture ENEMY_BOOM1;
	static sf::Texture ENEMY_2;
	static sf::Texture ENEMY_BOSS;

	static sf::Texture BULLET;
	static sf::Texture BULLET2;
	static sf::Texture BULLET_BOSS;

	static sf::Texture ITEM_HEALTH;
	static sf::Texture ITEM_SPEED;
	static sf::Texture ITEM_RAND;
	static sf::Texture ITEM_ATK;
	static sf::Texture ITEM_BUTTET_SPEED;

	static sf::Texture SKY;
	static sf::Texture SKY_BOOM;
	static sf::Image ICO;


	static sf::Texture LOADING;



	static void load();
};

