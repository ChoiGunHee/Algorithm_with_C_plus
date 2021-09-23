/**
* 2021. 09. 23
* Creater : Gunhee Choi
* Problem Number : 1991
* Title : 트리 순회

* Problem :
이진 트리를 입력받아 전위 순회(preorder traversal), 중위 순회(inorder traversal), 후위 순회(postorder traversal)한 결과를 출력하는 프로그램을 작성하시오.

예를 들어 위와 같은 이진 트리가 입력되면,

전위 순회한 결과 : ABDCEFG // (루트) (왼쪽 자식) (오른쪽 자식)
중위 순회한 결과 : DBAECFG // (왼쪽 자식) (루트) (오른쪽 자식)
후위 순회한 결과 : DBEGFCA // (왼쪽 자식) (오른쪽 자식) (루트)

* Input :
첫째 줄에는 이진 트리의 노드의 개수 N(1 ≤ N ≤ 26)이 주어진다. 둘째 줄부터 N개의 줄에 걸쳐 각 노드와 그의 왼쪽 자식 노드, 오른쪽 자식 노드가 주어진다. 노드의 이름은 A부터 차례대로 알파벳 대문자로 매겨지며, 항상 A가 루트 노드가 된다. 자식 노드가 없는 경우에는 .으로 표현한다.

    7
    A B C
    B D .
    C E F
    E . .
    F . G
    D . .
    G . .

* Output :
첫째 줄에 전위 순회, 둘째 줄에 중위 순회, 셋째 줄에 후위 순회한 결과를 출력한다. 각 줄에 N개의 알파벳을 공백 없이 출력하면 된다.

    ABDCEFG
    DBAECFG
    DBEGFCA

**/

#include <iostream>
#include <vector>
#include <algorithm>
#define MAX_NUM 26
using namespace std;

struct node{
    char left;
    char right;
};

vector<node> v(MAX_NUM);

void pre_order(char node) {
    if(node=='.')
        return;
    
    cout<<node;
    pre_order(v[node].left);
    pre_order(v[node].right);
}

void in_order(char node) {
    if(node=='.')
        return;
    
    in_order(v[node].left);
    cout<<node;
    in_order(v[node].right);
}

void post_order(char node) {
    if(node=='.')
        return;
    
    post_order(v[node].left);
    post_order(v[node].right);
    cout<<node;
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    
    int N;
    char node, l_node, r_node;
    
    cin>>N;
    for(int i=0; i<N; i++) {
        cin>>node>>l_node>>r_node;
        v[node].left = l_node;
        v[node].right = r_node;
    }
    
    pre_order('A');
    cout<<"\n";
    
    in_order('A');
    cout<<"\n";
    
    post_order('A');
    cout<<"\n";
    
	return 0;	
}