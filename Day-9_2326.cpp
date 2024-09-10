/*
2326. Spiral Matrix IV
You are given two integers m and n, which represent the dimensions of a matrix.

You are also given the head of a linked list of integers.

Generate an m x n matrix that contains the integers in the linked list presented in spiral order (clockwise), starting from the top-left of the matrix. If there are remaining empty spaces, fill them with -1.

Return the generated matrix.

 

Example 1:

Input: m = 3, n = 5, head = [3,0,2,6,8,1,7,9,4,2,5,5,0]
Output: [[3,0,2,6,8],[5,0,-1,-1,1],[5,2,4,9,7]]
Explanation: The diagram above shows how the values are printed in the matrix.
Note that the remaining spaces in the matrix are filled with -1.

Example 2:

Input: m = 1, n = 4, head = [0,1,2]
Output: [[0,1,2,-1]]
Explanation: The diagram above shows how the values are printed from left to right in the matrix.
The last space in the matrix is set to -1.

 

Constraints:

    1 <= m, n <= 105
    1 <= m * n <= 105
    The number of nodes in the list is in the range [1, m * n].
    0 <= Node.val <= 1000

*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>>res(m, vector<int>(n, -1));
        int id=0, top=0, left=0, right=n-1, down=m-1;
        while(top<=down and left<=right){
            if(id==0){
                for(int i=left;head!=nullptr and i<=right;i++){
                    res[top][i]=head->val;
                    head=head->next;
                }
                top++;
            }
            if(id==1){
                for(int i=top;head!=nullptr and i<=down;i++){
                    res[i][right]=head->val;
                    head=head->next;
                }
                right--;
            }
            if(id==2){
                for(int i=right;head!=nullptr and i>=left;i--){
                    res[down][i]=head->val;
                    head=head->next;
                }
                down--;
            }
            if(id==3){
                for(int i=down;head!=nullptr and i>=top;i--){
                    res[i][left]=head->val;
                    head=head->next;
                }
                left++;
            }
            id=(id+1)%4;
        }
        return res;

    }
};
