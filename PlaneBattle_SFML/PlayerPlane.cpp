#include "PlayerPlane.h"
#include "Sky.h"

PlayerPlane::PlayerPlane(Sky* l_sky):
	Plane(l_sky)
{
	this->setTexture(texture);
	this->setScale(0.3, 0.3);
	this->setPosition(sky->window->getSize().x / 2, sky->window->getSize().y - this->texture.getSize().y);
	this->setSpeed(100);
	this->setFireSpeed(15);
	life = 100;
	fireDensity = 20;
}

PlayerPlane::~PlayerPlane()
{

}

void PlayerPlane::fire()
{
	static int fireIndex = 0;

	if (fireIndex > fireDensity) {

		fireIndex = 0;
	}
	else {
		fireIndex++;
	}

}

bool PlayerPlane::isDead()
{
	return life > 0;
}

void PlayerPlane::damageAnimation()
{
	sf::Sprite boomImg;
	boomImg.setTexture(boomTexture);
	boomImg.setPosition(this->getPosition().x, this->getPosition().y);
	sky->window->draw(boomImg);
	sky->window->display();

	sf::Time s = sf::seconds(0.5);
	sf::sleep(s);
	life--;
}
