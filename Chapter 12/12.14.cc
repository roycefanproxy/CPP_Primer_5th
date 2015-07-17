#include <iostream>
#include <memory>
using namespace std;

struct destination;
struct connection;
typedef shared_ptr<destination> desti;
connection connect(desti);
void disconnect(connection*);
void end_connection(connection*);
void f(destination&);

int main()
{
    destination des;
    f(des);
}

void f(destination& des)
{
    auto con = connect(des);
    auto c = make_shared<connection>(con, end_connection);

    //blablabla


}

void end_connection(connection* p)
{
    disconnect(p);
}
