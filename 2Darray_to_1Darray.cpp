#include <iostream>
#include <iomanip>

using namespace std;

void rowTransform(const int originArray[][4], int colSize, int rowArray[]);     // 행방향으로 선형변환
void colTransform(const int originArray[][4], int rowSize, int colArray[]);     // 열방향으로 선형변환
void printTwoDimensional(const int twoDimentional[][4], int rowSize);           // 2차원 배열 출력
void printOneDimentsioal(const int oneDimentioal[], int size);                  // 1차원 배열 출력

int main()
{
    int originArray[2][4] = {{0, 1, 2, 3}, {10, 11, 12, 13}};
    int rowArray[8];
    int colArray[8];

    rowTransform(originArray, 4, rowArray);
    colTransform(originArray, 2, colArray);

    cout << " 원본 배열 " << endl;
    printTwoDimensional(originArray, 2);

    cout << "행방향으로 선형변환한 결과: ";
    printOneDimentsioal(rowArray, 8);

    cout << "열방향으로 선형변환한 결과: ";
    printOneDimentsioal(colArray, 8);
}

// 행방향으로 선형변환
void rowTransform(const int originArray[][4], int colSize, int rowArray[])
{
    int row = 0;
    int col = 0;

    for(int i = 0; i < 8; i++)
    {
        rowArray[i] = originArray[row][col];

        col++;

        if(col > colSize-1)
        {
            row++;
            col = 0;
        }
    }
}

// 열방향으로 선형변환
void colTransform(const int originArray[][4], int rowSize, int colArray[])
{
    int row = 0;
    int col = 0;

    for(int i = 0; i < 8; i++)
    {
        colArray[i] = originArray[row][col];
        
        row++;

        if(row > rowSize-1)
        {
            col++;
            row = 0;
        }
    }
}

// 2차원 배열 출력
void printTwoDimensional(const int twoDimentional[][4], int rowSize)
{
    for(int i = 0; i < rowSize; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            cout << setw(4) << twoDimentional[i][j];
        }

        cout << endl;
    }
}

// 1차원 배열 출력
void printOneDimentsioal(const int oneDimentioal[], int size)
{
    for(int i = 0; i < size; i++)
    {
        cout << setw(4) << oneDimentioal[i];
    }

    cout << endl;
}
