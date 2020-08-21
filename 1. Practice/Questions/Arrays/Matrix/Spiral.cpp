/*  
Given a matrix mat[][] of size M*N. Traverse and print the matrix in spiral form.


Example:
Input:
4 4 //Row,column
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16//Matrix
3 4 //Row,column
1 2 3 4 5 6 7 8 9 10 11 12//Matrix

Output:
1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10
1 2 3 4 8 12 11 10 9 5 6 7 
*/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        if(matrix.size()==0)
            return vector<int>();
        int lr,lc,hr,hc;
        lr = 0;
        lc = 0;
        hr = matrix.size();
        hc = matrix[0].size();
        
        while(lr<hr && lc<hc){
            // Top most row, left to right, so matrix[first_row][all_columns low to high]
            for( int i=lc;i<hc;i++)
                ans.push_back(matrix[lr][i]);
            lr++;
            //Right most Column elements, so matrix[all rows low to high][fix_lastColumn]
            
            for(int i=lr;i<hr;i++)
                ans.push_back(matrix[i][hc-1]);
            hc--;
            //We have to check the lower left PATTERNS :
            
            //Lowest Row, check if lowest row<highest row
            //Then , matrix[highest_row][all column from high to low]
            if(lr<hr){
                for(int i=hc-1;i>=lc;i--)
                    ans.push_back(matrix[hr-1][i]);
                hr--;
            }
            
            //Lowest column, check if lowest column<highest column
            //Then, matrix[highest_row to lowest row][lowest column]
            if(lc<hc){
                for(int i=hr-1;i>=lr;i--)
                    ans.push_back(matrix[i][lc]);
                lc++;
            }
        }
        return ans;
    }
};
