#include<iostream>
#include"Trie.h"
using namespace std;

int main()
{
    Trie h;
    h.insert("abcd");
    cout<<h.search("abcd")<<endl;
    h.remove("abcd");
    cout<<h.search("abcd")<<endl;
}