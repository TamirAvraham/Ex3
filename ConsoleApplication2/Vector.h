#pragma once
class Vector
{
private:
	int* _elements;
	int _size;
	int _capacity;
	int _resizeFactor;
	void Resize();//this is to change the length of a vector
	void Resize(int n);
public:
	Vector(int);
	~Vector();
	Vector(const Vector&);
	int size()const;
	int capacity()const;
	bool empty()const;
	void push_back(const int&);
	int pop_back();
	void reserve(int);
	void resize(int);
	void resize(int,const int&);
	void assign(int);
	Vector operator =(const Vector&);
};

