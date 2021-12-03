When there are more than two linked-lists, merge them until there is only one.

Let n denote the number of the lists. In first iteration, we merge n lists and n/2 lists left in the queue.

Merging two linked-lists in the first iteration can take O(2k) steps, since each time we choose a smaller element from the head of the both lists and move to the next node.

In the second iteration, we have n/2 lists left, but the list can have O(2k) elements and merging these can take O(4k) steps.

Each iteration we do O(2nk) work and there are logn iterations, so this takes O(nklogn) time.