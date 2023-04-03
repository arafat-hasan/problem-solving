/*
 * FILE: 1704.determine-if-string-halves-are-alike.cpp
 * @author: Arafat Hasan Jenin <opendoor.arafat[at]gmail[dot]com>
 * LINK: https://leetcode.com/problems/determine-if-string-halves-are-alike/
 * DATE CREATED: 01-12-22 14:57:10 (+06)
 * LAST MODIFIED: 01-12-22 14:57:30 (+06)
 * VERDICT: Accepted
 */

class Solution {
public:
    bool halvesAreAlike(string s) {
        int firstHalfVowelCount = 0, secondHalfVowelCount = 0;
        for(int i = 0; i < s.length(); ++i){
            if(isVowel(s[i])){
                i < s.length()/2 ? firstHalfVowelCount++ : secondHalfVowelCount++;
            }
        }
        return firstHalfVowelCount == secondHalfVowelCount;
    }

    bool isVowel(char ch){
        ch = tolower(ch);
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }
};
