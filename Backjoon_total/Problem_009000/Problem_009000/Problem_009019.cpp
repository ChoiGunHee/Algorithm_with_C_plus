/**
* 2021. 09. 18
* Creater : Gunhee Choi
* Problem Number : 1107
* Title : 리모컨

* Problem :
네 개의 명령어 D, S, L, R 을 이용하는 간단한 계산기가 있다. 이 계산기에는 레지스터가 하나 있는데, 이 레지스터에는 0 이상 10,000 미만의 십진수를 저장할 수 있다. 각 명령어는 이 레지스터에 저장된 n을 다음과 같이 변환한다. n의 네 자릿수를 d1, d2, d3, d4라고 하자(즉 n = ((d1 × 10 + d2) × 10 + d3) × 10 + d4라고 하자)

    D: D 는 n을 두 배로 바꾼다. 결과 값이 9999 보다 큰 경우에는 10000 으로 나눈 나머지를 취한다. 그 결과 값(2n mod 10000)을 레지스터에 저장한다.
    S: S 는 n에서 1 을 뺀 결과 n-1을 레지스터에 저장한다. n이 0 이라면 9999 가 대신 레지스터에 저장된다.
    L: L 은 n의 각 자릿수를 왼편으로 회전시켜 그 결과를 레지스터에 저장한다. 이 연산이 끝나면 레지스터에 저장된 네 자릿수는 왼편부터 d2, d3, d4, d1이 된다.
    R: R 은 n의 각 자릿수를 오른편으로 회전시켜 그 결과를 레지스터에 저장한다. 이 연산이 끝나면 레지스터에 저장된 네 자릿수는 왼편부터 d4, d1, d2, d3이 된다.
    
위에서 언급한 것처럼, L 과 R 명령어는 십진 자릿수를 가정하고 연산을 수행한다. 예를 들어서 n = 1234 라면 여기에 L 을 적용하면 2341 이 되고 R 을 적용하면 4123 이 된다.

여러분이 작성할 프로그램은 주어진 서로 다른 두 정수 A와 B(A ≠ B)에 대하여 A를 B로 바꾸는 최소한의 명령어를 생성하는 프로그램이다. 예를 들어서 A = 1234, B = 3412 라면 다음과 같이 두 개의 명령어를 적용하면 A를 B로 변환할 수 있다.

1234 →L 2341 →L 3412
1234 →R 4123 →R 3412

따라서 여러분의 프로그램은 이 경우에 LL 이나 RR 을 출력해야 한다.

n의 자릿수로 0 이 포함된 경우에 주의해야 한다. 예를 들어서 1000 에 L 을 적용하면 0001 이 되므로 결과는 1 이 된다. 그러나 R 을 적용하면 0100 이 되므로 결과는 100 이 된다.

* Input :
프로그램 입력은 T 개의 테스트 케이스로 구성된다. 테스트 케이스 개수 T 는 입력의 첫 줄에 주어진다. 각 테스트 케이스로는 두 개의 정수 A와 B(A ≠ B)가 공백으로 분리되어 차례로 주어지는데 A는 레지스터의 초기 값을 나타내고 B는 최종 값을 나타낸다. A 와 B는 모두 0 이상 10,000 미만이다.

    3
    1234 3412
    1000 1
    1 16

* Output :
A에서 B로 변환하기 위해 필요한 최소한의 명령어 나열을 출력한다. 가능한 명령어 나열이 여러가지면, 아무거나 출력한다.

    LL
    L
    DDDD

**/

#include <iostream>
#include <queue>
#include <cstring>
#include <string>
#define MAX_NUM 10000
using namespace std;

int A,B;
bool visited[MAX_NUM];

void bfs() {
    int D, S, L, R, tmp;
    queue<pair<int, string>> q;
    q.push(make_pair(A, ""));
    visited[A]=true;
    
    while(!q.empty()) {
        int current = q.front().first;
        string current_op = q.front().second;
        q.pop();
        
        if(current==B) {
            cout<<current_op<<"\n";
            break;
        }
        
        D=(current*2)%MAX_NUM;
        if(!visited[D]) {
            visited[D]=true;
            q.push(make_pair(D, current_op+"D"));
        }
        
        S=current-1<0 ? 9999 : current-1;
        if(!visited[S]) {
            visited[S]=true;
            q.push(make_pair(S, current_op+"S"));
        }
        
        L=(current%1000)*10+(current/1000);
        if(!visited[L]) {
            visited[L]=true;
            q.push(make_pair(L, current_op+"L"));
        }
        
        R=current/10+(current%10)*1000;
        if(!visited[R]) {
            visited[R]=true;
            q.push(make_pair(R, current_op+"R"));
        }
    }//end of q while
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int T;
    cin>>T;
    
    while(T--) {
        cin>>A>>B;
        memset(visited, false, sizeof(visited));
        bfs();
    }
    
	return 0;
}