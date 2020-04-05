#include "Game.h"



Game::Game() :
	m_Window(sf::VideoMode(900, 600), "Plane Battle", sf::Style::Default),
	player(PlayerPlane(&m_Window))
{
}

Game::~Game() {}

void Game::InitializeGame()
{

}

sf::Time Game::GetElapsed() {
	return m_elapsed;
}

void Game::RestartClock() {
	m_elapsed += m_clock.restart();
}
void Game::Update() {
	player.Update(GetElapsed());
}


void Game::Render() {
	//m_Window.Draw(m_Sprite);
	m_Window.clear();
	player.Render();
	m_Window.display();
}

void Game::run() {
	float frameTime = 1.0f / 60.0f;
	InitializeGame();
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
	game.run();
	return 0;
}