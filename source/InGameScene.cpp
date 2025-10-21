#include "InGameScene.h"
#include "Input.h"
#include "GameOver.h"
#include"SceneManager.h"

#include<iostream>

InGameScene::InGameScene()
	:m_battle(&m_characters)
{
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
}

void InGameScene::Render()
{

#if _DEBUG
	//std::cout << "InGame" << std::endl;
#endif // _DEBUG
	m_characters.Render();
}
