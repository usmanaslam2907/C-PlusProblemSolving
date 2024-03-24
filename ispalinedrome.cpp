#include <iostream>
using namespace std;

bool ispalindrome(string str)
{
	int left = 0;
	int right = str.length() - 1;
	while (left < right)
	{
		if (str[left] == ' ')
		{
			left++; // Skip space from the left side
		}
		else if (str[right] == ' ')
		{
			right--; // Skip space from the right side
		}
		else if (str[left] != str[right])
		{
			return false; // Characters don't match, not a palindrome
		}
		else
		{
			left++; // Move to the next characters
			right--;
		}
	}
	return true; // All characters matched, palindrome
}

int main()
{
	string str = " m aa m";
	if (ispalindrome(str))
	{
		cout << "Palindrome" << endl;
	}
	else
	{
		cout << "Not Palindrome" << endl;
	}
	return 0;
}
