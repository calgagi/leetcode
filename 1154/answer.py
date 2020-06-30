class Solution:
    def dayOfYear(self, date: str) -> int:
        t = date.split("-")    
        year = int(t[0])
        month = int(t[1]);
        day = int(t[2]);
        leap = False
        if year % 4:
            leap = False
        elif year % 100:
            leap = True
        elif year % 400:
            leap = False
        else:
            leap = True
        i = 1
        m = {
            1: 31,
            2: 28,
            3: 31,
            4: 30,
            5: 31,
            6: 30,
            7: 31,
            8: 31,
            9: 30,
            10: 31,
            11: 30,
            12: 31
        }
        r = 0
        while i < month:
            if i == 2 and leap:
                r += 1
            r += m[i]
            i += 1
        return r + day
