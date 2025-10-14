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
	//	�擪�̃t���[�͏ȗ����Ă����ɏ����܂��B
	//	�{���͕ʂŕ�����ׂ�������....

	//	�S�̃��X�g�̎擾

	//	�v���C���[�̔�
	auto p_index = m_characters.GetIndexsForTag(CharacterTag::player);
	
	std::cout << "�v���C���[�̃^�[��" << std::endl;
	
	for (auto index : p_index)
	{
		//	���͂܂�
		auto& p = m_characters.GetHandleForId(index);
		auto input = Input::GetChar();

		int a = 0;
		switch (input)
		{
		case '1':
			//	�����Ă���G��ID����G���w�肵�ĉ���

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
