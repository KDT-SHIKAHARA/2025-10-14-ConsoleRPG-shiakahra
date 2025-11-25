#include "GameOver.h"
#include"Input.h"
#include"SceneManager.h"
#include"InGameScene.h"
#include "ResultView.h"

void GameOver::Update()
{
	// 
	//std::cout << "とうばつ　しっぱい！" << std::endl;
	//std::cout << "1: リスタート  2: 未定" << std::endl;
	ResultView::Instance().OverMSG();
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
