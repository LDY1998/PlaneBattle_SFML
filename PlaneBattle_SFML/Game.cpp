#include "Game.h"



Game::Game():
	m_Window(sf::VideoMode(900, 600), "Plane Battle", sf::Style::Default)
{


}

Game::~Game() {
	
}

void Game::InitializeGame(Sky* l_sky)
{
	this->sky = l_sky;
}

sf::Time Game::GetElapsed() {
	return m_elapsed;
}

void Game::RestartClock() {
	m_elapsed += m_clock.restart();
}
void Game::Update() {
	sky->update(GetElapsed());
}


void Game::Render() {
	m_Window.clear();
	sky->render();
	m_Window.display();
}

void Game::run() {
	float frameTime = 1.0f / 60.0f;
	while (m_Window.isOpen())
	{
		if (m_elapsed.asSeconds() > frameTime) {
			Update();
			Render();
			m_elapsed -= sf::seconds(frameTime);
		}
		RestartClock();
	}
}

int main() {
	Game game;
	sf::RenderWindow window(sf::VideoMode(900, 600), "Plane Battle", sf::Style::Default);
	Sky sky(&window);
	game.InitializeGame(&sky);
	game.run();
	return 0;
}