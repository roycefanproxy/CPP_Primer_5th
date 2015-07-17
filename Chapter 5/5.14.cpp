#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    vector<string> input;
    vector<int> input_c;
    string temp;


    while(cin >> temp)
    {
        auto ins = input.cbegin();
        auto inc = input_c.begin();
        if(input.size() != 0)
        {
            while(ins != input.cend() && inc != input_c.end())
            {
                if(*ins == temp)
                {
                    (*inc)++;
                    break;
                }
                ins++;
                inc++;
            }
            if(ins == input.cend())
            {
                input.push_back(temp);
                input_c.push_back(1);
            }
        }
        else
        {
            input.push_back(temp);
            input_c.push_back(1);
        }
    }

    int index = 0;
    auto intpt = input_c.cbegin();
    auto x = input.cbegin();
    int largest = 0;
    string largests;
    while(x + index != input.cend())
    {
        if(*(intpt + index) > largest)
        {
            largest = *(intpt + index);
            largests = *(x + index);
        }
        index++;
    }

    cout << largests << " : " << largest << endl;

    return 0;
}
