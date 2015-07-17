#include <iostream>
#include <vector>

int main()
{
    std::vector<int> store;
    int temp;

    while(std::cin >> temp)
        store.push_back(temp);
    for(const auto x : store)
        std::cout << x << ' ';
    std::cout << std::endl;

    return 0;
}
