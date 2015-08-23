#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <stdlib.h>
using namespace std;

int num[3];
char ** map;
bool ** neighbors;
int *colorArray;
const int maxColors = 4;

void print()
{
	for(int i = 0; i < num[0]; i++)
	{
		cout << static_cast<char>('A'+i)<< '\t' << colorArray[i] << endl;
	}
}

bool isSafe(int x, int c)
{
	for (int i = 0; i < num[0]; i++)
	{
		if (neighbors[x][i] && c == colorArray[i])
			return false;
	}
	return true;
}


bool search(int max, int x)
{
	if (x == num[0])
		return true;
	else
	{
		for (int i = 1; i <= max; i++)
		{
			if(isSafe(x, i))
			{
				colorArray[x] = i;
				
				if (search(max, x+1) == true)
					return true;
				colorArray[x] = 0;
			}
		}
		return false;
	}
}

void colorGraph(int max)
{
	colorArray = new int[num[0]];
	for (int i = 0; i < num[0]; i++)
		colorArray[i] = 0;
	if (search(max, 0) == true)
		print();
}

void buildNeighbors()
{
	for (int i = 0; i < num[0]; i++)
	{
		for (int j = 0; j < num[0]; j++)
		{
			neighbors[i][j] = false;
		}
	}

	char temp1;
	char temp2;
	for (int i = 0; i < num[1]; i++)
	{
		for (int j = 0; j < num[2]; j++)
		{
			temp1 = map[i][j];
			if (j != num[2] - 1 && temp1 != map[i][j+1])
			{
				temp2 = map[i][j+1];	
				neighbors[temp1-'A'][temp2-'A'] = true;
				neighbors[temp2-'A'][temp1-'A'] = true;
			}
			if (i != num[1] - 1 && temp1 != map[i+1][j])
			{
				temp2 = map[i+1][j];
				neighbors[temp1-'A'][temp2-'A'] = true;
				neighbors[temp2-'A'][temp1-'A'] = true;
			}
		}
	}
}

int main(int argc, char * argv[])
{
	ifstream inFile(argv[1]);
	string input;

	inFile >> num[0] >> num[1] >> num[2];
	getline(inFile, input);

	map = new char*[num[1]];
	for (int i = 0; i < num[1]; i++)
		map[i] = new char[num[2]];
	neighbors = new bool*[num[0]];
	for (int i = 0; i < num[0]; i++)
		neighbors[i] = new bool[num[0]];

	for (int i = 0; i < num[1]; i++)
	{
		getline(inFile, input);
		stringstream ss(input);
		ss >> map[i];
	}

	buildNeighbors();

	colorGraph(maxColors);

	free(map);
	free(neighbors);
	free(colorArray);

	return 0;
}
