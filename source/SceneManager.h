#pragma once
#include"base_Scene.h"
#include"Singleton.h"
#include"Debug.h"

#include<memory>
#include<type_traits>

/// <summary>
/// 画面ごとの状態、描画更新クラスの管理。
/// トランジションなど後から追加できるように。（今回は多分しないけど拡張性的に一応ね？）
/// </summary>
class SceneManager : public Singleton<SceneManager>
{
	friend class Singleton<SceneManager>;
	SceneManager() = default;
	virtual ~SceneManager() = default;

public:
	void Initialize();
	void Update();
	void Render();
	void CreateNextScene();

	/// <summary>
	/// 次のスクリーンの生成申請
	/// </summary>
	/// <typeparam name="T"></typeparam>
	template<typename T>
	void CreateSceneRequest();

private:
	//	今のスクリーンのポインタ
	std::unique_ptr<Scene> m_currentScene;

	//	切り替えたいインスタンス
	std::unique_ptr<Scene> m_nextScene;
};

template<typename T>
inline void SceneManager::CreateSceneRequest()
{
	if (std::is_base_of<Scene, T>::value == false)
	{
		AssertExcept("Sceneを継承していないクラスが生成されようとしました");
	}

	//	次のスクリーンのインスタンス生成
	m_nextScene = std::make_unique<T>();

}
