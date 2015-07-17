#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;
typedef unordered_map<string, string> umap;

umap buildmap(string&);
string interpret(umap&, string&);
void transform(string&, string&, vector<string>&);
bool savefile(vector<string>&, string&);

int main()
{
    string sourcefile, datafile;
    vector<string> output;
    cout << "Enter the source file of mapping : ";
    if(getline(cin, sourcefile))
    {
        cout << "Enter the data file : ";
        getline(cin, datafile);
        transform(sourcefile, datafile, output);
        cout << "Do you want to save the output? [Y/N]" << endl;
        string response;
        cin >> response;
        cin.ignore();
        if(response[0] == 'y' || response[0] == 'Y')
        {
            cout << "Enter the file name : ";
            string filename;
            getline(cin, filename);
            if(!savefile(output, filename))
                cout << "Failed to save the output." << endl;
        }
        cout << "Done." << endl;
    }
    else
        cout << "No file?" << endl;

    return 0;
}

umap buildmap(string& filename)
{
    umap map;
    ifstream fs(filename);
    string key, value;

    if(!fs.is_open())
    {
        cout << "Failed to open source file." << endl;
        return umap();
    }

    while(fs >> key)
    {
        getline(fs, value);
        map[key] = value.substr(1);
    }
    fs.close();

    return map;
}

string interpret(umap& interpreter, string& word)
{
    auto location = interpreter.find(word);
    if(location != interpreter.end())
        return location->second;
    else
        return word;
}

void transform(string& sourcefile, string& datafile, vector<string>& output)
{
    umap interpreter = buildmap(sourcefile);
    ifstream input(datafile);
    string line, word;
    bool isfirstword;

    if(!input.is_open())
    {
        cout << "Failed to open input file." << endl;
        exit(1);
    }
    while(getline(input, line))
    {
        string result;
        isfirstword = true;
        stringstream getword(line);
        while(getword >> word)
        {
            word = interpret(interpreter, word);
            if(isfirstword)
                isfirstword = false;
            else
            {
                cout << ' ';
                result += ' ';
            }
            cout << word;
            result += word;
        }
        cout << endl;
        output.push_back(result);
    }

    input.close();
}

bool savefile(vector<string>& output, string& filename)
{
    ofstream fs(filename);

    if(fs.is_open())
    {
        for(auto& sentence : output)
            fs << sentence << endl;
        fs.close();

        return true;
    }
    else
        cout << "Failed to open save file." << endl;
    return false;
}
