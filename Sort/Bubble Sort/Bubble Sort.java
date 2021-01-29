import java.util.Scanner; // For taking input

class Bubble_Sort
{
	public static void main(String args[])
	{
		Scanner number = new Scanner(System.in);
		
		int N;
		System.out.print("\n Array size : ");
		N = number.nextInt();

		int A[] = new int[N], temp;
		System.out.print("\n Enter elements : ");

		for(int i = 0; i < N; ++i)
			A[i] = number.nextInt();

		// Bubble Sort
		//-------------
		for(int i = 0; i < (N-1); ++i)
		{
			for(int j = i; j < (N-1-i); ++j)
			{
				if(A[j] > A[j+1])
				{
					// Swapping
					//----------
					temp = A[j];
					A[j] = A[j+1];
					A[j+1] = temp;
				}
			}
		}

		System.out.print("\n Sorted Array : ");
		for(int i = 0; i < N; ++i)
			System.out.print(A[i] + " ");
	}
}
