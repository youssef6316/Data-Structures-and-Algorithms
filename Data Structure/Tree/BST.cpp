# include <iostream>
using namespace std;

class BinaryNode{
    private:
    int data;
    BinaryNode *left_child;
    BinaryNode *right_child;

    public:
    BinaryNode(){
        this->left_child = nullptr;
        this->right_child = nullptr;
    }
    BinaryNode(int d){
        this->data = d;
        this->left_child = nullptr;
        this->right_child = nullptr;
    }
    BinaryNode(int c, BinaryNode *left, BinaryNode *right){
        this->data = c;
        this->left_child = left;
        this->right_child = right;
    }

    void set_data(int c){ this->data = c; }
    void set_left_child(BinaryNode *node){ this->left_child = node; }
    void set_right_child(BinaryNode *node){ this->right_child = node; }

    int get_data(){ return this->data; }
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

        BinaryNode *search(BinaryNode *node, int data){
            // base case: node with the data is found or traversal failed to find it reaching child of a leaf node
            if(node->get_data() == data || node == nullptr) return node;

            // recursive case:
            if(data <= node->get_data()) return search(node->get_left_child(), data);
            if(data > node->get_data()) return search(node->get_right_child(), data);
        }

        BinaryNode *search(int data){
            return search(root, data);
        }

        BinaryNode *insert(BinaryNode *node, int data){
            // base case: reached place where node is to be placed
            if(node == nullptr) return new BinaryNode(data);

            // recursive case:
            if(data <= node->get_data()) node->set_left_child(insert(node->get_left_child(), data));
            else(data > node->get_data()) node->set_right_child(insert(node->get_right_child(), data));

            return node;
        }

        BinaryNode *insert(int data){
            return insert(root, data);
        }

        int min_node(BinaryNode *node){
            if (node->get_left_child() == nullptr || node == nullptr) return node->get_data();

            return min_node(node->get_left_child());
        }

        int max_node(BinaryNode *node){
            if (node->get_right_child() == nullptr || node == nullptr) return node->get_data();

            return max_node(node->get_right_child());
        }

        int min_node(){
            return min_node(root);
        }

        int max_node(){
            return max_node(root);
        }

        BinaryNode *delete_node(BinaryNode *node, int val_del){

            if(val_del > node->get_data()) delete_node(node->get_right_child(), val_del);
            else if(val_del < node->get_data()) delete_node(node->get_left_child(), val_del);
            else{
                // if node has no childs
                if(node->get_left_child() == nullptr && node->get_right_child() == nullptr){
                    delete (node);
                    return NULL;
                }

                // if node has one child
                if (node->get_left_child() == nullptr){
                    BinaryNode *temp;
                    temp = node->get_right_child();
                    delete (node);
                    return temp;
                }

                if (node->get_right_child() == nullptr){
                    BinaryNode *temp;
                    temp = node->get_left_child();
                    delete (node);
                    return temp;
                }

                // if node has 2 or more childs -> get the inorder successor:
                //      (highest left child or lowest right child)

                //find the min of the value in the right subtree
                int temp = min_node(node->get_right_child());  
                
                //set the value in the node ot be deleted with the inorder successor
                node->set_data(temp);                        

                //reset the right subtree without the successor node to prevent duplicating
                node->set_right_child(delete_node(node, temp));

            }
            return node;
        }

        void delete_node(int val_del){
            delete_node(root, val_del);
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

        int height(BinaryNode *node, int height_left, int height_right){
            if (node == nullptr) return;

            height_left = height(node->get_left_child(), height_left+1);
            height_right = height(node->get_right_child(), height_right+1);
            return max(height_left, height_right);
        }

        int height(){
            return height(root, 0, 0);
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