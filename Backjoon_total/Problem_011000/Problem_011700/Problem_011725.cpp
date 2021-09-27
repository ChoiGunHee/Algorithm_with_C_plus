/**
* 2021. 09. 27
* Creater : Gunhee Choi
* Problem Number : 11725
* Title : 트리의 부모 찾기

* Problem :
루트 없는 트리가 주어진다. 이때, 트리의 루트를 1이라고 정했을 때, 각 노드의 부모를 구하는 프로그램을 작성하시오.

* Input :
첫째 줄에 노드의 개수 N (2 ≤ N ≤ 100,000)이 주어진다. 둘째 줄부터 N-1개의 줄에 트리 상에서 연결된 두 정점이 주어진다.

    7
    1 6
    6 3
    3 5
    4 1
    2 4
    4 7

* Output :
첫째 줄부터 N-1개의 줄에 각 노드의 부모 노드 번호를 2번 노드부터 순서대로 출력한다.

    4
    6
    1
    3
    1
    4

**/

#include <iostream>
#include <vector>

#define MAX_NUM 100001

using namespace std;

int N;
int result[MAX_NUM];
bool visited[MAX_NUM];
vector<int> v[MAX_NUM];

void dfs(int n) {
    visited[n]=true;
    
    for(int i=0; i<v[n].size(); i++) {
        int next=v[n][i];
        if(!visited[next]) {
            result[next]=n;
            dfs(next);
        }
    }//end of for
}

int main() {
    int n1, n2;
    
    cin>>N;
    
    for(int i=0; i<N-1; i++) {
        cin>>n1>>n2;
        v[n1].push_back(n2);
        v[n2].push_back(n1);
    }
    
    dfs(1);
    
    for(int i=2; i<=N; i++)
        cout<<result[i]<<"\n";
    
	return 0;
}