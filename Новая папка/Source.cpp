#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void print(vector<int> a) {
	for (auto now : a) {
		cout << now << " ";
	}
	cout << endl;
}

void print2(vector<vector<int>> a) {
	for (auto now : a) {
		for (auto now2 : now) {
			cout << now2 << " ";
		}
		cout << endl;
	}
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		vector<int> a(temp); // �� �� ����� �� ���� ��������� � ����� ��������, ���� ������ ����� �����
		vector<int> cycle; // ��������� ������� ���� ������������ ����� ����������� ���������� ����������
		vector<int> ans(temp); // ������� �� ���� ������
		for (int j = 0; j < temp; j++) {
			cin >> a[j];
			a[j]--;
		}
		for (int j = 0; j < temp; j++) {
			int pos = a[j];
			int count = 1; // ���
			cycle.push_back(j);
			while (pos != j) {
				cycle.push_back(pos);
				count++;
				pos = a[pos];
			}
			//print(cycle);
			for (auto now : cycle) {
				ans[now] = count;
			}
			cycle = {};
		}
		print(ans);
	}
	return 0;
}