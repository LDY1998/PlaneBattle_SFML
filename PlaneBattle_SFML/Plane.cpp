#include "Plane.h"

Plane::Plane()
{
}

Plane::Plane(sf::RenderWindow* l_window):
	renderWindow(l_window)
{
}

Plane::~Plane()
{
}

sf::Vector2f Plane::GetPosition()
{
	return m_Sprite.getPosition();
}

int Plane::GetLife()
{
	return m_life;
}

void Plane::Damage(int l_damage)
{
	m_life -= l_damage;
}

void Plane::Render()
{
	renderWindow->draw(m_Sprite);
}

void Plane::Update()
{
	sf::Event evnt;
	while (renderWindow->pollEvent(evnt)) {
		if (evnt.type == sf::Event::Closed) {
			renderWindow->close();
			break;
		}
	}
}

bool Plane::isCollide()
{
	return false;
}
