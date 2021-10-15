#include "Vector.h"

template <class T>
Vector<T>::Vector()
{
	// ��������� ������ ��� ������
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
	if (arr != nullptr)
		delete[] arr;
}

template<class T>
size_t Vector<T>::vec_size() const
{
	return size;
}

template <class T>
void Vector<T>::resize(size_t new_size)
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

template <class T>
void Vector<T>::push_back(T elem)
{
	arr[size] = elem;			// �������� ������� � �����
	size++;						// ��������� ����� ����������� ���������
	if (size >= capacity)		// ���� ��� ����� ��������� ����. �����������,
		resize(capacity + 1);	// ��������� ����������� �� 1
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
		T temp = arr[min_idx];
		arr[min_idx] = arr[i];
		arr[i] = temp;
	}
}

template <class T>
T Vector<T>::linear_search(size_t ind)
{
	for (size_t i = 0; i < size; i++)  // �������� ���� ��������� �������
		if (i == ind)				// ���� ������� � ����� �������� ������, 
			return arr[i];          // ������� ���� ������� �������
	return (T)nullptr;                 // ������ ������� ������� ��������� (������� �� ������ � �������)
}

template <class T>
T Vector<T>::find_max()
{
	T max = arr[0];					// ����� ������������ - ������ �������
	for (size_t i = 1; i < size; i++)  // �������� ���� ��������� ������� �� �������
		if (arr[i] > max)			// ���� ������� ������� ������ �������������, ��
			max = arr[i];			// ������������ = ����� ��������
	return max;						// ������� ������������ ������� �������
}

template <class T>
T Vector<T>::find_min()
{
	T min = arr[0];					// ����� ����������� - ������ �������
	for (size_t i = 1; i < size; i++)  // �������� ���� ��������� ������� �� �������
		if (arr[i] < min)			// ���� ������� ������� ������ ������������, ��
			min = arr[i];			// ����������� = ����� ��������
	return min;						// ������� ����������� ������� �������
}

template <class T>
void Vector<T>::remove(size_t i)
{
	if (i >= 0 && i < size)                         // ���� ������� ������
	{
		size = size - 1;							// ��������� ����� ��������� ������� �� 1
		for (size_t j = i; j < size; j++)              // ������� � �������������� �������
			arr[j] = arr[j + 1];					// �������� �������� ������� �� 1 �����
		T* newarr = new T[capacity];				// ������� ����� ������
		copy(arr, arr + size, newarr);				// ����������� � ���� ������
		arr = newarr;                               // ������������ ������
	}
	else
		cout << "������� � ������ " << i << " �� ������ � �������!" << endl;
}

template <class T>
const Vector<T>& Vector<T>::operator=(const Vector& rhs) // �������� ������������ �������
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
const Vector<T>& Vector<T>::operator+(const Vector& rhs) // �������� �������� �������� �����������
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
size_t& Vector<T>::operator[](size_t size) const { return arr[size]; } // �������� ��������� �������� ������� �� �������

template <class T>
void Vector<T>::print() // ������ �������
{
	if (size <= 0)
	{
		cout << "������ ����!" << endl;
		return;
	}
	cout << "{";
	for (size_t i = 0; i < vec_size() - 1; ++i)
		cout << arr[i] << ", ";
	cout << arr[vec_size() - 1] << "}" << endl;
}