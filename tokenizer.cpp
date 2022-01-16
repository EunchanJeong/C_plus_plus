#include <iostream>

#include <string>

 

using namespace std;

 

class Tokenizer

{

	private:

		string target;

		string delim;

		int begin;

		int end;

	public:

		Tokenizer(const string& target, const string& delim);

		~Tokenizer();

		bool moreToken() const;

		string nextToken();

};

 

Tokenizer :: Tokenizer(const string& t, const string& d)

: target(t), delim(d)

{

	begin = target.find_first_not_of(delim, 0);

	end = target.find_first_of(delim, begin);

}

Tokenizer :: ~Tokenizer()

{

}

 

bool Tokenizer :: moreToken() const

{

	return (begin != -1);

}

 

string Tokenizer :: nextToken()

{

	string token = target.substr(begin, end - begin);

	begin = target.find_first_not_of(delim, end);

	end = target.find_first_of(delim, begin);

	

	return token;

}

 

int main() {

	string target("SPRING SUMMER FALL WINTER \n");

	string delim(" \n");

	

	Tokenizer t(target, delim);

	

	while(t.moreToken())

	{

		cout << t.nextToken() << endl;

	}

	return 0;

}