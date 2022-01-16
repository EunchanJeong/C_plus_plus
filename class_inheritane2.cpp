#include <iostream>

#include <cassert>

#include <iomanip>

 

using namespace std;

 

class Person

{

	private:

		long identity;

	public:

		Person();

		Person(long identity);

		~Person();

		Person(const Person& person);

		void print() const;

};

 

Person :: Person()

: identity(0)

{

}

 

Person :: Person(long id)

: identity(id)

{

	assert(identity >= 0 && identity <= 100);

}

 

Person :: ~Person()

{

}

 

Person :: Person(const Person& p)

: Person(p.identity)

{

}

 

void Person :: print() const

{

	cout << "identity: " << identity << endl;

}

 

class Student : public Person

{

	private:

		double gpa;

	public:

		Student();

		Student(long identity, double score);

		~Student();

		Student(const Student& student);

		void print() const;

		

};

 

Student :: Student()

: Person(0), gpa(0)

{

}

 

Student :: Student(long identity, double score)

: Person(identity), gpa(score)

{

	assert(score >= 0 && score <= 4.5);

}

 

Student :: ~Student()

{

}

 

Student :: Student(const Student& stu)

: Person(stu), gpa(stu.gpa)

{

}

 

void Student :: print() const

{

	Person :: print();

	cout << "GPA: " << gpa << endl;

}

int main() {

	

	Person p(22);

	p.print();

	

	Student stu(11, 4.5);

	stu.print();

	

	return 0;

}