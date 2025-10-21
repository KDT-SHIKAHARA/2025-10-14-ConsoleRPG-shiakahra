#pragma once
#include"base_Scene.h"
#include"Singleton.h"
#include"Debug.h"

#include<memory>
#include<type_traits>

/// <summary>
/// ��ʂ��Ƃ̏�ԁA�`��X�V�N���X�̊Ǘ��B
/// �g�����W�V�����Ȃǌォ��ǉ��ł���悤�ɁB�i����͑������Ȃ����Ǌg�����I�Ɉꉞ�ˁH�j
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
	/// ���̃X�N���[���̐����\��
	/// </summary>
	/// <typeparam name="T"></typeparam>
	template<typename T>
	void CreateSceneRequest();

private:
	//	���̃X�N���[���̃|�C���^
	std::unique_ptr<Scene> m_currentScene;

	//	�؂�ւ������C���X�^���X
	std::unique_ptr<Scene> m_nextScene;
};

template<typename T>
inline void SceneManager::CreateSceneRequest()
{
	if (std::is_base_of<Scene, T>::value == false)
	{
		AssertExcept("Scene���p�����Ă��Ȃ��N���X����������悤�Ƃ��܂���");
	}

	//	���̃X�N���[���̃C���X�^���X����
	m_nextScene = std::make_unique<T>();

}
