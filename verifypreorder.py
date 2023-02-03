
from typing import List
DEBUG = 1

def dbg_print(s):
    if DEBUG:
        print(s)


class Solution:
    def isValidSerialization(self, preorder: str) -> bool:
        def dfs_validate(preorder: List[str], nodeidx: int) -> int:
            dbg_print(f"nodeidx: {nodeidx}")

            if nodeidx >= len(preorder):
                dbg_print("over")
                dbg_print("")
                return 999999

            curnode = preorder[nodeidx]

            if curnode == "#":
                dbg_print("leaf")
                dbg_print("")
                parent_right_begin = nodeidx + 1
                return parent_right_begin
            
            left_begin = nodeidx + 1
            
            right_begin = dfs_validate(preorder, left_begin)
            dbg_print(f"right_begin: {right_begin}")
            parent_right_begin = dfs_validate(preorder, right_begin)
            dbg_print(f"parent_right_begin: {parent_right_begin}")
            return parent_right_begin

        split_preorder = preorder.split(sep=",")
        finish_idx = dfs_validate(split_preorder, 0)
        dbg_print(f"len(preorder): {len(preorder)}")
        dbg_print(f"finish_idx: {finish_idx}")
        if finish_idx == len(split_preorder):
            return True
        else:
            return False


