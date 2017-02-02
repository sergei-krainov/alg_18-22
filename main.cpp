#include <iostream>
using namespace std;

#define ARRLEN 10

void sel_sort(const int x[], int y[])
{
	int min = x[0];
	int index_array[ARRLEN];
	
	
	
	for (int i = 0; i < ARRLEN; i++) {
		int n = -1;
		for (int j = 0; j < ARRLEN; j++) {
			cout << "Start = " << min << " - " << x[j] << endl;
			
			if ( x[j] <= min ) {
				int match = 0;
				
				for (int t = 0; t <= i; t++) {
					if ( index_array[t] == j )
						match++;
				}
				
				if ( match == 0 ) {
					min = x[j];
					n = j;
				}
			}
		}
		index_array[i] = n;
		
		y[i] = min;
		min = 10;
	}
}

int main() {
	int a[ARRLEN] = {1,6,4,2,4,5,6,7,8,2};
	int b[ARRLEN];
	
	cout << "Before:" << endl;
	
	for (int i = 0; i< ARRLEN; i++) {
		cout << a[i] << ";";
	}
	cout << endl;
	
	sel_sort(a, b);
	
	cout << "After:" << endl;
	
	for (int i = 0; i< ARRLEN; i++) {
		cout << b[i] << ";";
	}
	
	
	return 0;
}
