#ifndef VECTOR
#define VECTOR

template <typename T>
class Vector{
private:
    T *array;
    int size; // текущий размер
    int capacity; // Вместимость массива
public:
    Vector();
    ~Vector();
    void PushBack(T value);
    bool Empty();
    T Back();
    T& operator[](int index); // Константный оператор индексирования
    int Size();
};

#include "Vetor_rls.h"
#endif

/*
int main(){
    Vector vector;
    std::cout << "empty: " << vector.Empty() << std::endl;
    std::cout << vector.Size() << std::endl;
    vector.PushBack(1);
    std::cout << "empty: " << vector.Empty() << std::endl;
    std::cout << vector.Size() << std::endl;
    vector.PushBack(2);
    std::cout << vector.Size() << std::endl;
    vector.PushBack(3);
    std::cout << vector.Size() << std::endl;
    std::cout << vector.Back() << std::endl;
}
*/