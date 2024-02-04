# Exercise 6-5

Write a function `undef` that will remove a name and definition from the table maintained by `lookup` and `install`.

## Solution

The present implementation removes the name and definition from the linked list by:

1. Removing the link from the list, properly accounting for it possibly being the first element in the list.
2. Freeing memory associated with the `name`, `defn`, and `nlist` itself.
