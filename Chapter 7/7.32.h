#ifndef _7_32_h_
#define _7_32_h_
#include <iostream>
#include <vector>

class Window_mngr;


class Screen
{
    friend class Window_mngr;

public:
    typedef std::string::size_type pos;
    Screen() : height(5), width(15), content(height * width, ' ') {}
    Screen(pos h, pos w, char c) : height(h), width(w), content(h * w, c) {}
    Screen& move(pos row, pos column)
    {
        cursor = row * width + column;

        return *this;
    }

    char get(void) const
    {
        return content[cursor];
    }

    char get(pos row, pos column) const
    {
        return content[row * width + column];
    }

    const Screen& move(pos row, pos column) const
    {
        cursor = row * width + column;

        return *this;
    }

    Screen& set(char c)
    {
        content[cursor] = c;

        return *this;
    }

    Screen& set(pos row, pos column, char c)
    {
        content[row * width + column] = c;

        return *this;
    }

    const Screen& display(std::ostream& os) const
    {
        do_display(os);

        return *this;
    }

    Screen&  display(std::ostream& os)
    {
        do_display(os);

        return *this;
    }

private:
    pos height = 5, width = 15;
    mutable pos cursor = 0;
    std::string content;

    void do_display(std::ostream& os) const
    {
        os << content;
    }
};


class Window_mngr
{
public:
    typedef std::vector<Screen>::size_type ScreenIndex;
    void clear(ScreenIndex);
    ScreenIndex addScreen(Screen&);
    Screen& get(ScreenIndex i)
    {
        return screens[i];
    }

private:
    std::vector<Screen> screens{Screen()};
};


void Window_mngr::clear(ScreenIndex i)
{
    screens[i].content = std::string(screens[i].height * screens[i].width, ' ');

}

Window_mngr::ScreenIndex Window_mngr::addScreen(Screen& s)
{
    screens.push_back(s);

    return screens.size() - 1;
}



#endif // _7_32_h_
