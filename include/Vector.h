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
    
    void PushBack(T const &value);
    
    bool Empty() const;
    
    T Back() const;
    
    T& operator[](int const index) const; // Constant indexing operator (etc Vector[i])
    
    int Size() const;
};

#include "Vetor_rls.h"
#endif