func canAliceWin(n int) bool {
    turn := 0
    for n >= 10-turn {
        n -= 10-turn
        turn++
    }
    return turn % 2 == 1
}