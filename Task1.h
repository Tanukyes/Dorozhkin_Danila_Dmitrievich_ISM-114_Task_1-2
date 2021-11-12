#ifndef DANYA_VECTOR_H
#define DANYA_VECTOR_H

#endif //DANYA_VECTOR_H


#include <iostream>
#include <algorithm>
#include <chrono>

using namespace std;


template<class T>
class Vector
{
private:
    T* arr;
    size_t size = 0;
    size_t capacity = 5;

    // методы обслуживания
    void swap(int min_ind, int ind);
public:
    Vector();
    Vector(const Vector& vec);
    ~Vector();

    size_t vec_size() const;
    void resize(size_t new_size);
    void push_back(T elem);

    void selection_sort();
    T linear_search(size_t ind);
    T find_max();
    T find_min();
    void remove(size_t i);

    const Vector& operator=(const Vector& rhs);

    const Vector& operator+(const Vector& rhs);

    size_t& operator[](size_t size) const;

    void print();
};
