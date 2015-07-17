#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

vector<string>& the_func(const string, vector<string>&);

int main(void)
{
    vector<string> storage;
    string filename("8.4.file");

    for(auto x : the_func(filename, storage))
        cout << x << endl;

    return 0;
}

vector<string>& the_func(const string filename, vector<string>& storage)
{
    ifstream file(filename,ifstream::in);

    if(file)
    {
        string buff;
        while(file >> buff)
            storage.push_back(buff);

        file.close();
    }

    return storage;
}
