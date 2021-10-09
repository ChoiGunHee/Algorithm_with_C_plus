//unsolve, 1197참고

/**
* 2021. 10. 09
* Creater : Gunhee Choi
* Problem Number : 4386
* Title : 별자리 만들기

* Problem :
도현이는 우주의 신이다. 이제 도현이는 아무렇게나 널브러져 있는 n개의 별들을 이어서 별자리를 하나 만들 것이다. 별자리의 조건은 다음과 같다.

별자리를 이루는 선은 서로 다른 두 별을 일직선으로 이은 형태이다.
모든 별들은 별자리 위의 선을 통해 서로 직/간접적으로 이어져 있어야 한다.
별들이 2차원 평면 위에 놓여 있다. 선을 하나 이을 때마다 두 별 사이의 거리만큼의 비용이 든다고 할 때, 별자리를 만드는 최소 비용을 구하시오.

* Input :
첫째 줄에 별의 개수 n이 주어진다. (1 ≤ n ≤ 100)

둘째 줄부터 n개의 줄에 걸쳐 각 별의 x, y좌표가 실수 형태로 주어지며, 최대 소수점 둘째자리까지 주어진다. 좌표는 1000을 넘지 않는 양의 실수이다.

    3
    1.0 1.0
    2.0 2.0
    2.0 4.0

* Output :
첫째 줄에 정답을 출력한다. 절대/상대 오차는 10-2까지 허용한다.

    3.41

**/

#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;

pair<int, pair<int, int>> edge[100];
int parents[101];
int v, e;

int m_find(int x) {
    if(x==parents[x])
        return x;
    else
        return parents[x]=m_find(parents[x]);
}

void m_union(int x, int y) {
    int xP = m_find(x);
    int yP = m_find(y);
    parents[xP]=yP;
}

int main() {
    int result=0;
    int cnt=0;
    
    cin>>v>>e;
    for(int i=1; i<=v; i++)
        parents[i]=i;
    
    for(int i=0; i<e; i++) {
        int a, b, c;
        cin>>a>>b>>c;
        edge[i].first=c;
        edge[i].second.first=a;
        edge[i].second.second=b;
    }
    
    sort(edge, edge+e);
    for(int i=0; i<e; i++) {
        int c=edge[i].first;
        int a=edge[i].second.first;
        int b=edge[i].second.second;
        
        if(m_find(a)==m_find(b))
            continue;
        m_union(a, b);
        result+=c;
        cnt++;
        
        if(cnt==v-1)
            break;
    }
    
    cout<<result<<"\n";
    
    return 0;
}