#ifndef _TextQuery_h_
#define _TextQuery_h_
#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <memory>
#include <cctype>

static void filter(std::string&);

class QueryResult;

class TextQuery
{
public:
	typedef std::vector<std::string>::size_type line_no;
	TextQuery(std::istream&);
	TextQuery(const TextQuery&);
	TextQuery& operator=(const TextQuery&);
	~TextQuery();
	QueryResult query(const std::string&) const;
private:
	void free();
	std::vector<std::string>* content;
	std::map<std::string, std::set<line_no>*>* dict;
	int* c_counter;
};

class QueryResult
{
	friend std::ostream& operator<<(std::ostream&, const QueryResult&);
	friend class TextQuery;
public:
	typedef TextQuery::line_no line_no;
	~QueryResult() {}
	std::set<line_no>::iterator begin() const { return indices->begin(); }
	std::set<line_no>::iterator end() const { return indices->end(); }
	std::vector<std::string>* get_file() const { return content; }
	QueryResult(const std::string& s, std::vector<std::string>* c, std::set<line_no>* i)
		: word(s), content(c), indices(i) {}
private:
	std::string word;
	std::vector<std::string>* content;
	std::set<line_no>* indices;
};

TextQuery::TextQuery(std::istream& is) : content(new std::vector<std::string>), dict(new std::map<std::string, std::set<line_no>*>), c_counter(new int(1))
{
	std::string line;
	line_no index = 0;
	
	while(std::getline(is, line))
	{
		std::string word;
		std::stringstream words(line);

		content->push_back(line);

		while(words >> word)
		{
			filter(word);
			auto& loc = (*dict)[word];
			if(!loc) loc = new std::set<line_no>();
			loc->insert(index);
		}
		++index;
	}
}

TextQuery::TextQuery(const TextQuery& tq) : content(tq.content), dict(tq.dict), c_counter(tq.c_counter)
{
	++*c_counter;
}

void TextQuery::free()
{
	if(--*c_counter == 0)
	{
		delete dict;
		delete content;
		delete c_counter;
	}
}

TextQuery& TextQuery::operator=(const TextQuery& tq)
{
	if(this != &tq)
	{
		free();
		dict = tq.dict;
		c_counter = tq.c_counter;
		++*c_counter;
	}
	return *this;
}

TextQuery::~TextQuery()
{
	free();
}

QueryResult TextQuery::query(const std::string& s) const
{
	auto result = dict->find(s);
	if(result != dict->end())
		return QueryResult(s, content, result->second);
	else
		return QueryResult(s, content, new std::set<line_no>());
}

std::ostream& operator<<(std::ostream& os, const QueryResult& qr)
{
	os << qr.word << " occurred " << qr.indices->size() << std::endl;
	int x = 1;
	for(auto index : *qr.indices)
	{
		os << "\t(line " << index + 1 << ") " << qr.content->at(index) << std::endl;
	}
	return os;
}

void filter(std::string& word)
{
	std::string replace;
	for(auto& c : word)
	{
		if(isupper(c)) replace.push_back(tolower(c));
		else if(!ispunct(c)) replace.push_back(c);
	}
	word = replace;
}	

#endif // _TextQuery_h_
