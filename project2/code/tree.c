#include<stdio.h>
#include<stdlib.h>

//define the structure of a tree node
struct tree{
    long long data;
    struct tree *left;
    struct tree *right;
};

//create a new tree node with the given data and return a pointer to it
struct tree *create(long long data){
    struct tree* node = (struct tree*)malloc(sizeof(struct tree)); //allocate memory for a new tree node
    node->data = data; //set the data of the node to the given value
    node->left = NULL;
    node->right = NULL; //initialize the left and right child pointers to NULL
    return node;
}

//build a binary tree from the input data, where each node's value and its parent's index are provided
struct tree* build_tree(int n){
    if(n == 0){
        return NULL;    //if the number of nodes is 0, return NULL as there is no tree to build
    }
    struct tree** nodes = (struct tree**)malloc(n * sizeof(struct tree*)); //allocate memory for an array of tree node pointers
    int* parent_index = (int*)malloc(n * sizeof(int)); //allocate memory for an array to store the parent indices of the nodes

    int iroot = -1;
    long long p;
    int q;
    //read the input for each node, create the node, and store its parent index
    for(int i=0; i<n; i++){
        scanf("%lld %d", &p, &q);
        nodes[i] = create(p);
        parent_index[i] = q;
        if(q == -1){
            iroot = i;
        }
    }

    //construct the tree by linking the nodes according to their parent indices
    for(int i=0; i<n; i++){
        if(parent_index[i] != -1){
            int parent = parent_index[i]; //find the parent node of the current node
            if(nodes[parent]->data > nodes[i]->data){
                nodes[parent]->left = nodes[i];     //link the current node as the left child of its parent if its value is less than the parent's value
            } else {
                nodes[parent]->right = nodes[i];    //link the current node as the right child of its parent if its value is greater than or equal to the parent's value
            }
        }
    }
    struct tree* root = nodes[iroot]; //the root of the tree is the node whose parent index is -1
    //free the memory allocated for the arrays of node pointers and parent indices
    free(nodes);
    free(parent_index);
    return root;
}

//free the memory allocated for the tree nodes to avoid memory leaks
void free_tree(struct tree* node){
    if(node == NULL) {
        return;
    }

    //recursively free the left and right subtrees to avoid memory leaks
    free_tree(node->left);
    free_tree(node->right);
    //free the memory allocated for the current node
    free(node);
}