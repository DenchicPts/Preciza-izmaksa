#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template<typename T>
ostream& operator<<(ostream& out, const vector<T>& v) {
	for (auto& i : v)
	{
		cout << i << " ";
	}
	return out;
}

void MD01();
void MD02();
void MD03();
void MD04();

