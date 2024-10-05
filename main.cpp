#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct TrieNode {
    char nodeChar;
    vector<TrieNode*> children;
};

void insert(string word, TrieNode* root) {
    TrieNode* currentNode = root;

    for (char c : word) {
        bool found = false;

        // Check if the current character exists in the current node's children
        for (int j = 0; j < currentNode->children.size(); j++) {
            if (c == currentNode->children[j]->nodeChar) {
                currentNode = currentNode->children[j];
                found = true;
                break;  // Stop searching once we find the match
            }
        }

        // If the character wasn't found, create a new node
        if (!found) {
            TrieNode* newChild = new TrieNode();  // Allocate new node
            newChild->nodeChar = c;
            currentNode->children.push_back(newChild);
            currentNode = newChild;
        }
    }
}

bool search(string word, TrieNode* root){
    TrieNode* currentNode = root;

    for (char c : word) {
        bool found = false;
        for (int j = 0; j < currentNode->children.size(); j++) {
            if (c == currentNode->children[j]->nodeChar) {
                currentNode = currentNode->children[j];
                found = true;
                break;
            }
        }
        if (!found) {
            return false;  // The word doesn't exist in the trie
        }
    }
    return true;
}

void printTrie(TrieNode* root){
    cout << "NODO" << endl;
    for(int i = 0; i < root->children.size(); i++){
        cout << root->children[i]->nodeChar << endl;
    }

    for(int i = 0; i < root->children.size(); i++){
        printTrie(root->children[i]);
    }
    
}

int main() {
    int numOfWords;
    int findOfWords;
    string currWord;
    
    // Initialize root node properly
    TrieNode* root = new TrieNode();  // Allocate root node
    root->nodeChar = '\0';  // Root node with null character (for no specific char)

    cout << "Cuantas palabras quiere insertar? " << endl;
    cin >> numOfWords;

    for (int i = 0; i < numOfWords; i++) {
        cout << "Inserte palabra: ";
        cin >> currWord;
        currWord = currWord + '\0';
        insert(currWord, root);
    }


    printTrie(root);

    cout << "Cuantas palabras quiere Buscar? " << endl;
    cin >> findOfWords;
    
    for (int i = 0; i < findOfWords; i++) {
        cout << "Inserte palabra: ";
        cin >> currWord;
        currWord = currWord + '\0';
        if(search(currWord, root)){
            cout << "Encontrado" << endl;
        } else {
            cout << "No encontrado" << endl;
        }
    }

    return 0; 
}
