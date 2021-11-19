#include "TXLib.h"
#include <stdio.h>

void FillArray_Random (int data[], int size);
void PrintArray       (const int data[], int size, const char title[]);
int CheckIndex        (int i, int size);
int IndMin(int data[], int ind_start, int size);
int IndMax(int data[], int ind_start, int size);
void LocalChange(int data[], int size);
void LeftShift(int data[], int size);
void RightShift(int data[], int size);
void Selection_Sort(int data[], int size);


int main()
{
    int arr[20]={};
    PrintArray(arr, 20, "source array");

    FillArray_Random (arr, 20);
    PrintArray       (arr, 20, "random array");

    Selection_Sort(arr, 20);

    PrintArray       (arr, 20, "sorted array");

    //printf("Èíäåêñ ìèíèìóìà = %d\n", IndMin(arr, 0, 20));

    //printf("Èíäåêñ ìàêñèìóìà = %d\n", IndMax(arr, 0, 20));

    //LocalChange (arr, 20);
    //PrintArray  (arr, 20, "Ïîìåíÿòü ìåñòàìè ñîñåäíèå ýëåìåíòû");

    //LeftShift        (arr, 20);
    //PrintArray       (arr, 20, "Öèêëè÷åñêèé ñäâèã âëåâî");

    //RightShift        (arr, 20);
    //PrintArray       (arr, 20, "Öèêëè÷åñêèé ñäâèã âïðàâî");


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

        $g printf("%2d ", data[i]);
    }

    printf("\n");
}

int CheckIndex(int i, int size)
{
    int code = 0;

    if ((0 >= i)     && (i     > size)) code = 1;

    return code;
}

int IndMin(int data[], int ind_start, int size)
{
   int ind_min = ind_start;

    for (int i = ind_start; i < size; i++)
    {
        //if ( CheckIndex(i, size) == 0)

            if (data[i] < data[ind_min])
                ind_min = i;

    }

    return ind_min;

}

int IndMax(const int data[], int ind_start, int size)
{
   int ind_max = 0;

    for (int i = ind_start; i < size; i++)
    {
        if ( CheckIndex(i, size) == 0)

            if (data[i] > data[ind_max])
                ind_max = i;

    }

    return ind_max;

}

void Selection_Sort(int data[], int size)
{
    for (int i=0; i<size-1; i++)
    {
        int indmin = IndMin(data, i, size);
        printf("i=%d indmin=%d\n", i, indmin);

        int buf      = data[IndMin(data, i, size)];
        data[IndMin(data, i, size)] = data[i];
        data[i]      = buf;

        PrintArray       (data, 20, "\n");
     }


}

