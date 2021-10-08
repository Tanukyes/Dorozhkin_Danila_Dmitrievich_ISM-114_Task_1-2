#include <iostream>
#include <algorithm>
#include <chrono>
using namespace std;

/// <summary>
/// ����� "���������� ������"
/// </summary>
/// <typeparam name="T"></typeparam>
template<class T>
class Vector
{
private:
	/// <summary>
	/// ��������� �� ������ ������� ������� 
	/// </summary>
	T* arr;
	
	/// <summary>
	/// ����� ��������� � �������
	/// </summary>
	size_t size = 0;
	
	/// <summary>
	/// ������������ �����������
	/// </summary>
	size_t capacity = 5;
public:
	/// <summary>
	/// ����������� �� ���������
	/// </summary>
	Vector()
	{
		// ��������� ������ ��� ������
		arr = new T[capacity];
	}

	/// <summary>
	/// ����������� �����������
	/// </summary>
	/// <param name="vec"></param>
	Vector(const Vector& vec) : capacity(vec.capacity)
	{
		size = vec.size;
		arr = new T[capacity];
		for (size_t i = 0; i < size; ++i)
			arr[i] = vec.arr[i];
	}

	/// ���������� ��� ������������ ������
	~Vector() { delete[] arr; }

	/// <summary>
	/// ������� ��������� ������� �������
	/// </summary>
	/// <returns></returns>
	size_t vec_size() const { return size; };

	/// <summary>
	/// ������� ��� ��������� ������� �������
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
	/// ������� ��� ���������� �������� � ����� �������
	/// </summary>
	/// <param name="elem"></param>
	void push_back(T elem)
	{
		arr[size] = elem;			// �������� ������� � �����
		size++;						// ��������� ����� ����������� ���������
		if (size >= capacity)		// ���� ��� ����� ��������� ����. �����������,
			resize(capacity + 1);	// ��������� ����������� �� 1
	}

	/// <summary>
	/// ���������� ������� �������� ������
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
	/// �������� ����� �������� �� �����
	/// </summary>
	/// <param name="ind"></param>
	/// <returns></returns>
	T linear_search(int ind) 
	{
		for (int i = 0; i < size; i++)  // �������� ���� ��������� �������
			if (i == ind)				// ���� ������� � ����� �������� ������, 
				return arr[i];          // ������� ���� ������� �������
		return INT_MAX;                 // ������ ������� ����. ����� �������� (������� �� ������ � �������)
	}

	/// <summary>
	/// ����� ������������� ��������
	/// </summary>
	/// <returns></returns>
	T find_max()
	{
		T max = arr[0];					// ����� ������������ - ������ �������
		for (int i = 1; i < size; i++)  // �������� ���� ��������� ������� �� �������
			if (arr[i] > max)			// ���� ������� ������� ������ �������������, ��
				max = arr[i];			// ������������ = ����� ��������
		return max;						// ������� ������������ ������� �������
	}

	/// <summary>
	/// ����� ������������ ��������
	/// </summary>
	/// <returns></returns>
	T find_min()
	{
		T min = arr[0];					// ����� ����������� - ������ �������
		for (int i = 1; i < size; i++)  // �������� ���� ��������� ������� �� �������
			if (arr[i] < min)			// ���� ������� ������� ������ ������������, ��
				min = arr[i];			// ����������� = ����� ��������
		return min;						// ������� ����������� ������� �������
	}

	/// <summary>
	/// ����� �������� �������� �� �������
	/// </summary>
	/// <param name="i"></param>
	void remove(int i)
	{
		if (i >= 0 && i < size)                         // ���� ������� ������
		{
			size = size - 1;							// ��������� ����� ��������� ������� �� 1
			for (int j = i; j < size; j++)              // ������� � �������������� �������
				arr[j] = arr[j + 1];					// �������� �������� ������� �� 1 �����
			T* newarr = new T[capacity];				// ������� ����� ������
			copy(arr, arr + size, newarr);				// ����������� � ���� ������
			arr = newarr;                               // ������������ ������
		}
		else
			cout << "������� � ������ " << i << " �� ������ � �������!" << endl;
	}

	const Vector& operator=(const Vector& rhs) // �������� ������������ �������
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

	const Vector& operator+(const Vector& rhs) // �������� �������� �������� �����������
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


	int& operator[](size_t size) const { return arr[size]; } // �������� ��������� �������� ������� �� �������

	void print() // ������ �������
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
};
