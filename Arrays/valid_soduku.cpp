class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<int> horizontal(9, 0);
        vector<int> vertical(9, 0);
        vector<int> box(9, 0);

        for (int i = 0;i < 9;i++) {
            for (int j = 0;j < 9;j++) {
                if (board[i][j] != '.') {
                    int h = board[i][j] - '0' - 1;
                    if (horizontal[i] & 1 << h) {
                        return false;
                    }
                    horizontal[i] |= 1 << h;
                }
                if (board[j][i] != '.') {
                    int v = board[j][i] - '0' - 1;
                    if (vertical[i] & 1 << v) {
                        return false;
                    }
                    vertical[i] |= 1 << v;
                }
                int r = (i / 3) * 3 + (j % 3);
                int c = (i % 3) * 3 + (j / 3);
                if (board[r][c] != '.') {
                    int b = board[r][c] - '0' - 1;
                    if (box[i] & 1 << b) {
                        return false;
                    }
                    box[i] |= 1 << b;
                }
            }
        }
        return true;
    }
};