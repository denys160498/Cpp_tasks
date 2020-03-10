#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void parseNames(string , vector<string>& );
void printVect(const vector<string>& );
int getMyIndex(string , vector<string>& );
/*void sortArr(string[], const int);
void swapStr(string*, string*);*/
int getWaitingTime(int , int , int processTime = 20);

int main()
{
	string myName;
	short int amountOfAgents;
	string othersNames;
	vector<string> namesVect;
	
	cin >> myName;
	cin >> amountOfAgents;
	cin.ignore(32767, '\n');
	getline(cin, othersNames);
	
	parseNames(othersNames, namesVect);
	namesVect.push_back(myName);
	sort(namesVect.begin(),namesVect.end());
	cout<< getWaitingTime(getMyIndex(myName,namesVect)+1, amountOfAgents);
}

void parseNames(string names, vector<string>& toStrArr)
{
	int startPos = 0;
	int endPos = names.find(' ');
	
	while(endPos != -1)
	{
		toStrArr.push_back(names.substr(startPos, endPos - startPos));
		startPos = endPos+1;
		endPos = names.find(" ",endPos+1);
		if(endPos == -1)
		{
			toStrArr.push_back(names.substr(startPos));
			break;
		}
	}
	
}

int getMyIndex(string myName, vector<string>& allNames)
{
	auto iter = allNames.begin();
	int i = 0;
	while(iter != allNames.end())
	{
		if(*iter == myName)
		{
			 return i;
		}
		i++;
		iter++;
	}
}

int getWaitingTime(int myIndex, int agentsAmount,  int processTime)
{
	int myWaitingTime;
	if(myIndex%agentsAmount == 0)
	{
		myWaitingTime = myIndex/agentsAmount*processTime;
		
	}
	else
	{
		myWaitingTime = (myIndex/agentsAmount + 1)*processTime;
	}
	return myWaitingTime;
}

void printVect(const vector<string>& vectToPrint)
{
	auto iter = vectToPrint.begin();
	while(iter != vectToPrint.end())
	{
		cout << *iter << ' ';
		iter++;
	}
}