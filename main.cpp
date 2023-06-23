//main.cpp
#include "stats.h"
#include "p1_library.h"
#include <iostream>
#include <cmath>
using namespace std;

int main() {
	//inputs
	vector<double> v;
	string filename;
	string column;
	cout << "enter a filename\n";
	cin >> filename;
	cout << "enter a column name\n";
	cin >> column;
	cout << "reading column " << column << " from " << filename << endl;

	//reads file and extracts data from a specified column
	v = extract_column(filename, column);

	//Outputs summary of the Data, or freqency table
	vector<vector<double>> summary = summarize(v);
	cout << "Summary (value: frequency)" << endl;
	for (unsigned int i = 0; i < summary.size(); i++) {
		cout << summary[i][0] << ": " << summary[i][1] << endl;
	}

	//Outputs all the various statistics
	cout << endl
		<< "count = " << count(v) << endl
		<< "sum = " << sum(v) << endl
		<< "mean = " << mean(v) << endl
		<< "stdev = " << stdev(v) << endl
		<< "median = " << median(v) << endl
		<< "mode = " << mode(v) << endl
		<< "min = " << min(v) << endl
		<< "max = " << max(v) << endl
		<< "  0th percentile = " << percentile(v, 0) << endl
		<< " 25th percentile = " << percentile(v, 25) << endl
		<< " 50th percentile = " << percentile(v, 50) << endl
		<< " 75th percentile = " << percentile(v, 75) << endl
		<< "100th percentile = " << percentile(v, 100) << endl;
}