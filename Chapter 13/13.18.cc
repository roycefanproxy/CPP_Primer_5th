#include <iostream>
#include <string>
using namespace std;

class Employee
{
friend void print(const Employee&);
public:
	Employee();
	Employee(const string&);
private:
	string name;
	int id;
	static int id_generator;
};

int Employee::id_generator = 0;

Employee::Employee()
{
	id = ++id_generator;
}

Employee::Employee(const string& s) : name(s)
{
	id = ++id_generator;
};


void print(const Employee&);

int main()
{
	Employee a("Test1"), b("Test2"), c = b;

	print(a);
	print(b); print(c);

	return 0;
}

void print(const Employee& e)
{
	cout << e.name << ' ' << e.id << endl;
} 	
