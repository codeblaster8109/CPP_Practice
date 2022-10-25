#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
   int n;
   cin>>n;
   vector<int>a(n);
   vector<int>b(n); 
   for(int i=0;i<n;i++) cin>>a[i];
   
   stack<int>s;
   for(int i=n-1;i>=0;i--){
       if(s.empty()){           //Stack intially empty at arrival
           b[i]=-1;
           s.push(a[i]);
       }
       else{
           while(!s.empty() && s.top()<=a[i]) s.pop();      //Removing all smaller elements from the stack
           if(s.empty()){       //Stack becomes empty i.e. no element greater on right than currrent 
               b[i]=-1;
               s.push(a[i]);
           }
           else{
               b[i]=s.top();    //Stack has some elements left so top most element must be greater than current       
               s.push(a[i]);
           }
       }
   }
   
    // printing the new vector with the next greater element
   for(int i=0;i<n;i++) cout<<b[i]<<" ";
}