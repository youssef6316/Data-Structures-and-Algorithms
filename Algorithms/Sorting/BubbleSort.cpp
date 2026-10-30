# include <iostream>
using namespace std;

void Bubblesort_Iterative(int arr[], int size){
    for(int j = 0; j < size; j++){
        for(int i = 0; i < size-1; i++){
            if(arr[i] > arr[i+1]) swap(arr[i], arr[i+1]);
        }
    }
}

void Bubblesort_Recursive(int arr[], int size){
    
    if(size == 1) return;

    for(int i = 0; i < size-1; i++){
            if(arr[i] > arr[i+1]) swap(arr[i], arr[i+1]);
    }
    
    Bubblesort_Recursive(arr, size-1);
}

int main(){

    int arr[10] = {8, 3, 7, 2, 9, 10, 1, 6, 5, 4};
    
    int size = sizeof(arr) / sizeof(arr[0]);

    Bubblesort_Recursive(arr, size);

    cout << "Final sorted array: ";
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}