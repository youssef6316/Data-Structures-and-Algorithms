# include <iostream>
#include <string>
#include <stack>
using namespace std;

// static array implementation
class Stack{
    private:
        char arr[1000];
        
    public:    
        int size = 0;
        Stack(){
            this->size = 0;
        }
        char top(){
            if (size > 0) return arr[size-1];
            else return ' ';
        }

        void push(char n){
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

int precedence(char op){
    if(op == '+' || op == '-'){return 1;}
    if(op == '*' || op == '/'){return 2;}
    if(op == '^') return 3;
    return 0;
}

string infix_to_postix(string infix){
    string postfix = "";
    Stack stack;
    cout << "Starting postfix operation..." << endl;
    cout << "----------------------------------------------------" << endl;
    for (int i = 0; i < infix.size(); i++){
        if(isalnum(infix[i])) {postfix += infix[i]; cout << infix[i] <<" operand was detected" << endl;}
        else if(infix[i] == '(') {stack.push(infix[i]); cout << infix[i] << " was detected" << endl;}
        else if(infix[i] == ')'){
            cout << infix[i] << " was detected" << endl;
            while(stack.top() != '('){
                postfix += stack.top();
                cout << "operand " <<  stack.top() << " was popped from stack & added to postfix" << endl;
                stack.pop();
            }
            stack.pop();
            cout << "( is popped from stack" << endl;
        }
        else{
            cout << "checking precedence between operators..." << endl;
            while(!stack.is_empty() && precedence(infix[i]) <= precedence(stack.top())){
                cout << infix[i] << " has lower or equal precedence than " << stack.top() << endl;
                cout << "popping " << stack.top() << " from stack and replacing it with " << infix[i] << endl;
                postfix += stack.top();
                stack.pop();
            }
            stack.push(infix[i]);
        }
    }
    while(!stack.is_empty()){
        cout << "popping the remaining operator " << stack.top() << endl;
        postfix += stack.top();
        stack.pop();
    }
    cout << "End of postfix operation" << endl;
    return postfix;
}

float operation(float op1, float op2, char sign){
    if(sign == '+') return op2 + op1;
    if(sign == '-') return op2 - op1;
    if(sign == '*') return op2 * op1;
    if(sign == '/') return op2 / op1;
    return 0;
}

int postfix_evaluate(string postfix){
    int result = 0;
    int op1 = 0;
    int op2 = 0;
    stack <int> st;
    cout << "Starting postfix operation..." << endl;
    for (int i = 0; i < postfix.size(); i++){
        if(isalnum(postfix[i])) st.push(postfix[i] - 48);
        else{
            op1 = float(st.top());
            cout << "operand1: " << op1 << endl;
            st.pop();
            op2 = float(st.top());
            cout << "operand2: " << op2 << endl;
            st.pop();
            result = operation(op1, op2, postfix[i]);
            cout << "result: " << op2 << postfix[i] << op1 << "=" << result << endl;
            st.push(result);
        }
    }
    cout << "End of postfix operation" << endl;
    return st.top();
}

int main(){
    // infix to postfix using stack
    string infix = "(-b+(b*b-4*a*c)^(1/2))/(2*a)";
    string postfix = infix_to_postix(infix);
    // cout << postfix << endl;

    cout << "=========================================" << endl;

    //postfix to infix using stack
    cout << "result of postfix: " << postfix_evaluate(postfix) << endl;
    return 0;
}