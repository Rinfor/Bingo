#ifndef _DRUM_H_
#define _DRUM_H_

#include "Data.h"
#include <vector>

class Drum
{
public:
	Drum(const TData data);
	uint16 PickBall();
	bool IsDrumEmty() const;
	std::vector<uint16> GetBallsOut() const;

private:
	TData mData;
	std::vector<uint16> mBallsIn;
	std::vector<uint16> mBallsOut;
};
#endif // !_DRUM_H_
