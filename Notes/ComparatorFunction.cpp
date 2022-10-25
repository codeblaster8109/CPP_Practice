#include<bits/stdc++.h>
using namespace std;

/*
    ******************************IMPORTANT*********************************

    When we define comparator Function The logic is a little different than 
    what we expect it to be.
    We need to return false if we want to do the thing. For example
    if we need to define comparator function for inbuilt sort function
    and we want to do increasing sort then we need to return false for a>b or return 
    true for a<b.
    Similarly we need to do for other implementation of Functions as well.
    For Sort function we need to pass comparator function with it like:-
    sort(a.begin(),a.end(),compare)
*/

/*
    For an easy way to remember we can just do by returning just what we want
    For example in return a>b we want in descending order as we want first 
    element greater than second element.
*/


//Comparator Function for Min Heap
auto cmp=[](int a, int b)
{
    return a>b;     //Return True if a>b which means false for a>b or true for a<b which is min logic
};




//Comparator Function for Max Heap
auto compare=[](int a ,int b)
{
    return a<b;     //Return true if a<b meaning true for a>b creating max logic
};


int main()
{
    
    //We use decltype because return type of cmp and compare if not defined so we use declare type (decltype)
    
    priority_queue<int,vector<int>,decltype(cmp)>pq_cmp(cmp);       
    priority_queue<int,vector<int>,decltype(compare)>pq_compare(compare);

    //Pushing Values into the queue.
    for(int i=0;i<20;i++)
    {
        pq_cmp.push(i);
        pq_compare.push(i);
    }

    //Printing Min Heap
    cout<<"Min Heap:- ";
    while(!pq_cmp.empty())
    {
        cout<<pq_cmp.top()<<" ";
        pq_cmp.pop();
    }
    cout<<endl<<"Max Heap:- ";


    //Printing Max Heap
    while(!pq_compare.empty())
    {
        cout<<pq_compare.top()<<" ";
        pq_compare.pop();
    }

}