// stats.cpp
#include "stats.h"
#include "p1_library.h"
#include <cassert>
#include <vector>
#include <cmath>
#include <iostream>
#include <unordered_map>
using namespace std;

vector<vector<double>> summarize(vector<double> v) {
	sort(v);
	vector<vector<double>> freqTable;
	double freq = 1;
	for (unsigned int i = 1; i < v.size(); i++) {
		if (v[i] == v[i - 1]) {
			freq = freq + 1;
		}
		if (v[i] != v[i - 1]) {
			freqTable.push_back({ v[i - 1], freq });
			freq = 1;
		}
		if (i == v.size() - 1) {
			freqTable.push_back({ v[i], freq });
		}
	}
	return freqTable; 
}

int count(vector<double> v) {
	return v.size();  
}

double sum(vector<double> v) {
	double prod = 0.0;
	for(int num : v) prod += num;
	return prod;  
}

double mean(vector<double> v) {
	return sum(v)/count(v);  
}

double median(vector<double> v) {
	int cnt = count(v);
	sort(v);
	if (cnt % 2 == 1) return v[cnt / 2];
	else return (v[(cnt / 2) - 1] + v[cnt / 2]) / 2;
}

double mode(vector<double> v) {
	double max = v[0];
	unordered_map<double, int> cnts;
	for(double num : v) {
		++cnts[num];
		if(cnts[num] > cnts[max]) max = num;	
	}
	return max;  
}

double min(vector<double> v) {
	double mini = v[0];
	for (unsigned int i = 1; i < v.size(); i++) mini = min(mini, v[i]);
	return mini;  
}

double max(vector<double> v) {
	double maxi = v[0];
	for (unsigned int i = 1; i < v.size(); i++) maxi = max(maxi, v[i]); 
	return maxi;  
}

double stdev(vector<double> v) {
	double avg = mean(v);
	int cnt = count(v) - 1;
	for (unsigned int i = 0; i < v.size(); i++) {
		v[i] -= avg; v[i] *= v[i];
	} return sqrt(sum(v)/cnt);
}

double percentile(vector<double> v, double p) {
	sort(v);
	int index = (p / 100) * (v.size()-1);
	return v[index];
}