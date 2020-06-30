class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        counts = {}
        for letter in magazine:
            try:
                counts[letter] += 1
            except:
                counts[letter] = 1
        for letter in ransomNote:
            try:
                counts[letter] -= 1
                if counts[letter] < 0:
                    return False
            except:
                return False
        return True
