// Brackets.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <stack>

const std::string StartBracketsPattern("({[<");
const std::string EndBracketsPattern(")}]>");

bool checkBrackets( const std::string& testLine )
{
	if ( testLine.empty() )
		return true;

	std::stack<std::string::value_type> startBrackets;	// stack of start brackets

	std::string::const_iterator idx = testLine.begin();	// old style iteration
	std::string::const_iterator end = testLine.end();
	for (; idx != end; ++idx)
	{
		std::string::value_type symbol = *idx;
		if ( std::string::npos != StartBracketsPattern.find(symbol) )
		{
			startBrackets.push(symbol);
		}
		else
		{
			if ( startBrackets.empty() )
				return false;

			std::string::value_type startBracket = startBrackets.top();
			startBrackets.pop();
			std::string::size_type endBracketPos = EndBracketsPattern.find(symbol);
			if ( std::string::npos != endBracketPos && endBracketPos != StartBracketsPattern.find(startBracket) )
			{
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

