#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>
using namespace std;

int main(void)
{
    vector<string> storage;
    string buff;
    ifstream file("8.4.file");
    if(file)
    {
        while(getline(file, buff))
        {
            istringstream iss(buff);
            string temp;
            while(iss >> temp)
                storage.push_back(temp);
        }

        for(auto& x : storage)
            cout << x << endl;

        file.close();
    }

    return 0;
}
