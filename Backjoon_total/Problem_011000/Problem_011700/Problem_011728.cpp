/**
* 2021. 09. 14
* Creater : Gunhee Choi
* Problem Number : 11728
* Title : 배열 합치기

* Problem :
정렬되어있는 두 배열 A와 B가 주어진다. 두 배열을 합친 다음 정렬해서 출력하는 프로그램을 작성하시오.

* Input :
첫째 줄에 배열 A의 크기 N, 배열 B의 크기 M이 주어진다. (1 ≤ N, M ≤ 1,000,000)

둘째 줄에는 배열 A의 내용이, 셋째 줄에는 배열 B의 내용이 주어진다. 배열에 들어있는 수는 절댓값이 109보다 작거나 같은 정수이다.

    4 3
    2 3 5 9
    1 4 7

* Output :
첫째 줄에 두 배열을 합친 후 정렬한 결과를 출력한다.

    1 2 3 4 5 7 9

**/

#include <iostream>
#define MAX_NUM 1000001

using namespace std;

int A[MAX_NUM];
int B[MAX_NUM];
int results[MAX_NUM*2];

int main(void) {
    ios::sync_with_stdio(false);
	cin.tie(nullptr);
    
    int N, M;
    
    cin>>N>>M;
    
    for(int i=0; i<N; i++)
        cin>>A[i];
    for(int i=0; i<M; i++)
        cin>>B[i];
    
    int a_i=0, b_i=0, k=0;
    while(a_i<N && b_i<M) {
        if(A[a_i]<B[b_i])
            results[k++]=A[a_i++];
        else
            results[k++]=B[b_i++];
    }
    
    while(a_i<N)
        results[k++]=A[a_i++];
    while(b_i<M)
        results[k++]=B[b_i++];
    
    for(int i=0; i<k; i++)
        cout<<results[i]<<" ";
    cout<<"\n";
    
    return 0;
}
