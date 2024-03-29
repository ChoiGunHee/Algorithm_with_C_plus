/**
* 2021. 09. 06
* Creater : Gunhee Choi
* Problem Number : 11286
* Title : 절댓값 힙

* Problem :
절댓값 힙은 다음과 같은 연산을 지원하는 자료구조이다.

    1. 배열에 정수 x (x ≠ 0)를 넣는다.
    2. 배열에서 절댓값이 가장 작은 값을 출력하고, 그 값을 배열에서 제거한다. 절댓값이 가장 작은 값이 여러개일 때는, 가장 작은 수를 출력하고, 그 값을 배열에서 제거한다.
    
프로그램은 처음에 비어있는 배열에서 시작하게 된다.

* Input :
첫째 줄에 연산의 개수 N(1≤N≤100,000)이 주어진다. 다음 N개의 줄에는 연산에 대한 정보를 나타내는 정수 x가 주어진다. 만약 x가 0이 아니라면 배열에 x라는 값을 넣는(추가하는) 연산이고, x가 0이라면 배열에서 절댓값이 가장 작은 값을 출력하고 그 값을 배열에서 제거하는 경우이다. 입력되는 정수는 -231보다 크고, 231보다 작다.

    18
    1
    -1
    0
    0
    0
    1
    1
    -1
    -1
    2
    -2
    0
    0
    0
    0
    0
    0
    0
	
* Output :
입력에서 0이 주어진 회수만큼 답을 출력한다. 만약 배열이 비어 있는 경우인데 절댓값이 가장 작은 값을 출력하라고 한 경우에는 0을 출력하면 된다.

	-1
    1
    0
    -1
    -1
    1
    1
    -2
    2
    0

**/

#include <iostream>
#include<queue>
#include<functional>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(0);
	cin.tie(0);
    
    //<data tape, container type, 정렬 기준>
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> p_queue;
    
    int N, x;
    cin>>N;
    
    for(int i=0; i<N; i++) {
        cin>>x;
        if(x!=0)
            p_queue.push({abs(x),x});
        else
            if(p_queue.empty())
                cout<<0<<"\n";
            else {
                cout<<p_queue.top().second<<"\n";
                p_queue.pop();
            }
    }
    
    return 0;
}
