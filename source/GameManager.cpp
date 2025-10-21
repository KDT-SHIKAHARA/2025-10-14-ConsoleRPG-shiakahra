#include "GameManager.h"
#include "SceneManager.h"

#include"InGameScene.h"

GameManager::GameManager() = default;

GameManager::~GameManager()
{
}

void GameManager::Initialize()
{
	//	���������ڂ������
	
	//	���[�h�n��

	SceneManager::Instance().Initialize();

}

void GameManager::Loop()
{

	auto& SceneManager = SceneManager::Instance();

	while (m_running)
	{
		//	����
		//	��ԁA�`��X�V
		SceneManager.Render();
		SceneManager.Update();

		//	��ʐ؂�ւ�
		SceneManager.CreateNextScene();

		//	�N���A
		//system("cls");
	}
}

void GameManager::Exit()
{
	//	����n�A�Z�[�u�n
}
