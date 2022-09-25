#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin>>n;
    ll array[n];
    ll prev=0;
    ll ans=0;
    for(ll i=0;i<n;i++)
    {
        cin>>array[i];
        if(i!=0)
        {
            if(array[i]<array[prev])
            {
                ans+=abs(array[prev]-array[i]);
                array[i]=array[prev];
            }
        }
        prev=i;
    }
    cout<<ans<<endl;
}
int main()
{
    solve();
}