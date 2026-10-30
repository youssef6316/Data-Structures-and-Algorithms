# include <iostream>
using namespace std;

class Node
{
private:
    int coeff;
    int power;
    Node *next;
public:
    Node(int coeff, int power){
        this->coeff = coeff;
        this->power = power;
        this->next = nullptr;
    };

    void setNode(Node *next){
        this->next = next;
    }

    Node* getNode(){
        return this->next;
    }

    ~Node(){};

    friend class Polynomial;


};

class Polynomial
{
private:
    Node *head;
public:
    Polynomial(){
        head = nullptr;
    }

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

    void pushFront(int coeff, int power){
        // // step1: create a new node to be head
        Node *new_head = new Node(coeff, power);

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
    
    void pushBack(int coeff, int power){
        // haandle empty list case
        if(this->empty()){
            Node *n = new Node(coeff, power);
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
            curr_node->next = new Node(coeff, power);
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

        if(!n) {
            cout << endl;
            return;
        }

        int coeff = n->coeff;
        int power = n->power;
        if(n->coeff != 0){
            if(n->power != 0){    
                if(n == this->head){
                    cout << "" <<coeff<< "*x" << "^" << power<<" ";
                }else{
                    cout << "+ " <<coeff<< "*x" << "^" << power<<" ";
                }
            }
            else coeff > 0? cout << "+ " <<coeff : cout << "- " <<abs(coeff);
        }
        print(n->next);
    }

    // helper function to prevent using the print functions using private data fields of class node as args
    void print(){
        print(head);
    }

    void clear(){
        while(!this->empty()) this->popBack();
    }

    // ==================polynomial related functions==================
    void construct(int coeffs[], int size){
        for(int i = 0; i < size; i++){
            pushBack(coeffs[i], size - 1 - i);
        }
    }

    void derivative(){
        Node *curr_node = head;
        while(curr_node->power != 0){
            curr_node->coeff *= curr_node->power;
            curr_node->power--;

            curr_node = curr_node->next;
        }
        curr_node->coeff = 0;
    }

    Polynomial* mult(Polynomial *sec){
        Polynomial *result = new Polynomial;
        int highest_order = this->head->power + sec->head->power;
        int coeffs[highest_order+1] ={0};
        Node *curr_node_st = this->head;
        while(curr_node_st){
            Node *curr_node_nd = sec->head;
            while(curr_node_nd){
                int coeff1 = curr_node_st->coeff;
                int coeff2 = curr_node_nd->coeff;

                int order1 = curr_node_st->power;
                int order2 = curr_node_nd->power;

                int product = coeff1 * coeff2;
                coeffs[highest_order - (order1 + order2)] += product;
                curr_node_nd = curr_node_nd->next;
            }
            curr_node_st = curr_node_st->next;
        }
        int size = sizeof(coeffs) / sizeof(coeffs[0]);
        result->construct(coeffs, size);
        return result;
    }

    ~Polynomial(){
        this->clear();
    };
};

int main() {

    Polynomial *poly1 = new Polynomial();
    int coeffs[] = {4, -2, 0, -1};
    int size = sizeof(coeffs) / sizeof(coeffs[0]);

    cout << "=== TESTING construct() ===" << endl;
    poly1->construct(coeffs, size);
    cout << "Expected: 4*x^3 - 2*x^2 - 1" << endl;
    cout << "Constructed: ";
    poly1->print();

    cout << "\n\n=== TESTING construct() for poly2 ===" << endl;
    Polynomial *poly2 = new Polynomial();
    int coeffs2[] = {10, 3, 3, 12, 7};
    int size2 = sizeof(coeffs2) / sizeof(coeffs2[0]);
    poly2->construct(coeffs2, size2);
    cout << "Expected: 10*x^4 + 3*x^3 + 3*x^2 + 12*x + 7" << endl;
    cout << "Constructed: ";
    poly2->print();

    cout << "\n\n=== TESTING mult() ===" << endl;
    Polynomial *result = poly1->mult(poly2);
    cout << "Result of multiplication: ";
    result->print();

    cout << "\n\n=== TESTING derivative() ===" << endl;
    cout << "Original poly2: ";
    poly2->print();
    cout << "After derivative: ";
    poly2->derivative();
    poly2->print();

    delete poly1;
    delete poly2;
    delete result;

    return 0;
}
