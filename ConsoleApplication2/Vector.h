#pragma once
class Vector
{
private:
	int* _elements;
	int _size;
	int _capacity;
	int _resizeFactor;
public:
	Vector(int n);
	~Vector();
	int size()const;
	int capacity()const;
	bool empty()const;
};

