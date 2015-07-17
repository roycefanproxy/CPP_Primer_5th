#include <iostream>
#include <vector>
#include <cctype>
using namespace std;

int main()
{
    vector<string> text;
    string temp;

    while((cin >> temp) && temp[0] != 'q')
        text.push_back(temp);
    for(auto word : text)
        cout << word;
    cout << endl;
    for(auto& word : text)
        for(auto c = word.begin(); c != word.end(); c++)
            *c = toupper(*c);
    for(auto word : text)
        cout << word << endl;

    return 0;
}
