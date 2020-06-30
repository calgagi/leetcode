class Solution:
    def reconstructQueue(self, people: List[List[int]]) -> List[List[int]]:
        from collections import defaultdict
        r = []
        peopledict = defaultdict(list)
        heights = []
        for person in people:
            peopledict[person[0]].append(person[1])
            if person[0] not in heights:
                heights.append(person[0])
                
        heights.sort()
        
        for h in heights[::-1]:
            peopledict[h].sort()
            for p in peopledict[h]:
                r.insert(p, [h, p])
        return r
