/**
* 2021. 09. 22
* Creater : Gunhee Choi
* Problem Number : 14500
* Title : 테트로미노

* Problem :
폴리오미노란 크기가 1×1인 정사각형을 여러 개 이어서 붙인 도형이며, 다음과 같은 조건을 만족해야 한다.

정사각형은 서로 겹치면 안 된다.
도형은 모두 연결되어 있어야 한다.
정사각형의 변끼리 연결되어 있어야 한다. 즉, 꼭짓점과 꼭짓점만 맞닿아 있으면 안 된다.
정사각형 4개를 이어 붙인 폴리오미노는 테트로미노라고 하며, 다음과 같은 5가지가 있다.

아름이는 크기가 N×M인 종이 위에 테트로미노 하나를 놓으려고 한다. 종이는 1×1 크기의 칸으로 나누어져 있으며, 각각의 칸에는 정수가 하나 쓰여 있다.

테트로미노 하나를 적절히 놓아서 테트로미노가 놓인 칸에 쓰여 있는 수들의 합을 최대로 하는 프로그램을 작성하시오.

테트로미노는 반드시 한 정사각형이 정확히 하나의 칸을 포함하도록 놓아야 하며, 회전이나 대칭을 시켜도 된다.

* Input :
첫째 줄에 종이의 세로 크기 N과 가로 크기 M이 주어진다. (4 ≤ N, M ≤ 500)

둘째 줄부터 N개의 줄에 종이에 쓰여 있는 수가 주어진다. i번째 줄의 j번째 수는 위에서부터 i번째 칸, 왼쪽에서부터 j번째 칸에 쓰여 있는 수이다. 입력으로 주어지는 수는 1,000을 넘지 않는 자연수이다.
	
    5 5
    1 2 3 4 5
    5 4 3 2 1
    2 3 4 5 6
    6 5 4 3 2
    1 2 1 2 1
    
* Output :
첫째 줄에 테트로미노가 놓인 칸에 쓰인 수들의 합의 최댓값을 출력한다.

    19
    
**/

#include <iostream>
#define MAX_NUM 501
using namespace std;

int N, M;
int map[MAX_NUM][MAX_NUM];
bool visited[MAX_NUM][MAX_NUM];
int result;

int dx[] = {0, 0, 1, -1};
int dy[] = {-1, 1, 0, 0};

int cx[4][4] = {{0, 0, 0, 1}, {0, 1, 2, 1}, {0, 0, 0, -1}, {0, -1, 0, 1}};
int cy[4][4] = {{0, 1, 2, 1}, {0, 0, 0, 1}, {0, 1, 2, 1}, {0, 1, 1, 1}};

bool check_inside(int x, int y) {
    return (x>=0 && y>=0 && x<N && y<M);
}

void dfs(int x, int y, int sum, int len) {
    if(len>=4) {
        result=max(result, sum);
        return;
    }
    
    for(int i=0; i<4; i++) {
        int nx=x+dx[i];
        int ny=y+dy[i];
        
        if(nx < 1 || nx > N || ny < 1 || ny > M)
            continue;
        
        if(!visited[nx][ny]) {
            visited[nx][ny]=true;
            dfs(nx, ny, sum+map[nx][ny], len+1);
            visited[nx][ny]=false;
        }
    }
}

void check_c(int x, int y) {
    for(int i=0; i<4; i++){

        bool out = false;
        int sum = 0;

        for(int j=0; j<4; j++){
            int nx=x+cx[i][j];
            int ny=y+cy[i][j];

            if(nx < 1 || nx > N || ny < 1 || ny > M) {
                out = true;
                break;
            }
            else
                sum += map[nx][ny];
        }
        
        if(!out) {
            result = max(result, sum);
        }
    }
}

int main(void) {
    cin>>N>>M;
    
    for(int i=1; i<=N; i++)
        for(int j=1; j<=M; j++)
            cin>>map[i][j];
    
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=M; j++) {
            visited[i][j]=true;
            dfs(i, j, map[i][j], 1);
            visited[i][j]=false;
            
            check_c(i, j);
        }
    }
    
    cout<<result<<"\n";
    
    return 0;
}
