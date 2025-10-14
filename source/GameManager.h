#pragma once
#include"Singleton.h"

class GameManager : public Singleton<GameManager>
{
	friend class Singleton<GameManager>;
	GameManager();
	virtual ~GameManager();
public:
	void Initialize();
	void Loop();
	void Exit();

private:
	bool m_running = true;
};