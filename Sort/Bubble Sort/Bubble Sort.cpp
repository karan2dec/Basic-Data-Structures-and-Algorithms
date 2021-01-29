#include <iostream>

using namespace std;

int main()
{
	int N;
	cout << "\n Array size : ";
	cin >> N;

	int a[N], temp;
	cout << "\n Enter elements : ";

	for(int i = 0; i < N; ++i)
		cin >> a[i];
		cout << "Hello" ;

	// Bubble Sort
	//-------------
	for(int i = 0; i < (N - 1); ++i)
	{
		for(int j = i; j < (N - 1 - i); ++j)
		{
			if(a[j] > a[j+1])
			{
				// Swapping
				//----------
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
		}
	}

	cout << "\n Sorted Array : ";

	for(int i = 0; i < N; ++i)
		cout << a[i] << " ";

	return 0;
}
