#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

int main()
{
    fstream io_file("17.11.h.h", fstream::in | fstream::out | fstream::ate);

    if (!io_file)
    {
        cerr << "Failed to open file." << endl;
        return EXIT_FAILURE;
    }
    
    string line;
    auto end_mark = io_file.tellg();
    io_file.seekg(0, fstream::beg);
    size_t count = 0;

    while (io_file && io_file.tellg() != end_mark && getline(io_file, line))
    {
        count += line.size() + 1;
        auto mark = io_file.tellg();
        io_file.seekp(0, fstream::end);
        io_file << count;
        if (mark != end_mark)
            io_file << ' ';
        io_file.seekg(mark, fstream::beg);
    }
    io_file << '\n';

    return 0;
}
