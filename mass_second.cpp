#include "TXLib.h"
#include <stdio.h>

void FillArray_Random (int data[], int size);
void PrintArray       (const int data[], int size, const char title[]);
int CheckIndex        (int i, int size);
int IndMin(const int data[], int size);
int IndMax(const int data[], int size);
void LocalChange(int data[], int size);
void LeftShift(int data[], int size);
void RightShift(int data[], int size);


int main()
{
    int arr[20]={};
    PrintArray(arr, 20, "Что было вначале");

    FillArray_Random (arr, 20);
    PrintArray       (arr, 20, "Случайные числа");

    printf("Индекс минимума = %d\n", IndMin(arr, 20));

    printf("Индекс максимума = %d\n", IndMax(arr, 20));

    LocalChange (arr, 20);
    PrintArray  (arr, 20, "Поменять местами соседние элементы");

    LeftShift        (arr, 20);
    PrintArray       (arr, 20, "Циклический сдвиг влево");

    RightShift        (arr, 20);
    PrintArray       (arr, 20, "Циклический сдвиг вправо");


    return 0;
}
void FillArray_Random (int data[], int size)
{
    for (int i = 0; i < size; i++)
    {
        if ( CheckIndex(i, size) == 0)

            data[i]  = random(50);

    }
}
void PrintArray (const int data[], int size, const char title[])
{
    printf("%s:\n",title);

    for (int i = 0; i < size; i++)
    {
        if ((i % 5 == 0) && (i!= 0))
            printf("\n");

        $c printf("[%2d]=", i);

        $g printf("%2d", data[i]);
    }

    printf("\n");
}

int CheckIndex(int i, int size)
{
    int code = 0;

    if ((0 <= i)     && (i     > size)) code = 1;

    return code;
}

int IndMin(const int data[], int size)
{
   int ind_min = 0;

    for (int i = 0; i < size; i++)
    {
        if ( CheckIndex(i, size) == 0)

            if (data[i] < data[ind_min])
                ind_min = i;

    }

    return ind_min;

}

int IndMax(const int data[], int size)
{
   int ind_max = 0;

    for (int i = 0; i < size; i++)
    {
        if ( CheckIndex(i, size) == 0)

            if (data[i] > data[ind_max])
                ind_max = i;

    }

    return ind_max;

}

void LocalChange(int data[], int size)
{
 for (int i = 0; i < size; i+=2)
    {
        if ( CheckIndex(i, size) == 0)

        {
            int buf   = data[i];
            data[i]   = data[i+1];
            data[i+1] = buf;
        }

    }
}

void LeftShift(int data[], int size)
{
    int buf = data[0];

    for (int i = 1; i < size; i++)
        {
            if ( CheckIndex(i, size) == 0)

                data[i-1] = data[i];
        }

    data[size-1] = buf;
}

void RightShift(int data[], int size)
{
    int buf = data[size-1];

    for (int i = size-1; i > 0; i--)
        {
            if ( CheckIndex(i, size) == 0)

                data[i] = data[i-1];
        }

    data[0] = buf;
}

