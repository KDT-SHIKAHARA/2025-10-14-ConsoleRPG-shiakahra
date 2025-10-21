#include "InGameScene.h"
#include "Input.h"
#include "GameOver.h"
#include"SceneManager.h"
#include"GameClear.h"

#include<iostream>

InGameScene::InGameScene()
	:m_battle(&m_characters)
{

	std::cout << "InGame‰Šú‰»" << std::endl;
	m_characters.CreateEntity(1, CharacterTag::player);
	m_characters.CreateEntity(2, CharacterTag::player);
	m_characters.CreateEntity(3, CharacterTag::enemy);
}

void InGameScene::Initialize()
{

}

void InGameScene::Update()
{

	m_battle.Start();

	auto alivePlayers = m_characters.GetEnableObjectForTag(CharacterTag::player);
	auto aliveEnenys = m_characters.GetEnableObjectForTag(CharacterTag::enemy);
	if (alivePlayers.empty() == true)
	{
		SceneManager::Instance().CreateSceneRequest<GameOver>();
	}
	else if (aliveEnenys.empty() == true)
	{
		SceneManager::Instance().CreateSceneRequest<GameClear>();
	}

}

void InGameScene::Render()
{
	std::cout << "============================================================" << std::endl;

#if _DEBUG
	//std::cout << "InGame" << std::endl;
#endif // _DEBUG
	m_characters.Render();
}
