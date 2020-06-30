class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:            
        schedule = []
        seen = collections.defaultdict(int)
        for task in tasks:
            if seen[task]:
                schedule[seen[task]-1] += 1
            else:
                seen[task] = len(schedule)+1
                schedule.append(1)
        schedule.sort()
        
        r = ""
        while len(schedule) != 0:
            c = 0
            for t in range(len(schedule)):
                r += str(t)
                c += 1
                schedule[t] -= 1
            schedule = [x for x in schedule if x != 0]
            if len(schedule) != 0:
                while c < n+1:
                    r += " "
                    c += 1
            print(r)
        return len(r)
        
                
