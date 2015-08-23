#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

void reversePrint(int *n, int lines)
{
	for (int i = lines - 1; i >= 0; i--)
	{
	        cout << n[i] << endl;
	}
}

int main(int argc, char * argv[])
{
	ifstream inFile(argv[1]);
	int lines = 0;
	char *a;
	string input;
	string data;
	int j = 0;
	int *numArray;
	int wordCount = 0;

	if (inFile.fail())
	{
		cout << "Error - file did not open! \n\n";
		return 1;
	}
	else
	{
		getline(inFile, input);
		stringstream buffer(input);
		buffer >> lines;
		numArray = new int[lines];
		getline(inFile, data);
		for (int i = 0; i < lines; i++)
		{
			a = new char[data.length() + 1];
			stringstream ss(data);

			while (ss >> a)
			{
				if ((a[j] = ' ') && (a[j + 1] != ' ')) 
					wordCount++;
				j++;
			}
			numArray[i] = wordCount;
			wordCount = 0;
			delete a;
			getline(inFile, data);
		}
	}

	inFile.close();

	reversePrint(numArray, lines);

	delete[] numArray;
	return 0;
}
