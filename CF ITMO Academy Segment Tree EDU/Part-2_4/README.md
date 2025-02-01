
## Part 2: Step 4 Practice Problems

---

### [Problem A: Assignment, Addition, and Sum](https://codeforces.com/edu/course/2/lesson/5/4/practice/contest/280801/problem/A)

<details>
  <summary><strong>Solution:</strong></summary>
  
  In this problem, we handle two types of update operations: assignment and addition. To solve it, we store both the update value and type in the segment tree and query the range sum.

  #### Propagation Logic:
  1. **If the child already has an update:**
     - **Assignment operation:** Assign the new update and replace the child's update.
     - **Addition operation:** Add the update value to the child's update value while retaining the child's update type.
  2. **If the child has no update:** Assign the update to the child.

  #### Node Update:
  1. **Assignment operation:** For the range \([l, r]\), the sum **becomes** `((r - l + 1) * update_value)`.
  2. **Addition operation:** For the range \([l, r]\), the sum **increases** by `((r - l + 1) * update_value)`.

  For query operations, we simply perform the range sum query.
</details>

---

### [Problem B: Add Arithmetic Progression On Segment](https://codeforces.com/edu/course/2/lesson/5/4/practice/contest/280801/problem/B)

<details>
  <summary><strong>Solution:</strong></summary>
  
  In this problem, we manage an update operation defined by four integers `(l, r, a, d)` — for each `(l <= i <= r)`, we update `x_i to (x_i + a + d * (i - l))`. To handle this efficiently, we store the starting value \( a \) and the increment \( d \) of the arithmetic progression within the node.

  #### Propagation Logic:
  1. **Left Child (range [l, mid]):** Add the starting value \( a \) and the increment \( d \).
  2. **Right Child (range [mid+1, r]):** Add the starting value adjusted for the midpoint `(a + d * (mid+1 - l))` and then add the increment \( d \).

  #### Node Update:
  1. Increase the node value by \( a \).

  For query operations, we simply return the node value.
</details>

---

### [Problem C: Painter](https://codeforces.com/edu/course/2/lesson/5/4/practice/contest/280801/problem/C)

<details>
  <summary><strong>Solution:</strong></summary>
  
  In this problem, we have a line of range \([-5e5, 5e5]\) initially in white color. We need to manage the line where segments are colored black or white. After each operation, we must determine the number of black segments and their total length.
  
  To handle this efficiently, we store:
  - **Number of black segments** (`cnt`),
  - **Total length of black segments** (`tree`),
  - **Two boolean values** (`pre`, `suf`) to indicate if the leftmost segment and rightmost segment are black. \(W = 0\), \(B = 1\)

  #### Propagation Logic:
  - **Assign the new update to the child even if it has an update.**

  #### Node Update:
  1. **If the update color is white**: Set `cnt`, `tree`, `pre`, and `suf` to zero.
  2. **If the update color is black**: Set `cnt = 1`, `tree = r - l + 1`, `pre = 1`, and `suf = 1`.

  #### Combine Left and Right Nodes:
  1. **Total length of black segments**: Sum of the lengths of both left and right children.
  2. **Count of black segments**: Sum of both left and right children's counts minus 1 if the left and right children join two black segments.
  3. **Leftmost segment color**: The color of the left child's leftmost segment.
  4. **Rightmost segment color**: The color of the right child's rightmost segment.

  For query operations, we simply return the node's values.
</details>

---

### [Problem D: Problem About Weighted Sum](https://codeforces.com/edu/course/2/lesson/5/4/practice/contest/280801/problem/D)

<details>
  <summary><strong>Solution:</strong></summary>
  
  In this problem, you are given an array \( a[1…n] \) of length \( n \) and need to handle two types of queries efficiently:
  
  1. **Change on Segment**: Add a value \( d \) to each element \( a[i] \) where \( l \leq i \leq r \).
  2. **Compute Weighted Sum**: Compute the weighted sum \( a[l] \times 1 + a[l+1] \times 2 + \dots + a[r] \times (r-l+1) \).

  To manage these operations, we use a **Segment Tree** that tracks:
  - **Sum of all elements in the range** (`sum`)
  - **Weighted sum of elements multiplied by their index** (`tree`)

  #### Propagation Logic:
  - Add the update value to the child's update value to ensure proper propagation.

  #### Node Update:
  1. **Range sum (`sum`)**: Update by adding the value \( d \times \text{range\_length} \).
  2. **Weighted Range sum (`tree`)**: Update by adding the value \( d \times \) (total number of times it contributes to the sum).

  #### Combine Left and Right Nodes:
  - **Range sum (`sum`)** and **Weighted Range sum (`tree`)**: Combine by summing the values from both the left and right child nodes.

  For query operations, use the segment tree to calculate the weighted sum from index 1, then subtract the range sum multiplied by \( l \).

