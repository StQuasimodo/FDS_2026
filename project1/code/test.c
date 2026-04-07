#include<stdio.h>
#include<stdlib.h>

#include "seq_iterative.c" //Include the function of iteractive sequential search
#include "seq_recursive.c" //Include the function of recursive sequential search
#include "binary_iterative.c" //Include the function of iterative binary search
#include "binary_recursive.c" //Include the function of recursive binary search

int main(){
    int arr[10]={0,1,2,3,4,5,6,7,8,9}; //Create an ordered array
    int target = 0; //Target in the beginning

    //Call the function to be tested
    int si = seq_iterative(arr, 10, target); 
    int sr = seq_recursive(arr, 10, target, 0);
    int bi = binary_iterative(arr, 10, target); 
    int br = binary_recursive(arr, 0, 9, target); 
    printf("%d %d %d %d\n", si, sr, bi, br);

    target = 9; //Target in the end
    //Call the function to be tested
    si = seq_iterative(arr, 10, target);
    sr = seq_recursive(arr, 10, target, 0);
    bi = binary_iterative(arr, 10, target);
    br = binary_recursive(arr, 0, 9, target);
    printf("%d %d %d %d\n", si, sr, bi, br);

    target = 5; //Target in the middle
    //Call the function to be tested
    si = seq_iterative(arr, 10, target);
    sr = seq_recursive(arr, 10, target, 0);
    bi = binary_iterative(arr, 10, target);
    br = binary_recursive(arr, 0, 9, target);
    printf("%d %d %d %d\n", si, sr, bi, br);

    target = 10; //Target not in the list
    //Call the function to be tested    
    si = seq_iterative(arr, 10, target);
    sr = seq_recursive(arr, 10, target, 0);
    bi = binary_iterative(arr, 10, target);
    br = binary_recursive(arr, 0, 9, target);
    printf("%d %d %d %d\n", si, sr, bi, br);

    int arr2[0]; //Empty array
    target = 5; //Target not in the list
    //Call the function to be tested
    si = seq_iterative(arr2, 0, target);
    sr = seq_recursive(arr2, 0, target, 0); 
    bi = binary_iterative(arr2, 0, target);
    br = binary_recursive(arr2, 0, 0, target);
    printf("%d %d %d %d\n", si, sr, bi, br);

    int arr3[1]={5}; //Array with one element
    target = 5; //Target in the list
    //Call the function to be tested
    si = seq_iterative(arr3, 1, target);
    sr = seq_recursive(arr3, 1, target, 0);
    bi = binary_iterative(arr3, 1, target);
    br = binary_recursive(arr3, 0, 0, target);
    printf("%d %d %d %d\n", si, sr, bi, br);

    target = 10; //Target not in the list
    //Call the function to be tested    
    si = seq_iterative(arr3, 1, target);
    sr = seq_recursive(arr3, 1, target, 0);
    bi = binary_iterative(arr3, 1, target);
    br = binary_recursive(arr3, 0, 0, target);
    printf("%d %d %d %d\n", si, sr, bi, br);

    return 0;
}