#ifndef _MyTextQuery_h_
#define _MyTextQuery_h_
#include <memory>
#include <vector>
#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <set>

struct QueryResult;
class TextQuery
{
public:
    typedef std::vector<std::string>::size_type line_no;
    TextQuery() = default;
    TextQuery(std::istream& is);
    QueryResult query(std::string& text);

private:
    std::shared_ptr<std::vector<std::string>> file_content;
};

TextQuery::TextQuery(std::istream& is)
{
    std::string buff;

    file_content = std::make_shared<std::vector<std::string>>();
    while(std::getline(is, buff))
        file_content->push_back(buff);
}

struct QueryResult
{
    typedef std::vector<std::string>::size_type line_no;
    std::shared_ptr<std::vector<std::string>> file_content;
    int occurence;
    std::shared_ptr<std::vector<line_no>> l_n;
    QueryResult(std::shared_ptr<std::vector<std::string>> fc, std::shared_ptr<std::vector<line_no>> ln, int occ) : file_content(fc), l_n(ln), occurence(occ) {}
};

QueryResult TextQuery::query(std::string& text)
{
    line_no index = 0;
    auto ln = std::make_shared<std::vector<line_no>>();
    int occurence = 0;
    for(std::string& s : *file_content)
    {
        std::istringstream words(s);
        std::string temp;

        while(words >> temp)
        {
            bool iscounted = false;
            if(text == temp)
            {
                if(!iscounted)
                {
                    iscounted = true;
                    ln->push_back(index);
                }
                ++occurence;
            }
        }
        index++;
    }

    return QueryResult(file_content, ln, occurence);
}
#endif // _MyTextQuery_h_
