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

	//	ID検索
	PoolHandle<Character>& GetHandleForId(size_t id);

	//	タグ検索
	std::vector<size_t> GetIndexsForTag(CharacterTag tag);

	//	ハンドルの生成
	//	構造体のデータ番号からステータス等を初期化メソッドでセットしてコレクションに追加する	
	size_t CreateEntity(size_t statusID,CharacterTag tag);

	//	タグ検索から有効フラグの立っているオブジェクトだけとってくる
	std::vector<Character*> GetEnableObjectForTag(CharacterTag tag);


	//	全体の描画
	//	省略してここに書くね
	void Render();


private:
	ObjectPool<Character> m_characters;

	/// <summary>
	/// アクティブなキャラクターのハンドル
	/// </summary>
	std::unordered_map<size_t, PoolHandle<Character>> m_handles;

	/// <summary>
	/// タグごとのIDコレクション
	/// </summary>
	std::unordered_map<CharacterTag, std::unordered_set<size_t>> m_tagIndexs;

	//	次のID
	size_t nextID = 0;

	/// <summary>
	/// defaultのステータス
	/// </summary>
	std::unordered_map<size_t, CharacterStatus> m_defaultStatus;

};