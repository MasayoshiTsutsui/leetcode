
DEBUG = 1

def dbg_print(s):
    if DEBUG:
        print(s)

class ValNode:
    def __init__(self, key:int, val: int) -> None:
        self.key = key
        self.val = val
        self.next = None
        self.prev = None

    def set_next(self, next):
        self.next = next

    def set_prev(self, prev):
        self.prev = prev
        
class LRUCache:

    def __init__(self, capacity: int):
        self.capcity = capacity
        self.key_val = {}
        self.key_node = {}
        self.root = ValNode(-1, -1)
        self.tail = ValNode(-1, -1)
        self.root.set_next(self.tail)
        self.tail.set_prev(self.root)

    def recently_used(self, node: ValNode) -> None:
        node.next.set_prev(node.prev)
        node.prev.set_next(node.next)

        self.tail.prev.set_next(node)
        node.set_prev(self.tail.prev)
        node.set_next(self.tail)
        self.tail.set_prev(node)
    
    def evict_oldest(self):
        evicted = self.root.next
        evicted.prev.set_next(evicted.next)
        evicted.next.set_prev(evicted.prev)
        self.key_val.pop(evicted.key)
        self.key_node.pop(evicted.key)
        dbg_print(f"evicted.key: {evicted.key}")
        dbg_print(f"evicted.val: {evicted.val}")
        
    def get(self, key: int) -> int:
        if key in self.key_val:
            node = self.key_node[key]
            self.recently_used(node)
            dbg_print(f"after get {key}")
            self.cacheprint()

            return self.key_val[key]
        return -1

    def put(self, key: int, value: int) -> None:
        if key in self.key_val:
            update_node = self.key_node[key]
            update_node.val = value
            self.recently_used(update_node)
            self.key_val[key] = value
        else:
            if len(self.key_val) == self.capcity:
                self.evict_oldest()
            added = ValNode(key, value)
            newest = self.tail.prev
            newest.set_next(added)
            added.set_next(self.tail)
            self.tail.set_prev(added)
            added.set_prev(newest)
            self.key_val[key] = value
            self.key_node[key] = added
        self.cacheprint()

    def cacheprint(self):
        node = self.root
        while True:
            node = node.next
            if node == None:
                break
            dbg_print(f"node.key: {node.key}")
            dbg_print(f"node.val: {node.val}")
            dbg_print("")




# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)