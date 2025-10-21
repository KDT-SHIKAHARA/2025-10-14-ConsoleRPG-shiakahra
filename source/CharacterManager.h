#pragma once
#include"ObjectPool.h"
#include"base_Character.h"

#include<unordered_map>
#include<unordered_set>
#include<vector>

class CharacterManager
{
public:
	CharacterManager(size_t pool_capacity = 10, bool pool_allowDynamic = true);
	virtual ~CharacterManager() = default;

	//	ID����
	PoolHandle<Character>& GetHandleForId(size_t id);

	//	�^�O����
	std::vector<size_t> GetIndexsForTag(CharacterTag tag);

	//	�n���h���̐���
	//	�\���̂̃f�[�^�ԍ�����X�e�[�^�X�������������\�b�h�ŃZ�b�g���ăR���N�V�����ɒǉ�����	
	size_t CreateEntity(size_t statusID,CharacterTag tag);

	//	�^�O��������L���t���O�̗����Ă���I�u�W�F�N�g�����Ƃ��Ă���
	std::vector<Character*> GetEnableObjectForTag(CharacterTag tag);


	//	�S�̂̕`��
	//	�ȗ����Ă����ɏ�����
	void Render();


private:
	ObjectPool<Character> m_characters;

	/// <summary>
	/// �A�N�e�B�u�ȃL�����N�^�[�̃n���h��
	/// </summary>
	std::unordered_map<size_t, PoolHandle<Character>> m_handles;

	/// <summary>
	/// �^�O���Ƃ�ID�R���N�V����
	/// </summary>
	std::unordered_map<CharacterTag, std::unordered_set<size_t>> m_tagIndexs;

	//	����ID
	size_t nextID = 0;

	/// <summary>
	/// default�̃X�e�[�^�X
	/// </summary>
	std::unordered_map<size_t, CharacterStatus> m_defaultStatus;

};