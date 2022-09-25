#include<iostream>
using namespace std;
void print(long long n)
{
    cout<<n<<" ";
    if(n==1)
    { 
        cout<<endl;
        return;  
    }
    if(n%2==0)
    {
        print(n/2);
    }
    else
    {
        print((3*n)+1);
    }

}
int main()
{
    long long n; //As when doing for some near large numbers it might overflow when doing 3*n+1
    cin>>n;
    print(n);
    return 0;
}