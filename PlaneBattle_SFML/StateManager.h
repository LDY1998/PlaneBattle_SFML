#pragma once
#include <SFML/Window.hpp>
#include "Window.h"
#include <functional>
#include <unordered_map>
#include <algorithm>

class StateManager;

class BaseState {
	friend class StateManager;

public:
	BaseState(StateManager* l_stateManager);
	virtual ~BaseState() {};

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

enum class StateType {
	Intro = 1, MainMenu, Game, Paused, GameOver, Credits
};
struct StateContext {
	StateContext() : m_Window(nullptr){}
	Window* m_Window;
};

using StateContainer = std::vector<std::pair<StateType, BaseState*>>;
using TypeContainer = std::vector<StateType>;
using StateFactory = std::unordered_map<StateType, std::function<BaseState*(void)>>;

class StateManager {
public:
	StateManager(StateContext* l_Context);
	~StateManager();

	void Update(const sf::Time& l_time);
	void Draw();

	void ProcessRequest();

	StateContext* GetContext() const;
	bool HasState(const StateType& l_type);
	void SwitchTo(const StateType& l_type);
	void Remove(const StateType& l_type);

private:
	void CreateState(const StateType& l_type);
	void RemoveState(const StateType& l_type);

	template<class T>
	void RegisterState(const StateType& l_type);

	StateContext* m_Context;
	StateContainer m_State;
	TypeContainer m_ToRemove;
	StateFactory m_Factory;
};