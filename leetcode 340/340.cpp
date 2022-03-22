/*340 题目：给定一个字符串s，找出至多包含k个不同字符的最长子串T。
输入: s = "eceba", k = 2
输出: 3
解释: 则 T 为 "ece"，所以长度为3。
示例 2:
输入: s = "aa", k = 1
输出: 2
解释: 则 T 为 "aa"，所以长度为2。*/
#include<iostream>
#include<string>
#include<algorithm>
#include<unordered_map>

using namespace std;
class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
            if (s.empty() || k <= 0) return 0;
            int n = s.length();
            unordered_map<char, int> myMap;
            int l = 0, r = 0;
            int maxLen = 1;
            int count = 0;
            while (r < n) {
                if (myMap[s[r]] == 0) {
                    count++;
                }
                myMap[s[r]]++;
                r++;
                while (count > k) {
                    if (myMap[s[l]] == 1) {
                        count--;
                    }
                    myMap[s[l]]--;
                    l++;
                }
                maxLen = max(maxLen, r - l);
            }
            return maxlen;
        }
    };
