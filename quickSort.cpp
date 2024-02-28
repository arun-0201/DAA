#include <iostream>
#include <fstream>
#include <cstring>
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
	char file[20];
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

int partition(int p,int r) {
	int x = arr[r];	
	int i = p-1;
	for(int j=p; j<=r-1 ; j++) {
		count++;
		if(arr[j] <= x) {	
			i++;
			int temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}
	int temp = arr[i+1];
	arr[i+1] = arr[r];
	arr[r] = temp;
	return i+1;
}

void quickSort(int p, int r) {
	if(p<r) {
		int q = partition(p,r);
		quickSort(p,q-1);
		quickSort(q+1,r);
	}
}

int main(){ 
	do {		
		getInput();
		quickSort(0,n-1);
		writeOutput();
		count=0;
	}while(true);
	return 0;	
}
