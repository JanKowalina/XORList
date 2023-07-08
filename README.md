Certainly! Here's an updated version of the README file that includes all the examples:

# Bidirectional List

This program implements a bidirectional list that uses XOR of addresses to store predecessor and successor information in each node. This reduces the memory usage by approximately 50% compared to a classic bidirectional list that stores actual addresses.

## List Functionality

The implemented bidirectional list provides the following functionalities:

- `ACTUAL`: Returns the value of the currently pointed element. For an empty list, it returns NULL. After adding the first element to the list, `ACTUAL` returns the value of that element until it is moved by other operations.
- `NEXT`: Prints the value of the successor of the currently pointed element and sets the pointer to the successor as the new current element. If the current element is the last element in the list, its successor will be the first element.
- `PREV`: Prints the value of the predecessor of the currently pointed element and sets the pointer to the predecessor as the new current element. If the current element is the first element in the list, its predecessor will be the last element.
- `ADD_BEG N`: Adds an element with value N to the beginning of the list.
- `ADD_END N`: Adds an element with value N to the end of the list.
- `ADD_ACT N`: Adds an element with value N as the predecessor of the currently selected element (`ACTUAL`).
- `DEL_BEG`: Removes the first element from the list.
- `DEL_END`: Removes the last element from the list.
- `DEL_VAL N`: Removes all nodes from the list whose value is equal to N.
- `DEL_ACT`: Removes the node pointed to by `ACTUAL` and sets `ACTUAL` to the predecessor. If the predecessor does not exist (i.e., the current element is the first element), `ACTUAL` will point to the last element of the list.
- `PRINT_FORWARD`: Prints the contents of the list from the first to the last element.
- `PRINT_BACKWARD`: Prints the contents of the list from the last to the first element.

## Input and Output

The program takes a number of commands as input, each invoking specific functionalities on the list. The output displays the results of the corresponding commands on the list, reflecting its current state. Initially, the list is empty, and its state evolves based on the sequence of commands.

## Examples

### Example 1

**Input:**
```
ADD_BEG 1
ADD_BEG 2
ADD_BEG 3
ADD_END 4
PRINT_FORWARD
PRINT_BACKWARD
```

**Output:**
```
3 2 1 4
4 1 2 3
```

### Example 2

**Input:**
```
ACTUAL
ADD_BEG 1
ACTUAL
ADD_BEG 2
ADD_BEG 3
ADD_END 4
PRINT_FORWARD
PRINT_BACKWARD
ACTUAL
NEXT
ACTUAL
NEXT
NEXT
PREV
ACTUAL
PREV
PREV
```

**Output:**
```
NULL
1
3 2 1 4
4 1 2 3
1
4
4
3
2
3
3
4
1
```

### Example 3

**Input:**
```
ACTUAL
NEXT
PREV
ADD_BEG 1
ACTUAL
NEXT
PREV
DEL_BEG
ACTUAL
NEXT
PREV
ADD_BEG 2
ACTUAL
NEXT
PREV
DEL_END
ACTUAL
NEXT
PREV
ADD_END 3
ACTUAL
NEXT
PREV
DEL_BEG
ACTUAL
NEXT
PREV
```

**Output:**
```
NULL
NULL
NULL
1
1
1
NULL
NULL
NULL
2
2
2
NULL
NULL
NULL
3
3
3
NULL
NULL
NULL
```

### Example 4

**Input:**
```
ADD_END 1
ADD_BEG 2
ADD_END 3
ADD_BEG 4
PRINT_FORWARD
DEL_BEG
PRINT_FORWARD
DEL_END
PRINT_FORWARD
ACTUAL
NEXT
ADD_ACT 5
PRINT_FORWARD
ACTUAL
NEXT
ADD_ACT  6
PRINT_FORWARD
ACTUAL
NEXT
DEL_ACT
PRINT_FORWARD
```

**Output:**
```
4 2 1 3
2 1 3
2 1
1
2
5 2 1
2
1
5 2 6 1
1
5
2 6 1
```

### Example 5

**Input:**
```
ADD_END 1
ADD_BEG 2
ADD_END 3
ADD_BEG 4
PRINT_FORWARD
DEL_VAL 3
PRINT_FORWARD
DEL_VAL 2
PRINT_FORWARD
ADD_END 1
ADD_BEG 2
ADD_END 3
ADD_BEG 4
PRINT_FORWARD
DEL_VAL 4
PRINT_FORWARD
```

**Output:**
```
4 2 1 3
4 2 1
4 1
4 2 4 1 1 3
2 1 1 3
```

### Example 6

**Input:**
```
DEL_BEG
DEL_END
DEL_ACT
ACTUAL
NEXT
PREV
PRINT_FORWARD
ADD_BEG 42
ACTUAL
NEXT
PREV
PRINT_FORWARD
DEL_ACT
ACTUAL
NEXT
PREV
PRINT_FORWARD
ADD_BEG 4
ADD_END 3
ADD_END 5
ADD_BEG 2
PRINT_FORWARD
ACTUAL
DEL_ACT
ACTUAL
DEL_ACT
ACTUAL
DEL_ACT
ACTUAL
DEL_ACT
ACTUAL
```

**Output:**
```
NULL
NULL
NULL
NULL
42
42
42
42
NULL
NULL
NULL
NULL
2 4 3 5
4
2
5
3
NULL
```

### Example 7

**Input:**
```
ADD_END 1
ADD_END 2
ADD_BEG 3
ADD_ACT 4
NEXT
PREV
ACTUAL
PREV
DEL_BEG
DEL_BEG
DEL_BEG
DEL_BEG
ADD_END 1
ADD_END 2
ADD_BEG 3
ADD_ACT 4
PREV
ACTUAL
NEXT
NEXT
DEL_END
DEL_END
DEL_END
DEL_END
ADD_END 1
ADD_END 2
ADD_BEG 3
ADD_ACT 4
ACTUAL
PREV
NEXT
NEXT
DEL_ACT
DEL_ACT
DEL_ACT
DEL_ACT
ADD_END 1
ADD_END 2
ADD_BEG 3
ADD_ACT 4
ACTUAL
NEXT
NEXT
NEXT
DEL_VAL 1
DEL_VAL 3
DEL_VAL 2
DEL_VAL 4
ADD_END 1
ADD_END 2
ADD_BEG 3
ADD_ACT 4
ACTUAL
PREV
PREV
PREV
```

**Output:**
```
2
1
1
4
4
4
1
2
1
4
1
2
