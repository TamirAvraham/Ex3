#pragma once
class Vector
{
private:
	int* _elements;
	int _size;
	int _capacity;
	int _resizeFactor;
	void resize();//this is to change the length of a vector
	void resize(int n);
public:
	Vector(int);
	~Vector();
	int size()const;
	int capacity()const;
	bool empty()const;
	void push_back(const int&);
	int pop_back();
	void reserve(int);
};

