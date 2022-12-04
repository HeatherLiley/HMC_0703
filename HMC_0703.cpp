/*Chapter 7: Programming Exercise #3
*Made by Heather Connor
*/

#include<iostream>
#include<string>
#include <string.h>

using namespace std;

bool isVowel(char ch);
string rotate(string pigLatin);
string pigLatinStr(string pigLatin);

int main()
{
	string engIn; //Declare user input variable

	cout << "Welcome to the Pig Latin Translator!" << endl
		<< "This program translates English into Pig Latin." << endl;

	cout << "English: ";
	getline(cin, engIn);
	cout << endl;

	cout << "Pig Latin: " << pigLatinStr(engIn) << endl;

	return 0;
}

bool isSpace(char ch)
{
	switch (ch)
	{
	case ' ':
		return true;
	default:
		return false;
	}
}

bool isVowel(char ch)
{
	switch (ch)
	{
	case 'A':
	case 'E':
	case 'I':
	case 'O':
	case 'U':
	case 'Y':
	case 'a':
	case 'e':
	case 'i':
	case 'o':
	case 'u':
	case 'y':
		return true;
	default:
		return false;
	}
}

bool isPunct(char ch)
{
	switch (ch)
	{
	case ',':
	case ';':
	case':':
	case '&':
	case '.':
	case '?':
	case '!':
		return true;
	default:
		return false;
	}
}

string rotate(string pigLatin)
{
	string::size_type len = pigLatin.length();
	string rStr;
	rStr = pigLatin.substr(1, len - 1) + pigLatin[0];

	return rStr;
}

string pigLatinStr(string pigLatin)
{
	string::size_type len;

	bool foundSpace;
	bool foundVowel;
	bool foundPunct;

	string::size_type counter;

	if (isSpace)
	{
		if (isVowel(pigLatin[0]))
			pigLatin = pigLatin + "-way";
		else
		{
			pigLatin = pigLatin + '-';
			pigLatin = rotate(pigLatin);

			len = pigLatin.length();
			foundVowel = false;

			for (counter = 1; counter < len - 1; counter++)
				if (isVowel(pigLatin[0]))
				{
					foundVowel = true;
					break;
				}
				else
					pigLatin = rotate(pigLatin);
			if (!foundVowel)
				pigLatin = pigLatin.substr(1, len) + "-way";
			else
				pigLatin = pigLatin + "ay";
		}
	}

	return pigLatin;
}