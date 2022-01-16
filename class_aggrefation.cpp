#include <iostream>

#include <cassert>

 

using namespace std;

 

class Date

{

	private:

		int month;

		int day;

		int year;

	public:

		Date(int month, int day, int year);

		~Date();

		void print() const;

};

 

Date :: Date(int m, int d, int y)

: month(m), day(d), year(y)

{

	if(month < 1 || month > 12)

	{

		assert(false);

	}

	

	int daysInMonths[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	

	if(day < 1 || day > daysInMonths[month])

	{

		assert(false);

	}

}

 

Date :: ~Date()

{

}

 

void Date :: print() const

{

	cout << month << "/" << day << "/" << year << endl;

}

 

class Person

{

	private:

		long identity;

		Date birthDate;

	public:

		Person(long identity, Date birthDate);

		~Person();

		void print() const;

};

 

Person :: Person(long id, Date date)

: identity(id), birthDate(date)

{

	assert(id >= 0 && id <= 100);

}

 

Person :: ~Person()

{

}

 

void Person :: print() const

{

	cout << "id: " << identity << endl;

	cout << "생년월일: ";

	birthDate.print();

	cout << endl;

	

}

 

int main() {

	Date date(12, 31, 20220);

	date.print();

	

	Person p(10, date);

	p.print();

	

	return 0;

}