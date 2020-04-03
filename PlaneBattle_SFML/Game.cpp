#include "Game.h"



Game::Game() :
	m_Window("Plane Battle", sf::Vector2u(900, 600))
{
	m_Texture.loadFromFile("assets/spacecraft.png");
	m_Sprite.setTexture(m_Texture);
	m_Speed = sf::Vector2f(200.f, 200.f);
	sf::Vector2f originPosition(m_Window.GetWindowSize().x / 2, m_Window.GetWindowSize().y - m_Texture.getSize().y);
	//m_Sprite.setOrigin(m_Window.GetWindowSize().x / 2, m_Window.GetWindowSize().y / 2);
	m_Sprite.setPosition(originPosition);
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
	sf::Vector2f speed(0, 0);
	/*if ((m_Sprite.getPosition().x) > l_windSize.y - l_textSize.y && m_Speed.y > 0) {
		m_Speed.y *= -1;
	}
	if ((m_Sprite.getPosition().x) < l_textSize.x - l_textSize.x && m_Speed.x > 0) {
		m_Speed.x *= -1;
	}
	if ((m_Sprite.getPosition().y) > l_windSitSize.x / 3 && m_Speed.x < 0) {
		m_Speed.x *= -1;
	}
	if ((m_Sprite.getPosition().y) < l_textSize.y / 3 && m_Speed.y < 0) {
		m_Speed.y *= -1;
	}*/
	if (mIsMovingUp) {
		speed.y = -200.f;
	}
	else if (mIsMovingDown) {
		speed.y = 200.f;
	}
	else if (mIsMovingRight) {
		speed.x = 200.f;
	}
	else if (mIsMovingLeft) {
		speed.x = -200.f;
	}
	float fElapsed = GetElapsed().asSeconds();
	m_Sprite.move(speed * fElapsed);
	
	
}

void Game::Render() {
	m_Window.Draw(m_Sprite);
}

void Game::HandlePlayerInput(sf::Keyboard::Key key, bool isPressed) {
	switch (key)
	{
	case sf::Keyboard::W:
		if (!mIsMovingDown) {
			mIsMovingUp = isPressed;
		}
		break;
	case sf::Keyboard::S:
		if (!mIsMovingUp) {
			mIsMovingDown = isPressed;
		}
		break;
	case sf::Keyboard::A:
		if (!mIsMovingRight) {
			mIsMovingLeft = isPressed;
		}
		break;
	case sf::Keyboard::D:
		if (!mIsMovingLeft) {
			mIsMovingRight = isPressed;
		}
		break;
	default:
		break;
	}
	Move();
}

void Game::ProcessEvent() {
	sf::Event evnt;
	sf::RenderWindow& renderWindow = GetWindow()->GetRenderWindow();
	while (renderWindow.pollEvent(evnt)) {
		if (evnt.type == sf::Event::KeyPressed) {
			HandlePlayerInput(evnt.key.code, true);
			break;
		}
		else if (evnt.type == sf::Event::KeyReleased) {
			HandlePlayerInput(evnt.key.code, false);
			break;
		}
		else if (evnt.type == sf::Event::Closed) {
			renderWindow.close();
			break;
		}
		
	}
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
			ProcessEvent();
			//Update();
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