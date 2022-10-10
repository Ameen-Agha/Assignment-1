#include <stdio.h>
#include <stdlib.h>
#include<string.h>

void merge();
void sort();
void print();

int main() {
    char *str1[2] = {"ab","ac"};
    char *str2[3] = {"za", "zb", "zzzzc"};
    merge(str1, str2, 2, 3);
}

//Specifcations: It takes two arrays of strings along with their size and returns them as one merged array.
//Test Cases: - If the 2 arrays are empty then it returns nothing. - If one of the arrays is empty then it returns the other on its own. - If both arrays have something then they are merged and returned in an alphabateical order.
void merge(char** arr0, char** arr1, int a0, int a1) {
    char* s[100];
    char* arr2[a0+a1];
    for (int i = 0 ; i < a0; i++) {
        char *pt = arr0[i];
        arr2[i] = pt;
        
    }
    int index = 0;

    for (int i = a0 ; i < a0 + a1 ; i++) {
        char *pt = arr1[index];
        arr2[i] = pt;
        index++;
    }
    sort(arr2, a0 + a1);
    print(arr2);
}
//Specifcations: It takes an array of strings and the size of the array, and returns the array sorted.
//Test Cases:- If the array is empty or consists of one element then it is already sorted. - If the array is filled then it checks number by number and arranges them by increasinf order to finally return the array back sorted. 
void sort(char** arr, int n) {
    for (int i = 0 ; i < n ; i++) {
        for (int j = i+1 ; j < n ; j++) {
            if(strcmp(arr[i], arr[j]) > 0) {
                char *temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    
    void print(char** array) {
    for (int i = 0 ; i < 6 ; i++) {
        char *pt = array[i];
        printf("%s\n", pt);
    }
}
}