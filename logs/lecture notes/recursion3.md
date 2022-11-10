# test

- templates
  - one programming exercise
- recursion
  - one programming exercise
- AGILE
  - word doc with answers to questions

- at home, no class

# MORE recursion

- shared state
  - between calls

- Queen on a 4x4 chessboard
	- 4 queens on the board, where no queen can attack eachother
		- place one, place second out of the way
			- next, try to place a third one
				- if there's a space, then good
				- if not, then you have to go back and fix the second one
			 		- backtrack the last decision
			 			- if no option, backtrack AGAIN

- now **CODE IT!!!**
	- probably gonna use recursion given the topic
	- 2d array, all 0s
	- no collumn, row, or diagonal can have 2 1s
	- so, implement a check function
		- place first 1 in a[0][0]
		- check
		- will be good, so move over collumn
		- place in a[0][1]
		- check
			- fail, try a[1][1]
			- check
				- fail, try a[2][1]
				- good, move on to second collumn
				- blah blah blah

	- ## function structue
		- findSolution(int boardSize)
			- places first queen, which leads to 1 of 3 states
				- leads to a solution
					- thus, prints the working solution
				- does not lead to a solution
					- move on to next row in collumn
					- if failed every row, backtrack to previous collumn
				
		- checkSolution(2dArr*)
