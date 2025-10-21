#pragma once
#include"CharacterManager.h"

class BattleManager
{
public:
	BattleManager(CharacterManager* a_characters);

	void Start();

private:
	CharacterManager* m_characters;
};