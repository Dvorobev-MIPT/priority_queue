#ifndef QUEUE_RLS
#define QUEUE_RLS

#include <iostream>

// realisation

template <typename T>
PriorityQueue<T>::PriorityQueue(): root(nullptr), size(0){}

template <typename T>
void PriorityQueue<T>::Push(T elem){ //inserts element and sorts the underlying container
    root = tree.Insert(root, elem);
    size += 1;
}        

//template <typename T>
//void PriorityQueue<T>::PushRange(T* begin, T* end){}   //inserts a range of elements and sorts the underlying container
// operator = 

template <typename T>
Node<T>* PriorityQueue<T>::Top(){         //accesses the top element
    return tree.GetMax(root);
}

template <typename T>
bool PriorityQueue<T>::Empty(){       // checks whether the container adaptor is empty
    if (size == 0) return true;
    else return false;
}

template <typename T>
int PriorityQueue<T>::Size(){        // returns the number of elements
    return size;
}

template <typename T>
void PriorityQueue<T>::PopTop(){     // removes the top element
    root = tree.Pop(root, tree.GetMax(root)->value);
    size--;
}

template <typename T>
void PriorityQueue<T>::Pop(T value){         // removes some element
    root = tree.Pop(root, value);
    if (root != nullptr) size--;
}

template <typename T>
void PriorityQueue<T>::Merge(PriorityQueue& other){
    root = other.tree.Merge(root, other.root);
    size += other.size;
}

template <typename T>
void PriorityQueue<T>::Print(){
    tree.PrintTree(root);
    std::cout << std::endl;
}

template <typename T>

Node<T>* PriorityQueue<T>::Find(T value){
    return tree.Find(root, value);
}

template <typename T>
bool PriorityQueue<T>::Contains(T value){
    if (tree.Find(root, value) == nullptr) return false;
    else return true;
}

template <typename T>
void PriorityQueue<T>::Clear(){
    tree.DeleteTree(root);
    root = nullptr;
    size = 0;
}

template <typename T>
PriorityQueue<T>& PriorityQueue<T>::operator=(const PriorityQueue<T>& other) {
    this->size = other.size;
    root = other.root;
    return *this;
}

template <typename T>
PriorityQueue<T> PriorityQueue<T>::operator+(PriorityQueue<T>& other){
    PriorityQueue<T> result;
    result.Merge(other);
    result.Merge(*this);
    result.size = this->size + other.size;
    return result;
}

/*
template <typename T>
PriorityQueue<T>::~PriorityQueue(){
    tree.DeleteTree(root); // Удаляем все узлы дерева
    root = nullptr;
    size = 0;
}
*/

//template <typename T>
//void PriorityQueue<T>::Swap(){}          // swaps the contents

#endif