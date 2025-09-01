def sum_of_modes(arr, k):
    """
    Calculates the sum of the modes of all subarrays of size k in the given array.

    Args:
        arr: A list of positive integers.
        k: An integer representing the size of the subarrays.

    Returns:
        The sum of the modes of all subarrays of size k.
    """
    n = len(arr)
    modes_sum = 0
    for i in range(n - k + 1):
        subarray = arr[i:i + k]
        counts = {}
        for num in subarray:
            counts[num] = counts.get(num, 0) + 1
        
        max_freq = 0
        mode = float('inf')
        for num, freq in counts.items():
            if freq > max_freq:
                max_freq = freq
                mode = num
            elif freq == max_freq and num < mode:
                mode = num
        modes_sum += mode
    return modes_sum