# include <iostream>
using namespace std;

void merge(int left_arr[], int left_size, int right_arr[], int right_size, int sorted_arr[]){

    int i = 0;
    int left_i = 0;
    int right_i = 0;
    while (left_i < left_size && right_i < right_size){
        if (left_arr[left_i] < right_arr[right_i]){
            sorted_arr[i++] = left_arr[left_i++];
        }
        else{
            sorted_arr[i++] = right_arr[right_i++];
        }   
    }
    
    // adding left overs from the other array after withdrawing all elements in the other
    while(left_i < left_size){
        sorted_arr[i] = left_arr[left_i];
        i++;
        left_i++;
    }
    while(right_i < right_size){
        sorted_arr[i] = right_arr[right_i];
        i++;
        right_i++;
    }

}

void merge_sort(int arr[], int size, int sorted_arr[]){

    if(size == 1) {sorted_arr[0] = arr[0]; return;}

    int mid = size/2;
    int *left_arr = new int[mid];
    int *right_arr = new int[size - mid];
    int *left_arr_sorted = new int[mid];
    int *right_arr_sorted = new int[size - mid];

    for (int i = 0; i < mid; i++)
        left_arr[i] = arr[i];
    for (int i = mid; i < size; i++)
        right_arr[i - mid] = arr[i];

    merge_sort(left_arr, mid, left_arr_sorted);
    merge_sort(right_arr, size - mid, right_arr_sorted);
    merge(left_arr_sorted, mid, right_arr_sorted, size - mid, sorted_arr);

    cout << "Array after sorting (" << size << "): ";
    for (int k = 0; k < size; k++)
        cout << sorted_arr[k] << " ";
    cout << endl;

    delete []left_arr;
    delete []right_arr;
    delete []left_arr_sorted;
    delete []right_arr_sorted;

}

int main(){

    int arr[10] = {8, 3, 7, 2, 9, 10, 1, 6, 5, 4};
    int *sorted_arr = new int[10];
    int size = sizeof(arr) / sizeof(arr[0]);

    merge_sort(arr, size, sorted_arr);

    delete []sorted_arr;
    return 0;
}