#include <iostream>
using namespace std;

class A
{
	public:
		A(int a = 0)
			:_a(a)
		{
			cout << "A(int a = 0) -> " << a << endl;
		}

		~A()
		{
			cout << "~A() -> " << _a << endl;
		}


		int _a;

};

A aa3(3);

void f()
{
	static A aa0(0);
	A aa1(1);
	A aa2(2);
	static A aa4(4);
}

// 构造顺序：3 0 1 2 4 1 2
// 析构顺序：2 1 2 1 4 0 3

int main()
{
	f();
	f();

	return 0;
}