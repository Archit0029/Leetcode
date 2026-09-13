class Solution {
public:
    int strStr(string haystack, string needle) {
          int n = haystack.size();  
                int m = needle.size();                // Edge case: if needle is longer than haystack   
                     if (m > n) return -1;    
                                 for (int i = 0; i <= n - m; i++) {        
                                        if (haystack.substr(i, m) == needle) {                return i; // found first occurrence   
                                                 }     
                                                    }      
                                                      return -1;
    }
};