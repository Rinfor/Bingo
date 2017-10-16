#include "Game.h"
#include <iomanip>
#include <conio.h>
#include "BingoUtils.h"

#define ESC 27

Game::Game(std::string config)
{
	mCard = new Card();
	mData = BingoUtils::LoadFromFile(config);
	mCard->CreateCard(mData);
	mDrum = new Drum(mData);
	mCredits = 0;
	mInput = '\0';
}

void Game::BeginPlay()
{
	std::cout << "Wellcome to bingo game" << std::endl <<"Press any key to begin or esc to exit"<< std::endl;
}

void Game::Input()
{
	mInput =_getch();
}

void Game::Run()
{
	uint16 ball = mDrum->PickBall();
	bool isInCard = mCard->CheckBall(ball);
	if (isInCard)
	{
		if (mCard->IsLine())
		{
			mCredits = mData.mLineCredits;
		}
		if (mCard->IsBingo())
		{
			mCredits = mData.mBingoCredits;
			mInput = ESC;
		}
	}
}

void Game::Render()
{
	std::cout << std::endl;
	BingoUtils::Log("Card");
	std::cout << std::endl;
	for (uint16 i = 0; i < mData.mRows;i++)
	{
		for (uint16 j = 0; j < mData.mColumns;j++)
		{
			std::string s;
			std::stringstream buffer;
			buffer << std::setw(2) << std::setfill('0') << mCard->GetCard()[j][i].mNumber<<" ";
			s = buffer.str();
			BingoUtils::Log(s);
			buffer.clear();			
		}
		std::cout<<std::endl;
	}
	std::cout << std::endl;

	BingoUtils::Log("Press any key to pick ball or press esc to exit");
	std::cout << std::endl;
	std::cout << std::endl;
	BingoUtils::Log("Balls Played");
	std::cout << std::endl;

	size_t OutBallSize = mDrum->GetBallsOut().size();;
	for (size_t i = 0; i < OutBallSize;i++)
	{
		std::string s;
		std::stringstream buffer;
		buffer << std::setw(2) << std::setfill('0') << mDrum->GetBallsOut()[i] << " ";
		s = buffer.str();
		BingoUtils::Log(s);
		buffer.clear();
	}
	std::cout << std::endl;
}

void Game::EndPlay()
{
	std::cout << std::endl;
	std::string s;
	std::stringstream buffer;
	buffer << "Credits: " << mCredits;
	s = buffer.str();
	BingoUtils::Log(s);
	buffer.clear();
	std::cout << std::endl;
}

bool Game::WantToEnd()
{
	if (mDrum->GetBallsOut().size() == mData.mBallsPlay)
	{
		mInput = ESC;
	}
	return mInput == ESC;
}

Game::~Game()
{
	delete mCard;
	delete mDrum;
}
