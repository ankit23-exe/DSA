class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
       
        int n = s.size();
        if (n < minSize) return 0;

        unordered_map<string, int> count;
        vector<int> freq(26, 0);
        int unique = 0;
        int ans = 0;

         
        for (int i = 0; i < minSize; i++) { //jitna given window hai , usmai kitna unique hai
            int idx = s[i] - 'a';
            if (freq[idx] == 0) unique++;
            freq[idx]++;
        }

        if (unique <= maxLetters) {
            string sub = s.substr(0, minSize);
            ans = max(ans, ++count[sub]);
        }

        // Slide the window
        for (int i = minSize; i < n; i++) {
            // Remove left char
            int leftIdx = s[i - minSize] - 'a';
            freq[leftIdx]--;
            if (freq[leftIdx] == 0) unique--;

            // Add right char
            int rightIdx = s[i] - 'a';
            if (freq[rightIdx] == 0) unique++;
            freq[rightIdx]++;

            // Check this window
            if (unique <= maxLetters) {
                string sub = s.substr(i - minSize + 1, minSize);
                ans = max(ans, ++count[sub]);
            }
        }

        return ans;
    }
};
