type Video struct {
    name string
    freq int
}

func watchedVideosByFriends(watchedVideos [][]string, friends [][]int, id int, l int) []string {
    n := len(friends)
    vis := make([]bool, n)
    level := make([]int, n)
    q := make([]int, 0, n)
    m := make(map[string]int)
    
    arr := make([]Video, 0)
    ans := make([]string, 0)

    q = append(q, id)
    vis[id] = true
    level[id] = 0

    for len(q) > 0 {
        cur := q[0]
        q = q[1:]
        if level[cur] == l {
            for _, vid := range watchedVideos[cur] {
                m[vid]++
            }
        }

        for _, to := range friends[cur] {
            if vis[to] { continue }
            q = append(q, to)
            vis[to] = true
            level[to] = level[cur] + 1
        }
    }

    for name, freq := range m {
        arr = append(arr, Video{name, freq})
    }
    slices.SortFunc(arr, func(a, b Video) int {
        if c := cmp.Compare(a.freq, b.freq); c != 0 { return c }
        return cmp.Compare(a.name, b.name)
    })
    for _, i := range arr {
        ans = append(ans, i.name)
    }

    return ans
}