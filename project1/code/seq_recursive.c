//Recursive sequential search
int seq_recursive(int arr[], int n, int target, int index) {
    if(index>=n) {
        return -1; // Target not found
    }
    if(arr[index]==target) {
        return index; // Target found at index
    }
    return seq_recursive(arr, n, target, index + 1); // Recursive call for the next index
}