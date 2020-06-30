class Solution:
    def findCircleNum(self, M: List[List[int]]) -> int:
        num_friends = 0
        for i in range(len(M)):
            for j in range(len(M[0])):
                if M[i][j] == 1:
                    num_friends += 1
                    stack = [[i,j]]
                    while len(stack) != 0:
                        root = stack.pop()
                        M[root[0]][root[1]] = 2
                        for a in range(len(M[0])):
                            if M[root[0]][a] == 1:
                                stack.append([root[0], a])
                                break
                        for b in range(len(M)):
                            if M[b][root[1]] == 1:
                                stack.append([b, root[1]])
                                break

        return num_friends
                
