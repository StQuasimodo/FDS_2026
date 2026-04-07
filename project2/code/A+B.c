#include<stdio.h>
#include<stdlib.h>

#include "tree.c"
#include "collect.c"
#include "output.c"


int main(){
    int n;
    scanf("%d", &n);
    struct tree* root1 = build_tree(n); //build the first tree using the input data

    int m;
    scanf("%d", &m);
    struct tree* root2 = build_tree(m); //build the second tree using the input data

    long long N;
    scanf("%lld", &N); //read the target sum N

    //collect the values of the nodes in the first tree into an array and remove duplicates
    long long* arr1 = (long long*)malloc(n * sizeof(long long));
    int index1 = 0;
    collect(root1, arr1, &index1);
    index1 = unique(arr1, index1);

    //collect the values of the nodes in the second tree into an array and remove duplicates
    long long* arr2 = (long long*)malloc(m * sizeof(long long));
    int index2 = 0;
    collect(root2, arr2, &index2);
    index2 = unique(arr2, index2);

    //check if there exists a pair of values from the two arrays that sum up to N 
    //if such a pair exists, print "true" and the pairs; otherwise, print "false"
    if(!find_ab(arr1, index1, arr2, index2, N)){
        printf("false\n");
    }

    //print the preorder traversal of thefirst tree
    preorder(root1, 1);
    printf("\n");

    //print the preorder traversal of the second tree
    preorder(root2, 1);
    printf("\n");

    //free the memory allocated for the arrays and the trees to avoid memory leaks
    free(arr1);
    free(arr2);
    free_tree(root1);
    free_tree(root2);

    return 0;
}




