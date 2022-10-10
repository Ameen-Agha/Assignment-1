#include <stdio.h>

//driver code
int main()
{
    int n1 = 9;
    int n2 = 14;
    printf("%d\n",hammingDistance(9,14));
    return 0;
}

//Specifications: It takes an input of two integers, and returns the hamming distance between them which is the number of bits that are different at the same position in both numbers. 
//Test Cases: -If the two digits are equal then the hamming distance is equal to 0. -If the two digits are not equal then we change them into binary and check for the different bits. When found we increment setBits and return it in the end.
int hammingDistance(int n1, int n2)
{
    int x = n1 ^ n2;
    int setBits = 0;
 
    while (x > 0) {
        setBits += x & 1;
        x >>= 1;
    }
 
    return setBits;
}