# include <iostream>
using namespace std;

int get_min_recursive(int arr[], int size){

    // base case
    if(size == 1) return arr[0];

    // recursive case
    int temp_min = get_min_recursive(arr, size-1);
    return min(temp_min, arr[size-1]);
}

int get_min_iterative(int arr[], int size){
    int min = arr[0];
    for(int i = 0; i < size; i++){
        if (arr[i] < min) min = arr[i];
    }
    return min;
}

int main(){

    int arr[10] = {8, 3, 7, 2, 9, 10, 1, 6, 5, 4};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Min value in array (recursive): " << get_min_recursive(arr, size);
    cout << endl;
    cout << "Min value in array (iterative): " << get_min_iterative(arr, size);
    return 0;
}