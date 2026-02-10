# Q4: How can we implement the doubly linked list using structure? Write a method to insert(after given node) and delete the node in doubly linked list. Write main() to demonstrate the use of the functions.

A doubly linked list is implemented using a structure that contains data and two pointers, one pointing to the previous node and the other to the next node.

## Data Structure
- **Node**: Has data, prev, and next pointers

## Key Functions
1. **insertAfter**: Insert new node after given node - O(1)
2. **deleteNode**: Delete specific node - O(1)

## Insert After Algorithm
1. Create new node
2. Link new node between prev and prev->next
3. Update all 4 pointers

## Delete Algorithm
1. Update next node's prev pointer
2. Update prev node's next pointer
3. Free node

## Output
```
List: 10 20 30 40 
Inserted 25 after 20
List: 10 20 25 30 40 
Deleted 25
List: 10 20 30 40 
```

## Complexity
- Insert/Delete: O(1) with node pointer