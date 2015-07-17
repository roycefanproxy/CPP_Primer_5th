#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

string make_plural(int, string, string);
void elimdups(vector<string>&);
void biggies(vector<string>&, vector<string>::size_type);

int main()
{
    vector<string> vs;
    string input, done("done");
    int size;

    while((cin >> input) && input != done)
        vs.push_back(input);
    cout << "size : ";
    cin >> size;
    biggies(vs, size);

    return 0;
}

string make_plural(int count, string word, string s) { return count > 1 ? word + s : word; }

void elimdups(vector<string>& vec)
{
    sort(vec.begin(), vec.end());
    auto x = unique(vec.begin(), vec.end());
    vec.erase(x, vec.end());
}

void biggies(vector<string>& vec, vector<string>::size_type sz)
{
    elimdups(vec);
    stable_sort(vec.begin(), vec.end(),
                [](const string& a, const string& b) { return a.size() < b.size(); });
    vector<string>::iterator wc = stable_partition(vec.begin(), vec.end(),
                                                   [=] (const string& s) { return s.size() >= sz; });

    vector<string>::difference_type count = wc - vec.begin();

    cout << count << " " << make_plural(count, string("word"), string("s")) << " of length " << sz << " or longer." << endl;
    for_each(vec.begin(), wc, [] (const string& s) { cout << s << ends; });
}
