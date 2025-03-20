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
    PriorityQueue();                // Default Constructor

    PriorityQueue(const Vector<T>& elements);   // Constructor with data assignment via Vector
    
    PriorityQueue(PriorityQueue const &сopied_queue);   // Copy constructor

    PriorityQueue(PriorityQueue&& other) noexcept;         // Move constructor

    ~PriorityQueue() = default;

    void Push(T const &elem);              // Inserts element and sorts the underlying container

    Node<T>* Top() const;                 // Accesses the top element
    
    bool Empty() const;                   // Checks whether the container adaptor is empty
    
    int Size() const;                     // Returns the count of elements
    
    void PopTop();                  // Removes the top element
    
    void Pop(T value);              // Removes some element
    
    void Merge(PriorityQueue& other);
    
    void Print() const;
    
    Node<T>* Find(T const &value) const;         // If use this - check nullpt after !!!
    
    bool Contains(T const &value) const;
    
    void Clear();


    PriorityQueue& operator=(const PriorityQueue& other);
    PriorityQueue<T> operator+(PriorityQueue<T>& other) ;
};
#include "Priority_queue_rls.h"

#endif 