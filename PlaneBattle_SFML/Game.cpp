#include "Game.h"



Game::Game()
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
void Game::ProcessEvent()
{
	sf::Event event;
	while (sky->window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed) {
			sky->window->close();
		}
	}
}
void Game::Update() {
	sky->update();
}


void Game::Render() {
	sky->window->clear();
	sky->render();
	sky->window->display();
}

void Game::run() {
	/*float frameTime = 1.0f / 60.0f;
	while (m_Window.isOpen())
	{
		if (m_elapsed.asSeconds() > frameTime) {
			Update();
			Render();
			m_elapsed -= sf::seconds(frameTime);
		}
		RestartClock();
	}*/
	while (sky->window->isOpen())
	{
		ProcessEvent();
		Update();
		Render();
	}
}

int main() {
	GTexture::load();
	Game game;
	sf::RenderWindow window(sf::VideoMode(900, 600), "Plane Battle", sf::Style::Default);
	Sky sky(&window);
	window.setFramerateLimit(120);
	game.InitializeGame(&sky);
	game.run();
	return 0;
}