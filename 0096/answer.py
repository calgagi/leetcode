class Solution:
    def numTrees(self, n: int) -> int:
        # DP problem
        t = [0 for i in range(n+1)]
        # Sets 0 and 1 to have one option for the empty tree and root
        t[0] = t[1] =  1
        # If there are two nodes, then we're talking
        # These loops will find the number of trees created with a root i.
        # Since it's a BST, these will be equal to the number of binary trees
        # created with 1..j-1 as left subtree and 1..(i-j) as right subtree 
        # multiplied together.
        
        # The trick for me was to figure out the base case.
        for i in range(2, n+1):
            for j in range(1, i+1):
                t[i] += t[j-1] * t[i-j]
            
        return t[n]
