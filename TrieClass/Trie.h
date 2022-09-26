#include<string>
#include"TrieNode.h"
using namespace std;
class Trie
{
    TrieNode*root;
    public:
    Trie()
    {
        root=new TrieNode('\0');  //Root has no data so initialising it with NULL
    }

    //Insert
    void insert(TrieNode*root,string word)
    {
        //Base Case
        if(word.size()==0)
        {
            root->isTerminal=true; //Word ends as the last character becomes root and no more word left
            return;
        }

        //Small Calculation
        int index=word[0]-'a';  //Allocating index according to alphabetical order so that ut takes no time in searching
        TrieNode*child=root->children[index];
        if(child==NULL)
        {
            child=new TrieNode(word[0]);  //Creating new TrieNode for non existent child
            root->children[index]=child;  //Joining the node
        }

        //Recursive Call
        insert(child,word.substr(1));  //Add remaining word on the subtrie
    }
    void insert(string word)
    {
        insert(root,word);  //Since user can't pass root as he does not have access to it
    }

    //Search
    bool search(TrieNode*root,string word)
    {
        //Base Case
        if(word.size()==0)
            return root->isTerminal;  //If word ends here then word is present even if the same word exist if it does not end here it does not exist 

        //Small Calculation
        int index=word[0]-'a';
        TrieNode*child=root->children[index];
        if(child==NULL)
            return false;   //Since child does not exist directly return false as word doees not exist 
        
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
            root->isTerminal=false;  //Setting isTerminal false inddicatin no word ends here inturn removing the word as now search will return false
            return ;
        }

        //Small Calculation
        int index=word[0]-'a';
        TrieNode*child=root->children[index];
        if(child==NULL)
            return ;    //Word not found
        
        //Recursive Call
        remove(child,word.substr(1));  //Remove the remianing word in the subtrie

        //Remove useless child
        if(child->isTerminal==false)  //Condition 1(For useless alphabet): If no word ends there rendering it useless
        {
            for(int i=0;i<26;i++)
            {
                if(child->children[i]!=NULL)  //Condition 2: If it has no child then then it is useless
                    return;
            }
            delete child;   //If both conditions satisfy then delete the child
            root->children[index]=NULL;  //Remove its address in the root's Array
        }
    }
    void remove(string word)
    {
        remove(root,word);
    }

    /*
        Please Dry run for better understanding with noting changes in root , word and size.
    */
};