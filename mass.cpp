#include <stdio.h>
#include "TXLib.h"

void FillArray_Task1 (int data[], int size);
int CheckIndex_Task1(int i, int size);
void FillArray_Task2 (int data[], int size);
int CheckIndex_Task2(int i, int size);
void FillArray_Task3 (int data[], int size);
int CheckIndex_Task3(int i, int size);
void FillArray_Task4 (int data[], int size);
int CheckIndex_Task4(int i, int size);
void FillArray_Task5 (int data[], int size);
int CheckIndex_Task5(int i, int size);
void PrintArray(const int data[], int size, const char title[]);

int main()
{
    int arr[20]={};
    PrintArray(arr,20, "Что было вначале");

    FillArray_Task1 (arr, 20);
    PrintArray(arr, 20, "Задача1");

    arr[20]={};
    FillArray_Task2 (arr, 20);
    PrintArray(arr, 20, "Задача2");

    arr[20]={};
    FillArray_Task3 (arr, 20);
    PrintArray(arr, 20, "Задача3");

    arr[20]={};
    FillArray_Task4 (arr, 20);
    PrintArray(arr, 20, "Задача4");

    arr[20]={};
    FillArray_Task5 (arr, 20);
    PrintArray(arr, 20, "Задача5");


}

void FillArray_Task1 (int data[], int size)
{
    for (int i = 0; i < size; i+=3)
    {
        if ( CheckIndex_Task1(i, size) == 0)
            {
                data[i]   = 1;
                data[i+1] = 2;
                data[i+2] = 3;
            }
    }
}

int CheckIndex_Task1(int i, int size)
{
    int code = 0;

    if ((0 <= i)     && (i     > size)) code = 1;
    if ((0 <= i + 1) && (i + 1 > size)) code = 1;
    if ((0 <= i + 2) && (i + 2 > size)) code = 1;

    return code;
}


void FillArray_Task2 (int data[], int size)
{
    for (int i = 0; i < size; i += 6)
        {
            if ( CheckIndex_Task2(i, size) == 0)
            {
                data[i]   = 1;
                data[i+1] = 2;
                data[i+2] = 3;
                data[i+3] = 3;
                data[i+4] = 2;
                data[i+5] = 1;
            }
        }

}
int CheckIndex_Task2(int i, int size)
{
    int code = 0;

    if ((0 <= i)     && (i     > size)) code = 1;
    if ((0 <= i + 1) && (i + 1 > size)) code = 1;
    if ((0 <= i + 2) && (i + 2 > size)) code = 1;
    if ((0 <= i + 3) && (i + 3 > size)) code = 1;
    if ((0 <= i + 4) && (i + 4 > size)) code = 1;
    if ((0 <= i + 5) && (i + 5 > size)) code = 1;

    return code;
}

void FillArray_Task3 (int data[], int size)
{
    data[0] = 1;
    data[1] = 2;
    data[2] = 3;

    for (int i = 3; i < size; i += 4)
        {
            if ( CheckIndex_Task3(i, size) == 0)
            {
                data[i]   = 2;
                data[i+1] = 1;
                data[i+2] = 2;
                data[i+3] = 3;

            }
        }

}

int CheckIndex_Task3(int i, int size)
{
    int code = 0;

    if ((0 <= i)     && (i     > size)) code = 1;
    if ((0 <= i + 1) && (i + 1 > size)) code = 1;
    if ((0 <= i + 2) && (i + 2 > size)) code = 1;
    if ((0 <= i + 3) && (i + 3 > size)) code = 1;

    return code;
}

void FillArray_Task4 (int data[], int size)
{
    int k=0;
    for (int i = 0; i < (int)(size/2); i +=1 )
        {
            //if ( CheckIndex_Task4(i, size) == 0)
            {

                data[i]      = k+1;
                data[size-i-1] = k+2;
                k+=2;

            }
        }

}

int CheckIndex_Task4(int i, int size)
{
    int code = 0;

    if ((0 <= i)        && (i        > size/2)) code = 1;
    if ((0 <= size-i-1) && (size-i-1 > size/2)) code = 1;

    return code;
}

void FillArray_Task5 (int data[], int size)
{
    int k=0;
    for (int i = 0; i < (int)(size/2); i +=3 )
        {
            //if ( CheckIndex_Task5(i, size) == 0)

            {
                data[i]      = k+1;
                data[i+1]      = k+2;
                data[i+2]      = k+3;

                data[size-i-1] = k+4;
                data[size-i-2] = k+5;
                data[size-i-3] = k+6;

                k+=6;

            }
        }

}

int CheckIndex_Task5(int i, int size)
{
    int code = 0;

    if ((0 <= i)        && (i        > size/2)) code = 1;
    if ((0 <= i + 1)    && (i + 1    > size/2)) code = 1;
    if ((0 <= i + 2)    && (i + 2    > size/2)) code = 1;

    if ((0 <= size-i-1) && (size-i-1 > size/2)) code = 1;
    if ((0 <= size-i-2) && (size-i-2 > size/2)) code = 1;
    if ((0 <= size-i-3) && (size-i-3 > size/2)) code = 1;

    return code;
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
