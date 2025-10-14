#include "InGameScene.h"
#include "Input.h"

#include<iostream>

InGameScene::InGameScene()
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
	//	先頭のフローは省略してここに書きます。
	//	本来は別で分けるべきかもね....

	//	全体リストの取得

	//	プレイヤーの晩
	auto p_index = m_characters.GetIndexsForTag(CharacterTag::player);
	
	std::cout << "プレイヤーのターン" << std::endl;
	
	for (auto index : p_index)
	{
		//	入力まち
		auto& p = m_characters.GetHandleForId(index);
		auto input = Input::GetChar();

		int a = 0;
		switch (input)
		{
		case '1':
			//	生きている敵のIDから敵を指定して殴る

			break;
		case '2':
			p->Heal(2);
			break;
		default:
			break;
		}
	}

}

void InGameScene::Render()
{
#if _DEBUG
	std::cout << "InGame" << std::endl;
#endif // _DEBUG
	m_characters.Render();
}
