#include<iostream>
using namespace std;
int main()
{
    long long n,data;
    long long sum=0,esum=0;
    cin>>n;
    for(int i=0;i<n-1;i++)
    {
        cin>>data;
        sum+=data;
    }
    esum=((n)*(n+1))/2;
    cout<<esum-sum<<endl;
    return 0;
}