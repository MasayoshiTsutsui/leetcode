import random


class RandomizedSet:

    def __init__(self):
        self.vals = []
        self.val_idx = {}

    def insert(self, val: int) -> bool:
        if val in self.val_idx:
            return False
        self.vals.append(val)
        self.val_idx[val] = len(self.vals) - 1
        return True

    def remove(self, val: int) -> bool:
        if val not in self.val_idx:
            return False
        idx = self.val_idx[val]
        last_val = self.vals[-1] 
        self.val_idx[last_val] = idx
        self.vals[idx] = last_val
        self.vals.pop()
        self.val_idx.pop(val)
        return True


    def getRandom(self) -> int:
        return self.vals[random.randint(0, len(self.vals)-1)]


# Your RandomizedSet object will be instantiated and called as such:
# obj = RandomizedSet()
# param_1 = obj.insert(val)
# param_2 = obj.remove(val)
# param_3 = obj.getRandom()