#include <iostream>

using namespace std;

// Задание №1

const int size = 14;

int intArray[size][size] = { 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0,
                       1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0,
                       0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0,
                       0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0,
                       0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0,
                       0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0,
                       0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0,
                       0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0,
                       1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0,
                       0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 0,
                       0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 1, 1,
                       0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 1,
                       0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0,
                       0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0,};

bool used[size];

int j = 0;
int r = 0;
int i = 0;
int k = 0;

void DepthTravers(int g)
{

	used[g] = true;
	int p;
	for (i = k; i < size; i++)
	{
		j = r;
		if ((intArray[i][j] != 0) && (!used[i]))
		{
			used[i] = true;
			p = i;
			cout << i << " ";
			for (j = 0; j < size; j++)
			{
				i == p;
				if (intArray[i][j] != 0)
				{
					r = j;
					for (k = 0; k < size; k++)
					{
						j == r;
						if ((intArray[k][j] != 0) && (!used[k]))
						{
							DepthTravers(i);
						}
					}
				}
			}
		}
	}
}

int main()
{

	for (int i = 0; i < size; i++)
	{
		used[i] = false;
		for (int j = 0; j < size; j++)
		{
			cout << " " << intArray[i][j];
        }
		cout << endl;
	}


	int t = 5;
	cout << "\n";
	cout << "The order: " << endl;

	DepthTravers(t);
	cout << endl;

	return 0;
}


