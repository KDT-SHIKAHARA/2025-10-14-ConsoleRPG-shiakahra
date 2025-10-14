#pragma once
#include<string>
#include<iostream>


//	�X�e�[�^�X
struct CharacterStatus
{
	std::string name ;
	int hp ;
	int attack ;
	//	�K�v�Ȃ瑮�����ǉ�
};

/// <summary>
/// �K�͊����������̂ō���͂��̂悤�Ȍ`�ɂ��܂��B
/// �{���Ȃ�^�O�͕�����Ō�������ׂ��Ń^�O�����W�X�^�[�Ɏ��O�ɓo�^����ׂ��Ȃ񂾂낤����
/// ����͋����Ă��������B
/// </summary>
enum class CharacterTag
{
	none,
	player,
	enemy,
};

class Character
{
public:		
	virtual ~Character() = default;
	virtual void Initialize(size_t id, CharacterStatus status,CharacterTag tag = CharacterTag::none)
	{
		m_isDead = false;
		m_id = id;
		m_tag = tag;
		m_status = status;
	};
	virtual void Draw() 
	{
		std::cout << m_status.name << " | �̗�: " << std::to_string(m_status.hp) << std::endl;
	};

	//	������
	void Damage(int attack) 
	{
		if (m_isDead == true)
		{
			return;
		}

		//	�h��͂�ǉ������炱���Ōv�Z
		auto damage = attack;
		m_status.hp -= damage;

		//	���S����
		if (m_status.hp <= 0)
		{
			m_isDead = false;
		}
	}

	//	����
	int Attack()const
	{
		if (m_status.attack > 0)
		{
			std::cout << m_status.name << "��" << "���������I" << std::endl;
			return m_status.attack;
		}

		return 0;
	}

	//	��
	void Heal(int heal)
	{
		if (m_isDead == true)
		{
			return;
		}

		m_status.hp += heal;

	}

	bool IsDead()const { return m_isDead; }

protected:
	/// <summary>
	/// �L�������Ƃ̃X�e�[�^�X�̍\����
	/// </summary>
	CharacterStatus m_status;

	/// <summary>
	/// �����̎��
	/// </summary>
	CharacterTag m_tag;

	//	���������Ԃ�ID���ǂ���
	size_t m_id = -1;

	/// <summary>
	/// �����t���O
	/// </summary>
	bool m_isDead = false;
};