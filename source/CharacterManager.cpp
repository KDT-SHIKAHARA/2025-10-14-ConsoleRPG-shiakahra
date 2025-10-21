#include "CharacterManager.h"
#include "Debug.h"

CharacterManager::CharacterManager(size_t pool_capacity, bool pool_allowDynamic)
	:m_characters(pool_capacity, pool_allowDynamic)
{
	m_defaultStatus.emplace(-1, CharacterStatus{});
	m_defaultStatus.emplace(1, CharacterStatus{ "ゆうしゃ",100,50,50 });
	m_defaultStatus.emplace(2, CharacterStatus{ "どれい",200,20,100 });
	m_defaultStatus.emplace(3, CharacterStatus{ "ドラゴン",500,40 });

}

PoolHandle<Character>& CharacterManager::GetHandleForId(size_t id)
{
	auto it = m_handles.find(id);
	if (it == m_handles.end())
	{
		//	
		AssertExcept("存在しないID");
	}
	return it->second;

}

std::vector<size_t> CharacterManager::GetIndexsForTag(CharacterTag tag)
{
	auto it = m_tagIndexs.find(tag);
	if (it == m_tagIndexs.end())
	{
		return std::vector<size_t>();
	}

	std::vector<size_t> result;

	//	
	for (auto& index : it->second)
	{
		result.push_back(index);
	}

	return result;
}



size_t CharacterManager::CreateEntity(size_t statusID, CharacterTag tag)
{
	std::cout << m_defaultStatus.size() << std::endl;
	auto it = m_defaultStatus.find(statusID);
	if (it != m_defaultStatus.end())
	{
		auto handle = m_characters.Acquire();
		handle->Initialize(nextID, it->second, tag);

		//	コレクションに追加
		m_handles.insert({ nextID, std::move(handle) });
		m_tagIndexs[tag].insert(nextID);

		nextID++;
	}



	return size_t();
}

std::vector<Character*> CharacterManager::GetEnableObjectForTag(CharacterTag tag)
{
	auto indexs = m_tagIndexs.find(tag);
	if (indexs == m_tagIndexs.end())
	{
		return std::vector<Character*>();
	}


	std::vector<Character*> result;

	for (auto& index : indexs->second)
	{
		auto it = m_handles.find(index);
		if (it != m_handles.end())
		{
			if (it->second->IsDead() == false)
			{
				result.push_back(it->second.GetObj());
			}
		}
	}

	return result;



}

void CharacterManager::Render()
{
	//	プレイヤー
	auto p_indexs = GetIndexsForTag(CharacterTag::player);
	for (auto index : p_indexs)
	{
		auto& p = GetHandleForId(index);
		p->Draw();
	}

	//	敵
	auto e_indexs = GetIndexsForTag(CharacterTag::enemy);
	for (auto index : e_indexs)
	{
		auto& e = GetHandleForId(index);
		e->Draw();
	}


}
