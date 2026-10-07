func maskPII(s string) string {
    idx := strings.IndexByte(s, '@')
    if idx != -1 {
        s = strings.ToLower(s)
        return s[0:1] + "*****" + s[idx-1:]
    } else {
        var ret []rune
        for _, c := range s {
            if '0' <= c && c <= '9' {
                ret = append(ret, c)
            }
        }
        s = string(ret)
        pref := ""
        switch len(s) {
            case 10: pref = ""
            case 11: pref = "+*-"
            case 12: pref = "+**-"
            case 13: pref = "+***-"
        }
        return pref + "***-***-" + s[len(s)-4:]
    }
    return ""
}