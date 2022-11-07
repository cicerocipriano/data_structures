#include <algorithm>
#include <iostream>
#include <chrono>
#include <iomanip>
using namespace std;

int main(int argc, char**argv) {
	int n = atoi(argv[1]);
	cout << n << endl;
	for(int i=0;i<n;i++) cout << rand() << "\n";

}