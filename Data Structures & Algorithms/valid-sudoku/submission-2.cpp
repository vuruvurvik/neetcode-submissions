class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<set<char>>rows(9);
        vector<set<char>>col(9);
        vector<set<char>>box(9);
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(board[i][j]=='.')continue;
                char num=board[i][j];
                int boxes=((i/3)*3)+(j/3);
                      if(rows[i].count(num)||col[j].count(num)||box[boxes].count(num))
                {
                    return false;
                }
                rows[i].insert(num);
                col[j].insert(num);
                box[boxes].insert(num);
            }
        } 
        return true;
    }
};
