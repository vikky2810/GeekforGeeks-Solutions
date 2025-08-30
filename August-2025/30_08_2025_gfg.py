def findCelebrity(mat: list[list[int]]) -> int:
    """
    Finds the celebrity in a party represented by a square matrix.

    Args:
        mat: A square matrix representing people at the party.
             mat[i][j] = 1 if person i knows person j, 0 otherwise.

    Returns:
        The index of the celebrity (0-based), or -1 if no celebrity exists.
    """
    n = len(mat)
    candidate = 0
    for i in range(1, n):
        if mat[candidate][i] == 1:
            candidate = i

    for i in range(n):
        if i != candidate and (mat[candidate][i] == 1 or mat[i][candidate] == 0):
            return -1

    if mat[candidate][candidate] == 0:
        return -1

    for i in range(n):
        if i != candidate and mat[i][candidate] == 0:
            return -1
    return candidate