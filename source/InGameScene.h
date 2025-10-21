#pragma once
#include"base_Scene.h"
#include"CharacterManager.h"
#include "BattleManager.h"

class InGameScene : public Scene
{
public:
	InGameScene();
	void Initialize()override;
	void Update()override;
	void Render()override;

private:
	CharacterManager m_characters;
	BattleManager m_battle;
	bool m_battlefinish = false;
};