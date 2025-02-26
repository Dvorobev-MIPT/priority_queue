template <typename T>
struct Node{
    T value;                          // Значение узла
    Node* left;                         // указатель на левый узел
    Node* right;                        // Указатель на правый узел
    int height;                         // высота узла

    Node(T value){
        this->value = value;
        this->left = this->right = nullptr;
        height = 1;
    }

    ~Node() {}
};
