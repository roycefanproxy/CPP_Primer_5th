#ifndef _TEXTQUERY_H_
#define _TEXTQUERY_H_
#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <map>
#include <set>

class QueryResult;

class TextQuery final
{
public:
	typedef std::vector<std::string>::size_type line_no;
	TextQuery(std::istream&);
	QueryResult query(const std::string&) const; //	extra parameters are for requirement of 15.42-c
private:
	std::shared_ptr<std::vector<std::string>> content;
	std::map<std::string, std::shared_ptr<std::set<line_no>>> dict;
};

class QueryResult final
{
	friend std::ostream& print(std::ostream&, const QueryResult&,
				   const TextQuery::line_no&, const TextQuery::line_no&);
public:
	typedef TextQuery::line_no line_no;
	std::set<line_no>::iterator begin() const { return indices->begin(); }
	std::set<line_no>::iterator end() const { return indices->end(); }
	std::shared_ptr<std::vector<std::string>> get_file() const { return content; }
	QueryResult(const std::string& s,
		    std::shared_ptr<std::vector<std::string>> c,
		    std::shared_ptr<std::set<line_no>> i) // extra parameters are for requirement of 15.42-c
			: word(s), content(c), indices(i) {}
private:
	std::string word;
	std::shared_ptr<std::vector<std::string>> content;
	std::shared_ptr<std::set<line_no>> indices;
};

std::ostream& operator<<(std::ostream&, const QueryResult&);

#endif // _TEXTQUERY_H_
