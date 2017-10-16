#ifndef _BINGO_UTILS_H_
#define _BINGO_UTILS_H_

#include <string>
#include "Data.h"
#include <fstream>
#include <sstream>
#include <string>
#include <random>
#include "rapidjson/document.h"
#include <limits>
#include <iostream>


using namespace rapidjson;

#define DEFAULT_ROWS 3
#define DEFAULT_COL 5
#define DEFAULT_BAGBALLS 60
#define DEFAULT_BAGPLAY 30
#define DEFAULT_LINE_CREDTIS 10
#define DEFAULT_BINGO_CREDITS 1500

namespace BingoUtils
{
	static TData LoadFromFile(std::string fileName)
	{
		TData data;
		Document document;

		std::ifstream inFile;
		inFile.open(fileName);

		std::stringstream strStream;
		strStream << inFile.rdbuf();
		std::string str = strStream.str();

		document.Parse<0>(str.c_str());
		bool isRead = true;
		if (!document.HasParseError())
		{
			if (document.HasMember("Rows"))
			{
				data.mRows = static_cast<uint16>(document["Rows"].GetInt());
			}
			else
			{
				isRead = false;
			}
			if (document.HasMember("Columns"))
			{
				data.mColumns = static_cast<uint16>(document["Columns"].GetInt());
			}
			else
			{
				isRead = false;
			}
			if (document.HasMember("BallsBag"))
			{
				data.mBallsBag = static_cast<uint16>(document["BallsBag"].GetInt());
			}
			else
			{
				isRead = false;
			}
			if (document.HasMember("BallsPlay"))
			{
				data.mBallsPlay = static_cast<uint16>(document["BallsPlay"].GetInt());
			}
			else
			{
				isRead = false;
			}
			if (document.HasMember("LineCredits"))
			{
				data.mLineCredits = static_cast<uint16>(document["LineCredits"].GetInt());
			}
			else
			{
				isRead = false;
			}
			if (document.HasMember("BingoCredits"))
			{
				data.mBingoCredits = static_cast<uint16>(document["BingoCredits"].GetInt());
			}
			else
			{
				isRead = false;
			}
		}
		else
		{
			isRead = false;
		}
		if (!isRead)
		{
			data.mBallsBag = DEFAULT_BAGBALLS;
			data.mBallsPlay = DEFAULT_BAGPLAY;
			data.mColumns = DEFAULT_COL;
			data.mRows = DEFAULT_ROWS;
			data.mLineCredits = DEFAULT_LINE_CREDTIS;
			data.mBingoCredits = DEFAULT_BINGO_CREDITS;
		}
		return data;
	}

	static uint16 Rand()
	{
		uint16 random = 1 + (std::rand() % std::numeric_limits<uint16>::max() - 1);
		return random;
	}

	static void Log(std::string log)
	{
		std::cout << log;
	}
}
#endif // !_BINGO_UTILS_H_
