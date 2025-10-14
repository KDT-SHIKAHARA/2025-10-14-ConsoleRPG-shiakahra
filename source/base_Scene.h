#pragma once
#include"ObjectPool.h"
#include"base_Character.h"

class Scene
{
public:
	Scene() = default;
	virtual ~Scene() = default;
	virtual void Initialize() = 0;
	virtual void Update() = 0;
	virtual void Render() = 0;

	//	åüçıã@î\

protected:
};