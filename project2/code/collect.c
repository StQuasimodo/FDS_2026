//collect the values of the nodes in an array using inorder traversal
void collect(struct tree* node, long long* arr, int* index){
    if(node == NULL) {
        return;     //base case: if the current node is NULL, return from the function
    }
    collect(node->left, arr, index); //traverse the left subtree first
    arr[(*index)++] = node->data;  //store the value of the current node in the array and increase the index
    collect(node->right, arr, index); //traverse the right subtree after processing the current node
}

//remove repeated values from the array and return the new length of the array containing only unique elements
int unique(long long* arr, int len) {
    if (len == 0) {
        return 0;   //if the length of the array is 0, return 0 as there are no unique elements
    }

    int j = 0;

    //iterate through the array and keep only the unique elements by comparing each element with the last unique element found
    for (int i = 1; i < len; i++) {
        if (arr[i] != arr[j]) {
            j++;
            arr[j] = arr[i];
        }
    }
    return j + 1;
}