class Solution {
    inline static const int R = 26;

    struct Node {
        int index{-1};
        vector<Node*> next{R};
    };

    vector<string> foundWords;
    Node root;

    void insert(Node* node, const string& word, int d, int wordIndex) {
        if (d == word.size()) {
            node->index = wordIndex;
            cout << "add: " << word << " index=" << wordIndex << endl;
            return;
        }

        int c = word[d] - 'a';
        if (!node->next[c]) {
            node->next[c] = new Node();
        }
        insert(node->next[c], word, d + 1, wordIndex);
    }

    void dfs(int r, int c, Node* node, vector<vector<char>>& board, vector<string>& words) {
        if (r < 0 || r >= board.size() || c < 0 || c >= board[0].size() || !node ||
            board[r][c] == '#') {
            return;
        }

        char chr = board[r][c];
        Node* next = node->next[chr - 'a'];
        if (!next) {
            return;
        }

        if (next->index != -1) {
            cout << "found: " << words[next->index] << " index=" << next->index << endl;
            foundWords.push_back(words[next->index]);
            next->index = -1;
        }

        board[r][c] = '#';
        dfs(r + 1, c, next, board, words);
        dfs(r - 1, c, next, board, words);
        dfs(r, c + 1, next, board, words);
        dfs(r, c - 1, next, board, words);
        board[r][c] = chr;
    }

   public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        for (int i = 0; i < words.size(); ++i) {
            insert(&root, words[i], 0, i);
        }

        for (int r = 0; r < board.size(); ++r) {
            for (int c = 0; c < board[0].size(); ++c) {
                dfs(r, c, &root, board, words);
            }
        }

        return foundWords;
    }
};
