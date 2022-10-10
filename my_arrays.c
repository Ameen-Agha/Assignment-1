#include <stdio.h>
#include <stdlib.h>
#define SIZE 10


int mode();
void printArray();
void arrayHistogram();
void swap();
void printPattern();
void bubblesort();
void median();
void isSorted();




int main() {
    int arr[] = {1,2,3,2,3,2,2,1,3,3};
    printArray(arr);
    arrayHistogram(arr);
    for (int i = 0 ; i < SIZE ; i++) {
        printf("%d", arr[i]);
    }
    printf("\n");
    swap(arr,1, 4);
    for (int i = 0 ; i < SIZE ; i++) {
        printf("%d", arr[i]);
    }
    printf("\n");
    bubblesort(arr);
    for (int i = 0 ; i < SIZE ; i++) {
        printf("%d", arr[i]);
    }
    printf("\n");
    median(arr);
    for (int i = 0 ; i < SIZE ; i++) {
        printf("%d", arr[i]);
    }
    printf("\n");
    int n = mode(arr);
    printf("The mode is %d", n);
    printf("\n");
    isSorted();
}
//Specifications:It takes an array of integers, and returns the values along with their indices.
//Test Cases: Numbers to be used should be 1,2,and 3 having a size of 10. Knowing that, we could have alot of cases such as:{1,1,2,3,3,2,1,1,1,2}-{2,2,2,2,3,3,3,1,1,2}.
void printArray(int arr[]) {
    printf("%s","Index  Value");
    for (int i = 0 ; i < SIZE; i++) {
        printf("%d      %d\n", arr[i], i );
    }
}
//Specifications:It takes an array of integers, and returns how many times each integer is repeated along with a histogram showing stars(*) of how many times it was repeated.
//Test Cases:-If only one number is repeated then it is the only one with stars.-If we only have 2 numbers repeated then also those two have stars. - If we have all three numbers repeated then all three have stars.
void arrayHistogram(int arr[]) {
    int repeated[SIZE];
    int i;
    int j;
    int count;

    printf("Enter the elements in the array: ");
    for (i = 0 ; i < SIZE; i++) {
        scanf("%d", &arr[i]);
        repeated[i] = -1;
    }

    for (i = 0 ; i < SIZE ; i++) {
        count = 1;
        for (j = i+ 1; j < SIZE; j++) {
            if (arr[i] == arr[j]) {
                count++;
                repeated[j] = 0;
            }
        }

        if (repeated[i]!= 0) {
            repeated[i] = count;
        }
    }

    printf("\nValue    Frequency     Histogram\n");
    for (i = 0 ; i < SIZE; i++) {
        if(repeated[i]!=0) {
            printf("%d         %d             ", arr[i], repeated[i]);
            printPattern(repeated[i]);
        }
    } 


}
void printPattern(int repeated) {
    for (int i = 0 ; i < repeated ; i++) {
        printf("*");
    }
    printf("\n");

}

//Specifications: It takes an array of integers, and two indicies you want to swap the values of.
//Test Cases: -If user chooses same index for both then nothing happens. - If user chooses an index that is out of bounds then an error happens. - If the user chooses two in bound indices then there values change.
void swap(int arr[],int a, int b) {
    int temp= arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

//Specifications: It takes an array, and returns it in increasing order.
//Test Cases: - If the array is empty or consists of one number then it is already in increasing order. - If the array consists of different numbers then it should be rearranged where ones are in the beginning followed by twos followed by threes.
void bubblesort(int arr[]) {
        for (int i = 0; i < SIZE - 1; ++i) {
            for (int j = 0; j < SIZE - i - 1; ++j) {   
                if (arr[j] > arr[j + 1]) {
                    swap(arr, j, j+1);
            }
        }
    }
}

void median(int arr[]) {
    bubblesort(arr);
    printf("%d",arr[5]);
}
//Specifications:It takes an array and the size of the array, and returns the most repeated number in the array.
//Test Cases: - If 1 number is dominant and repeated the most we return it such as {1,1,1,1,1,1,1,1,1,3}. -If we have 2 numbers that are dominant then we return them both such as{1,1,1,1,2,2,2,2,3,3}.
int mode(int a[], int n) {
    int max = 0;
    int maxCount = 0;
    for (int i = 0; i < n ;i++) {
        int count = 0;
        for (int j = 0; j <n ;j++) {
            if (a[j] ==a[i]) {
                count++;
            }

            if(count > maxCount) {
                maxCount = count;
                max = a[i];
            }
        }
    }
    return max;
}
//Specifications:It takes an array of integers and the size of the array, and returns if it is sorted or not.
//Test Cases: -If the array is empty or consists of 1 number then it is sorted. - If the array consists of multiple numbers then it checks them one by one and if at some place it is not sorted then it returns not sorted.
void isSorted(int a[], int n) {
    if(n==1 | n== 0) {
        printf("The array is sorted");
    if (a[n-1]< a[n-2]) {
        printf("The array isn't sorted");
    }
        isSorted(a,n-1);
    }
}