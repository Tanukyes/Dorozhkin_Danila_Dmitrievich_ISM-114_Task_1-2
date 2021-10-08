#include <iostream>
#include <algorithm>
#include <chrono>
using namespace std;

/// <summary>
/// Класс "одномерный массив"
/// </summary>
/// <typeparam name="T"></typeparam>
template<class T>
class Vector
{
private:
	/// <summary>
	/// Указатель на первый элемент массива 
	/// </summary>
	T* arr;
	
	/// <summary>
	/// Всего элементов в массиве
	/// </summary>
	size_t size = 0;
	
	/// <summary>
	/// Максимальная вместимость
	/// </summary>
	size_t capacity = 5;
public:
	/// <summary>
	/// Конструктор по умолчанию
	/// </summary>
	Vector()
	{
		// выделение памяти под массив
		arr = new T[capacity];
	}

	/// <summary>
	/// Конструктор копирования
	/// </summary>
	/// <param name="vec"></param>
	Vector(const Vector& vec) : capacity(vec.capacity)
	{
		size = vec.size;
		arr = new T[capacity];
		for (size_t i = 0; i < size; ++i)
			arr[i] = vec.arr[i];
	}

	/// Деструктор для освобождения памяти
	~Vector() { delete[] arr; }

	/// <summary>
	/// Функция получения размера вектора
	/// </summary>
	/// <returns></returns>
	size_t vec_size() const { return size; };

	/// <summary>
	/// Функция для изменения размера вектора
	/// </summary>
	/// <param name="new_size"></param>
	void resize(size_t new_size)
	{
		capacity = new_size;
		T* new_array = new T[capacity];
		size_t count = new_size < capacity ? new_size : capacity;
		for (size_t i = 0; i < count; ++i)
			new_array[i] = arr[i];
		delete[] arr;
		arr = new_array;
		capacity = new_size;
	}

	/// <summary>
	/// Функция для добавления элемента в конец вектора
	/// </summary>
	/// <param name="elem"></param>
	void push_back(T elem)
	{
		arr[size] = elem;			// добавить элемент в конец
		size++;						// увеличить число добавленных элементов
		if (size >= capacity)		// если это число превышает макс. вместимость,
			resize(capacity + 1);	// увеличить вместимость на 1
	}

	/// <summary>
	/// Сортировка методом простого обмена
	/// </summary>
	void selection_sort()
	{
		int i, j, min_idx;
		for (i = 0; i < size - 1; i++)
		{
			min_idx = i;
			for (j = i + 1; j < size; j++)
				if (arr[j] < arr[min_idx])
					min_idx = j;
			T temp = arr[min_idx];
			arr[min_idx] = arr[i];
			arr[i] = temp;
		}
	}

	/// <summary>
	/// Линейный поиск элемента по ключу
	/// </summary>
	/// <param name="ind"></param>
	/// <returns></returns>
	T linear_search(int ind) 
	{
		for (int i = 0; i < size; i++)  // просмотр всех элементов массива
			if (i == ind)				// если элемент с таким индексом найден, 
				return arr[i];          // вернуть этот элемент массива
		return INT_MAX;                 // отсюда вернуть макс. целое значение (элемент не найден в массиве)
	}

	/// <summary>
	/// Поиск максимального элемента
	/// </summary>
	/// <returns></returns>
	T find_max()
	{
		T max = arr[0];					// пусть максимальный - первый элемент
		for (int i = 1; i < size; i++)  // просмотр всех элементов массива со второго
			if (arr[i] > max)			// если текущий элемент больше максимального, то
				max = arr[i];			// максимальный = этому элементу
		return max;						// вернуть максимальный элемент массива
	}

	/// <summary>
	/// Поиск минимального элемента
	/// </summary>
	/// <returns></returns>
	T find_min()
	{
		T min = arr[0];					// пусть минимальный - первый элемент
		for (int i = 1; i < size; i++)  // просмотр всех элементов массива со второго
			if (arr[i] < min)			// если текущий элемент меньше минимального, то
				min = arr[i];			// минимальный = этому элементу
		return min;						// вернуть минимальный элемент массива
	}

	/// <summary>
	/// Метод удаления элемента из массива
	/// </summary>
	/// <param name="i"></param>
	void remove(int i)
	{
		if (i >= 0 && i < size)                         // если элемент найден
		{
			size = size - 1;							// уменьшить число элементов массива на 1
			for (int j = i; j < size; j++)              // начиная с освободившейся позиции
				arr[j] = arr[j + 1];					// сдвинуть элементы массива на 1 влево
			T* newarr = new T[capacity];				// создать новый массив
			copy(arr, arr + size, newarr);				// скопировать в него старый
			arr = newarr;                               // перезаписать массив
		}
		else
			cout << "Элемент с ключом " << i << " не найден в векторе!" << endl;
	}

	const Vector& operator=(const Vector& rhs) // оператор присваивания вектора
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

	const Vector& operator+(const Vector& rhs) // оператор сложения векторов поэлементно
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


	int& operator[](size_t size) const { return arr[size]; } // оператор получения элемента вектора по индексу

	void print() // печать вектора
	{
		if (size <= 0)
		{
			cout << "Вектор пуст!" << endl;
			return;
		}
		cout << "{";
		for (size_t i = 0; i < vec_size() - 1; ++i)
			cout << arr[i] << ", ";
		cout << arr[vec_size() - 1] << "}" << endl;
	}
};
