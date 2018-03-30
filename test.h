#ifndef TEST_H
#define TEST_H


class Test
{
public:
    Test();
    Test( int a, int b );

    static void print( Test &test );

private:
    int m;
    int n;
    int sum;
};

#endif // TEST_H
