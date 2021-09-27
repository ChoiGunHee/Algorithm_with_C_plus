/**
* 2021. 09. 27
* Creater : Gunhee Choi
* Problem Number : 16953
* Title : A → B

* Problem :
정수 A를 B로 바꾸려고 한다. 가능한 연산은 다음과 같은 두 가지이다.

    - 2를 곱한다.
    - 1을 수의 가장 오른쪽에 추가한다. 
    
A를 B로 바꾸는데 필요한 연산의 최솟값을 구해보자.

* Input :
첫째 줄에 A, B (1 ≤ A < B ≤ 109)가 주어진다.

    2 162
    
* Output : 
A를 B로 바꾸는데 필요한 연산의 최솟값에 1을 더한 값을 출력한다. 만들 수 없는 경우에는 -1을 출력한다.

    5
    
**/

/**
컴파일 : gcc back_08_09 -lm
**/

#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

queue<pair<long long, long long>> q;
long long result=-1;
long long A, B;

void bfs() {
    
    q.push({A, 1});
    
    while(!q.empty()) {
        long long tmp = q.front().first;
        long long cnt = q.front().second;
        q.pop();
        
        if(tmp==B) {
            result = cnt;
            break;
        }
        
        long long t1 = tmp*2;
        long long t2 = tmp*10+1;
        
        if(t1<=B)
            q.push({t1, cnt+1});
        
        if(t2<=B)
            q.push({t2, cnt+1});
    }
}

int main() {
	cin>>A>>B;
    
    bfs();
    
    cout<<result<<"\n";
    
	return 0;
}