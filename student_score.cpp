# include <iostream>
using namespace std;

int main() 
{
    int s1, s2, s3, min, max, avg;

    cout << "첫번째 입력: ";
    cin >> s1;
    cout << "두번째 입력: ";
    cin >> s2;
    cout << "세번째 입력: ";
    cin >> s3;

    // 가장 큰 수 찾기
    if((s1 > s2) && (s1 > s3)) {
        max = s1;
    }
    else if((s2 > s1) && (s2 > s3)) {
        max = s2;
    }
    else {
        max = s3;
    }

    // 가장 작은 수 찾기
    if((s1 < s2) && (s1 < s3)) {
        min = s1;
    }
    else if((s2 < s1) && (s2 < s3)) {
        min = s2;
    }
    else {
        min = s3;
    }

    // min, max의 평균 구하기
    int temp = min + max;

    if(temp % 2 == 1) {
        temp += 1;
    }

    avg = temp / 2;

    cout << "입력한 점수 = " << s1 << " " << s2 << " " << s3 << endl;
    cout << "최대값 = " << max << " 최소값 = " << min << endl;
    cout << "평균값 = " << avg; 
}