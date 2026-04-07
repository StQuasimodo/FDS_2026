//perform a preorder traversal of the tree and print the values of the nodes
void preorder(struct tree* root, int first){
    if(root == NULL) {
        return;
    }

    //print the value of the current node, ensuring that there is no extra space at the end of the output
    if(first){
        printf("%d", root->data);
        first = 0;
    }else{
        printf(" %d", root->data);
    }

    //traverse the left subtree first, then the right subtree
    preorder(root->left, 0);
    preorder(root->right, 0);
}

//find pairs of values from the two arrays that sum up to N using a two-pointer technique
int find_ab(long long* arr1, int len1, long long* arr2, int len2, long long N){
    int i = 0, j = len2 - 1;
    int found = 0;

    //use a two-pointer technique to find pairs of values from the two arrays that sum up to N
    while(i < len1 && j >= 0){
        long long sum = arr1[i] + arr2[j];

        //if a pair is found that sums up to N, print the pair and set the found flag to true
        if(sum == N){
            if(!found){
                printf("true\n");
                found = 1;
            }printf("%lld = %lld + %lld\n", N, arr1[i], arr2[j]); //print the pair of values that sum up to N
            i++;
            j--;
        } else if(sum < N){
            i++;    //if the sum of the current pair is less than N, move the left pointer to the right to increase the sum
        } else {
            j--;    //if the sum of the current pair is greater than N, move the right pointer to the left to decrease the sum
        }
    }
    return found;
}