#ifndef TREE
#define TREE

#include "Node.h"
#include <iostream>

template <typename T>
class Tree{
private:
    Node<T>* tree_root;
public:
    Tree();

    Node<T>* RightTurn(Node<T>* root);

    Node<T>* LeftTurn(Node<T>* root);

    Node<T>* RightBigTurn(Node<T>* root);

    Node<T>* LeftBigTurn(Node<T>* root);

    Node<T>* Balance(Node<T>* root);

    Node<T>* Insert(Node<T>* root, T value);
    
    Node<T>*  Pop(Node<T>* root, T value);

    int BalanceFactor(Node<T>* node);

    int Height(Node<T>* node);

    void HeightCorrect(Node<T>* node);

    int NumberOfSegmentElements(Node<T>* elem, T min, T max);

    void DeleteTree(Node<T>* node);

    ~Tree();

    Node<T>* Find(Node<T>* root, T value);

    Node<T>* GetMin(Node<T>* root);

    Node<T>* GetMax(Node<T>* root);

    void PrintTree(Node<T>* elem);

    Node<T>* Merge(Node<T>* root, Node<T>* other);

};

#include "Tree_rls.h"

#endif
