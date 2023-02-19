from typing import List, Optional
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    prev = None
    modes = []
    modeCnt = 0
    curCnt = 0

    def dfs(self, node: TreeNode) -> None:
        if node == None:
            return
        self.dfs(node.left)

        if self.prev == node.val:
            self.curCnt += 1
        else:
            if self.curCnt > self.modeCnt and self.prev != None:
                self.modes = [self.prev]
                self.modeCnt = self.curCnt
            elif self.curCnt == self.modeCnt and self.prev != None:
                self.modes.append(self.prev)
            self.curCnt = 1

        self.prev = node.val
        self.dfs(node.right)

    def findMode(self, root: Optional[TreeNode]) -> List[int]:
        self.dfs(root)
        if self.curCnt > self.modeCnt and self.prev != None:
            self.modes = [self.prev]
            self.modeCnt = self.curCnt
        elif self.curCnt == self.modeCnt and self.prev != None:
            self.modes.append(self.prev)
        return self.modes



