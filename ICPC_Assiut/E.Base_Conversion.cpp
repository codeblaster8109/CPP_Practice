#include<bits/stdc++.h>
using namespace std;
void binary(int &n)
{
    if(n==0||n==1)
    {
        cout<<n;
        return;
    }
    int rem=n%2;
    int quo=n/2;
    binary(quo);
    cout<<rem;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        binary(n);
        cout<<endl;
    }
}