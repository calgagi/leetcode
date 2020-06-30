class Solution:
    def updateMatrix(self, matrix: List[List[int]]) -> List[List[int]]:
        
        r = [row[:] for row in matrix]
        
        for i in range(len(matrix)):
            for j in range(len(matrix[0])):
                if matrix[i][j] == 1:
                    queue = [[i,j,0]]
                    while len(queue) != 0:
                        root = queue.pop(0)
                        x, y, level = root[0], root[1], root[2]
                        if x > 0:
                            if matrix[x-1][y] == 1:
                                queue.append([x-1, y, level+1])
                            else:
                                r[i][j] = level+1
                                break
                        if y > 0:
                            if matrix[x][y-1] == 1:
                                queue.append([x, y-1, level+1])
                            else:
                                r[i][j] = level+1
                                break
                        if y < len(matrix[0])-1:
                            if matrix[x][y+1] == 1:
                                queue.append([x, y+1, level+1])
                            else:
                                r[i][j] = level+1
                                break
                        if x < len(matrix)-1:
                            if matrix[x+1][y] == 1:
                                queue.append([x+1, y, level+1])
                            else:
                                r[i][j] = level+1
                                break
                else:
                    r[i][j] = 0
        return r
