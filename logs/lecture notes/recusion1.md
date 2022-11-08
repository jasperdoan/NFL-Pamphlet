# Why do we have to import the .h and .cpp file in main?
  
  - template casses aren't real classes
  - compiler doesn't generate a class until `List<int> myList{};` is called
  	- what the compiler does, is it builds an entire class replacing `T` with whatever datatype you specified
  - it can't build the class, it is unable to link the implementation of the functions with the header file
  	- so, either include .cpp file in main or copy and paste the cpp file at the bottom of the h file
  
---
# Recursion

## function calls itself
  - base case
  - call function case

## What are good use-cases for recursion?
  - factorial
      ```
      n! = n x (n-1) x (n-2) x ... x 1
         = n x (n-1)!
      ```
      - we end up with:
        ```
        n! = n x (n-1)! if n > 0      //call case
        n! = 1 if n = 0               //base case
        ```
        - or:
           ```
           5! = 5 x 4!
                    4! = 4 x 3!
                             3! = 3 x 2!
                                      2! = 2 x 1!
                                               1! = 1 x 0!
                                                        0! = 1
          ```
          - but this is a horrible approach for effeciency, for loop is more effecient
          - we will explore this from a different angle today
 
## similar to mathematical induction (shoutout kath)
  - if we can prove some thing `n`, then prove `n + 1`, we have shown all cases >= n are true
    - Sum of first n numbers: 1 + 2 + 3 + ... + n = n(n+1)/2
      - 50 pairs of `n+1`s
        - 1 + 100
        - 2 + 99
        - 3 + 98
        - ...
    - if this formula is true...
      - then the sum of n+1 numbers = (n+1)(n+2)/2

## raise 10 million dollars
  - rob a bank? NO JASPER!
  - I can't raise 10 million dollars
    - we can delegate this problem to friends
      - 10 friends to raise 1 million each
      - together, we'll have 10 million
        - those ten friends will delegate 10 friends each
        - now 100 people need to raise 100k
          - now 1000 people raise 10k
            - now at 10,000, raise 1k each
            - this is almost reaonable, A final base case

## people in line
  - is john in line?
    - ask person behind you if they're john
    - if no, they ask person behind them
    - ...
      - either they find jon, and then pass the message "we found john" back up, one by one
      - or they don't find john, and then they pass the message "john isn't here" back up, one by one

## let's write a simple recursion function for factorial
  ```
  int factorial(int n){ 
    if (n == 0){
      return 1;
    }
    return n * factorial(n-1);
  }
  ```
  #### what is happening on the call stack?
  - `main` is called when the program starts
    - `factorial(5)`
    - which calls `5 * factorial(4)`
    - which calls `4 * factorial(3)`
    - which calls `3 * factorial(2)`
    - which calls `2 * factorial(1)`
    - which calls `1 * factorial(0)`
      - returns 1, which pops off the stack
      - cascades back up, the opposite order they were called
        - this nonsense is why a for loop is faster, doesn't cascade up and back down

## print numbers
  - input for number `n`, return all ints from `0` to `n`
    - is there a difference between...
      ```
      cout << n << ' ';
      printNumbers(n-1);
      ```
      and
      ```
      printNumbers(n-1);
      cout << n << ' ';
      ```
      ?
      - yes!
        - instructions **before** the recursive call will happen "on the way up" (the stack frame)
        - instructions **after** the recursive call will happen "on the way down" (the stack frame)


## Tail recursion?
- optimation technique
  - why are we adding frames on the stack
  - compiler can actually omptimize this to not add stack frames
  - we do this using paramters

    ```
    int factorialTailRecursive(int n, int answerSoFar){
      if (n == 0){
        return answerSoFar;
      }
      return n * factorialTailRecursive(n-1, answerSoFar * n);
    }
   
    //overload for starting case
   
    int factorialTailRecursive(int n){ 
      return factorialTailRecursive(n, 1)
    }
    ```