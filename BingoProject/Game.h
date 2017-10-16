#ifndef _GAME_H_
#define _GAME_H_

#include <string>
#include "Card.h"
#include "Drum.h"

class Game
{
public:
	Game(std::string config);

	void BeginPlay();
	void Input();
	void Run();
	void Render();
	void EndPlay();
	bool WantToEnd();

	~Game();
private:
	Card* mCard;
	Drum* mDrum;
	TData mData;
	uint16 mCredits;

	char mInput;
};

#endif // !_GAME_H_
