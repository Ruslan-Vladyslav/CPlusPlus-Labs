#pragma once
#include <iostream>
#include <stdexcept>

class Vector {
private:
    int* elements;
    int size;

public:
    Vector(int size);
    ~Vector();

    int getSize() const;
    int& operator[](int index);
    const int& operator[](int index) const;

    int calculateDotProduct(const Vector& other) const;
};