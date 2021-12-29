// 다이어트 권장 칼로리 계산기

#include <iostream>
#include <iomanip>

using namespace std;

double calculateStadardWeight(double height, char sex);
double calculateCalories(double standardWeight, double activity);

int main()
{
    double height; // 키
    double standardWeight; // 표준체중
    char sex; // 성별
    double activity; // 활동량
    double recommendedCalories; // 다이어트 권장 섭취 칼로리

    cout << "다이어트 권장 섭취 칼로리 계산기 (일주일 0.5kg 감량기준)" << endl;
    
    cout << "키를 입력하시오 (cm): ";
    cin >> height;

    do {
        cout << "성별을 입력하시오 (M / F): ";
        cin >> sex;
    } while(sex != 'M' && sex != 'F');


    cout << "활동량을 입력하시오 (가벼운 활동: 25~30, 중등도 활동: 30~35, 강한 활동: 35~40, 아주 강한 활동: 40~): ";
    cin >> activity;
    
    standardWeight = calculateStadardWeight(height, sex);
    recommendedCalories = calculateCalories(standardWeight, activity);
    
    cout << endl;
    cout << "키:" << height << " cm" << endl;
    cout << "표준체중: " << fixed << setprecision(2) << standardWeight << " kg" << endl;
    cout << "권장 섭취 칼로리: " << fixed << setprecision(2) << recommendedCalories << " kcal";

    return 0;
}

// 표준체중 계산
double calculateStadardWeight(double height, char sex)
{
    if(sex == 'M') {
        return (height/100) * (height/100) * 22;
    }
    else {
        return (height/100) * (height/100) * 2116;
    }
}

// 다이어트 권장 섭취 칼로리 계산
double calculateCalories(double standardWeight, double activity)
{
    return standardWeight * activity - 500.0;
}

