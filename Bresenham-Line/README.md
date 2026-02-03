Algorithm:
BRESENHAM’S LINE DRAWING ALGORITHM
1. Input the two line end-points, storing the left end-point in (x0, y0)
2. Plot the point (x0, y0)
3. Calculate the constants Δx, Δy, 2Δy, and (2Δy - 2Δx) and get the first value for the decision parameter as:
 2  y
  x
4. At each xk along the line, starting at k = 0, perform the following test. If pk < 0, the next point
to plot is (xk+1, yk ) and:
p k  1 
2  y
Otherwise, the next point to plot is (xk+1, yk+1) and:
p k  1 
2  y  2  x
5. Repeat step 4 (Δx – 1) times
NOTE: The algorithm and derivation above assumes slopes are less than 1. For other slopes we need to adjust the algorithm slightly
5
