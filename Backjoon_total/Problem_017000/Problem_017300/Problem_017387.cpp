/**
* 2021. 09. 07
* Creater : Gunhee Choi
* Problem Number : 19387
* Title : 선분 교차 2

* Problem :
2차원 좌표 평면 위의 두 선분 L1, L2가 주어졌을 때, 두 선분이 교차하는지 아닌지 구해보자.

L1의 양 끝 점은 (x1, y1), (x2, y2), L2의 양 끝 점은 (x3, y3), (x4, y4)이다.

* Input :
첫째 줄에 L1의 양 끝 점 x1, y1, x2, y2가, 둘째 줄에 L2의 양 끝 점 x3, y3, x4, y4가 주어진다.

    1 1 5 5
    1 5 5 1

* Output :
L1과 L2가 교차하면 1, 아니면 0을 출력한다.

    1

**/

#include <iostream>
#include<algorithm>
using namespace std;

#define ll long long

int CCW(pair<ll, ll> a, pair<ll, ll> b, pair<ll, ll> c) {
    ll tmp = a.first * b.second
            + b.first * c.second
            + c.first * a.second
            - a.second * b.first
            - b.second * c.first
            - c.second * a.first;
    
    if(tmp>0)
        return 1;
    else if(tmp<0)
        return -1;
    else
        return 0;
}

bool check(pair<ll, ll> a, pair<ll, ll> b, pair<ll, ll> c, pair<ll, ll> d) {
    int abc = CCW(a, b, c);
    int abd = CCW(a, b, d);
    int cda = CCW(c, d, a);
    int cdb = CCW(c, d, b);
 
    if (abc*abd==0 && cda*cdb==0) {
        if (a > b) swap(a, b);
        if (c > d) swap(c, d);
        
        return a <= d && c <= b;
    }
 
    return abc*abd<=0 && cda*cdb<=0;
}

int main() {
    ios_base::sync_with_stdio(0);
	cin.tie(0);
    cout.tie(0);
    
    pair<ll, ll> point[4];
    int result;
    int x,y;
    
    for(int i=0; i<4; i++) {
        cin>>x>>y;
        point[i]=make_pair(x,y);
    }
    
    if(check(point[0], point[1], point[2], point[3]))
        cout<<"1\n";
    else
        cout<<"0\n";
    
	return 0;
}