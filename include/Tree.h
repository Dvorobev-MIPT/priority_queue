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

    Node<T>* Insert(Node<T>* root, T const &value);
    
    Node<T>*  Pop(Node<T>* root, T const &value);

    int BalanceFactor(Node<T>* node) const;

    int Height(Node<T>* node) const;

    void HeightCorrect(Node<T>* node) const;

    int NumberOfSegmentElements(Node<T>* elem, T const &min, T const &max) const;

    void DeleteTree(Node<T>* node);

    ~Tree();

    Node<T>* Find(Node<T>* root, T const &value) const;

    Node<T>* GetMin(Node<T>* root) const;

    Node<T>* GetMax(Node<T>* root) const;

    void PrintTree(Node<T>* elem) const;

    Node<T>* Merge(Node<T>* root, Node<T>* other);

};

#include "Tree_rls.h"

#endif
