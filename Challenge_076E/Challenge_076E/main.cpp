#include <algorithm>
#include <iostream>
#include <sstream>
#include <list>
#include <string>

std::string titleCase(std::string phrase, std::list<std::string>& exceptions) {
	std::string result = "";

	if(phrase.empty())
		return result;

	std::stringstream phraseStream(phrase);
	while(phraseStream.good()) {
		std::string word;
		phraseStream >> word;
		std::transform(word.begin(), word.end(), word.begin(), tolower);
		if(result.empty() || std::find(exceptions.begin(), exceptions.end(), word) == exceptions.end())
			word.replace(0, 1, std::string(1, toupper(word[0])));
		result += word + ' ';
	}
	result.erase(result.length() - 1);

	return result;
}

int main(int argc, char** argv) {
	if(argc == 1) {
		std::cerr << "Usage: " << argv[0] << " <string:titlecase> [<string:exception1>, [...]]" << std::endl;
		return 1;
	}

	std::string phrase = argv[1];

	std::list<std::string> exceptions;
	for(int i = 2; i < argc; i++)
		exceptions.push_back(std::string(argv[i]));

	std::cout << titleCase(phrase, exceptions);
}