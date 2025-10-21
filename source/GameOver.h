#pragma once
#include"base_Scene.h"

#include<iostream>

class GameOver : public Scene
{
public:
	void Initialize()override{}
	void Update()override;
	void Render()override;
private:

};