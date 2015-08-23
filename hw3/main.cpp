#include "Map.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

int main(int argc, char * argv[])
{
	ifstream inFile(argv[1]);
	string email;
	string name = "";
	string temp;
	Map<string, string> myMap;
	string input;

	if (inFile.fail())
	{
		cout << "Error - file did not open! \n\n";
		return 1;
	}
	else
	{
		while(!inFile.eof())
		{
			inFile >> email;
			getline(inFile, temp);
			name = "";
			int i = 0;
			while (temp[i] == ' ' || temp[i] == '\t')
			{
				i++;
			}

			while (i < temp.length())
			{
				name += temp[i];
				i++;
			}

			myMap.add(email, name);
		} 

		do {
			cout << "Please enter email address: ";
			cin >> input;

			if (input == ".")
			{
				cout << "Program ends! Good-Bye!" << endl;
				break;
			}

			try
			{
				cout << input << " is " << myMap.get(input) << endl;
			}
			catch (const logic_error & e)
			{
				cout << e.what() << endl;
			}
		} while (input != ".");
	}
	
	myMap.~Map();

	return 0;
}
