#include "TextQuery.h"
#include <sstream>
#include <cctype>

static void filter(std::string&);
static void line_cat(std::string&, const std::string&);

TextQuery::TextQuery(std::istream& is) : content(new std::vector<std::string>)
{
	std::string line;
	line_no counter = 0;

	while(std::getline(is, line))
	{
		//	to fulfill the requirement of exercise 15.42-a
reloop:
		static std::string temp;
		auto c = line.rbegin();
		if(*c == '\"')
		{
			if(*(c + 1) == ',')
			{
				if(std::getline(is, temp))
				{
					line_cat(line, temp);
					goto reloop;	// bypass the loop condition
				}
			}
		}
		else if(*c != '.')
		{
			if(std::getline(is, temp))
			{
				line_cat(line, temp);
				goto reloop; 	// bypass the loop condition
			}
		}
		
		content->push_back(line);
		std::stringstream words(line);
		std::string word;

		while(words >> word)
		{
			filter(word);
			auto& loc = dict[word];
			if(!loc) loc.reset(new std::set<line_no>);
			loc->insert(counter);
		}
		++counter;
	}
}

void line_cat(std::string& dest, const std::string& source)
{
	dest += "\n\t\t\t";
	dest += source;
}

QueryResult TextQuery::query(const std::string& s) const
{
	static QueryResult no_data(s, content, std::make_shared<std::set<line_no>>());
	auto result = dict.find(s);
	if(result == dict.end())
		return no_data;
	else
		return QueryResult(s, content, result->second);
}

void filter(std::string& word)
{
	std::string new_word;
	for(auto& c : word)
	{
		if(!ispunct(c) || c == '\'' || c == '-' )
		{
			if(isupper(c)) c = tolower(c);
			new_word.push_back(c);
		}
	}
	word = new_word;
}

std::ostream& print(std::ostream& os, const QueryResult& qr, const TextQuery::line_no& lower_b, const TextQuery::line_no& upper_b)
{
	if(lower_b > upper_b)
		return os << "illegal range." << std::endl;
	os << "\"" << qr.word << "\" occurred " << qr.indices->size() << (qr.indices->size() > 0 ? " times." : " time.") << std::endl;
	for(auto& index : *qr.indices)
	{
		if(lower_b <= index && index <= upper_b)
			os << "\t(sentence " << index + 1 << ")\t" << qr.content->at(index) << std::endl;
	}
	return os;
}
