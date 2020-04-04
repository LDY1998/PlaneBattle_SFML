#include "StateManager.h"

BaseState::BaseState(StateManager* l_StateManager):
	m_StateManager(l_StateManager)
{}

bool BaseState::isTranscendent() const{
	return m_Transcendent;
}

bool BaseState::isTransparent() const{
	return m_Transparent;
}

void BaseState::SetTranscendent(const bool& l_Transcendent) {
	m_Transcendent = l_Transcendent;
}

void BaseState::SetTransparent(const bool& l_Transparent) {
	m_Transparent = l_Transparent;
}

template<class T>
void StateManager::RegisterState(const StateType& l_type) {
	m_Factory[l_type] = [this]() -> BaseState* {
		return new T(this);
	};
}
StateManager::StateManager(StateContext* l_Context) :
	m_Context(l_Context)
{
	/*RegisterState<StateType_Intro>(StateType::Intro);
	RegisterState<StateType_Game>(StateType::Game);
	RegisterState<StateType_Paused>(StateType::Paused);
	RegisterState<StateType_GameOver>(StateType::GameOver);
	RegisterState<StateType_Credits>(StateType::Credits);*/

}
StateManager::~StateManager()
{
	for (auto iter = m_State.begin(); iter != m_State.end(); iter++) {
		iter->second->onDestroy();
		delete iter->second;
	}
}

void StateManager::CreateState(const StateType& l_type) {
	auto newState = m_Factory.find(l_type);
	if (newState == m_Factory.end()) {
		return;
	}
	BaseState* state = newState->second();
	state->onCreate();
	m_State.push_back({ l_type, state });
}

void StateManager::RemoveState(const StateType& l_type) {
	for (auto iter = m_State.begin(); iter != m_State.end(); iter++) {
		if (iter->first == l_type) {
			iter->second->onDestroy();
			delete iter->second;
			m_State.erase(iter);
			return;
		}
	}
}

void StateManager::Draw() {
	if (m_State.empty()) {
		return;
	}
	if (m_State.back().second -> isTransparent() && m_State.size() > 1)
	{
		auto iter = m_State.end();
		while (iter != m_State.begin())
		{
			if (iter != m_State.end()) {
				if (!iter->second->isTransparent()) {
					break;
				}
			}
		}
		for (; iter != m_State.end(); iter++) {
			iter->second->Draw();
		}
	}
	else {
		m_State.back().second->Draw();
	}
}
StateContext * StateManager::GetContext() const
{
	return m_Context;
}

bool StateManager::HasState(const StateType& l_type)
{
	for (auto iter = m_State.begin(); iter != m_State.end(); iter++) {
		if (iter->first == l_type) {
			auto remove = std::find(m_ToRemove.begin(), m_ToRemove.end(), l_type);
			if (remove == m_ToRemove.end()) {
				return true;
			}
			return false;
		}
	}
	return false;
}

void StateManager::Remove(const StateType& l_type) {
	m_ToRemove.push_back(l_type);
}

void StateManager::ProcessRequest() {
	while (m_ToRemove.begin() != m_ToRemove.end())
	{
		RemoveState(*m_ToRemove.begin());
		m_ToRemove.erase(m_ToRemove.begin());
	}
}

void StateManager::SwitchTo(const StateType& l_type) {
	for (auto iter = m_State.begin(); iter != m_State.end(); iter++) {
		if (iter->first == l_type) {
			m_State.back().second->Deactivate();
			StateType tempType = iter->first;
			BaseState* tempState = iter->second;
			m_State.erase(iter);
			m_State.emplace_back(tempType, tempState);
			tempState->Activate();
			return;
		}
	}
	if (!m_State.empty()) {
		m_State.back().second->Deactivate();
	}
	CreateState(l_type);
	m_State.back().second->Activate();
}
void StateManager::Update(const sf::Time& l_Time) {
	if (m_State.empty()) {
		return;
	}
	if (m_State.back().second->isTranscendent() && m_State.size() > 1)
	{
		auto iter = m_State.end();
		while (iter != m_State.begin())
		{
			if (iter != m_State.end()) {
				if (!iter->second->isTranscendent()) {
					break;
				}
			}
		}
		for (; iter != m_State.end(); iter++) {
			iter->second->Update(l_Time);
		}
	}
	else {
		m_State.back().second->Update(l_Time);
	}
}

