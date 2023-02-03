import csv
import requests
import sys

max_budget = 0
impresses = []
budgets = []
def dfs(headidx, inventory, collected):
    global impresses
    global budgets
    global max_budget
    if headidx >= len(impresses):
        return
    impr = impresses[headidx]
    if impr <= inventory:
        max_budget = max(max_budget, collected + budgets[headidx])
        dfs(headidx + 1, inventory - impr, collected + budgets[headidx])
    dfs(headidx + 1, inventory, collected)


def main():
    args = sys.argv
    csvfile = args[1]
    inventory = int(args[2])
    global impresses
    global budgets
    global max_budget
    with open(csvfile, 'r') as f:
        csvreader = csv.reader(f)

        for idx, row in enumerate(csvreader):
            if idx == 0:
                continue
            impresses.append(int(row[-2]))
            budgets.append(int(row[-1]))
    f.close()
    dfs(0, inventory, 0)
    print(max_budget)
    
main()