#pragma once
#include <SFML/Graphics.hpp>
class Plane
{

public:
	Plane();
	Plane(sf::RenderWindow* l_window);
	~Plane();
	virtual void Shoot() = 0;
	virtual void Move(sf::Time l_elapsed) = 0;
	sf::Vector2f GetPosition();
	int GetLife();
	void Damage(int l_damage);
	virtual void ProcessEvent() = 0;
	void Render();
	void Update();
	bool isCollide();


protected:
	sf::RenderWindow* renderWindow;
	sf::Texture m_Texture;
	sf::Sprite m_Sprite;
	sf::Vector2f m_Speed;
	bool mIsMovingUp = false, mIsMovingDown = false, mIsMovingLeft = false, mIsMovingRight = false;
	int m_life;
	sf::Clock* m_clock;
};

