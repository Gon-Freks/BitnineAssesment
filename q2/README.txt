How To Run:

- open the terminal at the folder q2 where q2.c is located
- compile the program using the command `gcc q1.c -o out`
- run the program using the command `./out`
- enter n to calculate the recurrence relation for n


Explanation:

- recurrence 1:
    This function implements the recurrence relation F[n] = F[n-3] + F[n-2] in the most naive way by calling the function itself recursively. This is a very inefficient way of calculating the nth term of the sequence as it has a time complexity of O(2^n) and a space complexity of O(n) due to the recursive calls.

- recurrence 2:
    This function implements the recurrence relation F[n] = F[n-3] + F[n-2] in a more efficient way by using dynamic programming. It uses an array to store the values of the sequence as they are calculated and then returns the nth term of the sequence. This is a much more efficient way of calculating the nth term of the sequence as it has a time complexity of O(n) and a space complexity of O(n) due to the array.

- recurrence 3:
    This function implements the recurrence relation F[n] = F[n-3] + F[n-2] in the most efficient way by using dynamic programming and only storing the last 3 values of the sequence. This is the most efficient way of calculating the nth term of the sequence as it has a time complexity of O(n) and a space complexity of O(1) due to the 3 variables.