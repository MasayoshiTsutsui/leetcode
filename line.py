import sys


def main():
    timestamps = []
    midnight_stamps = []
    dists = []
    for line in sys.stdin:
        if line.rstrip() == 'Exit':
            break
        try:
            time_dist = line.split()
            time = time_dist[0]
            hms = time.split(':')
            s_ms = hms[2].split('.')
            time_ms = int(hms[0]) * 60 * 60 * 1000 + int(hms[1]) * 60 * 1000 + int(s_ms[0]) * 1000 + int(s_ms[1])
            dist = int(''.join(time_dist[1].split('.')))
            timestamps.append(time_ms)
            midnight_stamps.append(
                int(hms[0]) % 24 >= 0 and int(hms[0]) % 24 <= 4
                or
                int(hms[0]) % 24 >= 22 and int(hms[0]) % 24 <= 23
            )
            dists.append(dist)
        except:
            return -1
    
    SPEED_THR = 10 * 1000 / 3600000

    price = 410
    total_dist = 0

    for i in range(len(timestamps) - 1):
        current_ts = timestamps[i]
        next_ts = timestamps[i+1]
        current_d = dists[i]
        next_d = dists[i+1]
        speed = (next_d - current_d) / (next_ts - current_ts)

        if speed <= SPEED_THR:
            price += int((next_ts - current_ts) / 90000) * 80
        
        if midnight_stamps[i] and midnight_stamps[i + 1]:
            total_dist += 1.25 * (next_d - current_d) 
        else:
            total_dist += next_d - current_d
        
    price += int(max((total_dist - 10520), 0) / 2370) * 80

    print(price)


    return 0




if __name__ == "__main__":
    main()
