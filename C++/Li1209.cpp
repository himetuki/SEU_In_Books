#include <iostream>
using namespace std;

class A
{
protected:
    int x;
public:
    A(int a = 0) : x(a) { }
};

class B : public A
{
protected:
    int y;
public:
    B(int a = 0, int b = 0) :A(a), y(b){ }
};

class C : public A
{
protected:
    int z;
public:
    C(int a = 0, int c = 0) :A(a), z(c){ }
};

class D : public B, public C
{
protected:
    int k;
public:
    D(int a1 = 0, int a2 = 0, int b = 0, int c = 0, int d = 0) : 
                                       B(a1, b), C(a2, c), k(d)   // E，续上一行
    { } //D类构造函数的函数体
    void Show()
    {
        cout << "x1=" << B::x << ", ";	// F
        cout << "x2=" << C::x << ", ";	// G
        cout << "y=" << y << ", ";
        cout << "z=" << z << ", ";
        cout << "k=" << k << endl;
    }
};

int main(void)
{
    D obj(1, 2, 3, 4, 5);

    obj.Show();
    return 0;
}
