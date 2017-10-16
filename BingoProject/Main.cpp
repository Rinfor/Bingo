#include <ctime>
#include "Game.h"
#include "BingoUtils.h"

void main()
{
	std::srand(static_cast<int>(std::time(0)));
	Game* game = new Game("Config.json");
	game->BeginPlay();
	while (!game->WantToEnd())
	{
		game->Input();
		if (!game->WantToEnd())
		{
			game->Run();
			game->Render();
		}
	}
	BingoUtils::Log("Prueba");
	BingoUtils::Log("Prueba del branch");

	game->EndPlay();
	delete game;
	getchar();
}