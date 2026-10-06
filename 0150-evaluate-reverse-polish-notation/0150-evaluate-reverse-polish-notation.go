func evalRPN(tokens []string) int {
    st := make([]int, len(tokens))
    top := -1
    tmp := 0

    for _, s := range tokens {
        if s == "+" || s == "-" || s == "*" || s == "/" {
            tmp = st[top]
            top--
            switch s {
                case "+": st[top] += tmp
                case "-": st[top] -= tmp
                case "*": st[top] *= tmp
                case "/": st[top] /= tmp
            }
        } else {
            top++
            st[top], _ = strconv.Atoi(s)
        }
    }
    return st[top]
}