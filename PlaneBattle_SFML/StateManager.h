#pragma once
#include <SFML/Window.hpp>

class StateManager;

class BaseState {
	friend class StateManager;

public:
	BaseState(StateManager* l_stateManager);
	virtual ~BaseState();

	virtual void onCreate() = 0;
	virtual void onDestroy() = 0;

	virtual void Activate() = 0;
	virtual void Deactivate() = 0;

	virtual void Draw() = 0;
	virtual void Update(const sf::Time& l_time) = 0;
	
	void SetTransparent(const bool& l_transparent);
	bool isTransparent () const;

	void SetTranscendent(const bool& l_transcendent);
	bool isTranscendent() const;

protected:
	StateManager* m_StateManager;
	bool m_Transparent;
	bool m_Transcendent;
};