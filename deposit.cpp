#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

void input(double& invest, double& rate, double& term);
void process(double invest, double rate, double term, double& multiplier, double& futureValue);
void output(double invest, double rate, double term, double multiplier, double futureValue);

double getInput(string message);
double findMultiplier(double rate, double period);
void printData(double invest, double rate, double term);
void printResult(double multiplier, double value);

int main() 
{
    // 변수 선언
    double invest, rate, term; // 입력 변수
    double multiplier, futureValue; // 출력 변수

    input(invest, rate, term);
    process(invest, rate, term, multiplier, futureValue);
    output(invest, rate, term, multiplier, futureValue);

    return 0;
}

void input(double& invest, double& rate, double& term) 
{
    invest = getInput("투자 금액을 입력하세요: ");
    rate = getInput("1년마다의 이율을 입력하시오: ");
    term = getInput("몇 년을 넣을지 입력하시오: ");
}


void process(double invest, double rate, double term, double& multiplier, double& futureValue)
{
    multiplier = findMultiplier(rate, term);
    futureValue = multiplier * invest;
}

void output(double invest, double rate, double term, double multiplier, double futureValue)
{
    printData(invest, rate, term);
    printResult(multiplier, futureValue);
}

double getInput(string message)
{
    double input;

    do
    {
        cout << message;
        cin >> input;
    } while(input < 0.0);

    return input;
}

double findMultiplier(double rate, double period)
{
    double factor = 1 + rate / 100;
    
    return pow(factor, period);
}

void printData(double invest, double rate, double term)
{
    cout << endl << "투자 정보" << endl;
    cout << "투자 금액: " << fixed << setprecision(2) << invest << endl;
    cout << "이율: " << rate << fixed << setprecision(2);
    cout << "% (1년 기준)" << endl;
    cout << "기간: " << term << "년" << endl << endl;
}

void printResult(double multiplier, double futureValue)
{
    cout << "투자의 승수 = " << fixed << setprecision(8);
    cout << multiplier << endl;
    cout << "미래 가치 = " << fixed << setprecision(2);
    cout << futureValue << endl;
}