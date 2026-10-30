#include <iostream>
using namespace std;

int get_min_idx(int arr[], int size, int i){

    if(i == size) return i;

    int temp_min_idx = get_min_idx(arr, size, i+1);
    if(arr[i] < arr[temp_min_idx]) return i;
    else return temp_min_idx;

}

void SelectionSort_Recursive(int arr[], int size, int pos){

    if(size == pos) return;

    int idx = get_min_idx(arr, size, pos);
    swap(arr[idx], arr[pos]);

    SelectionSort_Recursive(arr, size, pos+1);
}


int main(){

    int arr[] = {2,5,-3,4,8,1,6,5,16,68,15,65};
    int size = sizeof(arr) / sizeof(arr[0]); 

    SelectionSort_Recursive(arr, size, 0);

    cout << "Final sorted array: ";
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;


    // cout << get_min_idx(arr, 0, size-1) << endl;

    return 0;
}