#include "GTexture.h"


sf::Texture GTexture::SKY;
sf::Texture GTexture::SKY_BOOM;
sf::Texture GTexture::PLAYER_NORMAL;
sf::Texture GTexture::PLAYER_NULL;
sf::Texture GTexture::BULLET;
sf::Texture GTexture::BULLET2;
sf::Texture GTexture::ENEMY_NORMAL;
sf::Texture GTexture::ENEMY_BOOM1;
sf::Texture GTexture::ITEM_HEALTH;
sf::Texture GTexture::ITEM_SPEED;
sf::Texture GTexture::ITEM_RAND;
sf::Texture GTexture::ITEM_ATK;
sf::Texture GTexture::ITEM_BUTTET_SPEED;
sf::Texture GTexture::LOADING;
sf::Texture GTexture::ENEMY_2;
sf::Texture GTexture::BULLET_BOSS;
sf::Texture GTexture::ENEMY_BOSS;
sf::Image GTexture::ICO;
GTexture::GTexture()
{
	//ctor
}

GTexture::~GTexture()
{
	//dtor
}
void GTexture::load() {

	SKY.loadFromFile("assets\\SKY.jpg");
	SKY_BOOM.loadFromFile("assets\\SKY_BOOM.jpg");
	PLAYER_NORMAL.loadFromFile("assets\\plane_1.png", sf::IntRect(2, 9, 420, 272));
	BULLET.loadFromFile("assets\\bullet.png", sf::IntRect(313, 230, 31, 31));
	ENEMY_NORMAL.loadFromFile("assets\\plane_2.png", sf::IntRect(390, 549, 72, 63));
	ENEMY_BOOM1.loadFromFile("assets\\boom.png");
	BULLET2.loadFromFile("assets\\bullet.png", sf::IntRect(393, 0, 48, 94));
	ITEM_HEALTH.loadFromFile("assets\\plane_1.png", sf::IntRect(395, 750, 55, 55));
	ITEM_SPEED.loadFromFile("assets\\plane_1.png", sf::IntRect(456, 807, 52, 54));
	ITEM_RAND.loadFromFile("assets\\item.png");
	ITEM_ATK.loadFromFile("assets\\item_2.png");
	LOADING.loadFromFile("assets\\LOADING.png");
	ENEMY_2.loadFromFile("assets\\plane_2.png", sf::IntRect(276, 473, 103, 74));
	ICO.loadFromFile("assets\\ICO.png");
	ENEMY_BOSS.loadFromFile("assets\\BOSS.png");//BOSS
	BULLET_BOSS.loadFromFile("assets\\bullet.png", sf::IntRect(365, 439, 42, 90));

	PLAYER_NULL.loadFromFile("assets\\NULL.png");
	ITEM_BUTTET_SPEED.loadFromFile("assets\\plane_1.png", sf::IntRect(496, 866, 52, 52));
}
