#include <iostream>
#include <vector>
using namespace std;
// 14

// void storeString(TrieNode *root, vector<string> &ans, string &input, string
// &prefix)
// {
//     // base case
//     if (root->isTerminal == true)
//     {
//         // ans store
//         ans.push_back(prefix + input);
//         // there is no need for return in this case
//         // why no return? -> kyuki aisa ho sakta hai jo terminal node hai
//         uske niche bhi word ho
//     }

//     // kisi bhi root node pe aata hu to puchta hoon
//     // -> tere pass a-z tak konsa child hai

//     for (char ch = 'a'; ch <= 'z'; ch++)
//     {
//         int index = ch - 'a';
//         // a-z tak check kiya konsa char present hai
//         TrieNode *next = root->children[index];
//         if (next != NULL)
//         {
//             // child exist
//             // input i.e -> (ans) me push kardo
//             input.push_back(ch);
//             // baaki recursion
//             storeString(next, ans, input, prefix);
//             // backtrack
//             input.pop_back();
//         }
//     }
// }

// void findPrefixString(TrieNode *root, string input, vector<string> &ans,
// string &prefix)
// {
//     // base case
//     // empty string bacha hai ab
//     if (input.length() == 0)
//     {
//         // yaha tak pahoch chuke ho last char tak uske niche ke saare ke
//         saare ans ko store kar ke laao TrieNode *lastchar = root;
//         storeString(lastchar, ans, input, prefix);
//         return;
//     }

//     char ch = input[0];
//     int index = ch - 'a';
//     TrieNode *child;

//     // traversal of input, eg -> "ca" is present aur not
//     if (root->children[index] != NULL)
//     {
//         // child present
//         // go to that index where input last char, eg-> "ca" is present
//         child = root->children[index];
//     }
//     else
//     {
//         return;
//     }
//     // recursion call
//     // -> (child) ye naya root hai ab
//     //
//     findPrefixString(child, input.substr(1), ans, prefix);
// }

// vector<vector<string>> getSuggestions(TrieNode *root, string input)
// {

//     vector<vector<string>> output;
//     TrieNode *prev = root;
//     string inputHelper = "";

//     for (int i = 0; i < input.length(); i++)
//     {
//         char lastChar = input[i];
//         int index = lastChar - 'a';
//         TrieNode *curr = prev->children[index];

//         if (curr == NULL)
//         {
//             // No child exist
//             break;
//             ;
//         }
//         else
//         {
//             vector<string> nicheKaAns;
//             inputHelper.push_back(lastChar);
//             string dummy = "";
//             storeString(curr, nicheKaAns, inputHelper, dummy);
//             output.push_back(nicheKaAns);
//             // important update
//             prev = curr;
//         }
//     }
//     return output;
// }

// Node Creation
class TrieNode
{
public:
    char value;
    TrieNode *children[26];
    int childCount;
    bool isTerminal;

    TrieNode(char val)
    {
        this->value = val;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        this->isTerminal = false;
        this->childCount = 0;
    }
};

class Solution
{
public:
    // insertion O(length of the string)-> O(1);
    void insertWord(TrieNode *root, string word)
    {
        // base case
        if (word.length() == 0)
        {
            root->isTerminal = true;
            return;
        }
        char ch = word[0];
        int index = ch - 'a';
        TrieNode *child;
        if (root->children[index] != NULL)
        {
            // present
            child = root->children[index];
        }
        else
        {
            // absent
            child = new TrieNode(ch);
            root->childCount++;
            root->children[index] = child;
        }

        // recursion
        insertWord(child, word.substr(1));
    }

    // Searching Code
    bool searchWord(TrieNode *root, string word)
    {
        // base case
        if (word.length() == 0)
        {
            return root->isTerminal;
        }

        char ch = word[0];
        int index = ch - 'a';
        TrieNode *child;
        if (root->children[index] != NULL)
        {
            // present
            child = root->children[index];
        }
        else
        {
            // not found
            return false;
        }

        // baaki recursion
        bool recursionKaAns = searchWord(child, word.substr(1));
        return recursionKaAns;
    }

    // ->jitne char hai string me utna time laga
    // -> nearly o(1) constant time me kar diye hai
    void deleteWord(TrieNode *root, string word)
    {
        if (word.length() == 0)
        {
            root->isTerminal = false;
            return;
        }

        // 1 case mera
        char ch = word[0];
        int index = ch - 'a';
        TrieNode *child;

        if (root->children[index] != NULL)
        {
            // present
            child = root->children[index];
        }
        else
        {
            // not present
            return;
        }
        // baki recursion ka
        deleteWord(child, word.substr(1));
    }

    void findLCP(string &ans, TrieNode *root)
    {

        // base case
        if (root->isTerminal == true)
        {
            return;
        }
        // abhi main node par hu
        TrieNode *child;
        if (root->childCount == 1)
        {

            // child tak jao ans me store karwao
            for (int i = 0; i < 26; i++)
            {
                if (root->children[i] != NULL)
                {
                    child = root->children[i];
                }
            }
            // ans me store karwao
            ans.push_back(child->value);
        }
        else
        {
            return;
        }
        // ab recursion
        findLCP(ans, child);
    }

    string longestCommonPrefix(vector<string> &strs)
    {
        TrieNode *root = new TrieNode('-');
        // insert all string
        for (auto str : strs)
        {
            insertWord(root, str);
        }
        string ans = "";
        // string str = strs[0];
        findLCP(ans, root);
        return ans;
    }
};

int main()
{
    Solution sol;

    // Vector of strings
    vector<string> strs = {"flower", "flow", "flight"};

    // Find the longest common prefix
    string result = sol.longestCommonPrefix(strs);

    // Output the result
    cout << "Longest Common Prefix: " << result << endl;

    return 0;
}