#include <iostream>
using namespace std;

#define ARRLEN 10

void sel_sort_ugly(int x[], int y[])
{
	int min = x[0];
	int index_array[ARRLEN];
	
	
	
	for (int i = 0; i < ARRLEN; i++) {
		int n = -1;
		for (int j = 0; j < ARRLEN; j++) {
			//cout << "Start = " << min << " - " << x[j] << endl;
			
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

void sel_sort_v2(int x[], int y[])
{
	int pos = -1;
	int pmin = -1;
	int j;
	bool match = 0;
	static int min = x[0];
	for (int i = 0; i < ARRLEN; i++) {
		
		for ( j = 0; j < ARRLEN; j++) {
			//cout << "TEST" << min << endl; 
			//cout << "Test1" << x[j] << j << endl;
			//min = x[i];
			if ( x[j] > pmin && match != 1)
				min = x[j];
			
			
			if ( x[j] < min && match != 1) {
				//cout << "Test2" << x[j] << j << endl;
				min = x[j];
				pos = j;
				match = 1;
			}
			
			if ( x[j] == min && j != pos && match != 1 ) {
				min = x[j];
				pos = j;
			}
		}
		cout << "Min, pos = " << min << ";" << pos << endl;
		y[i] = min;
		pmin = min;
		match = 0;
	}
	
}

void sel_sort_v3(int x[], int y[])
{
	int j, i, c, min, pmin, max;
	bool ft = 1;
	pmin = 0;
	c = 0;
	max = 0;
	
	for (i = 0; i < ARRLEN; i++) {
		if ( x[i] > max)
			max = x[i];
	}
	
	for (i = 0; i < ARRLEN; i++) {
		if (c == 0) {
			min = max;
		
			for (j = 0; j < ARRLEN; j++) {
				
				if (ft == 1) {
					
					if (x[j] < min ) {
						min = x[j];
						c = 1;
					} else if (x[j] == min) {
						c++;
					}
				} else {
				
					if (x[j] < min && x[j] > pmin) {
						min = x[j];
						c = 1;
					} else if (x[j] == min) {
						c++;
					}
					
				}
			}
		}
		
		ft = 0;		
		y[i] = min;
		c--;
		pmin = min;	
	}
}

void sel_sort_proper(int x[], int y[])
{
	int indexMin,i,j;
	
	// loop through all numbers 
	for(i = 0; i < ARRLEN; i++) { 
	
		// set current element as minimum 
		indexMin = i;
			
		// check the element to be minimum 
		for(j = i+1;j<ARRLEN;j++) {
		   if(x[j] < x[indexMin]) {
			indexMin = j;
		   }
		}
	
		if(indexMin != i) {
				
		   // swap the numbers 
		   int temp = x[indexMin];
		   x[indexMin] = x[i];
		   x[i] = temp;
		}          

	
	}
}

int main() {
	int a[ARRLEN] = {7,6,4,2,4,5,6,7,8,2};
	int b[ARRLEN];
	//int c[ARRLEN];
	int d[ARRLEN];
	
	cout << "Before:" << endl;
	
	for (int i = 0; i< ARRLEN; i++) {
		cout << a[i] << ";";
	}
	cout << endl;
	
	sel_sort_ugly(a, b);
	
	cout << "After:" << endl;
	
	for (int i = 0; i< ARRLEN; i++) {
		cout << b[i] << ";";
	}
	
	cout << endl;
	
	
	//sel_sort_v2(a, c);
	
	//cout << "After:" << endl;
	
	//for (int i = 0; i< ARRLEN; i++) {
	//	cout << c[i] << ";";
	//}
	
	cout << endl;
	
	//sel_sort_proper(a, d);
	
	cout << "After:" << endl;
	
	//for (int i = 0; i< ARRLEN; i++) {
	//	cout << a[i] << ";";
	//}
	
	cout << endl;
	
	sel_sort_v3(a, d);
	
	cout << "After V3:" << endl;
	
	for (int i = 0; i< ARRLEN; i++) {
		cout << d[i] << ";";
	}
	
	return 0;
}
