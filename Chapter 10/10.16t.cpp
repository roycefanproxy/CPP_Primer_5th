#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

string make_plural(int, string, string);
void elimdups(vector<string>&);
void biggies(vector<string>&, vector<string>::size_type);

int main()
{
    vector<string> vs;
    string input;
    int size;

    while((cin >> input) && input != "done")
        vs.push_back(input);

    cout << "Size :" << ends;
    cin >> size;

    biggies(vs, size);

    return 0;
}

string make_plural(int c, string word, string s) { return c > 1 ? word + s : word; }

void elimdups(vector<string>& vs)
{
    sort(vs.begin(), vs.end());
    auto itr = unique(vs.begin(), vs.end());
    vs.erase(itr, vs.end());
}

void biggies(vector<string>& vec, vector<string>::size_type sz)
{
    elimdups(vec);
    stable_sort(vec.begin(), vec.end(),
                [] (const string& a, const string& b) { return a.size() < b.size(); });
    auto word_count = find_if(vec.begin(), vec.end(),
                              [sz] (const string& s) { return s.size() > sz; });
    auto count = word_count - vec.begin();
    cout << count << " " << make_plural(count, "word", "s") << " of length " << sz << " or shorter." << endl;
    for_each(vec.begin(), word_count,
             [] (const string& s) { cout << s << endl; });
}
