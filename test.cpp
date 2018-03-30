#include "test.h"

#include <iostream>

using namespace std;

Test::Test()
{

}

Test::Test(int a, int b)
{
    m = a;
    n = b;
    sum = m + n;
}

void Test::print(Test &test)
{
    cout << "m:" << test.m << endl
         << "n:" << test.n << endl
         << "sum:" << test.sum << endl;
}
