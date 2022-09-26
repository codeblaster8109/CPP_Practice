#include<iostream>
class TrieNode
{
    public:
    char data;
    TrieNode**children;   //Array pointer of TrieNode pointers(Dynamically allocating Array of TrieNode Pointer)
    bool isTerminal;   //Whether a word ends here or not

    TrieNode(char data)
    {
        this->data=data;
        isTerminal=false;
        children=new TrieNode*[26];
        for(int i=0;i<26;i++)
        {
            children[i]=NULL;   //Since intially no child so every index has NULL
        }
    }
};