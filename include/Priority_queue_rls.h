#ifndef QUEUE_RLS
#define QUEUE_RLS

#include <iostream>

// realisation

template <typename T>
PriorityQueue<T>::PriorityQueue(): root(nullptr), size(0){}

template <typename T>
PriorityQueue<T>::PriorityQueue(const Vector<T>& elements) : root(nullptr), size(0) {            
    for (int i = 0; i < elements.Size(); i++) {
        Push(elements[i]);
    }
}    

template <typename T>
PriorityQueue<T>::PriorityQueue(PriorityQueue<T> const &сopied_queue): size(0), root(nullptr) {
    if (this != &сopied_queue) {                       // Checking the self-sealing
        Clear();                                // Clearing the current queue
        root = tree.Merge(nullptr, сopied_queue.root); // Copy elements
        size = сopied_queue.size;                      // Copy size
        std::cout << "copy constructor was called\n";
    }  
}


template <typename T>
PriorityQueue<T>::PriorityQueue(PriorityQueue<T>&& other) noexcept      // Мув-конструктор
    : size(other.size), root(other.root) {
    other.size = 0;
    std::cout << "move constructor was called\n";
}


template <typename T>
void PriorityQueue<T>::Push(T const &elem){    // Inserts element and sorts the underlying container
    root = tree.Insert(root, elem);
    size++;
}        
    
template <typename T>
Node<T>* PriorityQueue<T>::Top() const {       // Accesses the top element
    if (tree.GetMax(root) == nullptr){
        throw std::out_of_range("Priority Queue is empty");
    }
    return tree.GetMax(root);
}

template <typename T>
bool PriorityQueue<T>::Empty() const {         // Checks whether the container adaptor is empty
    if (size == 0) return true;
    else return false;
}

template <typename T>
int PriorityQueue<T>::Size() const {           // Returns the number of elements
    return size;
}

template <typename T>
void PriorityQueue<T>::PopTop() {
    if (root != nullptr) {
        root = tree.Pop(root, tree.GetMax(root)->value);
        size--;
    }
    else{
        throw std::out_of_range("Priority Queue is empty");
    }
}

template <typename T>
void PriorityQueue<T>::Pop(T value){    // Removes some element
    if (root != nullptr){
        root = tree.Pop(root, value);
        size--;
    }
    else{
        throw std::out_of_range("Priority Queue is empty");
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
void PriorityQueue<T>::Print() const {
    if (root != nullptr){
        tree.PrintTree(root);
        std::cout << std::endl;
    }
}

template <typename T>
Node<T>* PriorityQueue<T>::Find(T const &value) const {
    if (root != nullptr){
        return tree.Find(root, value);
    }
    else{
        throw std::out_of_range("Priority Queue is empty");
    }
}

template <typename T>
bool PriorityQueue<T>::Contains(T const &value) const {
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