/**
* 2021. 09. 22
* Creater : Gunhee Choi
* Problem Number : 20149
* Title : 선분 교차 3

* Problem :
2차원 좌표 평면 위의 두 선분 L1, L2가 주어졌을 때, 두 선분이 교차하는지 아닌지 구해보자. 한 선분의 끝 점이 다른 선분이나 끝 점 위에 있는 것도 교차하는 것이다.

L1의 양 끝 점은 (x1, y1), (x2, y2), L2의 양 끝 점은 (x3, y3), (x4, y4)이다.

* Input :
첫째 줄에 L1의 양 끝 점 x1, y1, x2, y2가, 둘째 줄에 L2의 양 끝 점 x3, y3, x4, y4가 주어진다.

	1 1 5 5
    1 5 5 1

* Output :
L1과 L2가 교차하면 첫째 줄에 1, 아니면 0을 출력한다.

두 선분이 한 점에서 교차하는 경우 둘째 줄에 교차하는 점의 x좌표와 y좌표를 공백으로 구분해 출력한다. 한 점에서 교차하지 않는 경우에는 둘째 줄을 출력하지 않는다.

좌표의 절대/상대 오차는 10-9까지 허용한다.

	1
    3 3

* 제한
    -1,000,000 ≤ x1, y1, x2, y2, x3, y3, x4, y4 ≤ 1,000,000
    x1, y1, x2, y2, x3, y3, x4, y4는 정수    
**/

#include <iostream>
#include <vector>
#include <algorithm>

#define X first
#define Y second

using namespace std;

vector<pair<long long, long long>> v;

void find_intersection(pair<long long, long long> A,
                       pair<long long, long long> B,
                       pair<long long, long long> C,
                       pair<long long, long long> D) {
    
	double px = (A.first * B.second - A.second * B.first) * (C.first - D.first) - (A.first - B.first) * (C.first * D.second - C.second * D.first);
	double py = (A.first * B.second - A.second * B.first) * (C.second - D.second) - (A.second - B.second) * (C.first * D.second - C.second * D.first);
	double p = (A.first - B.first) * (C.second - D.second) - (A.second - B.second) * (C.first - D.first);

	if (p==0) {
		if (B == C && A <= C)
            cout << B.first << " " << B.second << '\n';
		else if (A == D && C <= A)
            cout << A.first << " " << A.second << '\n';
	} else {
		double x = px / p;
		double y = py / p;

		cout << fixed;
		cout.precision(9);
		cout << x << " " << y;
	}
}

long long CCW(pair<long long, long long> A,
              pair<long long, long long> B,
              pair<long long, long long> C) {
    
	long long tmp = A.first * B.second + B.first * C.second + C.first * A.second;
	tmp -= B.first * A.second + C.first * B.second + A.first * C.second;

	if (tmp>0)
        return 1;
	else if (tmp < 0)
        return -1;
    
    return 0;
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	long long x, y;
    long long ans1;
    long long ans2;
    
    for (int i = 0; i < 4; i++) {
		cin >> x >> y;
		v.push_back({x,y});
	}
    
    ans1 = CCW(v[0], v[1], v[2]) * CCW(v[0], v[1], v[3]);
	ans2 = CCW(v[2], v[3], v[0]) * CCW(v[2], v[3], v[1]);

	if (ans1 == 0 && ans2 == 0) {
		if (v[0] > v[1])
            swap(v[0], v[1]);
        
		if (v[2] > v[3])
            swap(v[2], v[3]);
		
		if (v[0] <= v[3] && v[1] >= v[2]) {
			cout << 1 << '\n';
			find_intersection(v[0], v[1], v[2], v[3]);
		}
		else cout << 0 << '\n';
	} else {
		if (ans1 <= 0 && ans2 <= 0) {
			cout << 1 << '\n';
			find_intersection(v[0], v[1], v[2], v[3]);
		} else
            cout << 0 << '\n';
	}
    
	return 0;	
}