#include <iostream>
#include <string>

using namespace std;

struct S_D
{
    string book_no;
    unsigned unit_sold = 0;
    double revenue = 0;

    S_D& combine(const S_D&);

    S_D() = default;
    S_D(const string &s) : book_no(s) {}
    S_D(const string& s, const unsigned u, const double r) : book_no(s), unit_sold(u), revenue(r) {}

    string isbn() const { return book_no; }

    double avg_price() const
    {
        return unit_sold ? revenue / (int) unit_sold : 0;
    }

};

S_D& S_D::combine(const S_D& item)
{
    this->revenue += item.revenue;
    this->unit_sold += item.unit_sold;

    return *this;
}

istream& read(istream&, S_D&);
ostream& print(ostream&, const S_D&);
S_D add(const S_D&, const S_D&);

int main()
{
    S_D curr, trans;

    if(read(cin, curr))
    {
        while(read(cin, trans))
        {
            if(curr.isbn() == trans.isbn())
                curr = add(curr, trans);
            else
            {
                print(cout, curr);
                curr = trans;
            }
        }
    }
    else
    {
        cout << "No book ?!" << endl;
    }

    cout << "Done." << endl;

    return 0;
}

istream& read(istream& is, S_D& item)
{
    double price = 0;

    is >> item.book_no >> item.unit_sold >> price;
    item.revenue = price * (int)item.unit_sold;

    return is;
}

ostream& print(ostream& os, const S_D& item)
{
    cout << item.isbn() << " " << item.unit_sold << " " << item.avg_price() << endl;

    return os;
}

S_D add(const S_D& a, const S_D& b)
{
    S_D* newsd = new S_D();

    *newsd = a;
    newsd->combine(b);

    return *newsd;
}

