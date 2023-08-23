#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//Basic structure of the binary tree that i think is required.
//i chose to use binary tree as it is given in the question that each person can have either 2 or 1 subordinates 

struct TreeNode {
    int val;
    string name;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), name(""), left(nullptr), right(nullptr) {}
    TreeNode(int x, string name) : val(x), name(name), left(nullptr), right(nullptr) {}
    TreeNode(int x, string name, TreeNode* left, TreeNode* right) : val(x), name(name), left(left), right(right) {}
};

class Solution {
public:

    //      10
    //  5        20
    //3   7   15   25
    //this method is calculating the nodes from root to any endlead whose values give the maximum sum and storing the values of it in a vector named "path"
    long long lineWithHighestSales(TreeNode* root, vector<TreeNode*>& path) {
        if (root == NULL) return 0;
        vector<TreeNode*> leftPath, rightPath;
        long long leftSum = lineWithHighestSales(root->left, leftPath);
        long long rightSum = lineWithHighestSales(root->right, rightPath);
        if (leftSum > rightSum) {
            path = leftPath;
        } else {
            path = rightPath;
        }
        path.insert(path.begin(), root);
        return max(leftSum, rightSum) + root->val;
    }


    //this method is calculating the sum of the nodes in the path
    long long maxSumOfArray(vector<TreeNode*>& path) {
        long long sum = 0;
        for (long long i = 0; i < path.size(); i++) {
            sum += path[i]->val;
        }
        return sum;
    }

    //this method is calculating the factorial of the number of nodes in the path which is used to calculate the bonus
    long long fact(long long n) {
        if ((n == 0) || (n == 1))
            return 1;
        else
            return n + fact(n - 1);
    }


    //this method is using to find the bonus 1 which is Budget Efficiency Reward distribution in which we have to calculate 25% of 3000000 
    //which comes out to be 750000 and then we have to distribute it among the nodes in the path 
    vector<long long> findBonus1(vector<TreeNode*>& path, long long totalSum, long long fact) {
        vector<long long> bonus1;
        long long n = path.size();
        long long flag = n;
        long long totalSubordinates = (n*(n - 1))/2;
        for (long long i = 0; i < n; i++) {
            //(indivisual_sub / total_sub) * total_money
            double temp =  ( (double)(flag - 1) / (double)totalSubordinates) * (double)750000;
            bonus1.push_back(temp);
            flag--;
        }
        return bonus1;
    }


    //this method is using to find the bonus 2 which is Individual Performance Reward distribution in which we have to calculate 27% of 3000000 
    //which comes out to be  2250000 and then we have to distribute it among the nodes in the path
    vector<long long> findBonus2(vector<TreeNode*>& path, long long totalSum) {
        vector<long long> bonus2;
        long long n = path.size();
        for (long long i = 0; i < n; i++) {
            //(indivisual_val / total_val) * total_money

            double temp = ( (double)path[i]->val * (double)2250000) / totalSum;
            bonus2.push_back(temp);
        }
        return bonus2;
    }


    //this calculates the total bonus by adding the bonus1 and bonus2
    vector<long long> findTotalBonus(vector<long long>& bonus1, vector<long long>& bonus2) {

        vector<long long> vec;
        for (long long i = 0; i < bonus2.size(); i++) {
            
            // cout << bonus1[i] << ":" << bonus2[i] << endl;
            vec.push_back(bonus2[i] + bonus1[i]);
        }
        return vec;
    }
};

int main() {
    TreeNode* root = new TreeNode(10,"SE1");
    root->left = new TreeNode(12,"SE2");
    root->right = new TreeNode(7,"SE3");
    root->left->left = new TreeNode(4,"SE4");
    root->left->right = new TreeNode(17,"SE5");
    root->right->left = new TreeNode(6,"SE6");
    root->right->left = new TreeNode(3,"SE7");
    root->left->left->left = new TreeNode(9,"SE8");
    root->left->left->left->left = new TreeNode(20,"SE15");
    root->left->right->left = new TreeNode(10,"SE9");
    root->left->right->right = new TreeNode(11,"SE10");
    root->left->right->left->left = new TreeNode(8,"SE16");
    root->left->right->left->left->left = new TreeNode(18,"SE17");
    root->right->left->left = new TreeNode(18,"SE11");
    root->right->left->right = new TreeNode(2,"SE12");
    root->right->left->left = new TreeNode(13,"SE13");
    root->right->left->right = new TreeNode(15,"SE14");

    Solution solution;
    vector<TreeNode*> path;
    long long maxSum = solution.lineWithHighestSales(root, path);
    long long n = path.size();
    long long totalSum = solution.maxSumOfArray(path);
    long long factVal = solution.fact(n);
    vector<long long> bonus1 = solution.findBonus1(path, totalSum, factVal);
    vector<long long> bonus2 = solution.findBonus2(path, totalSum);
    vector<long long> totalBonus = solution.findTotalBonus(bonus1, bonus2);

    cout << "Bonuses: " << endl;
    for (long long i = 0; i < path.size(); i++) {
        cout << path[i]->name << " : " << totalBonus[i] << endl;
    }

    return 0;
}
