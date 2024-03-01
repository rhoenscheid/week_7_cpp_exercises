## Responses to Section 1 of Week 7 Exercises.

### Tree (std::map)

Insertion:
The worst case scenario is O(n). The best case scenario is O(log(n)). The overall complexity is then O(nlog(n)).

Lookup: also O(nlog(n)) overall.

### Table (std::unordered_map)

Insertion:
best case is O(1) as there would be no extra data in the table. In the worst case scenario, there are many more keys than there are rows to put them in, so O(n).

Lookup is the same: 

### SortedList

Insertion:
Best case is O(n), worst case is O(n^2).
