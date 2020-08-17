#include <iostream>
#include <vector>
using namespace std;

bool check(int t, vector<vector<int>>& a, int m) {
	int main = 0; // ��, ������� ������� ������ �� ��� �����
	for (int i = 0; i < a.size(); i++) {
		int temp = 0; // ����� ��� ����, ����� �����������, ������� ������ �������� �����
		int v = (t / (a[i][0] * a[i][1] + a[i][2])) * a[i][1]; // ����� 2 ���� �� �������������
		main += v;
		temp += v;
		int ost = t % (a[i][0] * a[i][1] + a[i][2]);
		if (ost >= a[i][0] * a[i][1]) {
			main += a[i][1];
			temp += a[i][1];
		}
		else {
			main += ost / a[i][0];
			temp += ost / a[i][0];
		}
		a[i][3] = temp;
	}
	return main >= m;
}

int main() {
	int m, n;
	cin >> m >> n;
	vector<vector<int>> a(n);
	for (int i = 0; i < n; i++) {
		int h, q, c;
		cin >> h >> q >> c;
		a[i] = {h, q, c, 0};
	}
	int left = 0;
	int right = 1; // ���� ������� right � �������� long long, �� �������� ����� 2-� ������ �� ��������� �����, ������� �� ����, ����� ������� �������...
	while (!check(right, a, m)) {
		right *= 2;
	}
	right++;
	if (m != 0) {
		while (left < right - 1) {
			int mid = (left + right) / 2;
			if (check(mid, a, m)) { // visual ����������, ��� �� ���������� ������� ������ <= 1��
				right = mid;
			}
			else {
				left = mid;
			}
		}
		cout << right << endl;
		for (auto now : a) {
			cout << now[3] << " ";
		}
	}
	else {
		cout << 0 << endl;
		for (int i = 0; i < n; i++) {
			cout << 0 << " ";
		}
	}
	return 0;
}