</details>

---

### [Problem E: Wall](https://codeforces.com/edu/course/2/lesson/5/4/practice/contest/280801/problem/E)

<details>
  <summary><strong>Solution:</strong></summary>

  In this problem, we are given a **wall of height `a[1…n]`** with `n` columns, and we need to handle two types of queries efficiently:  

  1. **Increase Heights on a Segment**: Increase the height of all columns in range `[l, r]` to at least `h`.  
  2. **Decrease Heights on a Segment**: Reduce the height of all columns in range `[l, r]` to at most `h`.   

  After all **k** phases, the final height of each column is printed.

  #### **Segment Tree Structure**
  Each node in the **segment tree** maintains:  
  - **Minimum height (`mn`)**: The lowest height in the range.  
  - **Maximum height (`mx`)**: The highest height in the range.  
  - **Lazy updates (`lazy`)**: Stores pending height constraints to be applied later. 

  #### **Propagation Logic**
  When an update is pushed down to child nodes, it adjusts the height range based on previous constraints:
   - If the child update min limit is **smaller than** the new min limit, update it.  
   - If the child update max limit is **greater than** the new max limit, update it.  

  #### **Node Update**
  If a node’s lazy values exist:
  Update nodes `mn[i]` and `mx[i]` with adjusted height constraints. 

  #### **Querying Final Heights**
  After processing all queries, we query each column's height by retrieving the **minimum height** (`mn[i]`) from the segment tree.

</details>
 
---

### [Problem F: Mountain](https://codeforces.com/edu/course/2/lesson/5/4/practice/contest/280801/problem/F)

<details>
  <summary><strong>Solution:</strong></summary>
 
  In this problem, we are tasked with simulating a roller coaster ride over a series of **rails** of varying elevation, represented by an array `a[1…n]`. The system handles two types of queries:

  1. **Track Configuration Change**: Adjust the elevation of rails from index `a` to `b` by setting their elevation to a constant value `D`.
  2. **Start a Ride**: Given a maximum height `h` that the car can reach, determine how many consecutive rails the car will pass before the track exceeds the given height `h`.

  #### **Segment Tree Structure**
  Each node in the segment tree maintains the following information:
  - **Range [l, r]**: The segment of rails it represents.
  - **Tree Value (`tree`)**: The sum of elevations for this segment of rails.
  - **Prefix (`pre`)**: The max prefix sum of elevations for this segment of rails.
  - **Lazy Updates (`op`)**: Tracks the elevation adjustment.

  #### **Propagation Logic**
  - Assign the update value to the child's update (`op`) value to ensure proper propagation.

  #### **Node Update**
  - When a segment’s elevation needs to be changed (i.e., the segment is adjusted to a constant value `D`), the node's **tree value** and **prefix value** are updated accordingly.
  - **Prefix Logic**: For each node, the prefix is calculated to allow us to efficiently query how many rails the car will traverse before it reaches the maximum height `h`.

  #### **Querying for Ride Length**
  For the ride query:
  - We need to determine how many consecutive rails the trolley can pass, given its maximum allowable height `h`.
  - The key to this query is the **prefix sum**(max cumulative elevation) of each segment, which represents the maximum height of the track within the segment. 
   - If it's greater than allowable height `h`, the trolley can't pass the segment.
   - Otherwise, it can pass the segment.    
   - We recursively check the left and right subtrees, efficiently finding the stopping point.  

  In this solution, the **segment tree** is implemented using **pointers**, allowing dynamic memory allocation. This approach offers several advantages:

  1. **Memory Efficiency**: Nodes are created only when needed, avoiding pre-allocation for all ranges.
  2. **Scalability**: It efficiently handles large ranges and adapts to operations, without pre-defined limits.
  3. **Optimized Lazy Propagation**: Only relevant nodes are created and updated, improving propagation efficiency.

  This approach efficiently handles large inputs, ensuring the solution works even for the maximum limits of the problem constraints.
</details>
 
---