#include <iostream>

#include <string>

 

using namespace std;

 

class Base

{

	public:

		virtual void print() const { cout << "베이스 클래스" << endl; }

};

 

class Derive : public Base

{

	public:

		virtual void print() const { cout << "파생 클래스" << endl; }

};

 

int main() {

	

	Base* ptr;

	

	ptr = new Base();

	ptr -> print();

	delete ptr;

	

	ptr = new Derive();

	ptr -> print();

	delete ptr;

	

	return 0;

}