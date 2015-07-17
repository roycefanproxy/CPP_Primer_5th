#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

struct num_list
{
    string name;
    vector<string> phone_num;
};

void add_num(vector<num_list>&);
void show_list(const vector<num_list>&);

int main(void)
{
    int selection;
    vector<num_list> name_list;

    cout << "Add number(s) to list or Show numbers from list?" << endl;
    cout << "1: add number." << flush;
    cout << "\t2: show numbers." << endl;
    cin >> selection;

    switch(selection)
    {
    case 1:
        add_num(name_list);
        break;
    case 2:
        show_list(name_list);
        break;
    }

}

void add_num(vector<num_list>& l)
{
    string f_name;
    cout << "Filename : " << ends;
    cin >> f_name;
    ofstream file(f_name, ofstream::app);
    if(file)
    {
        num_list item;
        cout << "Enter the name and the phone number(s) in one line." << endl;
        cin >> item.name;
        while(cin >> f_name)
            item.phone_num.push_back(f_name);

        file << item.name;
        for(const auto& x : item.phone_num)
            file << " " << x;
        file << '\n';
        cout << "Done." << endl;

        file.close();
    }
    else
    {
        cerr << "Failed to open the file." << endl;
    }
}

void show_list(const vector<num_list>& l)
{
    string f_name;
    cout << "Filename : " << ends;
    cin >> f_name;
    ifstream file(f_name);
    if(file)
    {
        while(getline(file, f_name))
            cout << f_name << endl;
        file.close();
    }



}
