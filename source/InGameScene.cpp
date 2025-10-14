#include "InGameScene.h"
#include<iostream>

InGameScene::InGameScene()
{
}

void InGameScene::Initialize()
{
}

void InGameScene::Update()
{
	//	先頭のフローは省略してここに書きます。
	//	本来は別で分けるべきかもね....

	//	全体リストの取得


}

void InGameScene::Render()
{
#if _DEBUG
	std::cout << "InGame" << std::endl;
#endif // _DEBUG

}
