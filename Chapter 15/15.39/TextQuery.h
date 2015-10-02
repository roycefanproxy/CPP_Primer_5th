#ifndef _TextQuery_h_
#define _TextQuery_h_
#include <string>
#include <memory>
#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <sstream>

class QueryResult;

class TextQuery
{
public:
	typedef std::vector<std::string>::size_type line_no;
	TextQuery(std::istream&);
	QueryResult query(const std::string&) const;
private:
	std::shared_ptr<std::vector<std::string>> input;
	std::map<std::string, std::shared_ptr<std::set<line_no>>> result;
};

class QueryResult
{
	friend std::ostream& operator<<(std::ostream&, const QueryResult&);
public:
	using line_no = TextQuery::line_no;
	QueryResult(const std::string& s, std::shared_ptr<std::set<line_no>> set,
		    std::shared_ptr<std::vector<std::string>> file)
			: word(s), indices(set), input(file) {}
	std::set<line_no>::iterator begin() const { return indices->begin(); }
	std::set<line_no>::iterator end() const { return indices->end(); }
	std::shared_ptr<std::vector<std::string>> get_file() const
	{
		return input;
	}
private:
	std::string word;
	std::shared_ptr<std::set<line_no>> indices;
	std::shared_ptr<std::vector<std::string>> input;
};

TextQuery::TextQuery(std::istream& is) : input(new std::vector<std::string>)
{
	line_no index = 0;
	for(std::string line; std::getline(is, line); ++index)
	{
		input->push_back(line);
		std::stringstream words(line);
		for(std::string word; words >> word;)
		{
			auto& position = result[word];
			if(!position) position.reset(new std::set<line_no>);
			position->insert(index);
		}
	}
}

QueryResult TextQuery::query(const std::string& s) const
{
	auto found = result.find(s);

	if(found == result.end()) return QueryResult(s, std::make_shared<std::set<TextQuery::line_no>>(), input);
	else	return QueryResult(s, found->second, input);
};

std::ostream& operator<<(std::ostream& os, const QueryResult& qr)
{
	os << qr.word << " occurs " << qr.indices->size()
	   << (qr.indices->size() > 1 ? " times" : " time") << std::endl;
	for(auto i : *qr.indices)
		os << "\t(line " << i + 1 << ") " << qr.input->at(i) << std::endl;
	return os;
}

#endif // _TextQuery_h_

