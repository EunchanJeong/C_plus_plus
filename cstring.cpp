#include <iostream>
#include <cstring>

using namespace std;

int main() {
	char str1[] = "Hello my friends.";
	char str2[] = {'H', 'e', 'l', 'l', 'o', '\0'};
	
	// cstring 길이
	int x = strlen(str1);
	
	cout << "str1의 길이: " << x << endl;
	cout << "str2의 길이: " << strlen(str2) << endl;
	
	// cstring 입력 및 출력
	char str3[20];
	
	cout << "str3의 값을 입력하시오: ";
	cin >> str3; // 공백을 포함한 입력을 받지못한다.
	
	cout << "str3: " << str3 << endl;
	getchar();
	
	char lines[3][80];

	for(int i = 0; i < 3; i++)
	{
		cout << "한 줄을 입력하시오: ";
		cin.getline(lines[i], 80);  // 공백포함 입력
	}
	
	cout << "출력" << endl;
	
	for(int i = 0; i < 3; i++)
	{
		cout << lines[i] << endl;
	}
	
	
	// cstring 인덱스 활용
	char str4[] = "Welcome to my house!";
	
	cout << "str4: " << str4 << endl;
	cout << "str4[3]: " << str4[3] << endl;
	
	str4[3] = 'L';
	
	cout << "str4: " << str4 << endl;
	cout << "str4[3]: " << str4[3] << endl;
	
	
	// 문자 탐색후 변경
	char str5[] = "Hello friends.";
	
	char* cPtr = strchr(str5, 'e'); // 처음에 등장하는 e 찾기
	*cPtr = 'E';
	
	cout << "첫번째 변경 후의 str5: " << str5 << endl;
	
	cPtr = strrchr(str5, 'e');  // 마지막에 등장하는 e 찾기
	*cPtr = 'E';
	
	cout << "두번째 변경 후의 str5: " << str5 << endl;
	
	
	// 문자열 비교
	
	const char* str6 = "Hello Alice.";
	const char* str7 = "Hello John.";
	const char* str8 = "Hello Betsy.";
	// 문자열 전체 비교
	cout << "str6과 str7 비교하기: ";
	cout << strcmp(str6, str7) << endl; 
	
	cout << "str7와 str8 비교하기: ";
	cout << strcmp(str7, str8) << endl;
	
	// 앞의 5문자만 비교
	cout << "str6과 str7의 앞 5문자만 비교하기: ";
	cout << strncmp(str6, str7, 5) << endl;
	
	
	// 문자열 결합

	char str9[20] = "This is ";
	const char*  str10 = "a string.";
	strcat(str9, str10);
	cout << "str9: " << str1 << endl;

	// strncat 함수 사용
	char str11[20] = "abcdefghijk";
	const char* str12 = "ABCDEFGHIJK";
	strncat(str11, str12, 4);
	cout << "str11: " << str11 << endl;


	return 0;
}