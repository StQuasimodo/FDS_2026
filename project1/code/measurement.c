#include <stdio.h>
#include <stdlib.h>
#include <time.h>
clock_t start, stop;
double d_si, d_sr, d_bi, d_br, time_si, time_sr, time_bi, time_br, total_si, total_sr, total_bi, total_br;

#include "seq_iterative.c" //Include the function of iteractive sequential search
#include "seq_recursive.c" //Include the function of recursive sequential search
#include "binary_iterative.c" //Include the function of iterative binary search
#include "binary_recursive.c" //Include the function of recursive binary search




int main(){
    int test[8]={100, 500, 1000, 2000, 4000, 6000, 8000, 10000}; //Eight different values of N
    printf("N\tsi\tsr\tbi\tbr\n");
    for(int count=0; count<8; count++){
        int N=test[count];
        int arr[N];
        for(int i=0; i<N; i++){
            arr[i]=i; //Create an ordered array
        }
        int target = N; //Worst case: target not in the list

        long long k_si = 1; //operation times of Iteractive sequential search
        do{
            k_si *= 2;
            start = clock(); //Start timing
            for(long long i=0; i<k_si; i++){
                int si = seq_iterative(arr, N, target); //Call the function to be tested
            }stop = clock(); //Stop timing
            d_si = (double)(stop - start);
        }while(d_si < 10);
        total_si = d_si / CLK_TCK;
        time_si = d_si / k_si /CLK_TCK;

        long long k_sr = 1; //operation times of Recursive sequential search
        do{
            k_sr *= 2;
            start = clock(); //Start timing
            for(long long i=0; i<k_sr; i++){
                int sr = seq_recursive(arr, N, target, 0); //Call the function to be tested
            }stop = clock(); //Stop timing
            d_sr = (double)(stop - start);
        }while(d_sr < 10);
        total_sr = d_sr / CLK_TCK;
        time_sr = d_sr / k_sr /CLK_TCK;

        long long k_bi = 1; //operation times of iteractive binary search
        do{
            k_bi *= 2;
            start = clock(); //Start timing
            for(long long i=0; i<k_bi; i++){
                int bi = binary_iterative(arr, N, target); //Call the function to be tested
            }stop = clock(); //Stop timing
            d_bi = (double)(stop - start);
        }while(d_bi < 10);
        total_bi = d_bi / CLK_TCK;
        time_bi = d_bi / k_bi /CLK_TCK;

        long long k_br = 1; //operation times of recursive binary search
        do{
            k_br *= 2;
            start = clock(); //Start timing
            for(long long i=0; i<k_br; i++){
                int br = binary_recursive(arr, 0, N-1, target); //Call the function to be tested
            }stop = clock(); //Stop timing
            d_br = (double)(stop - start);
        }while(d_br < 10);
        total_br = d_br / CLK_TCK;
        time_br = d_br / k_br /CLK_TCK;

        printf("%d\t%.2e\t\t%.2e\t\t%.2e\t\t%.2e\n", N, time_si, time_sr, time_bi, time_br); //Print the single operation times in a table
        printf("K\t%lld\t%lld\t%lld\t%lld\n", k_si, k_sr, k_bi, k_br); //Print the iteration counts in a table
        printf("ticks\t%.2e\t%.2e\t%.2e\t%.2e\n", d_si, d_sr, d_bi, d_br); //Print the total clock ticks in a table
        printf("total time\t%.2e\t%.2e\t%.2e\t%.2e\n", total_si, total_sr, total_bi, total_br); //Print the total times in a table
    }
    return 0;
}
