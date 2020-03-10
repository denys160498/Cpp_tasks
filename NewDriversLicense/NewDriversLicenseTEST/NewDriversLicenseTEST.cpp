#include "pch.h"
#include "CppUnitTest.h"
#include <string>
#include <algorithm>
#include <vector>
#include "../NewDriversLicense/main.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace NewDriversLicenseTEST
{
	TEST_CLASS(NewDriversLicenseTEST)
	{
	public:

		TEST_METHOD(ParsingNames)
		{
			const int arrSize = 4;
			std::string names = "Jane Max Olivia Sam";
			std::string actualNames[arrSize];
			std::string expectingNames[] = { "Jane", "Max", "Olivia", "Sam" };

			parseNames(names, actualNames, arrSize);

			for (int i = 0; i < arrSize; i++)
			{
				Assert::AreEqual(expectingNames[i], actualNames[i]);
			}
		}

		TEST_METHOD(SortingArray)
		{
			const int arrSize = 7;
			std::string actualArray[] = { "Sunday", "Monday", "Sundai", "Wednesday", "Thirsday", "Friday", "Saturday" };
			std::vector<std::string> expectingArray = { "Sunday", "Monday", "Sundai", "Wednesday", "Thirsday", "Friday", "Saturday" };

			sort(expectingArray.begin(), expectingArray.end());
			sortArr(actualArray, arrSize);

			for (int i = 0; i < arrSize; i++)
			{
				Assert::AreEqual(expectingArray[i], actualArray[i]);
			}
		}

		TEST_METHOD(SwappingString)
		{
			std::string str1 = "Hi";
			std::string str2 = "Bye";
			std::string expectedStr1 = "Bye";
			std::string expectedStr2 = "Hi";

			swapStr(&str1, &str2);

			Assert::AreEqual(str1, expectedStr1);
			Assert::AreEqual(str2, expectedStr2);
		}

		TEST_METHOD(GettingIndex)
		{
			const int arrSize = 6;
			std::string name = "Hipogriff";
			std::string namesArr[] = { "Hipogriff", "Border", "Aaron", "Max", "Olivia", "Sam" };

			Assert::AreEqual(0, getMyIndex(name, namesArr, arrSize));
		}

		TEST_METHOD(GettingWaitingTime)
		{
			int myIndex = 0;
			int agentsAmount = 2;
			int expectingTime = 20;
			int processTime = 20;

			Assert::AreEqual(expectingTime, getWaitingTime(myIndex, agentsAmount, processTime));
		}
	}; 
}
