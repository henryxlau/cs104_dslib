#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <fstream>
#include "quicksort.h"
using namespace std;

struct Student
{
	string name;
	int grade;
	bool operator<(const Student & rhs)
	{
		return grade < rhs.grade;
	}
	Student operator=(const Student & rhs)
	{
		return rhs;
	}
	bool operator>(const Student & rhs)
	{
		return grade > rhs.grade;
	}
};

void swap(int &x, int &y)
{
	int temp = x;
	x = y;
	y = temp;
}

int main(int argc, char * argv[])
{
	//map of student with score
	//pointer to scores from map (sorted)
	//swap scores from other sorted array

	ifstream inFile(argv[1]);
	ofstream outFile(argv[2]);
	string name = "";
	Student *currGrade;
	int *curveGrades;
	int temp = 0;
	string input;
	int lines = 0;


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
		currGrade = new Student[lines];
		QuickSort<Student> sortedStudents(lines);
		QuickSort<int> sortedGrades(lines);

		for (int i = 0; i < lines; i++)
		{
			inFile >> currGrade[i].name;
			getline(inFile, input);
			stringstream ss(input);
			ss >> temp;
			currGrade[i].grade = temp;
			sortedStudents.inputData(currGrade[i]);
		} 

		sortedStudents.quicksort(0, lines);

		for (int i = 0; i < lines; i++)
		{
			currGrade[i] = sortedStudents.getData(i);
		}

		curveGrades = new int[lines];
		for (int j = 0; j < lines; j++)
		{
			getline(inFile, input);
			stringstream ss1(input);
			ss1 >> temp;
			curveGrades[j] = temp;
			sortedGrades.inputData(curveGrades[j]);
		}

		sortedGrades.quicksort(0, lines);

		for (int i = 0; i < lines; i++)
		{
			curveGrades[i] = sortedGrades.getData(i);
		}

		for (int i = 0; i < lines; i++)
		{
			swap(currGrade[i].grade, curveGrades[i]);
		}

		for (int i = 0; i < lines; i++)
		{
			outFile << currGrade[i].name << " " << currGrade[i].grade << endl;
		}
	}
	
	return 0;
}