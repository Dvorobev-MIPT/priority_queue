#ifndef VECTOR_RLS
#define VECTOR_RLS

template <typename T>
Vector<T>::Vector() : size(0), capacity(1) {
    array = new T[capacity];
}

template <typename T>
Vector<T>::~Vector(){
    delete[] array; // Освобождение памяти
    array = nullptr; // Установка указателя в nullptr для предотвращения двойного освобождения
}

template <typename T>
void Vector<T>::PushBack(T value){
    if (size >= capacity){
        capacity *= 2;
        T* new_array = new T[capacity];

        // Копируем старые элементы в новый массив
        for (int i = 0; i < size; ++i) {
            new_array[i] = array[i];
        }

        // Освобождаем старый массив
        delete[] array;
        array = new_array;
    }

    // Добавляем новый элемент
    array[size] = value; // Исправлено: используем size, а не size + 1
    size++;
}

template <typename T>
bool Vector<T>::Empty(){
    if (size == 0) return true;
    else return false;
}

template <typename T>
T Vector<T>::Back(){
    if (Empty()) { // Проверка на пустоту
        throw std::out_of_range("Vector is empty");
    }
    return array[size-1];
}

template <typename T>
T& Vector<T>::operator[](int index) { // Константный оператор индексирования
    if (index < 0 || index >= size) {
        throw std::out_of_range("Index out of range");
    }
    return array[index];
}

template <typename T>
int Vector<T>::Size(){
    return size;
}

#endif