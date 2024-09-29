#include <iostream>
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
// jitne char hai utna time laga
//nearly ->o(1) constant time me kar diye hai
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

    cout << "Insertion Done" << endl;

    string str;
    cin >> str;

    cout << "<<<<<-Searching->>>>" << endl;

    if (searchWord(root, str))
    {
        cout << "Found" << endl;
    }
    else
    {
        cout << "Not Found" << endl;
    }

    return 0;
}