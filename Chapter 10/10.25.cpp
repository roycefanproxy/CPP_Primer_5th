#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
#include <string>
using namespace std;
using namespace placeholders;

void elimdups(vector<string>&);
string make_plural(int count, string, string);
void biggies(vector<string>&, vector<string>::size_type);
bool check_size(const string&, int);

int main()
{
    vector<string> vs;
    string input;
    int size;

    while((cin >> input) && input != "done")
        vs.push_back(input);

    cout << "Size : " << flush;
    cin >> size;

    biggies(vs, size);

    return 0;
}

void elimdups(vector<string>& vec)
{
    sort(vec.begin(), vec.end());
    auto itr = unique(vec.begin(), vec.end());
    vec.erase(itr, vec.end());
}

string make_plural(int count, string word, string s) { return count > 1 ? word + s : word; }

void biggies(vector<string>& vec, vector<string>::size_type sz)
{
    elimdups(vec);
    stable_sort(vec.begin(), vec.end(), [] (const string& a, const string& b) { return a.size() < b.size(); });
    //auto word_count = partition(vec.begin(), vec.end(), [=] (const string& s) { return s.size() >= sz; });
    auto word_count = partition(vec.begin(), vec.end(), bind(check_size, _1, sz));
    vector<string>::difference_type count = word_count - vec.begin();
    cout << count << " " << make_plural(count, "word", "s") << " of length " << sz << " or longer." << endl;
    for_each(vec.begin(), word_count, [](const string& s) { cout << s << " "; });
    cout << endl;
}

bool check_size(const string& s, int sz) { return s.size() >= sz; }
