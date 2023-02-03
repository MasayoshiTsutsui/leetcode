import sys


if __name__ == '__main__':
    args = sys.argv
    weight = int(args[1])
    weight = weight // 500 * 500
    ans = 0
    if weight == 500:
        print(180 * weight // 100)
        sys.exit()
    while True:
        if weight <= 2000:
            ans += 275 * weight // 100
            print(ans)
            sys.exit()
        elif weight == 2500:
            ans += 290 * weight // 100
            print(ans)
            sys.exit()
        elif weight == 3000:
            ans += 275 * weight // 100
            print(ans)
            sys.exit()
        else:
            weight -= 2500
            ans += 290 * 2500 // 100
    






