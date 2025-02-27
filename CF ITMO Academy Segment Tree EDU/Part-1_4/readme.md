
#### [Part 1: Step 4 Practice Problems](https://codeforces.com/edu/course/2/lesson/4/4/practice)

###### [Problem A: Sign alternation](https://codeforces.com/edu/course/2/lesson/4/4/practice/contest/274684/problem/A)

<spoiler summary="Solution:">
To solve this problem, we negate the signs of the elements at even positions in the array and build a segment tree for range sums using this modified array. The alternating sum for a given range \([l, r]\) is then calculated as follows:

1. If \(l\) is odd, the alternating sum is the sum of the range \([l, r]\) from the segment tree.
2. If \(l\) is even, the alternating sum is the sum of the range \([l, r]\) from the segment tree, multiplied by \(-1\).
</spoiler>

<spoiler summary="Code(C++):">
[Github](https://github.com/Enamulhasan85/ProblemSolving/blob/main/CF%20ITMO%20Academy%20Segment%20Tree%20EDU/Part-2_4/A.cpp)
</spoiler>

###### [Problem B: Cryptography](https://codeforces.com/edu/course/2/lesson/4/4/practice/contest/274684/problem/B)

<spoiler summary="Solution:">
To solve this problem, we negate the signs of the elements at even positions in the array and build a segment tree for range sums using this modified array. The alternating sum for a given range \([l, r]\) is then calculated as follows:

1. If \(l\) is odd, the alternating sum is the sum of the range \([l, r]\) from the segment tree.
2. If \(l\) is even, the alternating sum is the sum of the range \([l, r]\) from the segment tree, multiplied by \(-1\).
</spoiler>

<spoiler summary="Code(C++):">
[Github](https://github.com/Enamulhasan85/ProblemSolving/blob/main/CF%20ITMO%20Academy%20Segment%20Tree%20EDU/Part-2_4/B.cpp)
</spoiler>
