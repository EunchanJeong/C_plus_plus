#include <string>

#include <iostream>

using namespace std;

 

int main()

{  

  // 변수 선언

  string text, word;

  string delimiter(" \n");

  string:: size_type wStart, wEnd;

  string::size_type npos = -1;

  // 한 줄 입력받기

  cout << "한 줄을 입력하세요: " << endl;

  getline(cin, text);

  // 문자 탐색하고 단어 추출

  cout << "추출한 단어:" << endl;

 

	wStart = text.find_first_not_of(delimiter, 0);

	

	while(wStart < npos)

	{

		wEnd = text.find_first_of(delimiter, wStart);

		cout << text.substr(wStart,  wEnd - wStart) << endl;

		wStart = text.find_first_not_of(delimiter, wEnd);

	}

	

  return 0;

}