#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

void elimdups(vector<string>&);
void biggies(vector<string>&, vector<string>::size_type);
string make_plural(int, string, string);

int main(void)
{
    vector<string> vs;
    string input;
    int size;

    while((cin >> input) && input != "done")
        vs.push_back(input);
    cout << "Input size :" << ends;
    cin >> size;
    biggies(vs, size);

    return 0;
}

void elimdups(vector<string>& vec)
{
    sort(vec.begin(), vec.end());
    auto x = unique(vec.begin(), vec.end());
    vec.erase(x, vec.end());
}

void biggies(vector<string>& vec, vector<string>::size_type sz)
{
    elimdups(vec);
    stable_sort(vec.begin(), vec.end(), [] (const string& a, const string& b) { return a.size() < b.size(); });
    vector<string>::iterator wc = find_if(vec.begin(), vec.end(), [=] (const string& s) { return s.size() >= sz; });
    vector<string>::difference_type count = vec.end() - wc;

    cout << count << " " << make_plural(count, "word", "s") << " of length " << sz << " or longer." << endl;

    for_each(wc, vec.end(), [](const string& s) { cout << s << " " << flush; });
    cout << endl;
}

string make_plural(int count, string word, string s)
{
    return count > 1 ? word + s : word;
}
