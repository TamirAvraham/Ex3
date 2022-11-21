#include "Vector.h"
#include <iostream>
int Vector::size()const {
	return _size;
}
int Vector::capacity()const {
	return _capacity;
}
bool Vector::empty()const {
	return _size <= 0;
}
int Vector::resizeFactor() const {
	return _resizeFactor;
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
	int diff = abs(_capacity + _resizeFactor * n);
	int* temp = new int[diff];
	int loopRunner = _size <= diff ? _size : diff;
	for (int i = 0; i < loopRunner; i++)
	{
		temp[i] = _elements[i];
	}
	delete[] _elements;
	_size = diff != 0 ? diff : _size;
	_elements = temp;
	_capacity =diff;
}
void Vector::reserve(int n) {
	int numOfRefactor = abs(((n - _capacity) / _resizeFactor) + (n  % _resizeFactor==0?0:1));//claclates how manty times to mull in resize(int) resize factor
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
	int minus = _size - 1;
	int ret = minus >= 0 ? _elements[minus == 0 ? minus : minus--] : -999;
	_size--;
	return ret;

}
void Vector::resize(int n) {
	int diff = n - _capacity;
	int carry = diff<0?-1:1;
	int numOfRefactor = (diff / _resizeFactor) + (diff % _resizeFactor == 0 ? 0 : carry);
	Resize(numOfRefactor);
}
void Vector::assign(int value) {
	for (int i = 0; i < _size; i++)
	{
		_elements[i] = value;
	}
}
void Vector::resize(int n,const int& val) {
	resize(n);
	assign(val);
}
Vector::Vector(const Vector& vec):_capacity(vec._capacity),_size(vec._size),_resizeFactor(vec._resizeFactor) {
	_elements = new int[vec._capacity];
	for (int i = 0; i < _size; i++)
	{
		_elements[i] = vec._elements[i];
	}

}
Vector Vector::operator=(const Vector& vec) {
	if (&vec==this)
	{
		return *this;
	}
	this->_capacity = vec._capacity;
	this->_resizeFactor = vec._resizeFactor;
	this->_size = vec._size;
	for (int i = 0; i < _size; i++)
	{
		_elements[i] = vec._elements[i];
	}
	return *this;
}

int& Vector::operator[](int index) {
	if (index<0||index>_size)
	{
		std::cerr << "Index out of range";
		return _elements[0];
	}
	return _elements[index];
}

Vector Vector::operator+(Vector v1, Vector v2) {
	Vector ret(v1);
	int loopLength = v1.size() < v2.size() ? v1.size() : v2.size();
	for (int i = 0; i < loopLength; i++)
	{
		ret[i] += v2[i];
	}
	return ret;
}