class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        x, y, length = 0, len(matrix)-1, len(matrix)-1
        for h in range(len(matrix)//2):
            i = x
            while i < y:
                self.swap(matrix, [h, i], [length-i, h], [length-h, length-i],  [i, length-h])
                i += 1
            x += 1
            y -= 1
            
    def swap(self, matrix: List[List[int]], i: List[int], j: List[int], k: List[int], l: List[int]) -> None:
        a = matrix[i[0]][i[1]]
        b = matrix[j[0]][j[1]]
        c = matrix[k[0]][k[1]]
        d = matrix[l[0]][l[1]]
        matrix[i[0]][i[1]] = b 
        matrix[j[0]][j[1]] = c
        matrix[k[0]][k[1]] = d
        matrix[l[0]][l[1]] = a
            
