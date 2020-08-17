#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

int check(vector<int> a) {
	int count = 0;
	for (int i = 0; i < a.size(); i++) {
		if (a[i] - 1 == i) {
			count++;
		}
	}
	return count;
}

string temp;

int main() {
	int n;
	cin >> n;
	for (int u = 0; u < n; u++) {
		int hernya;
		cin >> hernya;
		cin >> temp;
		int mainCount = 0;
		for (int i = 0; i < temp.size(); i++) {
			//vector<int> sum(temp.size()); // вектор префиксных сумм
			int num = temp[i] - '0';
			//sum[0] = num;
			int tmp1 = num, tmp2;
			if (tmp1 == 1) {
				mainCount++;
			}
			for (int j = i + 1; j < temp.size(); j++) {
				int tec = temp[j] - '0';
				//sum[j - i] = sum[j - i - 1] + tec;
				tmp2 = tmp1 + tec;
				if (tmp2 == j - i + 1) {
					mainCount++;
				}
				tmp1 = tmp2;
			}
		}
		cout << mainCount << endl;
	}
	return 0;
}