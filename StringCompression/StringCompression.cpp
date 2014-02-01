
#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

std::string inputString; //string to be compressed
size_t stringLen = 0;
size_t currLocation = 0;

int main(int argc, char* argv[])
{
    if( argc!=2 )
    {
        std::cout << "Error: Invalid arguments" << std::endl;
        std::cout << "Usage: " << argv[0] << "<string>" << std::endl;

        return EXIT_FAILURE;
    }
    inputString = argv[1];
    std::cout << "input String: " << inputString << std::endl;
    stringLen = inputString.length();
    std::string charToMatch;
    std::string compressedString;
    size_t tempIndex = 0;

    for( currLocation = 0; currLocation < stringLen; currLocation)
    {
        //std::cout << "CurrLocation " << currLocation << std::endl;

        charToMatch = inputString.at(currLocation);
        //std::cout << "Char to match: " << charToMatch << std::endl;

        tempIndex = inputString.find_first_not_of(charToMatch.c_str(), currLocation);
        if(tempIndex > inputString.length())
            tempIndex = inputString.length();
        //std::cout << "Index end of repeated letters " << tempIndex << std::endl;

        compressedString.append(charToMatch);

        if(tempIndex)
        {
            //std::cout << "Current substring:" << inputString.substr(currLocation, tempIndex-currLocation) << std::endl;
            ostringstream convert;
            convert << (tempIndex-currLocation);

            //Add number of repeated chars
            compressedString.append(convert.str());

            //Update location
            currLocation = tempIndex;
        }
        else
        {
            //since there was no index found, just add 1
            compressedString.append("1");
        }

       // std::cout << "Compressed string so far " << compressedString << std::endl << std::endl;
    }
    if( stringLen > compressedString.length() )
        std::cout << compressedString << std::endl;
    else
        std::cout << inputString << std::endl;
    return EXIT_SUCCESS;
}
