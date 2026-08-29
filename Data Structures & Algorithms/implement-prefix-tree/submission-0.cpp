class PrefixTree {
    inline static const int R = 26;

    struct Node {
        bool val{false};
        vector<Node*> next{R};
    };
    Node root;

    bool search(Node* node, const string& word, int d) {
        if (!node) {
            return false;
        }
        if (d == word.size()) {
            return node->val;
        }

        int c = word[d] - 'a';
        return search(node->next[c], word, d + 1);
    }

    void insert(Node* node, const string& word, int d) {
        if (d == word.size()) {
            node->val = true;
            return;
        }

        int c = word[d] - 'a';
        if (!node->next[c]) {
            node->next[c] = new Node();
        }
        insert(node->next[c], word, d + 1);
    }

    bool searchPrefix(Node* node, const string& word, int d) {
        if (!node) {
            return false;
        }
        if (d == word.size()) {
            return true;
        }

        int c = word[d] - 'a';
        return searchPrefix(node->next[c], word, d + 1);
    }

   public:
    PrefixTree() {}

    void insert(string word) {
        insert(&root, word, 0);
    }

    bool search(string word) { return search(&root, word, 0); }

    bool startsWith(string prefix) {
        return searchPrefix(&root, prefix, 0);
    }
};
