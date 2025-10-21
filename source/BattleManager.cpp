#include "BattleManager.h"

#include<iostream>
#include "Input.h"

BattleManager::BattleManager(CharacterManager* a_characters)
	:m_characters(a_characters)
{
}

void BattleManager::Start()
{
	std::cout << std::endl;
	std::cout << "‚ ‚È‚½‚Ìƒ^[ƒ“" << std::endl;
	std::cout << "1: UŒ‚   2: ‰ñ•œ" << std::endl;
	auto players = m_characters->GetEnableObjectForTag(CharacterTag::player);
	auto enemys = m_characters->GetEnableObjectForTag(CharacterTag::enemy);

	for (auto player : players)
	{
		if (player == nullptr)
		{
			continue;
		}

		std::cout << player->GetName() << std::endl;
		auto input = Input::GetChar();

		switch (input)
		{
		case '1':
			player->Attack(enemys);
			break;
		case '2':
			player->Heal(10);
			break;
		}

		std::cout << std::endl;

	}

	for (auto enemy : enemys)
	{
		enemy->Attack(players);
	}
	std::cout << std::endl;


}
