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
void Game::ProcessEvent(sf::Time elapsed)
{
	sf::Event event;
	while (sky->window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed) {
			sky->window->close();
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		//向左

		if (this->sky->getPlayerPosition().x > 0) {
			sky->movePlayer(sf::Vector2<float>(-1.0, 0.0)*elapsed.asSeconds());
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		//向右


		if (this->sky->getPlayerPosition().x < this->sky->getTextureRect().width) {
			sky->movePlayer(sf::Vector2<float>(1.0, 0.0)*elapsed.asSeconds());
		}
	}


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		//向左
		if (this->sky->getPlayerPosition().y > 0) {
			sky->movePlayer(sf::Vector2<float>(0.0, -1.0)*elapsed.asSeconds());
		}


	}


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		//向右

		if (this->sky->getPlayerPosition().y < (this->sky->window->getSize().y)) {
			sky->movePlayer(sf::Vector2<float>(0.0, 1.0)*elapsed.asSeconds());
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
		this->sky->player->fire();
	}
}
void Game::Update() {
	sky->update(GetElapsed());
}


void Game::Render() {
	sky->window->clear();
	sky->render();
	sky->window->display();
}

void Game::run() {
	float frameTime = 1.0f / 60.0f;
	while (sky->window->isOpen())
	{
		if (m_elapsed.asSeconds() > frameTime) {
			ProcessEvent(m_elapsed);
			Update();
			Render();
			m_elapsed -= sf::seconds(frameTime);
		}
		RestartClock();
	}
	/*while (sky->window->isOpen())
	{
		ProcessEvent();
		Update();
		Render();
	}*/
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