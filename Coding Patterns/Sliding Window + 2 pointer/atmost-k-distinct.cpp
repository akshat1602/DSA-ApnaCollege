#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int lengthOfLongestSubstringKDistinct(const string& s, int k) {
    int n = s.size();
    if (n == 0 || k == 0) return 0;

    unordered_map<char, int> hash;
    int left = 0, right = 0, maxLen = 0;

    while (right < n) {
        hash[s[right]]++;
        while (hash.size() > k) {
            hash[s[left]]--;
            if (hash[s[left]] == 0) {
                hash.erase(s[left]);
            }
            left++;
        }
        maxLen = max(maxLen, right - left + 1);
        right++;
    }
    return maxLen;
}

int main() {
    string s;
    int k;
    cout << "Enter string: ";
    getline(cin, s);
    cout << "Enter k: ";
    cin >> k;

    int result = lengthOfLongestSubstringKDistinct(s, k);
    cout << "Length of longest substring with at most " << k << " distinct characters: " << result << endl;
    return 0;
}
