#ifndef VECTOR_RLS
#define VECTOR_RLS

// realisation

template <typename T>
Vector<T>::Vector() : size(0), capacity(1) {
    array = new T[capacity];
}

template <typename T>
Vector<T>::~Vector(){
    delete[] array; // Freeing up memory
    array = nullptr; // Setting the pointer to nullptr to prevent double deallocation
}

template <typename T>
void Vector<T>::PushBack(T const &value){
    if (size >= capacity){
        capacity *= 2;
        T* new_array = new T[capacity];

        // Copying old elements to a new array
        for (int i = 0; i < size; ++i) {
            new_array[i] = array[i];
        }

        // Frees old array
        delete[] array;
        array = new_array;
    }

    // Add new element
    array[size] = value; 
    size++;
}

template <typename T>
bool Vector<T>::Empty() const {
    if (size == 0) return true;
    else return false;
}

template <typename T>
T Vector<T>::Back() const {
    if (Empty()) { // Empty check
        throw std::out_of_range("Vector is empty");
    }
    return array[size-1];
}

template <typename T>
T& Vector<T>::operator[](int const index) const { 
    if (index < 0 || index >= size) {
        throw std::out_of_range("Index out of range");
    }
    return array[index];
}

template <typename T>
int Vector<T>::Size() const {
    return size;
}

#endif