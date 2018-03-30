#include "test.h"

#include <iostream>

using namespace std;

//声明函数指针,声明时注意函数返回值类型及参数类型要保持一致
int (*p)( int, int );
void (*funcp)();

//函数声明
int add_ret(int a, int b);
int add(int a, int b, int (*p)(int, int));
void FileFunc();
void EditFunc();

int main(int argc, char *argv[])
{
    int a, b;
    cout << "please enter two number(eg:a b):";
    cin >> a >> b;

    Test test( a, b );
    Test::print( test );            //静态成员函数的调用

    p = add_ret;                    //把函数 add_ret 的地址赋给函数指针 p
    int sum = p( a, b );            //调用函数指针
    cout << "foo:" << sum << endl;
    sum += add( a, b, p );          //调用回调函数
    cout << "add:" << sum << endl;

    funcp = FileFunc;               //把函数 FileFunc 的地址赋给函数指针 funcp
    funcp();                        //调用函数指针
    funcp = EditFunc;               //把函数 EditFunc 的地址赋给函数指针 funcp
    (*funcp)();                     //调用函数指针

    return 0;
}

int add_ret( int a, int b )
{
    return a + b;
}

//回调函数
int add( int a, int b, int (*p)(int , int ))
{
    return (*p)( a, b );
}

void FileFunc()
{
    cout << "FileFunc!" << endl;
}

void EditFunc()
{
    cout << "EditFunc!" << endl;
}
