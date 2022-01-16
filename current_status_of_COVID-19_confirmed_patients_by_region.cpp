/*
    코로나 지역별 확진자 현황
	
	지역별 확진자 수를 입력받아 어제 확진자 수, 오늘 확진자 수, 변동 인원(오늘 확진자 수 - 어제 확진자 수), 누적 인원(누계)을 지역별로 출력한다.
	(새로 입력받은 확진자 수 = 오늘, 이전에 입력받은 확진자 수 = 어제)
	
	지역별 오늘 확진자 수 중 가장 큰 값을 괄호로 표시하여 출력한다.
	지역별 누적 확진자 수 중 가장 큰 값을 괄호로 표시하여 츨력한다.
	
	class를 통해 확진자 수를 계산하고 출력한다.
	확진자 수를 입력받을 때 음수일 경우 try-catch문을 통해 예외처리를 한다.
*/

#include <iostream>
#include<iomanip>
#include <string>
using namespace std;

class Covid19Counter
{
	private:
		int* today;     // 지역별 오늘 확진자 수 (배열, 포인터 변수)
		int* yesterday; // 지역별 어제 확진자 수 (배열, 포인터 변수)
		int* total;	    // 지역별 누적 확진자 수 (누계) (배열, 포인터 변수)
		string* cities; // 지역별 이름을 저장한 배열 (포인터변수)
	
		int todayMax;  // 지역별 오늘 확진자 수 중 가장 큰 값
		int totalMax;  // 지역별 누적 확진자 수 중 가장 큰 값
	
	public:
		Covid19Counter(int* today, int* yesterday, int* total, string* cities);  // 생성자
		~Covid19Counter();  // 소멸자
	
		void update(int* input);    // 지역별 확진자 수를 최신화한다.
		void print();  // 지역별로 어제 확진자 수, 오늘 확진자 수, 변동 인원(오늘-어제), 누적 인원(누계)를 출력한다.
};

Covid19Counter::Covid19Counter(int* tDay, int* y, int* t, string* c)       // 생성자
:today(tDay), yesterday(y), total(t), cities(c), todayMax(0), totalMax(0)
{
}

Covid19Counter::~Covid19Counter()  // 소멸자
{
}

void Covid19Counter::update(int* input) // 지역별 확진자 수를 최신화한다.
{
	int temp;
	
	// 이전에 입력받은 확진자 수를 어제 확진자수의 배열에 저장한다.
	// 새로 입력받은 확진자 수를 오늘 확진자수의 배열에 저장한다.
	for(int i = 0; i < 17; i++)
	{
		yesterday[i] = today[i];
		today[i] = input[i];
		
		total[i] += input[i];
	}
	
	// 지역별 오늘 확진자 수 중 제일 큰 값을 찾는다.
	// 지역별 누적 확진자 수 중 제일 큰 값을 찾는다.
	for(int i = 0; i < 17; i++)
	{
		if(today[i] > todayMax)
		{
			todayMax = today[i];
		}
		
		if(total[i] > totalMax)
		{
			totalMax = total[i];
		}
	}
	
}
void Covid19Counter::print() // 지역별로 어제 확진자 수, 오늘 확진자 수, 변동인원(오늘-어제), 누적인원(누계)를 출력한다.
{
	for(int i = 0; i < 17; i++)
	{
		cout << "\t" << cities[i]; 
	}
	cout << endl;
	
	cout << "어제";
	for(int i = 0; i < 17; i++)
	{
		cout << "\t" << yesterday[i]; 
	}
	cout << endl;
	
	cout << "오늘";
	for(int i = 0; i < 17; i++)
	{
		if(today[i] == todayMax)   // 지역별 오늘 확진자 수 중 제일 큰 값은 괄호로 표시해준다.
		{
			cout << "\t" << "(" << today[i] << ")";
		}
		else
		{
			cout << "\t" << today[i];
		}
	}
	cout << endl;
	
	cout << "변동";
	for(int i = 0; i < 17; i++)
	{
		int change = today[i]-yesterday[i];
		
		if(change > 0)
		{
			cout << "\t" << "+" << change; 
		}
		else
		{
			cout << "\t" << change;
		}
			
	}
	cout << endl;
	
	cout << "누적";
	for(int i = 0; i < 17; i++)
	{
		if(total[i] == totalMax) // 지역별 누적 확진자 수 중 제일 큰 값은 괄호로 표시해준다.
		{
			cout << "\t" <<  "(" << total[i] << ")";
		}
		else
		{
			cout << "\t" << total[i];
		}
	}
	cout << endl << endl;
	
	todayMax = 0;
	totalMax = 0;
}

int main() {
	int today[17];
	int yesterday[17];
	int total[17];
	string cities[17] = {"서울", "부산", "대구", "인천", "광주", "대전", "울산", "세종", "경기", "강원", "충북", "충남", "전북", "전남", "경북", "경남", "제주"};
	
	int input[17];
	
	for(int i = 0; i < 17; i++)
	{
		today[i] = 0;
		yesterday[i] = 0;
		total[i] = 0;
	}

	Covid19Counter covid19Counter(today, yesterday, total, cities);
	
	while(true)
	{
		try
		{
			cout << "지역별 확진자수를 입력하세요.(양수만 입력하세요.)" << endl;
			
			for(int i = 0; i < 17; i++)  // 지역별로 확진자 수 입력
			{
				cout << cities[i] << ": ";
				cin >> input[i];
				
				if(input[i] < 0) // 양수가 아닌 음수를 입력하였을 때 예외처리
				{
					throw 0; 
				}
			}
			cout << endl;
			
			covid19Counter.update(input);
			covid19Counter.print();
			
		}
		catch(int x)
		{
			cout << "음수를 입력하셨습니다! 다시 입력해주세요." << endl;
		}
	}
	
	return 0;
}