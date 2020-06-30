class Solution:
    def findTarget(self, root, k):
        """
        :type root: TreeNode
        :type k: int
        :rtype: bool
        """
        from collections import defaultdict
        seen = defaultdict(int)
        return self.findTargetHelper(root, k, seen)

    def findTargetHelper(self, root, k, seen):
        if not root:
            return False
        if seen[k-root.val] == 1:
            return True
        else:
            seen[root.val] = 1
            return self.findTargetHelper(root.left, k, seen) or self.findTargetHelper(root.right, k, seen)
