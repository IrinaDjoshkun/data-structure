#include <iostream>
#include <cmath>
using namespace std;

//Задание №1.

void fill_array(int **arr, const int size)
{
    for (int i = 0; i<size; i++)
    {
        for (int j=0; j<size; j++)
        {
            arr[i][j] = rand() % 100 + 1;
        }
    }
    return;
}

void print_array(int** arr, const int size)
{
    for (int i=0; i<size; i++)
    {
        for (int j=0; j<size; j++)
        {
            cout << arr[i][j] << '\t';
        }
        cout << '\n';
    }
    return;
}

void sort_array(int** arr, const int size)
{
    cout << "sorted:" << endl;
    int temp = 0;
    for(int k = 0; k < size; k++)
    {
        for(int l = 0; l < size; l++)
        {
            for(int i = 0; i < size; i++)
            {
                for(int j = 0; j < size; j++)
                {
                    if (i+1 == size && j+1 == size)
                    {
                        continue;
                    }
                    else
                    {
                        if (j+1 == size && arr[i][j] > arr[i+1][0])
                        {
                            int temp = arr[i][j];
                            arr[i][j] = arr[i+1][0];
                            arr[i+1][0] = temp;
                        }
                        else
                        {
                            if(arr[i][j] > arr[i][j+1])
                            {
                                int temp = arr[i][j];
                                arr[i][j] = arr[i][j+1];
                                arr[i][j+1] = temp;
                            }
                        }
                    }
                }
            }
        }
    }
    return;
}

void foo()
{
  int SIZE = 3;

  int **array = new int* [SIZE];
  for (int i =0 ;i < SIZE; i++)
  {
    array[i] = new int[SIZE];
  }

        fill_array(array,SIZE);
        print_array(array,SIZE);
        sort_array(array,SIZE);
        print_array(array, SIZE);

  for (int i=0; i < SIZE;i++)
  {
    delete []array[i];
  }

  delete []array;
  return;
}

//Задание №2.

void ask_sequence(double *seq, int size)
{
    cout << "Input values: " << endl;
    for(int i = 0; i < size; i++)
    {
        cin >> seq[i];
    }
    cout << "Your sequence is: " << endl;
    for(int i = 0; i < size; i++)
    {
        cout << seq[i] << " ";
    }
    cout << "\n";
    return;
}

void reverse_sequence(double *seq, int size)
{
    cout << "The reversed sequence is: " << endl;
    for (int i = size - 1; i >= 0; i --)
    {
        cout << seq[i] << " ";
    }
    cout << "\n";
    return;
}

void math_sequence(double *seq, int size)
{
    cout << "Sequence math: " << endl;
    for(int i  = 0; i < size; i++)
    {
        double x = (sqrt(seq[i])) + 5 * (pow(seq[i],3));
        x > 400
        ? cout << "Number " << "x" << " is bigger than 400. \n"
        : cout << "Number " << "x" << " is less than 400. \n";
    }
    cout << "\n";
    return;
}

void TPK()
{
    const int SIZE = 11;
    double sequence[SIZE];

    ask_sequence(sequence, SIZE);
    reverse_sequence(sequence, SIZE);
    math_sequence(sequence, SIZE);

    return;
}
