// https://leetcode.com/problems/search-suggestions-system/

#include <bits/stdc++.h>
using namespace std;
class TrieNode
{
public:
    char chr;
    TrieNode *chars[26];
    bool isTerminal;
    TrieNode(char chr)
    {
        this->chr = chr;
        isTerminal = false;

        for (int i = 0; i < 26; i++)
        {
            chars[i] = NULL;
        }
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
            if (temp->chars[ch - 'a'])
            {
                temp = temp->chars[ch - 'a'];
            }
            else
            {
                temp->chars[ch - 'a'] = new TrieNode(ch);
                temp = temp->chars[ch - 'a'];
            }
        }
        temp->isTerminal = true;
    }

    void search(string searchWord, vector<vector<string>> &ans)
    {
        TrieNode *temp = root;
        string prefix = "";
        // bool flag = true;
        int i = 0, n = searchWord.length();
        vector<string> res;
        for (; i < n; i++)
        {
            char ch = searchWord[i];
            if (temp->chars[ch - 'a'])
            {
                temp = temp->chars[ch - 'a'];
                prefix += ch;
                dfs_helper(temp, res, prefix);
                ans.push_back(res);
                res.clear();
            }
            else
                break;
        }

        while (i++ < n)
        {
            ans.push_back({});
        }
    }

    void dfs_helper(TrieNode *node, vector<string> &res, string word)
    {

        if (res.size() >= 3)
            return;

        if (node->isTerminal)
        {
            res.push_back(word);
            // cout<<word<<endl;
        }

        for (char ch = 'a'; ch <= 'z'; ch++)
        {
            if (node->chars[ch - 'a'])
            {
                word += ch;
                dfs_helper(node->chars[ch - 'a'], res, word);
                word.pop_back();
            }
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
            T.insert(str);

        vector<vector<string>> ans;
        T.search(searchWord, ans);

        return ans;
    }
};

int main()
{

    return 0;
}