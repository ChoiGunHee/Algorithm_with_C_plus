/**
* 2021. 10. 11
* Creater : Gunhee Choi
* Problem Number : 2738
* Title : 행렬 덧셈

* Problem :
N*M크기의 두 행렬 A와 B가 주어졌을 때, 두 행렬을 더하는 프로그램을 작성하시오.

* Input :
첫째 줄에 행렬의 크기 N 과 M이 주어진다. 둘째 줄부터 N개의 줄에 행렬 A의 원소 M개가 차례대로 주어진다. 이어서 N개의 줄에 행렬 B의 원소 M개가 차례대로 주어진다. N과 M은 100보다 작거나 같고, 행렬의 원소는 절댓값이 100보다 작거나 같은 정수이다.

    3 3
    1 1 1
    2 2 2
    0 1 0
    3 3 3
    4 4 4
    5 5 100

* Output :
첫째 줄부터 N개의 줄에 행렬 A와 B를 더한 행렬을 출력한다. 행렬의 각 원소는 공백으로 구분한다.

    4 4 4
    6 6 6
    5 6 100

**/

#include <iostream>
using namespace std;

int N, M;
int result[101][101];
int tmp[101][101];

int main() {
    cin>>N>>M;

    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++)
            cin>>result[i][j];
    
    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++)
            cin>>tmp[i][j];


    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++)
            result[i][j] = result[i][j] + tmp[i][j];

    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++)
            cout<<result[i][j]<<" ";
        cout<<"\n";
    }

    return 0;
}