# include <iostream>
using namespace std;

void RightPivot_QuickSort_Recursive(int arr[], int left, int right){

    if(left >= right) return;

    int pivot = arr[right];
    int start = left; 
    int end = right-1;

    while(start <= end){
        while(arr[start] <= pivot && start <= end) start++; //stops till reaching the first element > pivot
        while(arr[end] > pivot && end >= start) end--; //stops till reaching the first element > pivot

        if(start < end) swap(arr[start], arr[end]);
    }
    swap(arr[right], arr[start]);
    RightPivot_QuickSort_Recursive(arr, left, end);
    RightPivot_QuickSort_Recursive(arr, start+1, right);
}

void LeftPivot_QuickSort_Recursive(int arr[], int left, int right){

    if(left >= right) return;

    int pivot = arr[left];
    int start = left+1; 
    int end = right;
    while(start <= end){
        while(arr[start] <= pivot && start <= end) start++; //stops till reaching the first element > pivot
        while(arr[end] > pivot && end >= start) end--; //stops till reaching the first element < pivot

        if(start < end) swap(arr[start], arr[end]);
    }
    swap(arr[left], arr[end]);
    LeftPivot_QuickSort_Recursive(arr, left, end-1);
    LeftPivot_QuickSort_Recursive(arr, start, right);
}

int main(){

    int arr[10] = {8, 3, 7, 2, 9, 10, 1, 6, 5, 4};
    int size = sizeof(arr) / sizeof(arr[0]);

    LeftPivot_QuickSort_Recursive(arr, 0, size-1);

    cout << "Final sorted array: ";
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}