#ifndef _TextQuery_h_
#define _TextQuery_h_
#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <set>
#include <memory>
#include <vector>
#include <algorithm>
#include <cctype>

class QueryResult;

class TextQuery
{
public:
	typedef std::vector<std::string>::size_type line_no;
	TextQuery(std::istream&);
	~TextQuery() = default;
	QueryResult query(const std::string&) const;
private:
	std::shared_ptr<std::vector<std::string>> content;
	std::map<std::string, std::shared_ptr<std::set<line_no>>> dictionary;
};

class QueryResult
{
	friend QueryResult TextQuery::query(const std::string&) const;
	friend std::ostream& operator<<(std::ostream&, const QueryResult&);
private:
	typedef TextQuery::line_no line_no;
	QueryResult(const std::string& s,
		    std::shared_ptr<std::vector<std::string>> c,
		    std::shared_ptr<std::set<line_no>> i) :
			word(s), content(c), indices(i) {}
	std::string word;
	std::shared_ptr<std::vector<std::string>> content;
	std::shared_ptr<std::set<line_no>> indices;
};

TextQuery::TextQuery(std::istream& is) : content(new std::vector<std::string>)
{
	std::string line;
	line_no index = 0;
	while(std::getline(is, line))
	{
		std::stringstream words(line);
		std::string word;

		content->push_back(line);
		while(words >> word)
		{
			auto& pos = dictionary[word];
			if(!pos)
				pos.reset(new std::set<line_no>);
			pos->insert(index);
		}
		++index;
	}

}

QueryResult TextQuery::query(const std::string& s) const
{
	static QueryResult null_val(s, content, std::make_shared<std::set<line_no>>());
	auto loc = dictionary.find(s);
	if(loc != dictionary.end())
		return QueryResult(s, content, loc->second);
	else
		return null_val;
}

std::ostream& operator<<(std::ostream& os, const QueryResult& qr)
{
	os << qr.word << " occurs " << qr.indices->size() 
	   << (qr.indices->size() > 1 ? " times" : " time") << '.' << std::endl;
	for(auto& itr : *qr.indices)
		os << "\t(line " << itr + 1 << ") " << qr.content->at(itr)
		   << std::endl;
	return os;
}

#endif // _TextQuery_h_
