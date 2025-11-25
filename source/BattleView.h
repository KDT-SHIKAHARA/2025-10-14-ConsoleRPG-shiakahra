#pragma once
#include "Singleton.h"
#include <iostream>
#include <string>

class BattleView : public Singleton<BattleView>
{

	friend class Singleton<BattleView>;
	BattleView() = default;
	virtual ~BattleView() = default;

public:

	//　プレイヤーターン案内
	void ActionMSG() {
		std::cout << std::endl;
		std::cout << "あなたのターン" << std::endl;
		std::cout << "1: 攻撃   2: 回復" << std::endl;
	}

	// キャラクターステータス表示
	void StatusMSG(std::string arg_name, int arg_hp ) {
		std::cout << arg_name  << " | 体力: " << std::to_string(arg_hp) << std::endl;
	}

	// アクションメッセ
	void AttackMSG(std::string arg_name) {
		std::cout << arg_name << "の" << "こうげき！" << std::endl;

	}

	// ダメージ表示(名前、ダメージ量、残りHP)
	void DamageMSG(std::string arg_name, int arg_damage, int arg_pastHp, int arg_nowHp) {
		std::cout << arg_name<< "に " << arg_damage << "の ダメージ！" << std::endl
			<< arg_pastHp << " -> " << arg_nowHp << std::endl;
	}

	// ヒール
	void HealMSG(std::string arg_name,int arg_heal) {
		std::cout << arg_name << "の回復:" << arg_heal << std::endl;
	}


	// 死亡メッセ
	void DeadMSG(std::string arg_name) {
		std::cout << arg_name << "はしぼうした" << std::endl;
	}



};