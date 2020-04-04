#include "PlayerPlane.h"

PlayerPlane::PlayerPlane()
{
}

PlayerPlane::PlayerPlane(sf::RenderWindow* l_window):
	Plane(l_window)
{
	m_Texture.loadFromFile("assets/spacecraft.png");
	m_Sprite.setTexture(m_Texture);
	sf::Vector2f originPosition(renderWindow->getSize().x / 2, renderWindow->getSize().y - m_Texture.getSize().y);
	m_Sprite.setPosition(originPosition);
}

PlayerPlane::~PlayerPlane()
{
}

void PlayerPlane::ProcessEvent()
{
	sf::Event evnt;
	while (renderWindow->pollEvent(evnt))
	{
		if (evnt.type == sf::Event::Closed) {
			renderWindow->close();
		}
		else if (evnt.type == sf::Event::KeyPressed) {
			HandlePlayerInput(evnt.key.code, true);
			break;
		}
		else if (evnt.type == sf::Event::KeyReleased) {
			HandlePlayerInput(evnt.key.code, false);
			break;
		}
		
	}
}

void PlayerPlane::HandlePlayerInput(sf::Keyboard::Key key, bool isPressed)
{
	switch (key)
	{
	case sf::Keyboard::W:
		if (!mIsMovingDown) {
			mIsMovingUp = isPressed;
		}
		break;
	case sf::Keyboard::S:
		if (!mIsMovingUp) {
			mIsMovingDown = isPressed;
		}
		break;
	case sf::Keyboard::A:
		if (!mIsMovingRight) {
			mIsMovingLeft = isPressed;
		}
		break;
	case sf::Keyboard::D:
		if (!mIsMovingLeft) {
			mIsMovingRight = isPressed;
		}
		break;
	default:
		break;
	}
}

void PlayerPlane::Move(sf::Time l_elapsed)
{
	sf::Vector2f position = m_Sprite.getPosition();
	sf::Vector2f speed(0, 0);
	if (mIsMovingUp) {
		speed.y = -m_Speed.y;
	}
	else if (mIsMovingDown) {
		speed.y = m_Speed.y;
	}
	else if (mIsMovingRight) {
		speed.x = m_Speed.x;
	}
	else if (mIsMovingLeft) {
		speed.x = -m_Speed.x;
	}
	m_Sprite.move(speed*l_elapsed.asSeconds());
}

void PlayerPlane::Update(sf::Time l_elapsed)
{
	Move(l_elapsed);
	if (isCollide()) {
		Damage(m_life);
	}
}

void PlayerPlane::Shoot()
{
}
