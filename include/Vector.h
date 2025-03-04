#ifndef VECTOR
#define VECTOR

template <typename T>
class Vector{
private:
    T *array;
    int size;       // Current size
    int capacity;   // Vector capacity
public:
    Vector();
    ~Vector();
    void PushBack(T value);
    bool Empty();
    T Back();
    T& operator[](int index); // Constant indexing operator (etc Vector[i])
    int Size();
};

#include "Vetor_rls.h"
#endif