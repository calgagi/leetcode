class Solution:
    def tree2str(self, t):
        """
        :type t: TreeNode
        :rtype: str
        """
        if not t:
            return ""
        if t.right:
            return str(t.val) + "(" + self.tree2str(t.left) + ")(" + self.tree2str(t.right) + ")"
        elif t.left:
            return str(t.val) + "(" + self.tree2str(t.left) + ")"
        else:
            return str(t.val)
