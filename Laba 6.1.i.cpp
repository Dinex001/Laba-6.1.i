#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void Create(int* b, const int size, const int Low, const int High);
void Print(int* b, const int size);
bool Criterion(const int x);
int Count(int* b, const int size);
int Sum(int* b, const int size);
void Zero(int* b, const int size);

int main()
{
    srand((unsigned)time(NULL));    // ініціалізація генератора випадкових чисел

    const int n = 23;
    int b[n];

    int Low = -25;
    int High = 80;

    Create(b, n, Low, High);
    Print(b, n);

    cout << "Count = " << Count(b, n) << endl;
    cout << "Sum   = " << Sum(b, n) << endl;

    Zero(b, n);
    Print(b, n);

    return 0;
}

// формування масиву випадковими числами з [Low; High]
void Create(int* b, const int size, const int Low, const int High)
{
    for (int i = 0; i < size; i++)
        b[i] = Low + rand() % (High - Low + 1);
}

// виведення масиву в рядок
void Print(int* b, const int size)
{
    for (int i = 0; i < size; i++)
        cout << setw(4) << b[i];
    cout << endl;
}

// критерій: елемент додатний і непарний
bool Criterion(const int x)
{
    return x > 0 && x % 2 != 0;
}

// кількість елементів, що задовольняють критерію
int Count(int* b, const int size)
{
    int k = 0;
    for (int i = 0; i < size; i++)
        if (Criterion(b[i]))
            k++;
    return k;
}

// сума елементів, що задовольняють критерію
int Sum(int* b, const int size)
{
    int S = 0;
    for (int i = 0; i < size; i++)
        if (Criterion(b[i]))
            S += b[i];
    return S;
}

// заміна нулями елементів, що задовольняють критерію
void Zero(int* b, const int size)
{
    for (int i = 0; i < size; i++)
        if (Criterion(b[i]))
            b[i] = 0;
}