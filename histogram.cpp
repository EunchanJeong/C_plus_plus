#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main()
{
    const int CAPACITY = 10;
    int frequencies[CAPACITY] = {0};
    ifstream integerFile;

    integerFile.open("integer.txt");

    if(!integerFile)
    {
        cout << "에러. 파일을 열 수 없습니다." << endl;
        return 0;
    }

    int data;
    int size = 0;

    while(integerFile >> data)
    {
        if(data >= 0 && data <= 9)
        {
            size++;
            frequencies[data]++;
        }
    }

    integerFile.close();

    cout << "유효한 데이터 개수: " << size << endl;

    for(int i = 0; i < 10; i++)
    {
        cout << setw(3) << i << " ";

        for(int j = 1; j <= frequencies[i]; j++)
        {
            cout << '*';
        }

        cout << " " << frequencies[i] << endl;
    }

    return 0;
}