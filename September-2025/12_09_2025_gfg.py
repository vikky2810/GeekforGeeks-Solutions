def minimize_height(arr: list[int], k: int) -> int:
    """
    Given an array arr[] denoting heights of n towers and a positive integer k.
    For each tower, you must perform exactly one of the following operations exactly once.
        Increase the height of the tower by k
        Decrease the height of the tower by k
    Find out the minimum possible difference between the height of the shortest and tallest towers after you have modified each tower.
    Note: It is compulsory to increase or decrease the height by k for each tower. After the operation, the resultant array should not contain any negative integers.
    """
    n = len(arr)
    arr.sort()
    ans = arr[n - 1] - arr[0]
    smallest = arr[0] + k
    largest = arr[n - 1] - k
    for i in range(n - 1):
        minimum = min(smallest, arr[i + 1] - k)
        maximum = max(largest, arr[i] + k)
        if minimum < 0:
            continue
        ans = min(ans, maximum - minimum)
    return ans