class Solution(object):
    def calPoints(self, ops):
        """
        :type ops: List[str]
        :rtype: int
        """
        score = 0
        valid_scores = []
        for op in ops:
            try:
                valid_scores.append(int(op))
            except:
                if op == "C":
                    valid_scores.pop()
                elif op == "D":
                    valid_scores.append(valid_scores[-1]*2)
                elif op == "+":
                    valid_scores.append(valid_scores[-1] + valid_scores[-2])
        for s in valid_scores:
            score += s
        return score
        
