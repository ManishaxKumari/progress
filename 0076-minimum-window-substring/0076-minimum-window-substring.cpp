class Solution {
public:
    string minWindow(string s, string t) {
        /* Variable to store the minimum 
        length of substring found */
        int minLen = INT_MAX;
        
        /* Variable to store the starting index
        of the minimum length substring */
        int sIndex = -1;
        
        /* Array to count frequencies
        of characters in string t*/
        int hash[256] = {0};
        
        // Count the frequencies of characters in t
        for (char c : t) {
            hash[c]++;
        }
            
        int count = 0;
        int l = 0, r = 0;

        while (r < s.size()) {
            if (hash[s[r]] > 0) {
                count++;
            }
            hash[s[r]]--;
            while (count == t.size()) {
                    
    
                if (r - l + 1 < minLen) {
                    minLen = r - l + 1;
                    sIndex = l;
                }
                
    
                hash[s[l]]++;
                if (hash[s[l]] > 0) {
                    count--;
                }
                l++;
            }
            r++;
        }

        return (sIndex == -1) ? "" : s.substr(sIndex, minLen);
    }
    
};