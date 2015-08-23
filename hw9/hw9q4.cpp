#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <unordered_map>
using namespace std;

int main(int argc, char const *argv[])
{
	unordered_map<double, string> peopleWithSkill;

	ifstream inFile(argv[1]);
	string name = "";
	double temp = 0;
	string input;
	int lines = 0;
	double * scores;
	double sum = 0;
	double average = 0;

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
		scores = new double[lines];

		for (int i = 0; i < lines; i++)
		{
			inFile >> name;
			getline(inFile, input);
			stringstream ss(input);
			ss >> temp;
			scores[i] = temp;
			pair<double, string> studentSkills(temp, name);
			peopleWithSkill.insert(studentSkills);
		} 

		for (int i = 0; i < lines; i++)
		{
			sum += scores[i];
		}

		average = (sum/(lines/2));

		if ((int)average % 2 != 0)
		{
			cout << "Skill scores cannot create student pairs! \nProgram will now end!" << endl;
			exit(1);
		}
		
		for (int i = 0; i < lines; i++)
		{
			int tempAverage = average - scores[i];
			unordered_map<double,string>::const_iterator student1 = peopleWithSkill.find(scores[i]);
			unordered_map<double,string>::const_iterator student2 = peopleWithSkill.find(tempAverage);
			if (student1 == peopleWithSkill.end())
			{
				cout << "No matching skill for " << student1->second << endl;
			}
			else
			{
				cout << student1->second << " " << student2->second << endl;
			}
		}
	}

	return 0;
}