
import sys



def main():
    timestamps = []
    hours = []
    mins = []
    secs = []
    dists = []
    for line in sys.stdin:
        if line.rstrip() == 'Exit':
            break
        try:
            time_dist = line.split()
            time = time_dist[0]
            dist = time_dist[1]
            h_m_s = time.split(":")
            h = int(h_m_s[0])
            m = int(h_m_s[1])
            s = h_m_s[2]
            s_1000ms = int(s.replace(".", ""))
            dist_10cm = float(dist.replace(".", ""))
            hours.append(h)
            mins.append(m)
            secs.append(s_1000ms)
            dists.append(dist_10cm)
            timestamps.append(h * 60 * 60 * 1000 + m * 60 * 1000 + s_1000ms)
        except:
            return -1
    
    fee = 410
    total_dist = 0
    SPEED_THR_HOUR_10CM = 10 * 1000 * 10

    for i in range(len(timestamps)):
        lapsed_ms = timestamps[i] - timestamps[i-1]
        if i != 0 and (hours[i-1] % 24 <= 4 or hours[i-1] % 24 >=22) \
            and (hours[i] % 24 <= 4 or hours[i] % 24 >=22):
            total_dist += dists[i] * 1.25
            lapsed_ms *= 1.25
        else:
            total_dist += dists[i]
        
        #print(dists[i])
        #print(dists[i-1])
        #print(timestamps[i])
        #print(timestamps[i-1])
        #print((dists[i] - dists[i-1]) / (lapsed_ms))
        #print(SPEED_THR_HOUR_10CM)
        #print((dists[i] - dists[i-1]) * 10 / ((lapsed_ms) / (1000 * 3600)))
        #print((dists[i] - dists[i-1]) * 10 / ((lapsed_ms) / (1000 * 3600)) > SPEED_THR_HOUR_10CM)
        if i != 0 and (dists[i] - dists[i-1]) / (lapsed_ms) <= SPEED_THR_HOUR_10CM:
            print("low speed")
            fee += (lapsed_ms) // (90 * 1000) * 80

    fee += int(max(0, (total_dist - 10520 + 2360)) // 2370 * 80)
    print(fee)

    return 0





if __name__ == "__main__":
    main()
