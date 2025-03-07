// https://leetcode.com/problems/implement-strstr/
// Time Complexity: O(N)
// Memory Complexity: O(N+M)

class Solution {
public:   
    int strStr(string haystack, string needle) {
        int result = KMPSearch(haystack, needle);
        
        return result;
    }

    int KMPSearch(string haystack, string needle)
    {
        int haystackLen = haystack.length();
        int needleLen = needle.length();
        int lps[needleLen];

        computeLPSArray(needle, needleLen, lps);

        int i = 0;
        int j = 0;

        while (i < haystackLen) {
            if (needle[j] == haystack[i]) {
                j++;
                i++;
            }

            if (j == needleLen) {
                return (i-j);
                //j = lps[j - 1];
            }

            else if (i < haystackLen && needle[j] != haystack[i]) {
                if (j != 0)
                    j = lps[j - 1];
                else
                    i = i + 1;
            }
        }
        
        return -1;
    }

    void computeLPSArray(string needle, int needleLen, int* lps)
    {
        int cnt = 0;
        lps[0] = 0;

        int i = 1;
        while (i < needleLen) {
            if (needle[i] == needle[cnt]) {
                cnt++;
                lps[i] = cnt;
                i++;
            }
            else
            {
                if (cnt != 0) {
                    cnt = lps[cnt - 1];
                }
                else
                {
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }
};