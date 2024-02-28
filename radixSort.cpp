#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include <math.h>
using namespace std;

/*
	k - maximum value of count array
	d - digit counter
	n - no. of elements in A
	A - original array
	C - count array
	B - output array
*/

long int A[11000],B[11000];
int n,k=10,count;

void getInput() {
	ifstream fin("input_rsort.txt");
	for(int i=0; i<n; i++) {
		fin >> A[i];
	}
	fin.close();
}


void countSort(int d) {
    int C[k]
    int divisor = pow(10, d);

    for (int i = 0; i < k; i++) { 
        count = count + 1;
        C[i] = 0;
    }
    for (int j = 0; j < n; j++) { 
        count = count + 1;
        C[A[j] / divisor % 10] = C[A[j] / divisor % 10] + 1;
    }
    for (int i = 1; i < k; i++) { 
        count = count + 1;
        C[i] = C[i - 1] + C[i];
    }
    for (int j = n - 1; j >= 0; j--) { 
        count = count + 1;
        B[C[A[j] / divisor % 10] - 1] = A[j]; 
        C[A[j] / divisor % 10] = C[A[j] / divisor % 10] - 1;
    }
    for (int i = 0; i < n; i++) {
        A[i] = B[i];
    }
}

void writeOutput() {
	ofstream fout("output.txt");
	for(int i=0; i<n; i++) {
		fout << A[i] << "\t";
	}
	fout.close();
	cout << "n = " << n << "\nCount = " << count << "\n\n";
}

void createInput() {
	ofstream fout("input_rsort.txt");
	srand((long int)clock());
	for(int i=0; i<10000 ; i++)
		fout << 1000 + rand() % 9000 << "\t";
	fout.close();
}

int main(){ 
	createInput();
	do {
		cout << "Enter the no. of elements : " ;
		cin >> n;
		count=0;
		getInput();
		for(int d=0; d<=3; d++) 
			countSort(d);
		writeOutput();
	}while(true);
	return 0;	
}
