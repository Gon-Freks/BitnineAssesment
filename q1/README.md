# How To Run:

- open the terminal at the folder q1 where q1.c is located
- compile the program using the command `gcc q1.c -o out`
- run the program using the command `./out`


# Explanation:

## Assumptions:
- The numbers is in the range of 32 bit signed integer.
- The division is integer division.


## The Node structure stores the following attributes:
- type: which defines the type of the type of the node and accordingly the function to be called upon it
- func: which stores the function pointer to the function to be called upon the node. (subtract if the type is SUB)
- right: the right child node.
- left: the left child node.
- Evaluated: a boolean value to check if the node has been evaluated or not. (optimization to avoid re-evaluation of the same node)
- value: the value of the node. In case of NUM nodes it will store the value of the number, otherwise it will store the value that will be calculated by the function in func


## To create a node:
### Make a call to the function `createNode(type, func, left, right, value)` where:
- type: the type of the node
- func: the function pointer to the function to be called upon the node. it will be NULL if the type is NUM
- left: the left child node. it will be NULL if the type is NUM
- right: the right child node. it will be NULL if the type is NUM
- value: it's the value of the number if the type is NUM, otherwise it will be discarded.


## To evaluate a node:
Make a call to the function `evaluate(node)` where:
- node: the node to be evaluated



