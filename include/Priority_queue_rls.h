#ifndef QUEUE_RLS
#define QUEUE_RLS

#include <iostream>

// realisation

template <typename T>
PriorityQueue<T>::PriorityQueue(): root(nullptr), size(0){}

template <typename T>
void PriorityQueue<T>::Push(T elem){    // Inserts element and sorts the underlying container
    root = tree.Insert(root, elem);
    size++;
}        
    
template <typename T>
Node<T>* PriorityQueue<T>::Top(){       // Accesses the top element
    return tree.GetMax(root);
}

template <typename T>
bool PriorityQueue<T>::Empty(){         // Checks whether the container adaptor is empty
    if (size == 0) return true;
    else return false;
}

template <typename T>
int PriorityQueue<T>::Size(){           // Returns the number of elements
    return size;
}

template <typename T>
void PriorityQueue<T>::PopTop() {
    if (root != nullptr) {
        root = tree.Pop(root, tree.GetMax(root)->value);
        size--;
    }
}

template <typename T>
void PriorityQueue<T>::Pop(T value){    // Removes some element
    if (root != nullptr){
        root = tree.Pop(root, value);
        size--;
    }
}

template <typename T>
void PriorityQueue<T>::Merge(PriorityQueue& other) {
    if (other.root != nullptr) {
        root = tree.Merge(root, other.root);
        size += other.size;
    }
}
template <typename T>
void PriorityQueue<T>::Print(){
    if (root != nullptr){
        tree.PrintTree(root);
        std::cout << std::endl;
    }
}

template <typename T>
Node<T>* PriorityQueue<T>::Find(T value){
    if (root != nullptr){
        return tree.Find(root, value);
    }
    return nullptr;
}

template <typename T>
bool PriorityQueue<T>::Contains(T value){
    if (tree.Find(root, value) == nullptr) return false;
    else return true;
}

template <typename T>
void PriorityQueue<T>::Clear(){
    if (root != nullptr) {
        tree.DeleteTree(root);
        root = nullptr;
    }
    size = 0;
}

template <typename T>
PriorityQueue<T>& PriorityQueue<T>::operator=(const PriorityQueue<T>& other) {
    if (this != &other) {                       // Checking the self-sealing
        Clear();                                // Clearing the current queue
        root = tree.Merge(nullptr, other.root); // Copy elements
        size = other.size;                      // Copy size
    }
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

#endif