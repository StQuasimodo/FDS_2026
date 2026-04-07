//Recursive binary search
int binary_recursive(int arr[], int min, int max, int target){
    if(min>max){
        return -1; //Invalid inputs
    }
    int mid=(min+max)/2;
    if(arr[mid]==target){
        return mid; //Target found at mid
    }else if(arr[mid]<target){
        return binary_recursive(arr, mid+1, max, target); //Recursive call for the upper half of the interval
    }else{
        return binary_recursive(arr, min, mid-1, target); //Recursive call for the lower half of the interval
    }
    return -1; //Target not found
}