class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:      
        # Setup
        schedule = [0]*26
        max_freq, m = 0, 0
        for t in tasks:
            schedule[ord(t) - ord("A")] += 1
            if schedule[ord(t) - ord("A")] == m:
                max_freq += 1
            elif schedule[ord(t) - ord("A")] > m:
                max_freq = 1
                m = schedule[ord(t) - ord("A")]
        
        # Number of parts
        part_count = m - 1
        # Length of each part
        empty_slots_per_part = n - (max_freq - 1)
        # Available slots
        empty_slots = empty_slots_per_part*part_count
        # Find number of slots taken by max
        available_tasks = len(tasks) - (m * max_freq)
        idles = max(0, empty_slots-available_tasks)
        
        return len(tasks)+idles
        
