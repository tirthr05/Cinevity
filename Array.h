#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <cstdlib>
#include "defs.h"

using namespace std;

template <typename T>
class Array {

  public:
    Array();
    ~Array();

    Array<T>& operator+=(const T&);
    Array<T>& operator-=(const T&);
    T& operator[](int index);
    const T& operator[](int index) const;

    int getSize() const;
    bool isFull() const;
    void clear();

  private:
    int numElements;
    T* elements;
};

// Constructor
template <typename T>
Array<T>::Array() {
  elements = new T[MAX_ARR];
  numElements = 0;
}

// Destructor
template <typename T>
Array<T>::~Array() {
  delete[] elements;
}

// += operator (add)
template <typename T>
Array<T>& Array<T>::operator+=(const T& item) {
  if (numElements >= MAX_ARR)
    return *this;
  elements[numElements++] = item;
  return *this;
}

// -= operator (remove)
template <typename T>
Array<T>& Array<T>::operator-=(const T& item) {
  int index = 0;
  while (index < numElements) {
    if (elements[index] == item) {
      --numElements;
      break;
    }
    ++index;
  }

  while (index < numElements) {
    elements[index] = elements[index + 1];
    ++index;
  }

  return *this;
}

// [] operator (non-const)
template <typename T>
T& Array<T>::operator[](int index) {
  if (index < 0 || index >= numElements) {
    cerr << "Array index out of bounds" << endl;
    exit(1);
  }
  return elements[index];
}

// [] operator (const)
template <typename T>
const T& Array<T>::operator[](int index) const {
  if (index < 0 || index >= numElements) {
    cerr << "Array index out of bounds" << endl;
    exit(1);
  }
  return elements[index];
}

// getSize
template <typename T>
int Array<T>::getSize() const {
  return numElements;
}

// isFull
template <typename T>
bool Array<T>::isFull() const {
  return numElements >= MAX_ARR;
}

// clear
template <typename T>
void Array<T>::clear() {
  numElements = 0;
}

#endif
