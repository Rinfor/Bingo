#include "Drum.h"
#include "BingoUtils.h"

Drum::Drum(const TData data)
{
	mData = data;
	for (uint16 i = 1; i <= mData.mBallsBag; i++)
	{
		mBallsIn.push_back(i);
	}
}

uint16 Drum::PickBall()
{
	uint16 ret = 0;
	if (!mBallsIn.empty()) {
		size_t size = mBallsIn.size();
		if (size > 0)
		{
			int index = (BingoUtils::Rand() - 1) % size;
			ret = mBallsIn[index];
			mBallsIn.erase(std::find(mBallsIn.begin(), mBallsIn.end(), ret));
		}
		else
		{
			ret = mBallsIn[0];
			mBallsIn.clear();
		}
		mBallsOut.push_back(ret);
	}
	return ret;
}

bool Drum::IsDrumEmty() const
{
	return mBallsIn.empty();
}

std::vector<uint16> Drum::GetBallsOut() const
{
	return mBallsOut;
}
