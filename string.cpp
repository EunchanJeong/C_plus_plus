#include <iostream>
#include <string>

using namespace std;

void toUpper(string& strg); // 문자열을 대문자로 바꾸는 함수
void toLower(string& strg); // 문자열을 소문자로 바꾸는 함수

int main() {

	string strg1 = "Hello World!";
	
	// string 크기
	cout << "strg1의 크기: " << strg1.size() << endl;

	// string 입력
	cout << "strg1 입력($를 입력하면 종료): ";
	getline(cin, strg1, '$');
	
	cout << "출력: " << strg1 << endl;
	
	string strg2("Welcome!");
	
	cout << "strg2[1]: " << strg2[1] << endl;
	
	// 대문자, 소문자 변경
	string strg3 = "abcdefg";
	
	cout << "strg3: " << strg3 << endl;
	
	toUpper(strg3);
	
	cout << "대문자: " << strg3 << endl;
	
	toLower(strg3);
	
	cout << "소문자: " << strg3 << endl;
	
	
	// 서부문자열
	cout << strg3.substr(4) << endl;
	cout << strg3.substr(2, 6) << endl;
}


void toUpper(string& str)
{
	int size = str.size();
	
	for(int i = 0; i < size; i++)
	{
		str[i] = toupper(str[i]);
	}
}

void toLower(string& str)
{
	int size = str.size();
	
	for(int i = 0; i < size; i++)
	{
		str[i] = tolower(str[i]);
	}
}