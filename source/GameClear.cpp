#include "GameClear.h"
#include<iostream>
#include"Input.h"
#include"SceneManager.h"
#include"InGameScene.h"
void GameClear::Update()
{
	std::cout << "�Ƃ��΂@�����傤�I" << std::endl;
	std::cout << "1: ���X�^�[�g  2: ����" << std::endl;
	auto input = Input::GetChar();
	switch (input)
	{
	case '1':
		SceneManager::Instance().CreateSceneRequest<InGameScene>();
		break;
	}
}

void GameClear::Render()
{
}
