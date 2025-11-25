#pragma once
#include<string>
#include<iostream>
#include "BattleView.h"

//	ステータス
struct CharacterStatus
{
	std::string name ;
	int hp ;
	int attack ;
	int heal;
	//	必要なら属性も追加
};

/// <summary>
/// 規模感か小さいので今回はこのような形にします。
/// 本当ならタグは文字列で検索するべきでタグをレジスターに事前に登録するべきなんだろうけど
/// 今回は許してください。
/// </summary>
enum class CharacterTag
{
	none,
	player,
	enemy,
};


enum class AttackType
{
	Single,
	Whole,
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
		//
		//std::cout << m_status.name << " | 体力: " << std::to_string(m_status.hp) << std::endl;
		BattleView::Instance().StatusMSG(m_status.name,m_status.hp);
	};

	//	殴られる
	void Damage(int attack) 
	{
		if (m_isDead == true)
		{
			return;
		}
		auto hp = m_status.hp;

		//	防御力を追加したらここで計算
		auto damage = attack;
		m_status.hp -= damage;

		// //	
		//std::cout << m_status.name << "に " << damage << "の ダメージ！" << std::endl
		//	<< hp << " -> " << m_status.hp << std::endl;
		BattleView::Instance().DamageMSG(m_status.name, damage, hp, m_status.hp);

		//	死亡判定
		if (m_status.hp <= 0)
		{
			m_status.hp = 0;
			
			// 
			//std::cout << m_status.name << "はしぼうした" << std::endl;
			BattleView::Instance().DeadMSG(m_status.name);

			m_isDead = true;
		}
	}

	//	殴る
	int Attack(std::vector<Character*> a_character)
	{

		// 
		//std::cout << m_status.name << "の" << "こうげき！" << std::endl;
		BattleView::Instance().AttackMSG(m_status.name);

		for (auto& character : a_character)
		{
			character->Damage(m_status.attack);
		}

		return 0;
	}

	//	回復
	void Heal(int heal)
	{
		if (m_isDead == true)
		{
			return;
		}

		// 
		//std::cout <<  m_status.name <<"の回復:" << m_status.heal << std::endl;
		BattleView::Instance().HealMSG(m_status.name, m_status.heal);
		m_status.hp += m_status.heal;

	}

	bool IsDead()const { return m_isDead; }

	std::string GetName()const
	{
		return m_status.name;
	}

protected:

	/// <summary>
	/// キャラごとのステータスの構造体
	/// </summary>
	CharacterStatus m_status;

	/// <summary>
	/// 自分の種別
	/// </summary>
	CharacterTag m_tag;

	//	自分が何番のIDかどうか
	size_t m_id = -1;

	AttackType m_attackType = AttackType::Single;

	/// <summary>
	/// 生存フラグ
	/// </summary>
	bool m_isDead = false;
};