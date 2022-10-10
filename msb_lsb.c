#include <stdio.h>

//Specifications:It takes an input from the user, and returns the most significant bit after in binary.
//Test Cases: -If input=Positive:The function will change it to binary and check for msb. -If input=Negative:The function will change it to binary using 2's compliment and check for lsb.
int MSB(unsigned int n)
{
    int count = 0;

    while (n) {
        count++;
        n = n >> 1;
    }

    return count - 1;
}


//Specifications:It takes an input from the user, and returns the least significant bit after in binary.
//Test Cases: -If input=Positive:The function will change it to binary and check for lsb. -If input=Negative:The function will change it to binary using 2's compliment and check for lsb.
int LSB(int n) {
    int place = -1;
        if (n &1) {
            place = 0;
        } else {
            while (!(n & 1)) {
            place++;
            n >>= 1;
        }
    }
    return place;
}
//driver code
 int main() {
     int n;
     printf("Enter a positive number: \n");
     scanf("%d", &n);
     while (n <= 0) {
         printf("Enter a positive number: \n");
         scanf("%d", &n);
    }
    int msb = MSB(n);
    int lsb = LSB(n);
    printf("The difference between the MSB and LSB of %d is %d",n, msb- lsb);

}