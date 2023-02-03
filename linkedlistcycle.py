# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        nodeSet = set([])
        while True:
            if head == None:
                return False
            if head in nodeSet:
                return True
                sys.exit()
            nodeSet.add(head)
            head = head.next
