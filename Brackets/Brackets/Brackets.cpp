// Brackets.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <stack>

bool checkBrackets( const std::string& str )
{
	if ( str.empty() )
		return true;

	std::stack<std::string::value_type> startBrackets;

	std::string::const_iterator idx = str.begin();
	std::string::const_iterator end = str.end();
	for (; idx != end; ++idx)
	{
		if (*idx == '(' || *idx == '[' || *idx == '{')
		{
			startBrackets.push(*idx);
		}
		else
		{
			if ( startBrackets.empty() )
				return false;

			std::string::value_type symbol = startBrackets.top();
			startBrackets.pop();
			if ( *idx == ')' || *idx == ']' || *idx == '}' )
			{
				if ( *idx == ')' && symbol != '(')
					return false;
				if ( *idx == ']' && symbol != '[')
					return false;
				if ( *idx == '}' && symbol != '{')
					return false;
			}
			else
				; // doesn't matter, there is other symbol we don't care
		}
	}

	return true;
}

int main(int argc, char* argv[])
{
	if ( argc > 1)
	{
		std::string brackets( argv[1] );
		if ( checkBrackets(brackets) )
		{
			std::cout << "Check passed" << std::endl;
		}
		else
		{
			std::cout << "Check failed" << std::endl;
		}
	}

	return 0;
}

