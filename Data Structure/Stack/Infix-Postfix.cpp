#include <bits/stdc++.h>

using namespace std;

int precedence(char op) {
        if (op == '~') return 3;
        if (op == '&') return 2;
        if (op == '|') return 1;
        if (op == '>') return 0;
        return -1;
}

string infix_to_postix(string infix){
    string postfix = "";
    stack <char> stack;
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
            while(!stack.empty() && precedence(infix[i]) <= precedence(stack.top())){
                cout << infix[i] << " has lower or equal precedence than " << stack.top() << endl;
                cout << "popping " << stack.top() << " from stack and replacing it with " << infix[i] << endl;
                postfix += stack.top();
                stack.pop();
            }
            stack.push(infix[i]);
        }
    }
    while(!stack.empty()){
        cout << "popping the remaining operator " << stack.top() << endl;
        postfix += stack.top();
        stack.pop();
    }
    cout << "End of postfix operation" << endl;
    return postfix;
}

bool operation(bool op1, bool op2, char sign){
    if(sign == '>') return !op2 || op1;
    if(sign == '&') return op2 && op1;
    if(sign == '/') return op2 || op1;
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
    cout << endl;
    cout << "============================= Task1 =============================" << endl;
    cout << "****************Validity & Satisfiability Checker****************" << endl;
    cout << endl;
    cout << "-----------------------------------------------------------------" << endl;
    cout << endl;
    
    
    
    return 0;
}