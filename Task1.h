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
	Vector();

	/// <summary>
	/// Конструктор копирования
	/// </summary>
	/// <param name="vec"></param>
	Vector(const Vector& vec);

	/// Деструктор для освобождения памяти
	~Vector();

	/// <summary>
	/// Функция получения размера вектора
	/// </summary>
	/// <returns></returns>
	size_t vec_size() const;

	/// <summary>
	/// Функция для изменения размера вектора
	/// </summary>
	/// <param name="new_size"></param>
	void resize(size_t new_size);

	/// <summary>
	/// Функция для добавления элемента в конец вектора
	/// </summary>
	/// <param name="elem"></param>
	void push_back(T elem);

	/// <summary>
	/// Сортировка методом простого обмена
	/// </summary>
	void selection_sort();

	/// <summary>
	/// Линейный поиск элемента по ключу
	/// </summary>
	/// <param name="ind"></param>
	/// <returns></returns>
	T linear_search(size_t ind);

	/// <summary>
	/// Поиск максимального элемента
	/// </summary>
	/// <returns></returns>
	T find_max();

	/// <summary>
	/// Поиск минимального элемента
	/// </summary>
	/// <returns></returns>
	T find_min();

	/// <summary>
	/// Метод удаления элемента из массива
	/// </summary>
	/// <param name="i"></param>
	void remove(size_t i);

	const Vector& operator=(const Vector& rhs); // оператор присваивания вектора

	const Vector& operator+(const Vector& rhs); // оператор сложения векторов поэлементно

	size_t& operator[](size_t size) const; // оператор получения элемента вектора по индексу

	void print(); // печать вектора
};
