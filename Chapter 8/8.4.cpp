#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

vector<string>& open_f(vector<string>&);

int main(void)
{
    vector<string> contents;
    auto& t = open_f(contents);

    for(auto x : t)
        cout << x << endl;

    return 0;
}

vector<string>& open_f(vector<string>& contents)
{
    ifstream file("8.4.file");
    string buff;

    if(file)
    {
        while(getline(file, buff))
            contents.push_back(buff);
        file.close();
    }
    else
        cout << "Fail." << endl;

    return contents;
}
