#include "Window.h"


Window::Window() {
	Setup("Window", sf::Vector2u(800, 600));
}

Window::Window(const std::string& l_title, const sf::Vector2u& l_windowSize) {
	Setup(l_title, l_windowSize);
}

Window::~Window() {
	Destroy();
}

void Window::Destroy() {
	m_window.close();
}
	
void Window::Setup(const std::string& l_title, const sf::Vector2u& l_windowSize) {
	m_windowTitle = l_title;
	m_windowSize = l_windowSize;
	Create();
}

void Window::Create() {
	m_window.create(sf::VideoMode(m_windowSize.x, m_windowSize.y), m_windowTitle, sf::Style::Default);
}

void Window::Draw(sf::Drawable& l_drawable) {
	m_window.clear();
	m_window.draw(l_drawable);
	m_window.display();
}

sf::Vector2u Window::GetWindowSize() {
	return m_windowSize;
}

bool Window::isClosed() {
	return m_isClosed;
}
void Window::Update() {
	sf::Event evnt;
	while (m_window.pollEvent(evnt)) {
		if (evnt.type == sf::Event::Closed) {
			m_isClosed = true;
		}
	}
}