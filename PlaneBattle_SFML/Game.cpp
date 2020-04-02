#include "Game.h"
#include <iostream>



Game::Game() :
	m_Window("Plane Battle", sf::Vector2u(900, 600))
{
	m_Texture.loadFromFile("assets/spacecraft.png");
	m_Sprite.setTexture(m_Texture);
	m_Speed = sf::Vector2f(200.f, 200.f);
	//std::cout << "Size: x: " << m_Texture.getSize().x << ", y: " << m_Texture.getSize().y << std::endl;
}

Game::~Game() {}

Window* Game::GetWindow() {
	return &m_Window;
}
sf::Time Game::GetElapsed() {
	return m_elapsed;
}

void Game::RestartClock() {
	m_elapsed += m_clock.restart();
}
void Game::Update() {
	m_Window.Update();
	Move();
}

void Game::Move() {
	sf::Vector2u l_windSize = m_Window.GetWindowSize();
	sf::Vector2u l_textSize = m_Texture.getSize();
	sf::Vector2f position = m_Sprite.getPosition();
	if ((m_Sprite.getPosition().x) > l_windSize.x - l_textSize.x && m_Speed.x > 0) {
		m_Speed.x *= -1;
	}
	if ((m_Sprite.getPosition().y) > l_windSize.y - l_textSize.y && m_Speed.y > 0) {
		m_Speed.y *= -1;
	}
	if ((m_Sprite.getPosition().x) < l_textSize.x / 3 && m_Speed.x < 0) {
		m_Speed.x *= -1;
	}
	if ((m_Sprite.getPosition().y) < l_textSize.y / 3 && m_Speed.y < 0) {
		m_Speed.y *= -1;
	}
	float fElapsed = GetElapsed().asSeconds();
	m_Sprite.move(m_Speed * fElapsed);
	
	
}

void Game::Render() {
	m_Window.Draw(m_Sprite);
}
void Game::run() {
	float frameTime = 1.0f / 60.0f;
	
	while (!(GetWindow()->isClosed())) {
		//HandlePlayerInput();
		//std::cout << m_elapsed.asSeconds();
		/*Update();
		Render();*/
		//RestartClock();
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