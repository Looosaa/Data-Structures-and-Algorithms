//记忆搜索
#include <iostream>
#include <vector>
using namespace std;

vector <long long> memo;

long long fib(int n){
    if(n<2)
        return n;

    if(memo[n]!=-1)
        return memo[n];
    
    memo[n]=fib(n-1)+fib(n-2);

    return memo[n];
}

int main(){
    int n;
    cin>>n;
    
    memo.assign(n+1,-1);//大小n_1,元素初始化为-1

    cout<<fib(n);
    return 0;
}

//dp

// f=1; fib(-1)
// g=0; fib(0)

// while(0<n--){
//     g=g+f;
//     f=g-f;
// }

// return g;
