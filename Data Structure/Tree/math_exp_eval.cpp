# include <iostream>
# include <variant>
# include <string>
# include <cstdlib>
using namespace std;

class BinaryNode{
    private:
    string data;
    BinaryNode *left_child;
    BinaryNode *right_child;

    public:
    BinaryNode(){
        this->left_child = nullptr;
        this->right_child = nullptr;
    }
    BinaryNode(string c){
        this->data = c;
        this->left_child = nullptr;
        this->right_child = nullptr;
    }
    BinaryNode(string c, BinaryNode *left, BinaryNode *right){
        this->data = c;
        this->left_child = left;
        this->right_child = right;
    }

    void set_data(string c){ this->data = c; }
    void set_left_child(BinaryNode *node){ this->left_child = node; }
    void set_right_child(BinaryNode *node){ this->right_child = node; }

    string get_data(){ return this->data; }
    BinaryNode *get_left_child(){ return this->left_child; }
    BinaryNode *get_right_child(){ return this->right_child; }
    
    ~BinaryNode(){}

    friend class BinaryTree;
};

class BinaryTree{
    private:
        BinaryNode *root;
    public:
        BinaryTree(){
            this->root = nullptr;
        }
        BinaryTree(BinaryNode *node){
            this->root = node;
        }
        void inorder_Traversal(BinaryNode *node){
            if(node == nullptr) return;

            inorder_Traversal(node->get_left_child());
            cout << node->get_data() << " ";
            inorder_Traversal(node->get_right_child());
        }
        void preorder_Traversal(BinaryNode *node){
            if(node == nullptr) return;

            cout << node->get_data() << " ";
            preorder_Traversal(node->get_left_child());
            preorder_Traversal(node->get_right_child());
        }
        void postorder_Traversal(BinaryNode *node){
            if(node == nullptr) return;

            postorder_Traversal(node->get_left_child());
            postorder_Traversal(node->get_right_child());
            cout << node->get_data() << " ";
        }

        // helper function to call suitable traversal technique
        void postorder_Traversal(){
            postorder_Traversal(root);
        }
        void inorder_Traversal(){
            inorder_Traversal(root);
        }
        void preorder_Traversal(){
            preorder_Traversal(root);
        }

        int eval(BinaryNode *node){
            // handeling empty tree case
            if(node == nullptr) return 0;

            // base case : "leaf node reached"
            if(node->get_left_child() == nullptr && node->get_right_child() == nullptr) return stoi(node->get_data());

            // recursive case
            if(node->get_data() == "+") return eval(node->get_left_child()) + eval(node->get_right_child());
            if(node->get_data() == "-") return eval(node->get_left_child()) - eval(node->get_right_child());
            if(node->get_data() == "*") return eval(node->get_left_child()) * eval(node->get_right_child());
            if(node->get_data() == "/") return eval(node->get_left_child()) / eval(node->get_right_child());
        }

        int eval(){
            return eval(root);
        }

        int leaf_count(BinaryNode *node){
            if(node->left_child == nullptr && node->right_child == nullptr) return 1;

            int count = 0;
            return leaf_count(node->left_child) + leaf_count(node->right_child);
            return count;
        }

        int leaf_count(){
            return leaf_count(root);
        }

        ~BinaryTree(){
            destroy(root);
        }

        void destroy(BinaryNode* node){
            if(node == nullptr) return;
            destroy(node->left_child);
            destroy(node->right_child);
            delete node;
        }
};


int main(){
    /*
    Tree Example Structure
    
            +
        /       \
       *         +
      / \       / \
     2   -     3   *
        / \       / \
       10  7     2   4

    */

    // constructing right sub tree
    BinaryNode *leaf10 = new BinaryNode("10"); 
    BinaryNode *leaf7 = new BinaryNode("7"); 
    BinaryNode *minus = new BinaryNode("-", leaf10, leaf7);
    
    BinaryNode *left_leaf_2 = new BinaryNode("2"); 
    BinaryNode *left_mult = new BinaryNode("*", left_leaf_2, minus); 
    
    // constructing left sub tree
    BinaryNode *right_leaf_2 = new BinaryNode("2"); 
    BinaryNode *leaf4 = new BinaryNode("4"); 
    BinaryNode *right_mult = new BinaryNode("*", right_leaf_2, leaf4); 

    BinaryNode *leaf3 = new BinaryNode("3"); 
    BinaryNode *right_add = new BinaryNode("+", leaf3, right_mult); 

    BinaryNode *root = new BinaryNode("+", left_mult, right_add);

    BinaryTree *tree = new BinaryTree(root);
    
    cout << "inorder traversal: ";
    tree->inorder_Traversal();

    cout << endl;
    
    cout << "preorder traversal: ";
    tree->preorder_Traversal();
    
    cout << endl;

    cout << "postorder traversal: ";
    tree->postorder_Traversal();

    cout << endl;

    cout << "==========================" << endl;

    cout << "evaluation of the tree's expression: " << tree->eval() << endl;

    cout << "==========================" << endl;

    cout << "no. of leaves in tree: " << tree->leaf_count() << endl;

    return 0;
}