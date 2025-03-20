    #ifndef TREE_RLS
    #define TREE_RLS

    #include "Vector.h"
    #include <iostream>

    // realisation

    template <typename T>
    Tree<T>::Tree(): tree_root(nullptr) {};

    template <typename T>
    Node<T>* Tree<T>::RightTurn(Node<T>* root){
        Node<T>* new_root = root->left;
        root->left = new_root->right;
        new_root->right = root;
        HeightCorrect(root);
        HeightCorrect(new_root);
        return new_root;
    }

    template <typename T>
    Node<T>* Tree<T>::LeftTurn(Node<T>* root){
        Node<T>* new_root = root->right;
        root->right = new_root->left;
        new_root->left = root;
        HeightCorrect(root);
        HeightCorrect(new_root);
        return new_root;
    }

    template <typename T>
    Node<T>* Tree<T>::RightBigTurn(Node<T>* root){
        root->left = LeftTurn(root->left);
        return RightTurn(root);
    }

    template <typename T>
    Node<T>* Tree<T>::LeftBigTurn(Node<T>* root){
        root->right = RightTurn(root->right);
        return LeftTurn(root);
    }

    template <typename T>
    Node<T>* Tree<T>::Balance(Node<T>* root){
        if (root == nullptr) return nullptr;
        HeightCorrect(root);
        if(BalanceFactor(root) == 2) {
            if (BalanceFactor(root->right) < 0) return LeftBigTurn(root);
            else return LeftTurn(root);
        }
        else if (BalanceFactor(root) == -2) {
            if (BalanceFactor(root->left) > 0) return RightBigTurn(root);
            else return RightTurn(root);
        }

        return root;
    }

    template <typename T>
    Node<T>* Tree<T>::Insert(Node<T>* root, T const &key){
        if (root == nullptr) {
            return new Node<T>(key); // Allocate new node
        }
        if (key < root->value) {
            root->left = Insert(root->left, key);
        } else {
            root->right = Insert(root->right, key);
        }
        tree_root = Balance(root); // Balance the tree
        return tree_root;
    }

    template <typename T>
    Node<T>* Tree<T>::Pop(Node<T>* root, T const &value){
        if (root == nullptr) {
            return nullptr;             // If node not found -> return nptr
        }

        // Find node for pop
        if (value < root->value) {
            root->left = Pop(root->left, value);        // Find in left subtree
        } 
        else if (value > root->value) {
            root->right = Pop(root->right, value);      // Find in right subtree
        } 
        else {
            // If node found, delete node
            if (root->left == nullptr) {
                Node<T>* temp = root->right;
                delete root;
                return temp;                     // Return right subtree
            } 
            else if (root->right == nullptr) {
                Node<T>* temp = root->right;
                delete root;
                return temp;                    // Return right subtree
            } 
            else {
                // If node have 2 subnode
                Node<T>* temp = GetMin(root->right);    // Get min node from right subtree
                if (temp != nullptr) {
                    root->value = temp->value;          // Replace root valude
                    root->right = Pop(root->right, temp->value); // Delete node with min value
                }
            }
        }

        // Updating the node height and balancing the tree
        HeightCorrect(root);
        root = Balance(root);
        tree_root = root;
        return root; 
    }



    template <typename T>
    int Tree<T>::BalanceFactor(Node<T>* node) const {
        return (Height(node->right) - Height(node->left));
    }

    template <typename T>
    int Tree<T>::Height(Node<T>* node) const {
        return (node ? node->height : 0);
    }

    template <typename T>
    void Tree<T>::HeightCorrect(Node<T>* node) const {
        if (node != nullptr){
            int left_height = Height(node->left);
            int right_height = Height(node->right);
            node->height = (left_height > right_height ? left_height : right_height) + 1;
        }
    }

    template <typename T>
    int Tree<T>::NumberOfSegmentElements(Node<T>* elem, T const &min, T const &max) const {
        if (elem == nullptr) {
            return 0; // If node is empty, returns 0;
        }
        int count = 0;
        // Checking the left subtree
        if (elem->value > min) {
            count += NumberOfSegmentElements(elem->left, min, max);
        }
        // Checking the current value
        if (elem->value >= min && elem->value <= max) {
            count += 1;
        }
        // Checking the right subtree
        if (elem->value < max) {
            count += NumberOfSegmentElements(elem->right, min, max);
        }

        return count;
    }

    template <typename T>
    void Tree<T>::DeleteTree(Node<T>* node){
        if (node != nullptr) {
            // Recursively deleting the left and right subtrees
            if (node->left != nullptr){
                DeleteTree(node->left);
            }
            if (node->right != nullptr){
                DeleteTree(node->right);
            }
            delete node;
        }
        tree_root = nullptr;
    }


    template <typename T>
    Node<T>* Tree<T>::Find(Node<T>* root, T const &value) const {
        if (!root){
            return nullptr;
        }
        if (value == root->value){
            return root;
        }
        else if (value < root->value){
            return Find(root->left, value);
        }
        else{
            return Find(root->right, value);
        }
    }

    template <typename T>
    Node<T>* Tree<T>::GetMin(Node<T>* root) const {
        if (root == nullptr){
            return nullptr;
        }
        while (root->left){
            root = root->left;
        }
        return root;
    }
    
    template <typename T>
    Node<T>* Tree<T>::GetMax(Node<T>* root) const {
        if (root == nullptr){
            return nullptr;
        }
        while (root->right){
            root = root->right;
        }
        return root;
    }

    template <typename T>
    void Tree<T>::PrintTree(Node<T>* root) const {
        if (root == nullptr) {
            return; // If node is empty -> return (break)
        }
        PrintTree(root->left);
        std::cout << root->value << " ";
        PrintTree(root->right);
    }

    template <typename T>
    Node<T>* Tree<T>::Merge(Node<T>* root, Node<T>* other){
        if (other == nullptr) {
            return root; // If node is nptr -> return nptr
        }
        root = Merge(root, other->left);
        root = Insert(root, other->value);
        root = Merge(root, other->right);
        return root;
    }

    
    template <typename T>
    Tree<T>::~Tree(){
        DeleteTree(tree_root);
    }

    #endif  