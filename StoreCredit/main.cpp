#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
void runCase();

int cases, a, b;
string infileName = "A-large-practice.in", outfileName = "large.out";
ifstream infile(infileName.c_str());
ofstream outfile(outfileName.c_str());

int main() {

	infile >> cases;
	for (int i = 1; i <= cases; i++) {
		runCase();
		outfile << "Case #" << i << ": " << a << " " << b << endl;
	}

	infile.close();
	outfile.close();
	cin.get();
	return 0;
}

void runCase() {

	int credit, numItems, *list;
	infile >> credit >> numItems;

	list = new int[numItems];

	for (int i = 0; i < numItems; i++) {
		int item;
		infile >> item;
		list[i] = item;
	}

	for (int i = 0; i < numItems-1; i++)
		for (int j = i+1; j < numItems; j++) {
			if (list[i] + list[j] == credit) {
				a = i+1;
				b = j+1;
				break;
			}
		}

	delete[] list; list = NULL;
}