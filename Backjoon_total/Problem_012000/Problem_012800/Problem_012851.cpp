/**
* 2021. 10. 06
* Creater : Gunhee Choi
* Problem Number : 12851
* Title : 숨바꼭질 2

* Problem :
수빈이는 동생과 숨바꼭질을 하고 있다. 수빈이는 현재 점 N(0 ≤ N ≤ 100,000)에 있고, 동생은 점 K(0 ≤ K ≤ 100,000)에 있다. 수빈이는 걷거나 순간이동을 할 수 있다. 만약, 수빈이의 위치가 X일 때 걷는다면 1초 후에 X-1 또는 X+1로 이동하게 된다. 순간이동을 하는 경우에는 1초 후에 2*X의 위치로 이동하게 된다.

수빈이와 동생의 위치가 주어졌을 때, 수빈이가 동생을 찾을 수 있는 가장 빠른 시간이 몇 초 후인지 그리고, 가장 빠른 시간으로 찾는 방법이 몇 가지 인지 구하는 프로그램을 작성하시오.

* Input :
첫 번째 줄에 수빈이가 있는 위치 N과 동생이 있는 위치 K가 주어진다. N과 K는 정수이다.

    5 17

* Output :
첫째 줄에 수빈이가 동생을 찾는 가장 빠른 시간을 출력한다.

둘째 줄에는 가장 빠른 시간으로 수빈이가 동생을 찾는 방법의 수를 출력한다.

    4
    2

**/

#include <iostream>
#include <queue>
#define MAX_NUM 100001
using namespace std;

int N, K;
bool visited[MAX_NUM];
queue<pair<int, int>> q;
int result_time;
int result_cnt;

int bfs() {
    while(!q.empty()) {
        int currunt = q.front().first;
        int time = q.front().second;
        
        q.pop();
        visited[currunt]=true;
        
        if(result_cnt && currunt==K && result_time==time)
            result_cnt++;
        
        if(!result_cnt && currunt==K) {
            result_time=time;
            result_cnt++;
        }
        
        if(currunt-1>=0 && !visited[currunt-1])
            q.push({currunt-1, time+1});
        
        if(currunt+1<=MAX_NUM-1 && !visited[currunt+1]) 
            q.push({currunt+1, time+1});
        
        if(currunt*2<=MAX_NUM-1 && !visited[currunt*2]) 
            q.push({currunt*2, time+1});
        
    }//end of while
    
    return -1;
}


int main(void) {
    cin>>N>>K;
    
    q.push({N,0});
    bfs();
    
    cout<<result_time<<"\n"<<result_cnt<<"\n";
    
    return 0;
}
