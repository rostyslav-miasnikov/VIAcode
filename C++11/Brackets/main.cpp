#include <string>
#include <algorithm>
#include <iostream>
#include <stack>

const std::string StartBracketsPattern("({[<");
const std::string EndBracketsPattern(")}]>");

bool checkBrackets( const std::string& testLine )
{
    if ( testLine.empty() )
        return true;

    bool result = true;
    std::stack<std::string::value_type> startBrackets;	// stack of start brackets
    std::for_each (testLine.cbegin(), testLine.cend(), [&](char symbol)
    {
        if ( std::string::npos != StartBracketsPattern.find(symbol) )
        {
            startBrackets.push(symbol);
        }
        else
        {
            if ( startBrackets.empty() )
                result = false;

            std::string::value_type startBracket = startBrackets.top(); // last in start element (old style)
            startBrackets.pop(); // remove element from stack
            auto endBracketPos = EndBracketsPattern.find(symbol);
            // check symbol if it's close bracket
            // and if it's correct close (same position in pattern)
            if ( std::string::npos != endBracketPos && endBracketPos != StartBracketsPattern.find(startBracket) )
            {
                result = false;
                return;
            }
            else
                ; // doesn't matter, there is other symbol we don't care
        }
    });

    return result;
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
