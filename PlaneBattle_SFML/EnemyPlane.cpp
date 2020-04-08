#include "EnemyPlane.h"

EnemyPlane::EnemyPlane()
{
}

EnemyPlane::EnemyPlane(sf::RenderWindow * l_window):
	Plane(l_window),
	m_Velocity(sf::Vector2f(200, 200))
{
}

EnemyPlane::~EnemyPlane()
{
}

void EnemyPlane::Shoot()
{
}

void EnemyPlane::Move(sf::Time l_elapsed)
{
	if (m_Sprite.getPosition().y > renderWindow->getSize().y / 4) {
		m_Velocity.y = 0;
		m_Velocity.x = 0;
	}
	m_Sprite.move(m_Velocity*l_elapsed.asSeconds());
}

void EnemyPlane::Update(sf::Time l_elapsed)
{
	Move(l_elapsed);
}


void EnemyPlane::Render()
{
	renderWindow->draw(m_Sprite);
}

void EnemyPlane::InitializeTexture()
{
	m_Texture.loadFromFile("assets/EnemyPlane.png");
	m_Sprite.setTexture(m_Texture);
	sf::Vector2f originPosition(renderWindow->getSize().x / 2, m_Texture.getSize().y);
	m_Sprite.setPosition(originPosition);
}
