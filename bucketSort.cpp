#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include <cmath>
using namespace std;

struct node {
	float data;
	node* link;
};

struct bucket {
	node* head;
};	

float A[11000];
int n,count;
bucket* B[10];

node* createNode(float key) {
	node *temp = new node;
	temp -> data = key;
	temp -> link = NULL;
	return temp;
}

//--------------------------------------------------------------------------------------------------------------------------------

void insertByOrder(float key) {
	int index = floor(key*10);
	node *newNode = createNode(key);

	node* temp = B[index] -> head;
	if (temp == NULL || temp -> data >= key) {
        	newNode -> link = B[index] -> head;
        	B[index] -> head = newNode;
        	return;
    	}
	while(temp -> link != NULL && temp->link->data < key) {
		count++;
		temp = temp -> link;
		newNode -> link = temp->link;
    		temp->link = newNode;
		return;
	}
}

void concatenateOutput() {
	int index = 0;
	for(int i = 0; i < 9 ; i++) {
		node *temp = B[i] -> head;
		while(temp != NULL) {
			A[index++] = temp -> data;
			temp = temp -> link;
		}
	}
	count = count + index;
}

void bucketSort() {
	for(int i = 0 ; i < 10 ; i++) {
		B[i] = new bucket;
		B[i] -> head = 	NULL;
	}
	for(int i=0; i<n ; i++) {
		insertByOrder(A[i]);
		count++;
	}
	concatenateOutput();
}

//--------------------------------------------------------------------------------------------------------------------------------

void genInputFile() {
	ofstream fout("input_bsort.txt");
	srand((long int) clock());
	for(int i=0 ; i<10000 ; i++) 
		fout << (float)rand()/RAND_MAX << "\t";
	fout.close();
}

void getInput() {
	ifstream fin("input_bsort.txt");
	for(int i=0; i<n; i++) {
		fin >> A[i];
	}
	fin.close();
}

void writeOutput() {
	ofstream fout("output.txt");
	for(int i = 0; i < n ; i++) {
		fout << A[i] << "\t";
	}
	fout.close();	
	cout << "n = " << n << "\nCount = " << count << "\n\n";
}

//--------------------------------------------------------------------------------------------------------------------------------

int main() {
	genInputFile();
	do {
		cout << "Enter the no. of elements : " ;
		cin >> n;
		count=0;
		getInput();
		bucketSort();
		writeOutput();
	}while(true);
	return 0;
}
