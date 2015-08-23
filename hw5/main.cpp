#include "Stack.h"
#include "Map.h"
#include <fstream>
#include <ctype.h>
#include <locale>

int main(int argc, char * argv[])
{
	Map<string, char> myMap;
	Stack<char> myStack;
	ifstream inFile(argv[2]);
	ifstream dataFile(argv[1]);
	string key;
	char value;
	unsigned int i;
	int count = 0;

	string s;
	unsigned int pos;
	char a;
	char b;

	while(inFile >> key)
	{
		inFile >> value;

		try
		{
			myMap.add(key, value);
		}
		catch (logic_error & e)
		{
			cout << e.what() << endl;
		}
	}

	while(!dataFile.eof())
	{
		getline(dataFile,s);
		count++;
		i = 0;
		string temp = "";
		while (i < s.length())
		{
			if (s[i] == ' ')
				i++;
			else
			{
				temp = temp + s[i];
				i++;
			}
		}
		s = temp;
		pos = 0;

		while (pos < s.length())
		{
			try
			{
				switch (s[pos])
				{
				case '(': 
					{ 
						myStack.push(s[pos]);
						pos++;
						break;
					}
				case '&': case '|': case '~':
					{
						myStack.push(s[pos]);
						pos++;
						break;
					}
				case ')':
					{
						pos++;
						if (isalnum(myStack.top()))
						{
							a = myStack.top();
							myStack.pop();
							i = 0;
							while(myStack.top() == '~')
							{
								myStack.pop();
								++i;
							}

							if (!(i % 2 == 0))
							{
								if (a == 'T')
									a = 'F';
								else if (a == 'F')
									a = 'T';
							}
							if (myStack.top() == '|')
							{
								myStack.pop();
								b = myStack.top();
								myStack.pop();
								i = 0;
								while(myStack.top() == '~')
								{
										myStack.pop();
										++i;
								}

								if (!(i % 2 == 0))
								{
									if (b == 'T')
										b = 'F';
									else if (b == 'F')
										b = 'T';
								}
								if (a == 'T' || b == 'T')
									a = 'T';
								else
									a = 'F';
							}
							else if (myStack.top() == '&')
							{
								myStack.pop();
								b = myStack.top();
								myStack.pop();
								i = 0;
								while(myStack.top() == '~')
								{
									myStack.pop();
									++i;
								}

								if (!(i % 2 == 0))
								{
									if (b == 'T')
										b = 'F';
									else if (b == 'F')
										b = 'T';
								}
								if (a == 'T' && b == 'T')
									a = 'T';
								else
									a = 'F';
							}
							if (myStack.top() == '(')
							{
								myStack.pop();
								if (!myStack.isEmpty())
								{
									i = 0;
									if (myStack.top() == '~');
									{
										while(myStack.top() == '~')
										{
											myStack.pop();
											++i;
										}

										if (!(i % 2 == 0))
										{
											if (a == 'T')
												a = 'F';
											else if (a == 'F')
												a = 'T';
										}
									}
								}
								myStack.push(a);
								continue;
							}
						}
						else
							throw logic_error("Malformatted expression");
				case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9':
						{
							string num = "";
							while(isalnum(s[pos]))
							{
								num += s[pos];
								pos++;
							}
							myStack.push(myMap.get(num));
							num = "";
						}
					}
				}
			}
			catch (logic_error & e)
			{
				cout << e.what() << endl;
				myStack.~Stack();
				break;
			}
		}
	}

	while (!myStack.isEmpty())
	{
		cout << "Expression #" << count << ": " << myStack.top() << endl;
		myStack.pop();
		count--;
	}

	myStack.~Stack();

	return 0;
}
