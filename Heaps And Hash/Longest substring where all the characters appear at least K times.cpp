Approach: Consider all the possible sub-strings and for every sub-string, calculate the frequency of each of its character and check whether all the characters appear at least K times. For all such valid sub-strings, find the largest length possible.
Below is the implementation of the above approach: 


bool atLeastK(int freq[], int k)
{
    for (int i = 0; i < MAX; i++) {
 
        // If the character is present and
        // its frequency is less than k
        if (freq[i] != 0 && freq[i] < k)
            return false;
    }
 
    return true;
}
 
// Function to set every frequency to zero
void setZero(int freq[])
{
    for (int i = 0; i < MAX; i++)
        freq[i] = 0;
}
 
// Function to return the length of the longest
// sub-string such that it contains every
// character at least k times
int findlength(string str, int n, int k)
{
 
    // To store the required maximum length
    int maxLen = 0;
 
    int freq[MAX];
 
    // Starting index of the sub-string
    for (int i = 0; i < n; i++) {
        setZero(freq);
 
        // Ending index of the sub-string
        for (int j = i; j < n; j++) {
            freq[str[j] - 'a']++;
 
            // If the frequency of every character
            // of the current sub-string is at least k
            if (atLeastK(freq, k)) {
 
                // Update the maximum possible length
                maxLen = max(maxLen, j - i + 1);
            }
        }
    }
 
    return maxLen;
}
 


 //efficient approach is that firs..
 find frequency of all character 
 //consider the string upto where there are no count of characters is less than k
 // the ans will lie before where the frequency of char is less than k
 int longestSubstring(string s, int k) {
    int n = s.length();
    if(n == 0 || n < k) return 0;
    if(k <= 1) return n;

    unordered_map<char, int> counts;
    for(char c: s) counts[c] += 1;

    int l = 0;
    while(l < n && counts[s[l]] >= k) l++;
    if(l >= n-1) return l;

    int ls1 = longestSubstring(s.substr(0, l), k);
    while(l < n && counts[s[l]] < k) l++;
    int ls2 = (l < n) ? longestSubstring(s.substr(l), k) : 0;
    return max(ls1, ls2);
}




int longestSubstring(string s, int k)
{
    // Store the required answer
    int ans = 0;
 
    // Create a frequency map of the
    // characters of the string
    int freq[26] = { 0 };
 
    // Store the length of the string
    int n = s.size();
 
    // Traverse the string, s
    for (int i = 0; i < n; i++)
 
        // Increment the frequency of
        // the current character by 1
        freq[s[i] - 'a']++;
 
    // Stores count of unique characters
    int unique = 0;
 
    // Find the number of unique
    // characters in string
    for (int i = 0; i < 26; i++)
        if (freq[i] != 0)
            unique++;
 
    // Iterate in range [1, unique]
    for (int curr_unique = 1;
         curr_unique <= unique;
         curr_unique++) {
 
        // Initialize frequency of all
        // characters as 0
        memset(freq, 0, sizeof(freq));
 
        // Stores the start and the
        // end of the window
        int start = 0, end = 0;
 
        // Stores the current number of
        // unique characters and characters
        // occurring atleast K times
        int cnt = 0, count_k = 0;
 
        while (end < n) {
            if (cnt <= curr_unique) {
                int ind = s[end] - 'a';
 
                // New unique character
                if (freq[ind] == 0)
                    cnt++;
 
                freq[ind]++;
 
                // New character which
                // occurs atleast k times
                if (freq[ind] == k)
                    count_k++;
 
                // Expand window by
                // incrementing end by 1
                end++;
            }
            else {
                int ind = s[start] - 'a';
 
                // Check if this character
                // is present atleast k times
                if (freq[ind] == k)
                    count_k--;
 
                freq[ind]--;
 
                // Check if this character
                // is unique
                if (freq[ind] == 0)
                    cnt--;
 
                // Shrink the window by
                // incrementing start by 1
                start++;
            }
 
            // If there are curr_unique
            // characters and each character
            // is atleast k times
            if (cnt == curr_unique
                && count_k == curr_unique)
 
                // Update the overall
                // maximum length
                ans = max(ans, end - start);
        }
    }
 
    // return the answer
    return ans;
}