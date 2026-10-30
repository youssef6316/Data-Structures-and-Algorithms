# include <iostream>
#include <string>
using namespace std;

// static array implementation
class Stack{
    private:
        int arr[1000];
        
    public:    
        int size = 0;
        Stack(){
            this->size = 0;
        }
        int top(){
            if (size > 0) return arr[size-1];
            else return 0;
        }

        void push(int n){
            if (size < 1000) {
                size++;
                arr[size-1] = n;
            }
        }

        void pop(){
            if (size > 0){
                size--;
            }
        }

        // extra memeber functions
        bool is_full(){
            return this->size == 1000;
        }

        bool is_empty(){
            return size == 0;
        }

        bool is_equal(Stack second){
            Stack first = *this;  //cloning the object to freely edit its content for equality logic
            if(first.size == second.size){
                while(first.is_empty() && second.is_empty()){
                    if(first.top() != second.top()) break;
                    first.pop();
                    second.pop();
                }
            }
            return first.is_empty() && second.is_empty();
        }
};

int *duplicate_removal(int arr[], int size, int &unique_size){

    cout << "starting duplicates removal..." << endl;
    Stack unique_stack;
    unique_stack.push(arr[0]);

    for(int i = 1; i < size; i++){
        if(unique_stack.top() != arr[i]) unique_stack.push(arr[i]);
    }

    unique_size = unique_stack.size;    
    int *unique = new int [unique_stack.size];

    for(int i = 0; i < unique_size; i++){
        unique[unique_size - i - 1] = unique_stack.top();
        unique_stack.pop();
    }

    return unique;
}

int main(){
    // removing duplicates by from sorted array by stack
    int arr[] = {1,2,3,3,4,5,5,6,6,7,7,7,8,9,11,15,16,16,17,18,18,19,19};
    int size = sizeof(arr) / sizeof(arr[0]);

    int unique_size;
    int *unique_sorted = duplicate_removal(arr, size, unique_size);
    cout << "=======================================" << endl;
    cout << "array after removal of duplicates: " << endl;
    for(int i = 0; i < unique_size; i++){
        cout << unique_sorted[i] << " ";
    } 

    delete[] unique_sorted;

    return 0;
}