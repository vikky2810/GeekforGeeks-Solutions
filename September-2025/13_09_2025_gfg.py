def minimumCostToCutBoard(n : int, m : int, x : list[int], y : list[int]) -> int:
    """
    Given a board of dimensions n x m that needs to be cut into n*m squares.
    The cost of making a cut along a horizontal or vertical edge is provided in two arrays:

    x[]: Cutting costs along the vertical edges (length-wise).
    y[]: Cutting costs along the horizontal edges (width-wise).

    Find the minimum total cost required to cut the board into squares optimally.
    """
    x.sort(reverse=True)
    y.sort(reverse=True)
    
    horizontal_segments = 1
    vertical_segments = 1
    
    x_index = 0
    y_index = 0
    
    total_cost = 0
    
    while x_index < len(x) and y_index < len(y):
        if x[x_index] > y[y_index]:
            total_cost += x[x_index] * horizontal_segments
            vertical_segments += 1
            x_index += 1
        else:
            total_cost += y[y_index] * vertical_segments
            horizontal_segments += 1
            y_index += 1
            
    while x_index < len(x):
        total_cost += x[x_index] * horizontal_segments
        vertical_segments += 1
        x_index += 1
        
    while y_index < len(y):
        total_cost += y[y_index] * vertical_segments
        horizontal_segments += 1
        y_index += 1
        
    return total_cost