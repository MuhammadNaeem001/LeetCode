class Solution {
public:
    struct TrieNode {
        TrieNode* children[26];
        string word = "";
        TrieNode() {
            for (int i = 0; i < 26; i++) children[i] = nullptr;
        }
    };

    TrieNode* buildTrie(vector<string>& words) {
        TrieNode* root = new TrieNode();
        for (auto& w : words) {
            TrieNode* node = root;
            for (char c : w) {
                int idx = c - 'a';
                if (!node->children[idx]) node->children[idx] = new TrieNode();
                node = node->children[idx];
            }
            node->word = w;  // mark end of word
        }
        return root;
    }

    void dfs(vector<vector<char>>& board, int i, int j, TrieNode* node, vector<string>& res) {
        char c = board[i][j];
        if (c == '#' || !node->children[c - 'a']) return;
        node = node->children[c - 'a'];

        if (node->word != "") {
            res.push_back(node->word);
            node->word = ""; // avoid duplicates
        }

        board[i][j] = '#';
        int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
        for (auto& dir : dirs) {
            int x = i + dir[0], y = j + dir[1];
            if (x >= 0 && y >= 0 && x < board.size() && y < board[0].size())
                dfs(board, x, y, node, res);
        }
        board[i][j] = c;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> res;
        TrieNode* root = buildTrie(words);

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                dfs(board, i, j, root, res);
            }
        }
        return res;
    }
};
