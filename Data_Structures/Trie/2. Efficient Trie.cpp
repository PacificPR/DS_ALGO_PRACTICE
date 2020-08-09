#include <iostream>
#include <cstring>         //For using memset
#include <unordered_map>

using namespace std;

struct Trie{                //Created a Trie Structure 
    bool wordEnd;           //wordEnd indicates if the word has ended or not
    unordered_map<char,Trie*> child;
    Trie(){                 //Defining a Trie Node
        wordEnd = false;                //By default putting wordEnd as false
        child.clear();
    }
};

Trie* root;                             //Trie Root

void insert(string s){
    Trie* curr = root;
    for(char c:s){                      //Traverse for all char in string as string is an array of char
        if(curr->child.count(c)==0){    //Check if the char is present in the child map of current node
            curr->child[c] = new Trie();//IF it's not there, create a child node mapped to this char
        }
        curr = curr->child[c];       //Travel to the child node
    }
    curr->wordEnd = true;               //Once all the nodes are created for the word, at the end node mark it as wordEnd
}

bool check(string s){                   //Search for a string 
    Trie* curr = root;
    for(char c:s){      
        if(curr->child.count(c)==0)     //Check if a child node of same index as the character is present or not
            return false;               //IF no such child node is present then return false;
        curr = curr->child[c];       //If it is present, travel to that node
    }
    
    return curr->wordEnd;               //At the end check if it is the wordEnd 
                                        //If abc is present and we check for ab, we check if b has the wordEnd as true, thus the last statement
}

int main(){
    int N;
    cout<<"Enter number of words to enter in Trie\n";
    cin>>N;
    string st;
    root = new Trie();
    cout<<"Enter the words in small letters\n";
    for(int i=1;i<=N;i++){
        cin>>st;
        insert(st);
    }

    cout<<"Enter number of words to check if it's present or not\n";
    cin>>N;
    for(int i=1;i<=N;i++){
        cin>>st;
        if(check(st))
            cout<<st<<" FOUND \n";
        else
            cout<<st<<" NOT FOUND \n";
    }

}