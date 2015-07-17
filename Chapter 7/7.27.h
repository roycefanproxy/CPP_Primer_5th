#ifndef _7_23h_
#define _7_23h_
#include <iostream>

class Screen
{
public:
    typedef std::string::size_type pos;
    Screen() : contents(height * width, ' ') {}
    Screen(pos h, pos w) : height(h), width(w), contents(h * w, ' ') {}
    Screen(pos h, pos w, char content_val) : height(h), width(w), contents(h * w, content_val) {}
    Screen& move(pos row, pos column)
    {
        cursor = row * width + column;
        return *this;
    }
    Screen& set(char x)
    {
        contents[cursor++] = x;

        return *this;
    }
    Screen& set(pos row, pos column, char x)
    {
        cursor = width * row + column;
        contents[cursor++] = x;

        return *this;
    }

    Screen& display(std::ostream& os)
    {
        do_display(os);
        return *this;
    }

    const Screen& display(std::ostream& os) const
    {
        do_display(os);
        return *this;
    }

private:
    void do_display(std::ostream& os) const
    {
        os << contents;
    }

    pos height = 20, width = 130;
    mutable pos cursor = 0;
    std::string contents;
};
#endif // _7_23h_

