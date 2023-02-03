import json
import sys

def dfsCounter(dict): #該当するレシピカテゴリを発見後、dfsでそれより下の階層のレシピ数を足し合わせていく
    if 'recipes' in dict:
        return dict['recipes']

    subcat = dict['subcategories']
    ans = 0
    for i in range(len(subcat)):
        ans += dfsCounter(subcat[i])
    return ans


def dfsSubcat(subcat, name): #dfsで、該当するレシピカテゴリを探索
    for i in range(len(subcat)):
        #print(subcat)
        if subcat[i]['name'] == name:
            print(dfsCounter(subcat[i]))
            sys.exit
        else:
            if not 'recipes' in subcat[i]:
                dfsSubcat(subcat[i]['subcategories'], name)

if __name__ == '__main__':
    args = sys.argv
    name = args[1]
    if len(args) == 3: # json fileに一つだけあるshort plateというスペース区切りのメニュー名に対応
        name += " "
        name += args[2]
    json_open = open('categories.json', 'r')
    json_load = json.load(json_open)
    if json_load['name'] == name:
        print(dfsCounter(json_load))
    else:
        dfsSubcat(json_load['subcategories'], name)
