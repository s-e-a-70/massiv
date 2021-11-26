#include "TXLib.h"
#include <stdio.h>
struct stat_sort
{
    int n_comparison;
    int n_exchange;
};

void FillArray_Random (int data[], int size);
void PrintArray       (const int data[], int size, int ind_start, const char title[]);
int CheckIndex        (int i, int size);
int IndMin(int data[], int ind_start, int size, stat_sort *st);
int IndMax(int data[], int ind_start, int size);

stat_sort Selection_Sort(int data[], int size);
stat_sort Bubble_Sort(int data[], int size);
void One_Bubble_Pass(int data[], int ind_start, int size, stat_sort *st);


int main()
{
    int arr[20]={};

    stat_sort st;

    FillArray_Random (arr, 20);
    PrintArray       (arr, 20, 0, "random array");

    st=Selection_Sort(arr, 20);

    printf("n_comparison=%4d, n_exchange=%4d", st.n_comparison, st.n_exchange );

    PrintArray       (arr, 20, 0,  "selection sorted array");

    FillArray_Random (arr, 20);
    PrintArray       (arr, 20, 0, "random array");

    st=Bubble_Sort(arr, 20);

    printf("n_comparison=%4d, n_exchange=%4d", st.n_comparison, st.n_exchange );

    PrintArray       (arr, 20, 0, " bubble sorted array");

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
void PrintArray (const int data[], int size, int ind_start, const char title[])
{
    printf("%s:\n",title);

    for (int i = 0; i < size; i++)
    {
        if ((i % 5 == 0) && (i!= 0))
            printf("\n");

        $c printf("[%2d]=", i);

        if ((i >= ind_start)&&(i >= ind_start))
            {$y printf("%2d ", data[i]);}
        else
            {$g printf("%2d ", data[i]);}
    }

    printf("\n");
}

int CheckIndex(int i, int size)
{
    int code = 0;

    if ((0 >= i)     && (i     > size)) code = 1;

    return code;
}

int IndMin(int data[], int ind_start, int size, stat_sort *st)
{
   int ind_min = ind_start;

    for (int i = ind_start; i < size; i++)
    {
        //if ( CheckIndex(i, size) == 0)

            if (data[i] < data[ind_min])
                ind_min = i;

            st->n_comparison++;

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

stat_sort Selection_Sort(int data[], int size)
{
    stat_sort st;

    st.n_comparison = 0;
    st.n_exchange   = 0;

    for (int i=0; i<size-1; i++)
    {
        int ind_min = IndMin(data, i, size, &st);

        int buf      = data[ind_min];
        data[ind_min] = data[i];
        data[i]      = buf;

        st.n_exchange ++;

        PrintArray       (data, 20, i, "\n");
     }

    return st;
}

stat_sort Bubble_Sort(int data[], int size)
{
    stat_sort st;

    st.n_comparison = 0;
    st.n_exchange   = 0;


    for (int i=0; i<size-1; i++)
    {
        One_Bubble_Pass(data, i, size, &st);
        PrintArray       (data, 20, i, "\n");
    }

    return st;

}
void One_Bubble_Pass(int data[], int ind_start, int size, stat_sort *st)
{
    for (int i=0; i<size-1-ind_start; i++)
    {
        st->n_comparison ++;

        if (data[i]>data[i+1])
        {
            int buf      = data[i];
            data[i] = data[i+1];
            data[i+1]      = buf;

            st->n_exchange++;
        }
    }
}


