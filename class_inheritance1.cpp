#include <iostream>

#include <cassert>

#include <string>

 

using namespace std;

 

class Person

{

	private:

		long identity;

	public:

		void setId(long identity);

		long getId() const;

};

 

void Person :: setId(long id)

{

	identity = id;

	assert(identity >= 100 && identity <= 999);

}

 

long Person :: getId() const

{

	return identity;

}

 

class Student : public Person

{

	private:

		double gpa;

	public:

		void setGPA(double score);

		double getGPA() const;

};

 

void Student :: setGPA(double score)

{

	gpa = score;

	assert(gpa >= 0.0 && gpa <= 4.5);

}

 

double Student :: getGPA() const

{

	return gpa;

}

 

int main() {

	

	Person p;

	p.setId(111);

	

	cout << "p의 id: " << p.getId() << endl;

	

	Student st;

	st.setGPA(4.5);

	st.setId(123);

	

	cout << "st의 gpa: " << st.getGPA() << endl;

	cout << "st의 id: " << st.getId() << endl;

	

	return 0;

}