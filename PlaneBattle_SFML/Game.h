#pragma once
#include <SFML/Graphics.hpp>
#include "Window.h"
#include <iostream>
#include "StateManager.h"
#include "PlayerPlane.h"


class Game {


public:
	Game();
	~Game();
	void InitializeGame();
	void run();
	void Render();
	void Update();
	//void HandlePlayerInput(sf::Keyboard::Key key, bool isPressed);
	//void ProcessEvent();
	//Window* GetWindow();
	sf::Time GetElapsed();
	void RestartClock();

private:
	sf::RenderWindow m_Window;
	//bool mIsMovingUp=false, mIsMovingDown=false, mIsMovingLeft=false, mIsMovingRight=false;
	//void Move();
	/*sf::Texture m_Texture;
	sf::Sprite m_Sprite;
	sf::Vector2f m_Speed;*/
	sf::Time m_elapsed;
	sf::Clock m_clock;
	PlayerPlane player;
};