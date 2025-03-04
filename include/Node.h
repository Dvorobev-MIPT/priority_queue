template <typename T>
struct Node{
    T value;                            // Node value
    Node* left;                         // Pointer to the left node
    Node* right;                        // Pointer to the right node
    int height;                         // Node height

    Node(T value){
        this->value = value;
        this->left = this->right = nullptr;
        height = 1;
    }

    ~Node() {}
};
