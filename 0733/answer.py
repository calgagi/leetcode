class Solution:
    def floodFill(self, image: 'List[List[int]]', sr: 'int', sc: 'int', newColor: 'int') -> 'List[List[int]]':
        oldColor = image[sr][sc]
        image[sr][sc] = newColor
        if oldColor == newColor:
            return image

        if sr > 0 and oldColor == image[sr-1][sc]:
            self.floodFill(image, sr-1, sc, newColor)

        if sc > 0 and oldColor == image[sr][sc-1]:
            self.floodFill(image, sr, sc-1, newColor)

        if sr < len(image)-1 and oldColor == image[sr+1][sc]:
            self.floodFill(image, sr+1, sc, newColor)

        if sc < len(image[0])-1 and oldColor == image[sr][sc+1]:
            self.floodFill(image, sr, sc+1, newColor)

        return image
