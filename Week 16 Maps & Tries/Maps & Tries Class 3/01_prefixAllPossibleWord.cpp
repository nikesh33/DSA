#include <iostream>
#include <vector>
using namespace std;

// Node Creation
class TrieNode
{
public:
    char value;
    TrieNode *children[26];
    bool isTerminal;

    TrieNode(char val)
    {
        this->value = val;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        this->isTerminal = false;
    }
};

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

void storeString(TrieNode *root, vector<string> &ans, string &input, string &prefix)
{
    // base case
    if (root->isTerminal == true)
    {
        // ans store
        ans.push_back(prefix + input);
        // there is no need for return in this case
        // why no return? -> kyuki aisa ho sakta hai jo terminal node hai uske niche bhi word ho
    }

    // kisi bhi root node pe aata hu to puchta hoon
    // -> tere pass a-z tak konsa child hai
    
    for (char ch = 'a'; ch <= 'z'; ch++)
    {
        int index = ch - 'a';
        // a-z tak check kiya konsa char present hai
        TrieNode *next = root->children[index];
        if (next != NULL)
        {
            // child exist
            // input i.e -> (ans) me push kardo
            input.push_back(ch);
            // baaki recursion
            storeString(next, ans, input, prefix);
            // backtrack
            input.pop_back();
        }
    }
}

void findPrefixString(TrieNode *root, string input, vector<string> &ans, string &prefix)
{
    // base case
    // empty string bacha hai ab
    if (input.length() == 0)
    {
        // yaha tak pahoch chuke ho last char tak uske niche ke saare ke saare ans ko store kar ke laao
        TrieNode *lastchar = root;
        storeString(lastchar, ans, input, prefix);
        return;
    }

    char ch = input[0];
    int index = ch - 'a';
    TrieNode *child;

    // traversal of input, eg -> "ca" is present aur not
    if (root->children[index] != NULL)
    {
        // child present
        // go to that index where input last char, eg-> "ca" is present
        child = root->children[index];
    }
    else
    {
        return;
    }
    // recursion call
    // -> (child) ye naya root hai ab 
    //  
    findPrefixString(child, input.substr(1), ans, prefix);
}

int main()
{
    TrieNode *root = new TrieNode('-');
    insertWord(root, "cater");
    insertWord(root, "care");
    insertWord(root, "com");
    insertWord(root, "lover");
    insertWord(root, "load");
    insertWord(root, "loved");
    insertWord(root, "lov");
    insertWord(root, "bat");
    insertWord(root, "cat");
    insertWord(root, "car");

    string input = "ca";
    string prefix = input;
    // isme ans store kar liya
    vector<string> ans;

    // ans ke liye function
    // logic: 1 Traverse kar
    //        2 Strore karo ans ko
    findPrefixString(root, input, ans, prefix);

    // print 
    for (auto i : ans)
    {
        cout << i << " ";
    }
    cout << endl;

        return 0;
}