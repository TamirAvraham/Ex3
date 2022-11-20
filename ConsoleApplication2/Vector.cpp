#include "Vector.h"
int Vector::size()const {
	return _size;
}
int Vector::capacity()const {
	return _capacity;
}
bool Vector::empty()const {
	return _size <= 0;
}
Vector::Vector(int n) {
	n = n < 2 ? n : 2;
	_capacity = n;
	_elements = new int[_capacity];
	_size = 0;
	_resizeFactor = _capacity;
}
Vector::~Vector() {
	delete[] _elements;

}