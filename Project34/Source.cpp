#include <iostream>
#include <limits.h>
#include <iomanip>
#include<Windows.h>

using namespace std;

enum userChoice
{
    Exit = 0,
    Initialize = 1,
    Print = 2,
    MinMax = 3,
    Sort = 4
};

void matrixDoSomething(int(*)[10], int, int);
void matrixDoSomething(int(*)[10], int);
void matrixDoSomething(int(*)[10], int, int, int);
void matrixDoSomething(int(*)[10]);


 
void matrixDoSomething(int arr[][10], int size, int limitNumber)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            arr[i][j] = rand() % limitNumber;
        }
    }
    std::cout << "An array initialized" ;
}
 
void matrixDoSomething(int arr[][10], int arSize)
{
    std::cout << "Start massiv: " ;
    for (int i = 0; i < arSize; i++)
    {
        for (int j = 0; j < arSize; j++)
        {
            std::cout << fixed << setw(3) << arr[i][j] << " ";
        }
        
    }
}
 
void matrixDoSomething(int arr[][10], int arSize, int minElement, int maxElement)
{
    for (int i = 0; i < arSize; i++)
    {
        if (arr[i][i] > maxElement)
        {
            maxElement = arr[i][i];
        }
        if (arr[i][i] < minElement)
        {
            minElement = arr[i][i];
        }
    }
    std::cout << "Min element = " << minElement <<
        "Max element = " << maxElement;
}
 
void matrixDoSomething(int arr[][10])
{
    int arraySize = 10;
    int bufer;
    std::cout << "Sort Ascending elements of each line separately" ;
    for (int k = 0; k < arraySize; k++)
    {
        for (int j = 0; j < arraySize - 1; j++)
        {
            for (int i = 1; i < arraySize - j; i++)
            {
                if (arr[k][i] < arr[k][i - 1])
                {
                    bufer = arr[k][i - 1];
                    arr[k][i - 1] = arr[k][i];
                    arr[k][i] = bufer;
                }
            }
        }
    }
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int const massivDimention = 10;
    int massiv[massivDimention][massivDimention] = { 0 };
    int limitNumber = 100;
    int max = INT_MIN;
    int min = INT_MAX;
    int intUserChoice;
    enum userChoice userChoice;

    std::cout << "This program do something with matrix"  ;
    do
    {
        std::cout << "Select what you want to do: "   <<
            "0 = Exit"   << "1 = Initialize matrix" <<
            "2 = Print matrix" << "3 = Find min and max elements" <<
            "4 = Sorting rows";
        std::cin >> intUserChoice;
        userChoice = (enum userChoice)intUserChoice;

        switch (userChoice)
        {
        case Exit:
            cout << "You want to exit" ;
            break;
        case Initialize:
            matrixDoSomething(massiv, massivDimention, limitNumber);
            break;
        case Print:
            matrixDoSomething(massiv, massivDimention);
            break;
        case MinMax:
            matrixDoSomething(massiv, massivDimention, min, max);
            break;
        case Sort:
            matrixDoSomething(massiv);
            break;
        default:
            std::cout << "Error. Uncorrect choice!" ;
            return 1;
        }
    } while (userChoice != Exit);
    return 0;
}