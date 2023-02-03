class Solution:
    def reverseVowels(self, s: str) -> str:
        vowels = ["a", "e", "i", "o", "u"]
        left_vowel_idx = 0
        right_vowel_idx = len(s) - 1
        left_s = ""
        right_s = ""

        while True:
            while left_vowel_idx < len(s) and s[left_vowel_idx] not in vowels:
                left_s += s[left_vowel_idx]
                left_vowel_idx += 1

            while right_vowel_idx >= 0 and s[right_vowel_idx] not in vowels:
                right_s += s[right_vowel_idx]
                right_vowel_idx -= 1
            
            if left_vowel_idx >= right_vowel_idx:
                break
            
            left_s += lef

        return s
