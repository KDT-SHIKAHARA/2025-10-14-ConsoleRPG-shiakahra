#include "SceneManager.h"
#include "Debug.h"
#include "InGameScene.h"

void SceneManager::Initialize()
{
	//	何かあれば

	//	デバック
	m_currentScene = std::make_unique<InGameScene>();
	m_currentScene->Initialize();
}

void SceneManager::Update()
{
	if (m_currentScene == nullptr)
	{
		AssertExcept("スクリーンのポインタが空です");
	}

	m_currentScene->Update();

}

void SceneManager::Render()
{
	m_currentScene->Render();
}

void SceneManager::CreateNextScene()
{
	if (m_nextScene != nullptr)
	{
		m_currentScene = std::move(m_nextScene);
	}
}
