class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        primes = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103]
        hashmap = {}
        for s in strs:
            key = 1
            for c in s:
                key *= primes[ord(c)-ord('a')]
            try:
                hashmap[key].append(s)
            except:
                hashmap[key] = [s]
        return [hashmap[v] for v in hashmap]
