
#### [Part 2: Step 4 Practice Problems](https://codeforces.com/edu/course/2/lesson/5/4/practice)

---

###### [Problem A: Assignment, Addition, and Sum](https://codeforces.com/edu/course/2/lesson/5/4/practice/contest/280801/problem/A)

In this problem, we handle two types of update operations: assignment and addition. To solve it, we store both the update value and type in the segment tree and query the range sum.

##### **Propagation Logic**:
1. **If the child already has an update:**
   - **Assignment operation:** Assign the new update and replace the child's update.
   - **Addition operation:** Add the update value to the child's update value while retaining the child's update type.
2. **If the child has no update:** Assign the update to the child.

##### **Node Update**:
1. **Assignment operation:** For the range \([l, r]\), the sum **becomes** `((r - l + 1) * update_value)`.
2. **Addition operation:** For the range \([l, r]\), the sum **increases** by `((r - l + 1) * update_value)`.

For query operations, we simply perform the range sum query.

---

###### [Problem B: Add Arithmetic Progression On Segment](https://codeforces.com/edu/course/2/lesson/5/4/practice/contest/280801/problem/B)

In this problem, we manage an update operation defined by four integers `(l, r, a, d)` — for each `(l <= i <= r)`, we update `x_i to (x_i + a + d * (i - l))`. To handle this efficiently, we store the starting value \( a \) and the increment \( d \) of the arithmetic progression.

##### **Propagation Logic**:
1. **Left Child (range [l, mid]):** Add the starting value \( a \) and the increment \( d \).
2. **Right Child (range [mid+1, r]):** Add the starting value adjusted for the midpoint `(a + d * (mid+1 - l))` and then add the increment \( d \).

##### **Node Update**:
1. Increase the node value by \( a \).

For query operations, we simply return the node value.

---

###### [Problem C: Painter](https://codeforces.com/edu/course/2/lesson/5/4/practice/contest/280801/problem/C)
 
In this problem, we manage an update operation defined by four integers `(l, r, a, d)` — for each `(l <= i <= r)`, we update `x_i to (x_i + a + d * (i - l))`. To handle this efficiently, we store the starting value \( a \) and the increment \( d \) of the arithmetic progression.

##### **Propagation Logic**:
1. **Left Child (range [l, mid]):** Add the starting value \( a \) and the increment \( d \).
2. **Right Child (range [mid+1, r]):** Add the starting value adjusted for the midpoint `(a + d * (mid+1 - l))` and then add the increment \( d \).

##### **Node Update**:
1. Increase the node value by \( a \).

For query operations, we simply return the node value.

---