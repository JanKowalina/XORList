# XOR List

## Description

This program implements a bidirectional XOR list, which stores the XOR values of predecessor and successor addresses in nodes. It reduces memory usage by approximately 50% compared to a traditional doubly linked list.

The program provides various functionalities to manipulate the XOR list, including adding elements to the beginning or end, adding an element before the currently selected element, deleting elements, and navigating through the list.

## Compilation and Execution

To compile the program, follow these steps:

1. Use a C++ compiler (such as g++) to compile the code:

   ```shell
   g++ -o XORList XORList.cpp
   ```

2. Run the program using the following command:

   ```shell
   ./XORList
   ```

   The program will start running and wait for user input.

## Usage

After running the program, you can interact with the XOR list by entering various commands. Here are the available commands:

- `ACTUAL`: Displays the value of the currently selected element.
- `NEXT`: Moves the selection to the next element and displays its value.
- `PREV`: Moves the selection to the previous element and displays its value.
- `ADD_BEG N`: Adds an element with value `N` to the beginning of the list.
- `ADD_END N`: Adds an element with value `N` to the end of the list.
- `ADD_ACT N`: Adds an element with the value `N` before the currently selected element.
- `DEL_BEG`: Removes the first element from the list.
- `DEL_END`: Removes the last element from the list.
- `DEL_VAL N`: Removes all elements with the value `N` from the list.
- `DEL_ACT`: Removes the currently selected element and moves the selection to the previous element (or the last element if the previous doesn't exist).
- `PRINT_FORWARD`: Prints the contents of the list from the first to the last element.
- `PRINT_BACKWARD`: Prints the contents of the list from the last to the first element.

Enter the commands one by one and observe the output to see the effects on the XOR list.

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
