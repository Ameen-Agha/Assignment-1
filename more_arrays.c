#include <stdio.h>

//Specifications: It takes an input of a 2D array of strings and returns them as one 1D array array of strings.
//Test Cases: - If the aray is empty then it returns nothing. - If the array is filled it is returned as one full sentence without slashes or parts.
int main() {
  char s1[100] = "I" "Love" "Coding", s2[] = "This" "is" "Sparta";
  int length, j;

  // store length of s1 in the length variable
  length = 0;
  while (s1[length] != '\0') {
    ++length;
  }

  // concat s2 to s1
  for (j = 0; s2[j] != '\0'; ++j, ++length) {
    s1[length] = s2[j];
  }

  // terminating the s1 string
  s1[length] = '\0';

  printf("After concatenation: ");
  puts(s1);

  return 0;
}