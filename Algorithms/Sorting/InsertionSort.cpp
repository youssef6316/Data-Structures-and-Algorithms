# include <iostream>
using namespace std;

void log_print(int i, int arr[], int size, int shifts){
    cout << "iteration: " << i << "  array : {" << arr[0];
    for(int j = 1; j < size; j++) cout << ", " << arr[j];
    cout << "}  shifts: " << shifts << endl; 
}

int Insertionsort_Iterative(int arr[], int size){
    log_print(0, arr, size, 0);
    int total_shifts = 0;
    for(int i = 1; i < size; i++){
        int shifts = 0;
        for (int j = i; j > 0; j--){
            if(arr[j] < arr[j-1]) {swap(arr[j], arr[j-1]); shifts++;}
        }
        total_shifts += shifts;
        log_print(i, arr, size, shifts);
    }
    return total_shifts;
}

int main(){

    int arr[10] = {8, 3, 7, 2, 9, 8, 1, 6, 5, 4};
    
    int size = sizeof(arr) / sizeof(arr[0]);

    int shifting_ops = Insertionsort_Iterative(arr, size);
    cout << shifting_ops << endl;

    return 0;
}