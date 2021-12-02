Although this one is tagged as dynamic programming problem, I learned there is a "sweep algorithm" that can solve this in O(nlogn) instead of O(n^2) using DP.

For each element, check where can we append this element to an array X. X[i] stores an element value which is some LIS' last element and this LIS length equals to i. For example, let LIS = {5,6,7}, X[3]'s value will be 7.

X[i] will always lesser than X[i+1]. Assuming there exist some X[i+1] < X[i], we would have update X[k]'s value, where 1 <= k <= i.

Since array X is sorted, we can find appending position by binary searching from 1 to current maximum LIS. If we can append some element to current maximum LIS say L, increment L and store element in X[L].

We loop through each element and find where to append in some LIS, so this takes O(nlogn) time.