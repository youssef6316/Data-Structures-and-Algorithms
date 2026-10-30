# include <iostream>
using namespace std;

class Node
{
private:
    int data;
    Node *next;
public:
    Node(int data){
        this->data = data;
        this->next = nullptr;
    };

    void setNode(Node *next){
        this->next = next;
    }

    Node* getNode(){
        return this->next;
    }

    ~Node(){};

    friend class LinkedList;


};

class LinkedList
{
private:
    Node *head;
public:
    LinkedList(){
        head = nullptr;
    };

    bool empty(){
        return head == nullptr;
    }

    int length(){
        Node *curr_node = head;
        int length = 0;
        while(curr_node){ // breaks when curr_node == nullptr (last node points to nothing)
            length++;
            curr_node = curr_node->next; // equivalent to (*curr_node).next --> (*ptr) = derefrencing(returns the bject itself)
        }
        return length;
    }

    void pushFront(int d){
        // // step1: create a new node to be head
        Node *new_head = new Node(d);

        // // step2: set new_head to point to the old head
        new_head->setNode(head);

        // // step3: set the head of list to point to the new head
        this->head = new_head;
    }

    void popFront(){
        // handle empty list case
        if(this->empty()) return;
        
        // get the ptr of the old head to delete it
        Node *old_head = head;
        // change the value stored at the head ptr to point to the sec node before deleting the old head
        head = head->next;
        delete old_head;
    }
    
    void pushBack(int d){
        // haandle empty list case
        if(this->empty()){
            Node *n = new Node(d);
            this->head = n;
            
            // other option: 
            // this->pushFront(d)
        }
        else{
            Node *curr_node = head;
            while(curr_node->next){
                curr_node = curr_node->next;
            }
            // curr_node after loop is at last node with a nullptr in the next data field
            curr_node->next = new Node(d);
        }
    }
    
    void popBack(){
        // handle empty list case
        if(this->empty()) return;

        // handle length = 1 case
        if(!head->next) {
            delete head;
            head = nullptr;
            return;
        }

        Node *pre_last = nullptr;
        Node *last = head;
        while(last->next){
            pre_last = last;
            last = last->next;
        }
        delete last;
        pre_last->next = nullptr;
    }

    void print(Node *n){

        if(!n) return;

        int d = n->data;
        cout << d << " ";
        print(n->next);
    }

    // helper function to prevent using the print functions using private data fields of class node as args
    void print(){
        print(head);
    }

    void printReverse(Node *n){

        if(!n) return;

        int d = n->data;
        print(n->next);
        cout << d << " ";
    }

    void printReverse(){
        printReverse(head);
    }

    bool contains(int d){
        Node *curr_node = head;
        bool is_found = false;

        while (curr_node)
        {
            if(curr_node->data == d){
                is_found = true;
                break;
            }
            curr_node = curr_node->next;
        }
        
        return is_found;
    }

    void clear(){
        while(!this->empty()) this->popBack();
    }

    void bubbleSort(){
        if (!head || !head->next) return; //handeling empty or length = 1 cases

        bool is_swapped;
        Node * endNode = nullptr;
        while(endNode != head){
            is_swapped = false;
            Node *first = head;
            Node *second = head->next;
            while(second != endNode){
                if(first->data > second->data){
                    int temp = second->data;
                    second->data = first->data;
                    first->data = temp;
                    is_swapped = true;
                }
                first = first->next;
                second= second->next;
            }
            endNode = first;
            if(!is_swapped) break;
        }
    }

    void selectionSort(){
        Node *pos = head;
        while (pos)
        {// loopt to iterate for each position in the list to find the nth min and place it in correct position
            Node *min_d = pos;
            Node *i = pos->next;
            while(i){ //looop iterates to find the minimum data value among all
                if(i->data < min_d->data) min_d = i;
                i = i->next;
            }
            int temp = min_d->data;
            min_d->data = pos->data;
            pos->data = temp;
            pos = pos->next;
        }
    }

    ~LinkedList(){
        this->clear();
    };
};

int main() {
    LinkedList list;

    cout << "=== TESTING LINKED LIST IMPLEMENTATION ===\n\n";

    cout << "1️.Check if list is empty initially: ";
    cout << (list.empty() ? "✅ Empty\n" : "❌ Not empty\n");

    cout << "\n2️.Pushing elements at the back...\n";
    list.pushBack(10);
    list.pushBack(5);
    list.pushBack(20);
    list.pushBack(15);
    list.pushBack(2);

    cout << "List elements (expected 10 5 20 15 2): ";
    list.print(); cout << "\n";

    cout << "\n3️.Pushing element at the front (42)...\n";
    list.pushFront(42);
    cout << "List after pushFront: ";
    list.print(); cout << "\n";

    cout << "\n4️.Current length: " << list.length() << "\n";

    cout << "\n5️.Checking if value 20 exists: ";
    cout << (list.contains(20) ? "✅ Found\n" : "❌ Not found\n");

    cout << "Checking if value 99 exists: ";
    cout << (list.contains(99) ? "✅ Found\n" : "❌ Not found\n");

    cout << "\n6️.Popping one element from front...\n";
    list.popFront();
    cout << "List after popFront: ";
    list.print(); cout << "\n";

    cout << "\n7️.Popping one element from back...\n";
    list.popBack();
    cout << "List after popBack: ";
    list.print(); cout << "\n";

    cout << "\n8️.Print list in reverse order: ";
    list.printReverse(); cout << "\n";

    cout << "\n9️.Testing bubble sort...\n";
    list.bubbleSort();
    cout << "List after bubble sort (ascending): ";
    list.print(); cout << "\n";

    cout << "\n10.Adding more unsorted data for selection sort test...\n";
    list.pushBack(50);
    list.pushBack(7);
    list.pushBack(13);
    list.pushBack(1);
    cout << "Before selection sort: ";
    list.print(); cout << "\n";

    list.selectionSort();
    cout << "After selection sort: ";
    list.print(); cout << "\n";

    cout << "\n1️1️.Clearing list...\n";
    list.clear();
    cout << "Is list empty after clear? " << (list.empty() ? "✅ Yes" : "❌ No") << "\n";

    cout << "\n=== ALL TESTS COMPLETED ===\n";

    return 0;
}