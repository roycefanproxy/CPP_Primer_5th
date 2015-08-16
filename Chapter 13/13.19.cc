#include <iostream>
#include <string>
using namespace std;

class Employee
{
friend void print(const Employee&);
public:
	Employee();
	Employee(const Employee& e) : name(e.name), id(e.id) {}
	Employee(const string& s) : name(s), id(id_generator++) {}
	Employee& operator=(const Employee& e)
	{
		id = e.id;
		name = e.name;

		return *this;
	}
private:
	string name;
	int id;
	static int id_generator;
};

Employee::Employee() { id = id_generator++; }

int Employee::id_generator = 1;

int main()
{
	Employee a("1"), b, c = a, d("2");

	print(a);
	print(b); print(c); print(d);

	return 0;
}

void print(const Employee& e)
{
	cout << e.name << ' ' << e.id << endl;
}
