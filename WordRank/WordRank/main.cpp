#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void sortArr(string[], long long int);
void getRearrangedStrs(string[], string);
void swapStr(string*, string*);
void printArr(string[], long long int);
long long int getWordRank(string[], long long int, string);
long long int fact(int);

int main()
{
	string str;
	cin >> str;

	long long int arraySize = fact(str.length());
	string* rearrangedStrsArr = new string[arraySize];

	getRearrangedStrs(rearrangedStrsArr, str);
	//sortArr(rearrangedStrsArr, arraySize);
	cout << getWordRank(rearrangedStrsArr, arraySize, str);
}

void getRearrangedStrs(string arr[], string str1)
{
	long long int i = 0;
	sort(str1.begin(), str1.end());
	do {
		arr[i] = str1;
		i++;
	} while (std::next_permutation(str1.begin(), str1.end()));
}

void sortArr(string arr[], long long int arrL)
{
	for (long long int i = 0; i < arrL; i++)
	{
		for (long long int j = i + 1; j < arrL; j++)
		{
			auto iterI = arr[i].begin();
			auto iterJ = arr[j].begin();
			while (iterI != arr[i].end() || iterJ != arr[j].end())
			{
				if (*iterI > * iterJ)
				{
					swapStr(&arr[i], &arr[j]);
					break;
				}
				else if (*iterI == *iterJ)
				{
					iterI++;
					iterJ++;
					continue;
				}
				break;
			}
		}
	}
}

void swapStr(string* str1, string* str2)
{
	string temp;
	temp = *str1;
	*str1 = *str2;
	*str2 = temp;
}

long long int fact(int x)
{
	if (x == 1 || x == 0)
	{
		return 1;
	}
	else
	{
		return x * fact(x - 1);
	}
}

long long int getWordRank(string arr[], long long int len, string word)
{
	for (long long int i = 0; i < len; i++)
	{
		if (arr[i] == word)
		{
			return ++i;
		}
	}
	return -1;
}

void printArr(string arr[], long long int len)
{
	for (long long int i = 0; i < len; i++)
	{
		cout << arr[i] << " , ";
	}
}
