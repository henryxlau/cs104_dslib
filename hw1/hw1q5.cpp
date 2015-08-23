#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

void recursion(char *characters, int n, string data, int size)
{
	if (n == 0)
		cout << data << endl;
	else 
	{
		for (int i = 0; i < size; i++)
		{
			recursion(characters, n-1, data + characters[i], size);
		}
	}
}

int main(int argc, char * argv[])
{
	string arg1 = argv[1];
	string arg2 = argv[2];
	char *a;
	int n;

	stringstream ss(arg1);
	a = new char[arg1.size() + 1];
	ss >> a;

	stringstream iss(arg2);
	iss >> n;

	recursion(a, n, "", arg1.length());

	delete[] a;

	return 0;
}
