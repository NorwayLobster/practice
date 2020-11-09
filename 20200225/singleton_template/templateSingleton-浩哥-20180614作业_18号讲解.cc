 ///
 /// @file    templateSingleton.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-06-18 09:39:37
 ///
 
#include <stdio.h>
#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;


class Point
{
public:
	Point(int ix = 0, int iy = 0)
	: _ix(ix)
	, _iy(iy)
	{
		cout << "Point()" << endl;
	}

	void print() const
	{
		cout << "(" << _ix
			 << "," << _iy
			 << ")" << endl;
	}

	~Point()
	{
		cout << "~Point()" << endl;
	}
	
private:
	int _ix;
	int _iy;
};

template <typename T> class Singleton {
	class AutoRelease
	{
	public:
		AutoRelease() {	cout << "AutoRelease()" << endl;	}
		~AutoRelease() 
		{
			if(_pInstance)
				delete _pInstance;
			cout << "~AutoRelease()" << endl;
		}
	};

public:
	template <typename... Args> static T * getInstance(Args... args)
	{
		if(_pInstance == NULL)
		{
			_auto;//使用一下_auto对象
			_pInstance = new T(args...);
		}
		return _pInstance;
	}

	static void destroy()
	{
		if(_pInstance)
			delete _pInstance;
	}
private:
	Singleton(){ cout << "Singleton()" << endl;}
	~Singleton(){ cout << "~Singleton()" << endl;	}
private:
	static T * _pInstance; 
	static AutoRelease _auto;
};

template <typename T> T * Singleton<T>::_pInstance = NULL;

template <typename T> typename Singleton<T>::AutoRelease Singleton<T>::_auto; 

int main(void)
{
	Point * pt1 = Singleton<Point>::getInstance(1, 2);
	Point * pt2 = Singleton<Point>::getInstance(3, 4);
	pt1->print();
	pt2->print();
	printf("pt1 = %p\n", pt1);
	printf("pt2 = %p\n", pt2);

	vector<int> * pVector1 = Singleton<vector<int>>::getInstance(10, 1);
	vector<int> * pVector2 = Singleton<vector<int>>::getInstance(10, 1);
	cout << pVector1->size() << endl;
	for(auto & number : *pVector1)
	{
		cout << number << " ";
	}
	cout << endl;
	printf("pVector1 = %p\n", pVector1);
	printf("pVector2 = %p\n", pVector2);

//	Singleton<Point>::destroy();

	return 0;
}
