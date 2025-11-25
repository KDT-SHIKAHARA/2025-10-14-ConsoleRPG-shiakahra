#include "GameClear.h"
#include<iostream>
#include"Input.h"
#include"SceneManager.h"
#include"InGameScene.h"
#include "ResultView.h"

void GameClear::Update()
{
	// 
	//std::cout << "とうばつ　かんりょう！" << std::endl;
	//std::cout << "1: リスタート  2: 未定" << std::endl;

	ResultView::Instance().ClearMSG();

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
