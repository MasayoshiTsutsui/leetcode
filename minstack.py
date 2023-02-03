from collections import deque

class MinStack:
    class Node:
        def __init__(self, val: int, min: int) -> None:
            self.val = val
            self.min = min

    def __init__(self):
        self.stk = deque()

    def push(self, val: int) -> None:
        if len(self.stk) > 0:
            prev_min = self.stk[-1].min
        else:
            prev_min = val
        new_min = min(prev_min, val)
        self.stk.append(self.Node(val, new_min))

    def pop(self) -> None:
        self.stk.pop()

    def top(self) -> int:
        if len(self.stk) > 0:
            return self.stk[-1].val
        return -1

    def getMin(self) -> int:
        return self.stk[-1].min
        


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(val)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()