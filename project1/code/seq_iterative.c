//Iteractive  sequential search 
int seq_iterative(int arr[], int n, int target) {
    for(int i=0; i<n; i++) {
        if(arr[i]==target) {
            return i; // Target found at index i
        }
    }
    return -1; // Target not found
}
