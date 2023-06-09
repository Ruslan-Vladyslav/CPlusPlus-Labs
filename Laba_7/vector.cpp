#include "header.h"
#include <iostream>
#include <stdexcept>

Vector::Vector(int size) {
    this->size = size;
    elements = new int[size];
    for (int i = 0; i < size; i++) {
        elements[i] = 0;
    }
}

Vector::~Vector() {
    delete[] elements;
}

int Vector::getSize() const {
    return size;
}

int& Vector::operator[](int index) {
    return elements[index];
}

const int& Vector::operator[](int index) const {
    return elements[index];
}

int Vector::calculateDotProduct(const Vector& other) const {
    int dotProduct = 0;
    for (int i = 0; i < getSize(); i++) {
        dotProduct += (*this)[i] * other[i];
    }
    return dotProduct;
}