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
	n = n > 2 ? n : 2;
	_capacity = n;
	_elements = new int[_capacity];
	_size = 0;
	_resizeFactor = _capacity;
}
Vector::~Vector() {
	delete[] _elements;

}
void Vector::Resize() {
	int* temp = new int[_capacity + _resizeFactor];
	for (int i = 0; i < _size; i++)
	{
		temp[i] = _elements[i];
	}
	delete[] _elements;
	_elements = temp; 
	_capacity += _resizeFactor;
}
void Vector::Resize(int n){
	int* temp = new int[_capacity + _resizeFactor*n];
	for (int i = 0; i < _size; i++)
	{
		temp[i] = _elements[i];
	}
	delete[] _elements;
	_elements = temp;
	_capacity += _resizeFactor*n;
}
void Vector::reserve(int n) {
	int numOfRefactor = ((n - _capacity) / _resizeFactor) + (n  % _resizeFactor==0?0:1);//claclates how manty times to mull in resize(int) resize factor
	Resize(numOfRefactor);
}
void Vector::push_back(const int& val) {
	if (_size == _capacity) 
	{ 
		Resize(); 
	}
	_elements[_size++] = val;
}
int Vector::pop_back() {
	return _elements[_size--];

}
void Vector::resize(int n) {

}