

// this code is not optimized

#include <bits/stdc++.h>
using namespace std;

class TrieNode
{
public:
    char chr;
    map<char, TrieNode *> children;
    bool isTerminal;
    TrieNode(char chr)
    {
        this->chr = chr;
        isTerminal = false;
    }
};

class Trie
{
public:
    TrieNode *root;

    Trie()
    {
        root = new TrieNode('\0');
    }

    void insert(string str)
    {
        TrieNode *temp = root;
        for (char ch : str)
        {
            if (temp->children.count(ch))
            {
                temp = temp->children[ch];
            }
            else
            {
                temp->children[ch] = new TrieNode(ch);
                temp = temp->children[ch];
            }
        }
        temp->isTerminal = true;
    }

    bool search(string str)
    {
        TrieNode *temp = root;
        for (char ch : str)
        {
            if (temp->children.count(ch))
            {
                temp = temp->children[ch];
            }
            else
            {
                return false;
            }
        }
        return true;
    }

    bool startWith(string prefix)
    {
        TrieNode *temp = root;
        for (char ch : prefix)
        {
            if (temp->children.count(ch))
            {
                temp = temp->children[ch];
            }
            else
            {
                return false;
            }
        }
        return true;
    }

    //     void getAllWords(){
    //         TrieNode *temp = root;
    //         vector<string> ans;
    //         string word = "";
    //         dfs_helper(root,ans,word);
    //     }

    //     void dfs_helper(TrieNode *node, vector<string> &ans, string &word){

    //         if(node->isTerminal){
    //             ans.push_back(word);
    //             cout<<word<<endl;
    //         }

    //         for(auto it : node->children){
    //             word += it.first;
    //             dfs_helper(it.second,ans,word);
    //             word.pop_back();
    //         }

    //     }

    void search(string searchWord, vector<vector<string>> &ans)
    {
        TrieNode *temp = root;
        string word = "";
        for (char c : searchWord)
        {
            vector<string> res;
            word += c;
            if (temp->children.count(c))
            {
                temp = temp->children[c];
                dfs_helper(temp, res, word);
            }
            else
            {
                res.clear();
            }
            ans.push_back(res);
        }
    }

    void dfs_helper(TrieNode *node, vector<string> &res, string &word)
    {
        if (node->isTerminal)
        {
            res.push_back(word);
            // cout<<word<<endl;
        }

        if (res.size() >= 3)
            return;

        for (auto it : node->children)
        {
            word += it.first;
            dfs_helper(it.second, res, word);
            word.pop_back();
        }
    }


       void searchNew(string searchWord, vector<vector<string>> &ans){
        TrieNode *temp = root;
        string prefix = "";
        // bool flag = true;
        int i=0, n=searchWord.length();
        vector<string> res;
        for(;i<n;i++){
            char ch = searchWord[i];
            if(temp->children.count(ch)){
                temp = temp->children[ch];
                prefix += ch;
                dfs_helper(temp,res,prefix);
                ans.push_back(res);
                res.clear();
            }
            else break;
        }
        
        while(i++<n){
            ans.push_back({});
        }
    }
    
};

class Solution
{
public:
    vector<vector<string>> suggestedProducts(vector<string> &products, string searchWord)
    {

        Trie T;
        for (string str : products)
        {
            T.insert(str);
        }

        vector<vector<string>> ans;
        // T.getAllWords();
        T.search(searchWord, ans);

        return ans;
    }
};

int main()
{

    return 0;
}