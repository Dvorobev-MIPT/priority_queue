#ifndef QUEUE
#define QUEUE

#include "Tree.h"

template <typename T>
class PriorityQueue {
private:        
    int size;                       // Array size
    Tree<T> tree;                   // Array container
    Node<T>* root;                  // Tree (container) root
public:
    PriorityQueue(); 
    ~PriorityQueue() = default;
    void Push(T elem);              // Inserts element and sorts the underlying container
    Node<T>* Top();                 // Accesses the top element
    bool Empty();                   // Checks whether the container adaptor is empty
    int Size();                     // Returns the count of elements
    void PopTop();                  // Removes the top element
    void Pop(T value);              // Removes some element
    void Merge(PriorityQueue& other);
    void Print();
    Node<T>* Find(T value);         // If use this - check nullpt after !!!
    bool Contains(T value);
    void Clear();

    PriorityQueue& operator=(const PriorityQueue& other);
    PriorityQueue<T> operator+(PriorityQueue<T>& other) ;
};
#include "Priority_queue_rls.h"

#endif 