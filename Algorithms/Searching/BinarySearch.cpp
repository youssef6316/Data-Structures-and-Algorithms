#include <iostream>
using namespace std;

void bsearch_iterative(int arr[], int size, int target){
    int low = 0;
    int high = size - 1;
    int iter = 0;
    bool found = false;
    while (low <= high){
        iter++;
        int mid = (low  + high) / 2;
        cout << "divide at " << arr[mid] << " at index " << mid <<endl;
        if (target < arr[mid]) high = (mid) - 1;
        else if (target > arr[mid]) low = (mid) + 1;
        else{
            found = true;
            cout << "target " << target << " found after " << iter << " breakdowns" << endl;
            break;
        }
    }
    
    if (!found) cout << "Target was not found in list after " << iter << " breakdowns " << endl;
}

int bsearch_recursive(int arr[], int low, int high, int target){
    if (low > high) return -1;

    int mid = (low  + high) / 2;
    if (target < arr[mid]) high = mid - 1;
    else if (target > arr[mid]) low = mid + 1;
    else{
        return mid;
    }

    return bsearch_recursive(arr, low, high, target);
}

int main() {
    int arr[] = {0,2,3,4,5,7,7,8,10,10,11,12,12,14,15,16,16,18,19,19};
    
    bsearch_iterative(arr, sizeof(arr) / sizeof(arr[0]), 0);
    bsearch_iterative(arr, sizeof(arr) / sizeof(arr[0]), 19);
    bsearch_iterative(arr, sizeof(arr) / sizeof(arr[0]), -5);

    cout << "--------------------------------------" << endl;

    cout << "target fuound at index " << bsearch_recursive(arr, 0, (sizeof(arr) / sizeof(arr[0])) - 1, 0) << endl;
    cout << "target fuound at index " << bsearch_recursive(arr, 0, (sizeof(arr) / sizeof(arr[0])) - 1, 15) << endl;
    cout << "target fuound at index " << bsearch_recursive(arr, 0, (sizeof(arr) / sizeof(arr[0])) - 1, 19) << endl;
    cout << "target fuound at index " << bsearch_recursive(arr, 0, (sizeof(arr) / sizeof(arr[0])) - 1, 25) << endl;


    return 0;
}