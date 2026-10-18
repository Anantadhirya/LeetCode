type Node struct {
    val int
    left *Node
    right *Node
}

func add(cur *Node, val int) *Node {
    if cur == nil { return &Node{val, nil, nil} }
    if val < cur.val {
        cur.left = add(cur.left, val)
    } else {
        cur.right = add(cur.right, val)
    }
    return cur
}

func numOfWays(nums []int) int {
    n := len(nums)
    root := &Node{nums[0], nil, nil}
    MOD := int(1e9 + 7)
    for i := 1; i < n; i++ {
        add(root, nums[i])
    }

    comb := make([][]int, n+1)
    for i := 0; i <= n; i++ {
        comb[i] = make([]int, n+1)
        comb[i][0] = 1
        for j := 1; j <= i; j++ {
            comb[i][j] = (comb[i-1][j-1] + comb[i-1][j]) % MOD
        }
    }

    var solve func(cur *Node) [2]int
    solve = func(cur *Node) [2]int {
        if cur == nil { return [2]int{1, 0} }
        l := solve(cur.left)
        r := solve(cur.right)
        ret := int(int64(l[0]) * int64(r[0]) % int64(MOD) * int64(comb[l[1]+r[1]][l[1]]) % int64(MOD))
        cnt := 1 + l[1] + r[1]
        return [2]int{ret, cnt}
    };

    return (solve(root)[0] - 1 + MOD) % MOD
}