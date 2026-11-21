#include <cstdio>
#include <vector>
using namespace std;
int tree[100001];
int gcd(int a,int b){
    if (b>a)
        swap(a,b);
    if(b==0)
        return a;
    return gcd(b,a%b);
}
int main(){
    int mindis;
    int n,x;
    scanf("%d",&n);
    for(int i=0;i<n;i++){scanf("%d",&tree[i]);}
    mindis = tree[1]-tree[0];
    for(int i=1;i<n;i++)
        mindis = gcd(tree[i]-tree[i-1],mindis);
 
 
    printf("%d",(tree[n-1]-tree[0])/mindis+1-n);
 
}