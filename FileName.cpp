#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<string>getNum(string s) {
        int i = 0;
        vector<string>nums;
        if (s.length() == 1) {
            nums.push_back(s);
            return nums;
        }
        while (i < s.length()) {
            string left = s.substr(0, i);
            string right = s.substr(i++);
            if ((left.length() > 1 && left[0] == '0') || right[right.length() - 1] == '0')continue;
            if (left.length() == 0)
            {
                nums.push_back(right);
                continue;
            }
            if (right.length() == 0)
            {
                nums.push_back(left);
                continue;
            }
            nums.push_back(left + "." + right);
        }
        return nums;
    }
    vector<string> ambiguousCoordinates(string s) {
        vector<string>res;
        s = s.substr(1, s.length() - 2);
        for (int i = 0; i < s.length(); i++) {
            string l = s.substr(0, i);
            string r = s.substr(i);
            for (string left : getNum(l)) {
                for (string right : getNum(r)) {
                    if (left.length() > 0 && right.length() > 0)
                        res.push_back("(" + left + ", " + right + ")");
                }
            }
        }
        return res;
    }
};
//class Solution {
//public:
//    vector<string>res;
//    void dfs(string s,int index) {
//        if (index = s.length()) {
//            res.push_back(s);
//            return;
//        }
//        if (isdigit(s[index]))dfs(s, index + 1);
//        else {
//            dfs(s, index + 1);
//            s[index] ^= 32;
//            dfs(s, index + 1);
//        }
//    }
//    vector<string> letterCasePermutation(string s) {
//        dfs(s, 0);
//        return res;
//    }
//};
class Solution {
public:
    int sum ;
    void backtracking(int n, vector<bool>& used, int index) {
        if (index == n+1) { sum++; return; }
        for (int i = 1; i <= n; i++) {
            if (used[i] == true || (i % index != 0 && index % i != 0))continue;
            used[i] = true;
            backtracking(n,used,index + 1);
            used[i] = false;
        }
    }
    int countArrangement(int n) {
        vector<bool>used(n + 1, false);
        backtracking(n, used, 1);
        return sum;
    }
};