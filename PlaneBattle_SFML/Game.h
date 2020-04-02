#pragma once
#include <SFML/Graphics.hpp>
#include "Window.h"


class Game {


public:
	Game();
	~Game();
	void run();
	void ProcessEvent();
	void Render();
	void Update();
	void HandlePlayerInput(sf::Keyboard::Key key, bool isPressed);
	Window* GetWindow();
	sf::Time GetElapsed();
	void RestartClock();

private:
	Window m_Window;
	bool mIsMovingUp, mIsMovingDown, mIsMovingLeft, mIsMovingRight;
	void Move();
	sf::Texture m_Texture;
	sf::Sprite m_Sprite;
	sf::Vector2f m_Speed;
	sf::Time m_elapsed;
	sf::Clock m_clock;
};