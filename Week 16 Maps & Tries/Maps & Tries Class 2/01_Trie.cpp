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
// jitne char hai utna time laga
//-> nearly o(1) constant time me kar diye hai
void insertWord(TrieNode *root, string word)
{
    cout << "recieved word: " << word << " for Insertion" << endl;
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

int main()
{
    TrieNode *root = new TrieNode('-');
    insertWord(root, "donation");
    return 0;
}