# Recursion pt2: fibonacci
```
int fib(int n){
	if (n==0){
		return 0;
	}
	if (n==1){
		return 1;
	}
	return fib(n-1) + fib(n-2);
}
```
- very slow for fib(50)
```
				                 f(6)
				__________________/\___________________
			   /                                       \
			 f(5)                                      f(4)
			 /  \___	                               /  \____ 
			/       \___                             f(3)      \
		  f(4)          \____                        / \        f(2)
		  /  \_		        f(3)                   f(2) f(1)    /   \
		 /     \_		    /   \                   |    |     f(1) f(0)
	   f(3)      \        f(2) f(1)                f(1) f(0)
	   /\        f(2)      |     |
	  /  \        / \     f(1) f(0)
	f(2)  \    f(1) f(0)
	/\    f(1)
   /  \
 f(1) f(0)  	
```
- what do you notice?
  - so much repetition
  - when f(6),
	- 25 function calls
	- 6 "levels"
		- level 0 =>  1 nodes
		- level 1 =>  2 nodes
		- level 2 =>  4 nodes
		- level 3 =>  8 nodes
		- level 4 =>  16 nodes
	      - i level, 2^i nodes
		  - num of nodes:
		  	- `1 + 2 + 4 + ... + 2^h`
			- where `h` is the height of the tree
  - is there a generalized way for this

# iteratively..?
```
int fib(int n){
	int fn1 = 1;
	int fn0 = 0;
	for (int i = 2; i<= n; i++){
		int fi = fn0 + fn1;
		fn0 = fn1;
		fn1 = fi;
	}
	return fn1;
}
```
- almost instantanious for fib(50)
  - again, no overhead with iteration

# it seems like recursion sucks
# what can we do to eliminate duplicate work

- memoization
  - record nodes we have already calculated, return them when needed
  - still slower than iteration (it's over)

	```
	//function call
	long fibmemo(long n);
	long fibmemohelper(long n, long* memo);

	//implementation
	long fibmemo(long n){
		long* memo = new long[(int)n + 1];

		for (int i = 0; i <= n; i++){
			memo[i] = -1
		}

		memo[0] = 0;
		memo[1] = 1;

		long answer = fibmemohelper(n, memo);

		delete[] memo;

		return answer;
	}

	long fibmemohelper(long n, long* memo){
		int memoindex = (int)n;
		
		if (memo[memoindex] != -1){
			return memo[memoindex]
		}

		long fibN = fibmemohelper(n-1, memo) + fibmemohelper(n-2, memo);
		memo[memoindex] = fibN;
		return fibN;
	}
	```
	- is this the best way to write fibbonacci?
	  - no! do the loop

# problems that ONLY have a recursive solution...? do they exist?

- min/max algorithm (too hard)

- **print** all binary strings of length `n`
  - let n = 3
	- 000 
	- 001
	- 010
	- ....
  - how would you solve this
    - obviously, it involves recursion
	- write some function that can print a value of length n
	```
	void printBinaryStrings(int n);
	void printBinaryStringsHelper(int length, int index, string& solutionSoFar);
	//----------------------------------------------
	
	void printBinaryStrings(int n){

		string soltion;
		printBinaryStringsHelper(n, 0, solution);
	}

	void printBinaryStringsHelper(int length, int index, strin& solutionSoFar){
		if (length == index){
			cout << solutionoFar << endl;
			return;
		}

		solutionSoFar.append("0");
		printBinaryStringsHelper(length, index + 1, solutionSoFar);

		solutionSoFar.append("1")
		printBinaryStringsHelper(length, index + 1, solutionSoFar);
	}
	```

# solve this problem	
- take either 1, 2, 3 steps
- how many combinations to descend `n` number of stairs