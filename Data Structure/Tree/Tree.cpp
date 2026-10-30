# include <iostream>
# include <vector>
using namespace std;

class Node{
    private:
    int data;
    vector <Node *> children; //vector of pointers pointing toward chidren nodes
    friend Tree;
    public:

};

class Tree{
    private:
    Node * root;
    public:

};

class BinaryNode{
    private:
    int data;
    BinaryNode *left_child;
    BinaryNode *right_child;

    friend BinaryTree;
    public:
};

class BinaryTree{
    private:
        BinaryNode *root;
    public:
        void inorder_Traversal(BinaryNode *node){
            if(node == nullptr) return;

            inorder_Traversal(node->left_child);
            cout << node->data << "->";
            inorder_Traversal(node->right_child);
        }
        void preorder_Traversal(BinaryNode *node){
            if(node == nullptr) return;

            cout << node->data << "->";
            preorder_Traversal(node->left_child);
            preorder_Traversal(node->right_child);
        }
        void postorder_Traversal(BinaryNode *node){
            if(node == nullptr) return;

            postorder_Traversal(node->left_child);
            postorder_Traversal(node->right_child);
            cout << node->data << "->";
        }

        // helper function to call suitable traversal technique
        void traversal(){
            cout << "choose between preorder - postorder - inorder traversals" << endl;
            string type;
            cin >> type;
            if (type == "preorder") preorder_Traversal(root);
            else if (type == "postorder") postorder_Traversal(root);
            else if (type == "inorder") inorder_Traversal(root);
            else{
                cout << "wrong chosen traversal type" << endl;
            }
        }

        int leaf_count(BinaryNode *node){
            if(node->left_child == nullptr || node->right_child == nullptr) return 1;

            int count = 0;
            count += leaf_count(node->left_child);
            count += leaf_count(node->right_child);
            return count;
        }
};


int main(){
    
    return 0;
}