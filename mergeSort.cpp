#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>	//for floor function
#include <limits.h>	//for INT_MAX (infinity)
using namespace std;

long int arr[11000];
int n,count=0;

void getInput() {
	int type;
	cout << "1.Random Input \n2.Ascending Input  \n3.Descending Input \n4.Equal Input";
	cout << "\nEnter input type : ";
	cin >> type;
	cout << "\nEnter the size of the array : ";
	cin >> n;
	char file[16];
	switch(type) {
		case 1:
			strcpy(file,"input.txt");
			break;
		case 2:
			strcpy(file,"input-asc.txt");
			break;
		case 3:
			strcpy(file,"input-desc.txt");
			break;
		case 4:
			strcpy(file,"input-equal.txt");
			break;
	}
	ifstream fin(file);
	for(int i=0; i<n; i++) {
		fin >> arr[i];
	}
	fin.close();
}

void writeOutput() {
	ofstream fout("output.txt");
	for(int i=0; i<n; i++) {
		fout << arr[i] << "\t";
	}
	fout.close();

	cout << "Count : " << count <<"\n\n\n"; 
}

void merge(int p,int q,int r) {
	int i, j;
	int n1 = q - p + 1;
	int n2 = r - q;
	int L[n1+2], R[n2+2];
	for (int i=0; i<n1; i++)
	    L[i] = arr[p+i];
	L[n1] = INT_MAX;
	for (int j=0; j<n2; j++)
	    R[j] = arr[q+j+1];
	R[n2]=INT_MAX;
	i=0; j=0;
	for (int k=p; k<=r; k++){
		count++;
		if (L[i] <= R[j]){
			arr[k] = L[i];
			i++;
		}
		else{
			arr[k] = R[j];
			j++;
		}
	}
}

void mergeSort(int p,int r) {
	if(p<r) {
		int q = floor((p+r)/2);
		mergeSort(p,q);
		mergeSort(q+1,r);
		merge(p,q,r);
	}
}


int main(){ 
	do {		
		getInput();
		mergeSort(0,n-1);
		writeOutput();
		count=0;
	}while(true);
	return 0;	
}
