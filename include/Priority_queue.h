#ifndef QUEUE
#define QUEUE

#include "Tree.h"
// делаем на шаблонах; STL в бане

template <typename T>
class PriorityQueue {
private:
    int size; 
public:
    Tree<T> tree; // Используйте указатель
    Node<T>* root; // вершина дерева

    PriorityQueue(); // Должен быть как дефолтный Priority_queue(), так и Priority_queue(compare)
    ~PriorityQueue() = default;
    void Push(T elem);        //inserts element and sorts the underlying container
    //void PushRange(T* begin, T* end);   //inserts a range of elements and sorts the underlying container
    // operator = 
    Node<T>* Top();         //accesses the top element
    bool Empty();       // checks whether the container adaptor is empty
    int Size();        // returns the number of elements
    void PopTop();     // removes the top element
    void Pop(T value);         // removes some element
//    void Swap();          // swaps the contents
    void Merge(PriorityQueue& other);
    void Print();
    Node<T>* Find(T value); // if use this - check nullpt after
    bool Contains(T value);
    void Clear();

    PriorityQueue& operator=(const PriorityQueue& other);
    PriorityQueue<T> operator+(PriorityQueue<T>& other) ;
};
#include "Priority_queue_rls.h"

#endif 