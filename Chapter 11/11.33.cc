#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <sstream>
#include <vector>
using namespace std;
typedef map<string, string> tmap;
tmap buildmap(string&);
void transform_file(string&, string&, vector<string>&);
string transform(tmap&, string&);
bool savefile(vector<string>&, string&);

int main()
{
    string map_source, datafile;
    vector<string> output;
    string response;

    cout << "Enter the source of mapping : ";
    if(cin >> map_source)
    {
        cout << "Enter the input file : ";
        if(cin >> datafile)
        {
            transform_file(map_source, datafile, output);
            cout << "Transformation is done. Do you like to save the output? [Y/N]" << endl;
            cin >> response;
            if(response[0] == 'y' || response[0] == 'Y')
            {
                cout << "Enter the output filename : ";
                cin >> response;
                if(!savefile(output, response))
                    cout << "Failed to save." << endl;
            }
            cout << "Done." << endl;
        }
        else
            cout << "No quest?" << endl;
    }
    else
        cout << "No file?" << endl;

    return 0;

}

void transform_file(string& map_source, string& datafile_name, vector<string>& output)
{
    auto mapper = buildmap(map_source);
    ifstream datafile(datafile_name);
    string line, key, mappedword;
    bool isfirstword;

    if(!datafile.is_open())
    {
        cout << "Failed to open datafile." << endl;
        return;
    }

    while(getline(datafile, line))
    {
        stringstream words(line);
        string vec_value;
        isfirstword = true;
        while(words >> key)
        {
            if(isfirstword)
                isfirstword = false;
            else
            {
                cout << ' ';
                vec_value += " ";
            }
            mappedword = transform(mapper, key);
            vec_value += mappedword;
            cout << mappedword;
        }
        cout << endl;
        output.push_back(vec_value);
    }

    datafile.close();
}

tmap buildmap(string& filename)
{
    tmap mapper;
    ifstream fs(filename);
    string key, value;

    if(!fs.is_open())
    {
        cout << "Failed to open source of mapping." << endl;
        return tmap();
    }
    while(fs >> key)
    {
        getline(fs, value);
        mapper[key] = value.substr(1);
    }

    fs.close();
    return mapper;
}

string transform(tmap& mapper, string& word)
{
    auto itr = mapper.find(word);

    if(itr == mapper.end())
        return word;
    else
        return itr->second;
}

bool savefile(vector<string>& output, string& filename)
{
    ofstream fs(filename);

    if(fs.is_open())
    {
        for(auto& line : output)
            fs << line << '\n';
        fs.close();
        return true;
    }
    else
        return false;
}
