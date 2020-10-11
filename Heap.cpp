#include <iostream>

using namespace std;

class Heap
{
	public:
		int* data;
		int max_size;
		int current_size;

		Heap(int N)
		{
			data = new int[N]();
			max_size = N;
			current_size = 0;

			for (int i = 0; i < N; ++i)
				data[i] = -1;
		}

		//------------------
		// Helper Functions
		//------------------
		int parent(int index)
		{
			return (index - 1)/2;
		}

		int left_child(int index)
		{
			return 2*index + 1;
		}

		int right_child(int index)
		{
			return 2*index + 2;
		}

		void swap(int i, int j)
		{
			int temp = data[i];
			data[i] = data[j];
			data[j] = temp;
		}

		//----------------
		// MAIN FUNCTIONS
		//----------------
		void insert(int d)
		{
			if (current_size < max_size)
			{
				data[current_size] = d;
				min_heapify_up(current_size++);
			}
		}

		void min_heapify_down(int index)
		{
			int SCI; // SCI : Smallest Child Index

			while (right_child(index) < current_size)
			{
				SCI = (data[left_child(index)] < data[index]) ? left_child(index) : index;
				SCI = (data[right_child(index)] < data[SCI]) ? right_child(index) : SCI;

				if (SCI == index)
					break;
				else
					swap(index, SCI);
				
				index = SCI;
			}

			if (left_child(index) < current_size && data[left_child(index)] < data[index])
				swap(index, left_child(index));
		}

		void min_heapify_up(int index)
		{
			int PI = parent(index);

			while (PI >= 0 && data[PI] > data[index])
			{
				swap(PI, index);
				index = PI;
				PI = parent(index);
			}
		}

		int get_min()
		{
			return (current_size > 0) ? data[0] : -1;
		}

		int extract_min()
		{
			int min = -1;
			
			if (current_size > 0)
			{
				min = data[0];
				swap(0, --current_size);
				data[current_size] = -1;
				min_heapify_down(0);
			}

			return min;
		}

		void decrease_key(int index, int new_value) // Assuming new_value < data[index]
		{
			data[--index] = new_value;
			min_heapify_up(index);
		}

		void remove(int index)
		{
			data[--index] = -1;
			min_heapify_up(index);
			extract_min();
		}

		void display()
		{
			for (int i = 0; i < current_size; ++i)
			{
				cout << data[i] << " ";
			}

			cout << endl;
		}
};

int main()
{
	int N, temp;
	cin >> N;
	
	Heap h(N);
	
	for (int i = 0; i < N; ++i)
	{
		cin >> temp;
		h.insert(temp);
	}
	
	// Heap Sort
	//-----------
	int heap_size = h.current_size;

	for (int i = 0; i < heap_size; ++i)
	{
		cout << h.extract_min() << " ";
	}

	cout << endl;

	return 0;
}
