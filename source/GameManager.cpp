#include "GameManager.h"
#include "SceneManager.h"

#include"InGameScene.h"

GameManager::GameManager() = default;

GameManager::~GameManager()
{
}

void GameManager::Initialize()
{
	//	初期化項目があれば
	
	//	ロード系等

	SceneManager::Instance().Initialize();

}

void GameManager::Loop()
{

	auto& SceneManager = SceneManager::Instance();

	while (m_running)
	{
		//	入力
		//	状態、描画更新
		SceneManager.Render();
		SceneManager.Update();

		//	画面切り替え
		SceneManager.CreateNextScene();

		//	クリア
		//system("cls");
	}
}

void GameManager::Exit()
{
	//	解放系、セーブ系
}
