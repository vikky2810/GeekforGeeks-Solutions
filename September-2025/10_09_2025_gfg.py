def largest_lexicographical(s: str) -> str:
    n = len(s)
    s_list = list(s)
    for i in range(n):
        max_char = s_list[i]
        max_index = i
        for j in range(i + 1, n):
            if s_list[j] >= max_char:
                max_char = s_list[j]
                max_index = j
        if max_char > s_list[i]:
            s_list[i], s_list[max_index] = s_list[max_index], s_list[i]
            return "".join(s_list)
    return s