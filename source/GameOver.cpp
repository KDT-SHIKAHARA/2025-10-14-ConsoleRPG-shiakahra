#include "GameOver.h"
#include"Input.h"
#include"SceneManager.h"
#include"InGameScene.h"

void GameOver::Update()
{
	std::cout << "1: ���X�^�[�g  2: ����" << std::endl;
	auto input = Input::GetChar();
	switch (input)
	{
	case '1':
		SceneManager::Instance().CreateSceneRequest<InGameScene>();
		break;
	}
}

void GameOver::Render()
{
}
