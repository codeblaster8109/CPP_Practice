#include<string>
#include"TrieNode.h"
using namespace std;
class Trie
{
    TrieNode*root;
    public:
    Trie()
    {
        root=new TrieNode('\0');
    }

    //Insert
    void insert(TrieNode*root,string word)
    {
        //Base Case
        if(word.size()==0)
        {
            root->isTerminal=true;
            return;
        }

        //Small Calculation
        int index=word[0]-'a';
        TrieNode*child=root->children[index];
        if(child==NULL)
        {
            child=new TrieNode(word[0]);
            root->children[index]=child;
        }

        //Recursive Call
        insert(child,word.substr(1));
    }
    void insert(string word)
    {
        insert(root,word);
    }

    //Search
    bool search(TrieNode*root,string word)
    {
        //Base Case
        if(word.size()==0)
            return root->isTerminal;

        //Small Calculation
        int index=word[0]-'a';
        TrieNode*child=root->children[index];
        if(child==NULL)
            return false;
        
        //Recursive Call
        return search(child,word.substr(1));
    }
    bool search(string word)
    {
        return search(root,word);
    } 

    //Remove
    void remove(TrieNode*root,string word)
    {
        //Base Case
        if(word.size()==0)
        {
            root->isTerminal=false;
            return ;
        }

        //Small Calculation
        int index=word[0]-'a';
        TrieNode*child=root->children[index];
        if(child==NULL)
            return ;
        
        //Recursive Call
        remove(child,word.substr(1));

        //Remove useless child
        if(child->isTerminal==false)
        {
            for(int i=0;i<26;i++)
            {
                if(child->children[i]!=NULL)
                    return;
            }
            delete child;
            root->children[index]=NULL;
        }
    }
    void remove(string word)
    {
        remove(root,word);
    }
};