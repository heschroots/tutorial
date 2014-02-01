
#include <stdio.h>
#include <iostream>
#include <bitset>


unsigned int num1 = 0; //input num1
unsigned int num2 = 0; //input num2
unsigned int xor_result= 0; //result of xor the two numbers
unsigned int mask = 1; //mask for logical AND. Only lowest bit should be 1
unsigned int num_flipped_bits = 0;

int main(int argc, char* argv)
{
    if (argc != 3)
    {
        std::cout << "Error. Invalid arguments" << std::endl;
        std::cout << "Usage: " << argv[0] << "num1 num2" << std::endl;
        return EXIT_FAILURE;
    }

    num1 = argv[1];
    num2 = argv[2];

    //Get the bitwise XOR of the number
    xor_result = num1 ^ num2;

    unsigned int temp = 0;
    for(int i = 0; i < sizeof(unsigned int); i++)
    {
        if(xor_result & mask)
        {
            num_flipped_bits++;
        }

        xor_result>>1;
    }

    std::cout << "num of flipped bits: " << num_flipped_bits << std::endl;

    return EXIT_SUCCESS;

}
