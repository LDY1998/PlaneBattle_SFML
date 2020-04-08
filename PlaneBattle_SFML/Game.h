#pragma once
#include <SFML/Graphics.hpp>
#include "Window.h"
#include <iostream>
#include "StateManager.h"
#include "PlayerPlane.h"
#include "EnemyPlane.h"
#include "Sky.h"


class Game {


public:
	Game();
	~Game();
	void InitializeGame(Sky* l_sky);
	void run();
	void Render();
	void Update();
	sf::Time GetElapsed();
	void RestartClock();

private:
	sf::RenderWindow m_Window;
	sf::Time m_elapsed;
	sf::Clock m_clock;
	Sky* sky;
};