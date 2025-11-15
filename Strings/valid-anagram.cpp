//TC : O(n+m) --> O(n) or O(m) depending upon who's length is greater 

#include <iostream>
#include <string>
using namespace std;

bool isAnagram(string s1, string s2){
    if(s1.length() != s2.length()) { //as length is always equal in anagram.
        cout<< "Not Valid Anagrams!"<<endl;
        return false;
    }

    int count[26] = {0};

    for (int i = 0; i < s1.length(); i++)
    {
        int idx = s1[i] - 'a';
        count[idx]++;
    }
    
    for (int i = 0; i < s2.length(); i++)
    {
        int idx = s2[i] - 'a';
        if(count[idx] == 0) {
            cout<< "Not Valid Anagrams!"<<endl;
            return false;
        }
        count[idx]--; //stores the occurence of each character as an element.
    }
    cout<< "Valid Anagrams!"<<endl;
    return true;
}

int main() {
    
    string s1 = "anagram";
    string s2 = "nagaram";

    isAnagram(s1,s2);

    return 0;
}

// ============ REVISION NOTES ============
// Problem: Check if two strings are valid anagrams (same characters with same frequencies).
//
// Algorithm approach:
// 1. Early exit: if lengths differ, cannot be anagrams -> return false immediately.
// 2. Use frequency array count[26] to track occurrences of each lowercase letter ('a'-'z').
// 3. First loop: iterate s1 and increment count[s1[i] - 'a'] for each character.
// 4. Second loop: iterate s2 and decrement count[s2[i] - 'a']; if count becomes negative 
//    or was already 0, strings differ -> return false.
// 5. If all checks pass, strings are anagrams.
//
// Time Complexity: O(n) where n = length of s1 (or s2, since they must be equal).
// Space Complexity: O(1) — fixed-size array count[26] for lowercase English letters.
//
// Key points to remember:
// - Character-to-index mapping: idx = ch - 'a' converts 'a'->0, 'b'->1, ..., 'z'->25.
// - Assumes input contains only lowercase English letters (no uppercase, digits, or symbols).
// - For case-insensitive or extended character sets, adjust array size or use unordered_map.
// - Alternative approach: sort both strings and compare (O(n log n) time, simpler code).
// - Edge cases:
//   * Empty strings: both "" are valid anagrams.
//   * Single character: "a" and "a" are anagrams; "a" and "b" are not.
//   * Different lengths: immediate false return (handled at start).
// - Common mistakes:
//   * Forgetting to check length equality upfront -> wastes time processing unequal strings.
//   * Not handling case sensitivity -> "Anagram" vs "nagaram" would fail with this code.
//   * Off-by-one in count array indexing if input contains non-lowercase letters.
// - Testing tips:
//   * Test with identical strings: "listen" and "listen" -> true.
//   * Test with different order: "listen" and "silent" -> true.
//   * Test with extra character: "listen" and "listens" -> false (different lengths).
//   * Test with different characters: "abc" and "def" -> false.
//
// Example dry-run (s1 = "anagram", s2 = "nagaram"):
// Step 1: lengths both 7 -> proceed.
// Step 2: Build count[] from s1:
//   'a' appears 3 times -> count[0] = 3
//   'n' appears 1 time  -> count[13] = 1
//   'g' appears 1 time  -> count[6] = 1
//   'r' appears 1 time  -> count[17] = 1
//   'm' appears 1 time  -> count[12] = 1
// Step 3: Process s2 and decrement count[]:
//   s2[0]='n' -> count[13]-- (1->0)
//   s2[1]='a' -> count[0]-- (3->2)
//   s2[2]='g' -> count[6]-- (1->0)
//   s2[3]='a' -> count[0]-- (2->1)
//   s2[4]='r' -> count[17]-- (1->0)
//   s2[5]='a' -> count[0]-- (1->0)
//   s2[6]='m' -> count[12]-- (1->0)
// Step 4: All counts become 0 or stay non-negative -> Valid Anagrams!
//
// Optimization notes:
// - Current code prints inside function; for library use, separate logic from I/O.
// - Can combine both loops into one if processing characters simultaneously (less readable).
// - For Unicode or large character sets, use unordered_map<char, int> instead of fixed array.