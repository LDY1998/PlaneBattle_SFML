#include "Sky.h"
#include <math.h>


Sky::Sky(sf::RenderWindow* l_window):
	window(l_window)
{
	this->setTexture(texture);
	this->setScale(1.0*window->getSize().x / texture.getSize().x, 1.0*window->getSize().y / texture.getSize().y);
	player = new PlayerPlane(this);
}

Sky::~Sky()
{
}

void Sky::addPlayer(PlayerPlane* l_player)
{
	player = l_player;
}

void Sky::update(sf::Time elapsed)
{
	checkCollision();
	this->createEnemies();
	for (auto bullet : bullets)
		bullet->move();

	for (auto enemy : enemies) {
		enemy->update(elapsed);
	}
	
}

void Sky::addEnemy(EnemyPlane * enemy)
{
	enemies.insert(enemy);
}

void Sky::setEnemyCreationRate(int rate)
{
	createEnemyRate = rate;
}

void Sky::render()
{
	window->draw(*this);
	window->draw(*player);
	for (auto enemy = enemies.begin(); enemy != enemies.end(); enemy++) {
		window->draw(**enemy);
	}
	for (auto bullet : bullets)
		window->draw(*bullet);
}

sf::Vector2f Sky::getPlayerPosition()
{

	return player->getPosition();
}

void Sky::movePlayer(sf::Vector2f direction)
{
	player->move(direction);
}

void Sky::addBullet(Bullet *bullet)
{
	this->bullets.insert(bullet);
}

void Sky::checkCollision()
{
	for (auto enemy = enemies.begin(); enemy != enemies.end();) {
		if ((*enemy)->isDead()) {
			delete *enemy;
			enemy = enemies.erase(enemy);
			continue;
		}
		for (auto bullet = bullets.begin(); bullet != bullets.end();) {
			sf::Vector2f positionDiff((*enemy)->getPosition() - (*bullet)->getPosition());
			if (abs(positionDiff.x) <= 1 || abs(positionDiff.y) <= 5) {
				delete (*bullet);
				bullet = bullets.erase(bullet);
				(*enemy)->damage(10);
			}
			else {
				bullet++;
			}
		}
		enemy++;
	}
}

void Sky::createEnemies()
{
	static int count = 0;

	if (count > createEnemyRate) {
		EnemyPlane* enemy1 = new EnemyPlane(this);
		EnemyPlane* enemy2 = new EnemyPlane(this);
		enemy1->setSpeed(20);
		enemy2->setSpeed(20);
		//this->addEnemy(enemy1);
		//this->addEnemy(enemy2);
		this->enemies.insert(enemy1);
		this->enemies.insert(enemy2);
		count = 0;
	}
	else {
		count++;
		return;
	}
}


