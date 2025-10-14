#include"GameManager.h"

int main() 
{
	GameManager& game = GameManager::Instance();
	game.Initialize();
	game.Loop();
	game.Exit();
	return 0;
}