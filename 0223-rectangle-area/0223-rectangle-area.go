func computeArea(ax1 int, ay1 int, ax2 int, ay2 int, bx1 int, by1 int, bx2 int, by2 int) int {
    cx1 := max(ax1, bx1)
    cy1 := max(ay1, by1)
    cx2 := min(ax2, bx2)
    cy2 := min(ay2, by2)

    area := func(x1, y1, x2, y2 int) int {
        if x1 <= x2 && y1 <= y2 {
            return (x2-x1)*(y2-y1)
        }
        return 0
    }
    return area(ax1, ay1, ax2, ay2) + area(bx1, by1, bx2, by2) - max(0, area(cx1, cy1, cx2, cy2))
}