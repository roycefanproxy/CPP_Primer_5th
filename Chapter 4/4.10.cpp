#include <iostream>
using std::cin;
int main()
{
    int temp(0);

    cin >> temp;
    while(temp != 42)
        cin >> temp;

    std::cout << "Done." << std::endl;

    return 0;
}
