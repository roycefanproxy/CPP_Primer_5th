#ifndef _TextQuery_h_
#define _TextQuery_h_
#include <iostream>
#include <fstream>
#include <sstream>
#include <memory>
#include <map>
#include <set>
#include <vector>
#include <string>

class QueryResult;
class TextQuery
{
public:
	typedef std::vector<std::string>::size_type line_no;
	TextQuery(std::istream& is);

	QueryResult query(const std::string& s) const;

private:
	std::shared_ptr<std::vector<std::string>> file_content;
	std::map<std::string, std::shared_ptr<std::set<line_no>>> dict;
};

class QueryResult
{
public:
	typedef std::vector<std::string>::size_type line_no;
	QueryResult(std::string s, std::shared_ptr<std::set<line_no>> ln, std::shared_ptr<std::vector<std::string>> lines) : word(s), indices(ln),
		file_content(lines) {}

	const std::string word;
	std::shared_ptr<std::set<line_no>> indices;
	std::shared_ptr<std::vector<std::string>> file_content;
};

TextQuery::TextQuery(std::istream& is) : file_content(new std::vector<std::string>)
{
	std::string line;

	while (std::getline(is, line))
	{
		std::string word;
		std::istringstream words(line);

		file_content->push_back(line);
		while (words >> word)
		{
			auto& set_ptr = dict[word];
			if (set_ptr == nullptr)
				set_ptr.reset(new std::set<line_no>);
			set_ptr->insert(file_content->size() - 1);
		}
	}
}

QueryResult TextQuery::query(const std::string& s) const
{
	auto set_ptr = dict.find(s);

	if (set_ptr != dict.end())
		return QueryResult(s, set_ptr->second, file_content);
	else
	{
		std::shared_ptr<std::set<line_no>> ret_val(new std::set<line_no>);
		return QueryResult(s, ret_val, file_content);
	}
}

std::ostream& print(std::ostream& os, const QueryResult& qr)
{
	os << "The word " << qr.word << " you searched for occurred " << qr.indices->size() << " time(s).\n" << std::endl;

	if (qr.indices->size() == 0) return os;
	for (auto no : *qr.indices)
		os << "(line " << no + 1 << ") " << *(qr.file_content->begin() + no) << std::endl;

	return os;
}
#endif // _TextQuery_h_
