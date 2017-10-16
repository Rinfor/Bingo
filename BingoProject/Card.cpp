#include "Card.h"
#include "BingoUtils.h"
#include <algorithm>

void Card::CreateCard(const TData data)
{
	uint16 squaresNumber = data.mColumns * data.mRows;
	mRows = data.mRows;
	mColumns = data.mColumns;
	std::vector<uint16> numbers;
	uint16 index = 0;
	while(index < squaresNumber)
	{
		uint16 ball = BingoUtils::Rand() % data.mBallsBag + 1;
		if (numbers.empty())
		{
			numbers.push_back(ball);
			index++;
		}
		else if (!(std::find(numbers.begin(), numbers.end(), ball) != numbers.end()))
		{
			numbers.push_back(ball);
			index++;
		}
	}
	std::sort(numbers.begin(), numbers.end());
	for (uint16 i = 0; i < mColumns; i++)
	{
		std::vector<Card::TSquare> aux;
		for (uint16 j = 0; j < mRows; j++)
		{
			aux.push_back(TSquare(numbers.front()));
			numbers.erase(numbers.begin());
		}
		mCard.push_back(aux);
	}
}

std::vector<std::vector<Card::TSquare>> Card::GetCard() const
{
	return mCard;
}

uint16 Card::GetRows() const
{
	return mRows;
}

uint16 Card::GetColumns() const
{
	return mColumns;
}

bool Card::IsLine() const
{
	uint16 i = 0;
	uint16 j = 0;
	bool notLine = false;
	bool isLine = false;
	while (!isLine && i < mRows)
	{
		j = 0;
		notLine = false;
		while (!isLine && !notLine && j < mColumns)
		{
			if (!mCard[j][i].mIsChecked)
			{
				notLine = true;
			}
			else
			{
				j++;
				if (j == mColumns)
				{
					isLine = true;
				}
			}
		}
		i++;
	}
	return isLine;
}

bool Card::IsBingo() const
{
	uint16 i = 0;
	uint16 j = 0;
	bool notBingo = false;
	while (!notBingo && i < mRows)
	{
		j = 0;
		while (!notBingo && j < mColumns)
		{
			if (mCard[j][i].mIsChecked == false)
			{
				notBingo = true;
			}
			else
			{
				j++;
			}
		}
		i++;
	}
	return !notBingo;
}

bool Card::CheckBall(uint16 ball) const
{
	bool isChecked = false;
	uint16 i = 0;
	uint16 j = 0;
	while (!isChecked && i < mColumns)
	{
		j = 0;
		while (!isChecked && j < mRows)
		{
			if (mCard[i][j].mNumber == ball)
			{
				TSquare & info = const_cast<TSquare&>(mCard[i][j]);
				info.mIsChecked = true;
				isChecked = true;
			}
			else
			{
				j++;
			}
		}
		i++;
	}
	return isChecked;
}
