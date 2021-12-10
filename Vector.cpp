#include "Vector.h"
#include <exception>

template <class T>
Vector<T>::Vector()
{
    // Выделение памяти под массив
    arr = new T[capacity];
}

template <class T>
Vector<T>::Vector(const Vector& vec) : capacity(vec.capacity)
{
    size = vec.size;
    arr = new T[capacity];
    for (size_t i = 0; i < size; ++i)
        arr[i] = vec.arr[i];
}

template <class T>
Vector<T>::~Vector()
{
    if (arr != nullptr) {
        delete[] arr;
        arr = nullptr;
    }
}

template<class T>
size_t Vector<T>::vec_size() const
{
    return size;
}

template <class T>
void Vector<T>::resize(size_t new_size)
{
    if(capacity < new_size) {
        capacity = new_size;
    }
    T* new_array = new T[capacity];
    size_t count = new_size < capacity ? new_size : capacity;
    for (size_t i = 0; i < count; ++i)
        new_array[i] = arr[i];
    delete[] arr;
    arr = new_array;
    //capacity = new_size;
}

template <class T>
void Vector<T>::push_back(T elem)
{
    arr[size] = elem;			// добавить элемент в конец
    size++;						// увеличить число добавленных элементов
    if (size >= capacity)		// если это число превышает макс. вместимость,
        resize(capacity*2);	// увеличить вместимость в два раза
}

template <class T>
void Vector<T>::swap(int min_ind, int ind){
    T temp = arr[min_ind];
    arr[min_ind] = arr[ind];
    arr[ind] = temp;
}

template <class T>
void Vector<T>::selection_sort()
{
    size_t i, j, min_idx;
    for (i = 0; i < size - 1; i++)
    {
        min_idx = i;
        for (j = i + 1; j < size; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;


//        T temp = arr[min_idx];
//        arr[min_idx] = arr[i];
//        arr[i] = temp;
        swap(min_idx, i);
    }
}

template <class T>
T Vector<T>::linear_search(size_t ind)
{
    for (size_t i = 0; i < size; i++)  // просмотр всех элементов массива
        if (i == ind)				// если элемент с таким индексом найден,
            return arr[i];          // вернуть этот элемент массива
    return (T)nullptr;                 // отсюда вернуть нулевой указатель (элемент не найден в массиве)
}

template <class T>
T Vector<T>::find_max()
{
    T max = arr[0];					//  пусть максимальный - первый элемент
    for (size_t i = 1; i < size; i++)  // просмотр всех элементов массива со второго
        if (arr[i] > max)			// если текущий элемент больше максимального, то
            max = arr[i];			// максимальный = этому элементу
    return max;						// вернуть максимальный элемент массива
}

template <class T>
T Vector<T>::find_min()
{
    T min = arr[0];					// пусть минимальный - первый элемент
    for (size_t i = 1; i < size; i++)  // просмотр всех элементов массива со второго
        if (arr[i] < min)			// если текущий элемент меньше минимального, то
            min = arr[i];			// минимальный = этому элементу
    return min;						// вернуть минимальный элемент массива
}

template <class T>
void Vector<T>::remove(size_t i)
{
    if (i < size)                         // если элемент найден
    {
        size = size - 1;							// уменьшить число элементов массива на 1
        for (size_t j = i; j < size; j++)           //  начиная с освободившейся позиции
            arr[j] = arr[j + 1];					// сдвинуть элементы массива на 1 влево
        T* newarr = new T[capacity];				// создать новый массив
        copy(arr, arr + size, newarr);				// скопировать в него старый
        arr = newarr;                               // перезаписать массив
    }
    else
        cout << "Элемент с ключом " << i << " не найден в векторе!" << endl;
}

template <class T>
const Vector<T>& Vector<T>::operator=(const Vector& rhs) // оператор присваивания вектора
{
    if (&rhs != this)
    {
        capacity = rhs.capacity;
        size = rhs.size;
        delete[] arr;
        arr = new T[capacity];
        for (size_t i = 0; i < vec_size(); ++i)
            arr[i] = rhs.arr[i];
    }
    return *this;
}

template <class T>
const Vector<T>& Vector<T>::operator+(const Vector& rhs) // оператор сложения векторов поэлементно
{
    size_t count;
    if (size < rhs.size)
        count = size;
    else
        count = rhs.size;
    for (size_t i = 0; i < count; ++i)
        this->arr[i] = this->arr[i] + rhs.arr[i];
    return *this;
}

template <class T>
size_t& Vector<T>::operator[](size_t index) const { return arr[index]; }

template <class T>
void Vector<T>::print() // печать вектора
{
    if (size <= 0)
    {
        throw std::runtime_error("Non-positive size error");
    }
    cout << "{";
    for (size_t i = 0; i < vec_size() - 1; ++i)
        cout << arr[i] << ", ";
    cout << arr[vec_size() - 1] << "}" << endl;
}
