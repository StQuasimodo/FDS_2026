//Iteractive binary search
int binary_iterative(int arr[], int n, int target) {
	int min=0, max=n-1;
	while(min<=max){
        int mid=(max+min)/2;
        if(arr[mid]==target){
            return mid; //Target found at mid
        }else if(arr[mid]<target){
            min=mid+1; //Iterate the lower bound of the interval
        }else{
            max=mid-1; //Iterate the upper bound of the interval
        }
    }
    return -1; //Target not found
}