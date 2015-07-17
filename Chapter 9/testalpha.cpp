#include <iostream>

char func(char);

int main(void)
{
    char a = 'A', b = 'b';

    a = func(a);
    b = func(b);
    auto t = func('.');

    std::cout << a << ' ' << b << ' ' << t << std::endl;

    return 0;
}

char func(char x)
{
    if(('a' <= x && x <= 'z') || ('A' <= x && x <= 'Z'))
        x = x ^ ' ';

    return x;
}
