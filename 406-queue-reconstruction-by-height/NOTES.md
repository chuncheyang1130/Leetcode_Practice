### Implementation
- Write a compare function to be used in sorting
- The way of sorting: first compare height of a person (first element in each vector), smaller height push front. If same height, next compare how many people is higher or equal the person (second element in each vector), the bigger one push front
- When putting into new order, put at the position according to those positions left, for example, if 1 2 6 9 is left, and the position we want is 3, then put the vector at position 6 of the new order
