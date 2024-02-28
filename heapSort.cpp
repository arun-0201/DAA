#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>

using namespace std;

long int arr[11000];
int n,count=0,heapsize;

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

void maxHeapify(int i) {	
	int l = 2*i + 1;
	int r = 2*i + 2;
	int largest;
	count++;
	if(l<=heapsize && arr[l]>arr[i])
	{
		largest = l;
	}
	else
	{
		largest = i;
	}
	if(r<=heapsize && arr[r]>arr[largest])
	{
		largest = r;
	}
	if(largest!=i)
	{
		int temp = arr[i];
		arr[i] = arr[largest];
		arr[largest] = temp;
		maxHeapify(largest);
	}
}

void buildMaxHeap() {
	for(int i=floor(n/2); i>=0; i--) {
		maxHeapify(i);
	}
}

void heapSort() {
	heapsize = n-1;
	buildMaxHeap();
	for(int i=n; i>=1; i--) {
		int temp = arr[0];
		arr[0] = arr[i];
		arr[i] = temp;
		heapsize--;
		maxHeapify(0);
	}
}
int main(){ 
	do {		
		getInput();
		heapSort();
		writeOutput();
		count=0;
	}while(true);
	return 0;	
}
