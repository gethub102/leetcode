class Solution {
  public:
//这个题目解的太崎岖了。
//首先这个题目是个定律 叫作 Levenshtein distance，这个算法是这样的
// (1)str1或str2的长度为0返回另一个字符串的长度。 if(str1.length==0) return str2.length; if(str2.length==0) return str1.length;
// (2)初始化(n+1)*(m+1)的矩阵d，并让第一行和列的值从0开始增长。
// (3)扫描两字符串（n*m级的），如果：str1[i] == str2[j]，用temp记录它，为0。否则temp记为1。
//（4）然后在矩阵d[i,j]赋于d[i-1,j]+1 、d[i,j-1]+1、d[i-1,j-1]+temp三者的最小值。
// (5) 扫描完后，返回矩阵的最后一个值d[n][m]即是它们的距离。

// 于是按照这个思路写了一个，果断超时
// 然后又用 DP解答，结果还是超时，为什么呢，看注释
    int minDistance(string word1, string word2) {
        vector<vector<int> > dp(word1.length(), vector<int>(word2.length(), -1));
        return minDistanceRecursion(word1, word2, word1.length(), word2.length(), dp);
    }

    int minDistanceRecursion(string word1, string word2, int length1, int length2, vector<vector<int> >& dp) {
        if (length1 == 0) return length2;
        if (length2 == 0) return length1;
        if (dp[length1 - 1][length2 - 1] != -1) return dp[length1 - 1][length2 - 1];
        int flag;
        if (word1[length1 - 1] == word2[length2 - 1]) {
            flag = 0;
            // 这里，特别关键，如果 word1[length1 - 1] == word2[length2 - 1]，还比什么大小？！直接两个 length 都减去1
            dp[length1 - 1][length2 - 1] = minDistanceRecursion(word1, word2, length1 - 1, length2 - 1, dp);
        } else {
            flag = 1;
            dp[length1 - 1][length2 - 1] = min(minDistanceRecursion(word1, word2, length1 - 1, length2 - 1, dp) + flag,
                                               min(minDistanceRecursion(word1, word2, length1 - 1, length2, dp) + 1,
                                                   minDistanceRecursion(word1, word2, length1, length2 - 1, dp) + 1));

        }
        return dp[length1 - 1][length2 - 1];

    }
};