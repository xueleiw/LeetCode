#include <iostream>
#include <vector>
using namespace std;

// 09-03

class Trie {
    private:
        struct TreeNode {
            TreeNode* child[26];
            string result;
            TreeNode() {
                for(int i = 0; i < 26; i++) {
                    child[i] = nullptr;
                    result = "";
                }
            }
        };
        TreeNode* root;

    public:
        Trie() {
            root = new TreeNode();
        }
        
        void insert(string word) {
            TreeNode* p = root;
            int len = word.length();
            char c = ' ';
            int index = 0;

            for(int i = 0; i < len; i++) {
                c = word[i];
                index = c - 'a';
                if(p->child[index] == nullptr) {
                    p->child[index] = new TreeNode();
                }
                p = p->child[index];
            }
            p->result = word;
        }
        
        bool search(string word) {
            TreeNode* p = root;
            int len = word.length();
            char c = ' ';
            int index = 0;

            for (int i = 0; i < len; i++) {
                c = word[i];
                index = c - 'a';
                if (p->child[index] == nullptr) {
                    return false;
                } else {
                    if (p->child[index]->result == word) {
                        return true;
                    }
                }
                p = p->child[index];
            }

            return false;
        }
        
        bool startsWith(string prefix) {
            TreeNode* p = root;
            int len = prefix.length();
            char c = ' ';
            int index = 0;

            for (int i = 0; i < len; i++) {
                c = prefix[i];
                index = c - 'a';
                if (p->child[index] == nullptr || p->result == prefix) {
                    return false;
                }
                p = p->child[index];
            }

            return true;
        }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

int main() {
    Trie* obj = new Trie();
    obj->insert("apple");
    bool param_2 = obj->search("apple");
    bool param_3 = obj->startsWith("app");
    cout << "Search for 'apple': " << (param_2 ? "Found" : "Not Found") << endl;
    cout << "Starts with 'app': " << (param_3 ? "Yes" : "No") << endl;

    return 0;
}