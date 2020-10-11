#include <bits/stdc++.h>
using namespace std;

template<typename T>
void merge(vector<T>& m, const vector<T>& a, const vector<T>& b)
{
	int i = 0, j = 0;
	for ( ; i < a.size() && j < b.size(); ) {
		if (a[i] < b[j]) {
			m[i+j] = a[i]; ++i;
		}
		else { // (a[i] >= b[j])
			m[i+j] = b[j]; ++j;
		}
	}

	for ( ; i < a.size(); ++i) {
		m[i+j] = a[i];
	}

	for ( ; j < b.size(); ++j) {
		m[i+j] = b[j];
	}
}

template<typename T>
void mergeSort(vector<T>& m)
{
	if (m.size() == 1) {
		return ;
	}

	int mid = m.size() / 2;
	vector<T> a (m.begin(), m.begin() + mid);
	vector<T> b (m.begin() + mid, m.end());
	mergeSort(a);
	mergeSort(b);
	merge(m, a, b);
}

int main()
{
	vector<int> v = {5, 1, 4, 2, 3};
	mergeSort(v);
}
