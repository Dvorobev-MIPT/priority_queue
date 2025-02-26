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
    //    root->left = Balance(root->left);
    //    root->right = Balance(root->right);
        return root;
    }

    template <typename T>
    Node<T>* Tree<T>::Insert(Node<T>* root, T key) {
        // Стек для хранения узлов
        Vector<Node<T>*> nodeStack;
        Node<T>* current = root;

        // Поиск места для вставки
        while (current) {
            nodeStack.PushBack(current);
            if (key < current->value) {
                current = current->left;
            } else {
                current = current->right;
            }
        }

        // Вставка нового узла
        Node<T>* newNode = new Node<T>(key);
        if (nodeStack.Empty()) {
            tree_root = newNode;
            return newNode; // Дерево было пустым
        }

        Node<T>* parent = nodeStack.Back();
        if (parent){
        if (key < parent->value) {
            parent->left = newNode;
        } else {
            parent->right = newNode;
        }
        }

        // Обновляем высоты и проверяем балансировку
        for (int i = nodeStack.Size() - 1; i >= 0; --i) {
            Node<T>* node = nodeStack[i];

            // Обновляем высоту узла
            HeightCorrect(node);

            // Получаем баланс узла
            Node<T>* balancedNode = Balance(node); // Изменил имя переменной на balancedNode
            // Если это не корень, обновляем ссылку родителя
            if (i > 0) {
                Node<T>* parent = nodeStack[i - 1];
                if (balancedNode->value < parent->value) {
                    parent->left = balancedNode;
                } else {
                    parent->right = balancedNode;
                }
            } else {
                // Если это корень, обновляем root
                root = balancedNode;
            }
        }

        // Удаление newNode здесь не нужно, так как он уже вставлен в дерево
        // delete[] newNode; // Удаляем эту строку

        // Обновляем высоту корня
        HeightCorrect(root);
        tree_root = root;
        return root;
    }

    template <typename T>
    Node<T>* Tree<T>::Pop(Node<T>* root, T value) {
        if (root == nullptr) {
            return nullptr; // Узел не найден
        }

        // Ищем узел для удаления
        if (value < root->value) {
            root->left = Pop(root->left, value); // Ищем в левом поддереве
        } 
        else if (value > root->value) {
            root->right = Pop(root->right, value); // Ищем в правом поддереве
        } 
        else {
            // Узел найден, удаляем его
            if (root->left == nullptr) {
                Node<T>* temp = root->right; // Сохраняем правое поддерево
                //delete root; // Удаляем узел
                return temp; // Возвращаем правое поддерево
            } 
            else if (root->right == nullptr) {
                Node<T>* temp = root->left; // Сохраняем левое поддерево
                //delete root; // Удаляем узел
                return temp; // Возвращаем левое поддерево
            } 
            else {
                // Узел с двумя дочерними узлами: найти минимальный узел из правого поддерева
                Node<T>* temp = GetMin(root->right); // Получаем минимальный узел из правого поддерева
                if (temp != nullptr) {
                    root->value = temp->value; // Заменяем значение
                    root->right = Pop(root->right, temp->value); // Удаляем узел с минимальным значением
                }
            }
        }

        // Обновляем высоту узла и балансируем дерево
        HeightCorrect(root);
        return Balance(root); // Балансируем после удаления
    }



    template <typename T>
    int Tree<T>::BalanceFactor(Node<T>* node){
        return (Height(node->right) - Height(node->left));
    }

    template <typename T>
    int Tree<T>::Height(Node<T>* node){
        return (node ? node->height : 0);
    }

    template <typename T>
    void Tree<T>::HeightCorrect(Node<T>* node){
        if (node != nullptr){
            int left_height = Height(node->left);
            int right_height = Height(node->right);
            node->height = (left_height > right_height ? left_height : right_height) + 1;
        }
    }

    template <typename T>
    int Tree<T>::NumberOfSegmentElements(Node<T>* elem, T min, T max) {
        if (elem == nullptr) {
            return 0; // Если узел пустой, возвращаем 0
        }
        int count = 0;
        // Проверяем левое поддерево
        if (elem->value > min) {
            count += NumberOfSegmentElements(elem->left, min, max);
        }
        // Проверяем текущее значение
        if (elem->value >= min && elem->value <= max) {
            count += 1;
        }
        // Проверяем правое поддерево
        if (elem->value < max) {
            count += NumberOfSegmentElements(elem->right, min, max);
        }

        return count;
    }

    template <typename T>
    void Tree<T>::DeleteTree(Node<T>* node){
        if (node != nullptr) {
            // Рекурсивно удаляем левое и правое поддеревья
            if (node->left){
                DeleteTree(node->left);
            }
            if (node->right){
                DeleteTree(node->right);
            }
            delete node; // Освобождаем память для текущего узла
            node = nullptr; // Установите указатель на nullptr после удаления
        }
    }

    /*
    template <typename T>
    Tree<T>::~Tree(){
        DeleteTree(tree_root);
    }
    */
    template <typename T>
    Node<T>* Tree<T>::Find(Node<T>* root, T value){
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
    Node<T>* Tree<T>::GetMin(Node<T>* root){
        while (root && root->left != nullptr) {
            root = root->left;
        }
        return root;
    }

    template <typename T>
    Node<T>* Tree<T>::GetMax(Node<T>* root){
        while (root && root->right != nullptr) {
            root = root->right;
        }
        return root;
    }

    template <typename T>
    void Tree<T>::PrintTree(Node<T>* root){
        if (root == nullptr) {
            return; // Если узел пустой, просто выходим
        }
        PrintTree(root->left);
        std::cout << root->value << " ";
        PrintTree(root->right);
    }

    template <typename T>
    Node<T>* Tree<T>::Merge(Node<T>* root, Node<T>* other) {
        if (other == nullptr) {
            return root; // Приведение к неконстантному указателю
        }
        root = Merge(root, other->left);
        root = Insert(root, other->value);
        root = Merge(root, other->right);
        return root;
    }

    /*
    template <typename T>
    Tree<T>::~Tree(){
        DeleteTree(tree_root);
        tree_root = nullptr;   
    }
*/
    #endif  