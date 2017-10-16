#ifndef _CARD_H_
#define _CARD_H_

#include "Types.h"
#include "Data.h"
#include <vector>

class Card
{
public:
	struct TSquare
	{
		TSquare(uint16 number) :mNumber(number), mIsChecked(false) {}
		uint16 mNumber;
		bool mIsChecked;
	};
	void CreateCard(const TData data);
	std::vector<std::vector<TSquare>> GetCard() const;
	uint16 GetRows() const;
	uint16 GetColumns() const;
	bool IsLine() const;
	bool IsBingo() const;
	bool CheckBall(uint16) const;

private:
	uint16 mRows;
	uint16 mColumns;
	std::vector<std::vector<TSquare>> mCard;
	bool mIsLine;
	bool mIsBingo;
};

#endif // !_CARD_H_
