/**
* 2021. 09. 21
* Creater : Gunhee Choi
* Problem Number : 10026
* Title : 적록색약
* Problem :
적록색약은 빨간색과 초록색의 차이를 거의 느끼지 못한다. 따라서, 적록색약인 사람이 보는 그림은 아닌 사람이 보는 그림과는 좀 다를 수 있다.

크기가 N×N인 그리드의 각 칸에 R(빨강), G(초록), B(파랑) 중 하나를 색칠한 그림이 있다. 그림은 몇 개의 구역으로 나뉘어져 있는데, 구역은 같은 색으로 이루어져 있다. 또, 같은 색상이 상하좌우로 인접해 있는 경우에 두 글자는 같은 구역에 속한다. (색상의 차이를 거의 느끼지 못하는 경우도 같은 색상이라 한다)

예를 들어, 그림이 아래와 같은 경우에

    RRRBB
    GGBBB
    BBBRR
    BBRRR
    RRRRR

적록색약이 아닌 사람이 봤을 때 구역의 수는 총 4개이다. (빨강 2, 파랑 1, 초록 1) 하지만, 적록색약인 사람은 구역을 3개 볼 수 있다. (빨강-초록 2, 파랑 1)

그림이 입력으로 주어졌을 때, 적록색약인 사람이 봤을 때와 아닌 사람이 봤을 때 구역의 수를 구하는 프로그램을 작성하시오.

* Input :
첫째 줄에 N이 주어진다. (1 ≤ N ≤ 100)
둘째 줄부터 N개 줄에는 그림이 주어진다.

    5
    RRRBB
    GGBBB
    BBBRR
    BBRRR
    RRRRR
	
* Output :
적록색약이 아닌 사람이 봤을 때의 구역의 개수와 적록색약인 사람이 봤을 때의 구역의 수를 공백으로 구분해 출력한다.

    4 3
    
**/

#include <iostream>
#include <cstring>
#include <queue>
#define MAX_NUM 100

using namespace std;

int dx[]={0, 0, 1, -1};
int dy[]={1, -1, 0, 0};

char map[MAX_NUM][MAX_NUM];
bool visited[MAX_NUM][MAX_NUM];
int N;

void bfs(int s_x, int s_y) {
    queue<pair<int,int>> q;
    q.push(make_pair(s_x, s_y));
    visited[s_x][s_y]=true;
    
    while(!q.empty()) {
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        
        for(int i=0; i<4; i++) {
            int nx=x+dx[i];
            int ny=y+dy[i];
            
            if(nx>=0 && ny>=0 && nx<N && ny<N) {
                    if(visited[nx][ny]==false && map[x][y]==map[nx][ny]) {
                        visited[nx][ny]=true;
                        q.push(make_pair(nx, ny));
                    }
            }
        }//end of for
    }//end of while
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int result1=0, result2=0;
    
    cin>>N;
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            cin>>map[i][j];
    
    //적록색약이 아닌 사람 result
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            if(visited[i][j]==false) {
                bfs(i, j);
                result1++;
            }
        }
    }
    
    memset(visited, false, sizeof(visited));
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            if(map[i][j]=='G')
                map[i][j]='R';
        }
    }
    
    //적록색약인 사람 result
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            if(visited[i][j]==false) {
                bfs(i, j);
                result2++;
            }
        }
    }
    
    cout<<result1<<" "<<result2<<"\n";
    
	return 0;
}