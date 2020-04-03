#pragma once
#include <string>
#include <SFML/Graphics.hpp>

class Window
{
public:
	Window();
	Window(const std::string& l_title, const sf::Vector2u& l_size);
	~Window();

	void Draw(sf::Drawable& l_drawable);//Clear, draw and render the window
	void Update();
	sf::Vector2u GetWindowSize();
	bool isClosed();
	sf::RenderWindow& GetRenderWindow();
	void HandlePlayerInput(sf::Keyboard::Key key, bool isPressed);

private:
	void Setup(const std::string& l_title, const sf::Vector2u& l_size);
	void Destroy();
	void Create();

	sf::RenderWindow m_window;
	sf::Vector2u m_windowSize;
	std::string m_windowTitle;
	bool m_isClosed = false;
};
