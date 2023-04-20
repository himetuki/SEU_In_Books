//例15.15：使用类模板的特别类实现对字符数据的特殊处理。源程序名为Li1515.cpp
#include  <iostream>
using namespace std;

template  < typename T >  
class  Test
{
private:
	T  val;
public:
	Test(T  var):val(var){}
	friend  ostream&  operator << (ostream& os, Test<T> &value)
	{
		os<<value.val<<endl;
		return os;
	}
};

//类模板的特别类，用以处理char数据类型
template  < >
class  Test  <char>
{
private:
	char  val;
public:
	Test(char  var):val(var){}
	void  operator = (char var);
};

int  main( )
{
	Test<int>     t1(30);       //生成整数类型对象
	Test<char>    t2('C');      //生成字符类型对象
	
	cout << t1;
	cout << t2;       		 //错误，char型特别类没有重载定义<<运算符
	
	return 0;
}
