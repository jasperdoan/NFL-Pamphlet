# First Checkpoint Nov 2
# Second Checkpoint Nov 9
# Introduce second project
# Third Checkpoint Nov 16

---
---
# How we could have designed the User Stories
- ignore part about 10 user stories

- Some of the requirements are user stories

- Examples:
	- Help Option
		- how deep is this feature? we don't know!
			- but, we will have a conversation about it later
			- (whole point of user story)
	- Contact Us option
- can combine Help and Contact us into one user story
	- changing stuff is key to agile team
- Items 3, 4, 5, 6, 7 are about displaying the original list
	- Display list of teams
		- put everything in terms of display list of teams...?

# 3 Main stories
- main menu
- display league stats
- display list of teams

# all three need to be broken down
- main menu
	- as a user, I want to access a main menu so that I have centralized access to all the actions I can take
		- gives context
		- starting with the end goal in mind
		- how do we know when this user story is done?
			- 99% isn't done, it has to be ALL THE WAY done
			- so we need to be clear on what "done" means
	- This will be done when user clicks help button and user recieves help prompt, same with contact us
	--- 
	- **Tasks**
		- this is where it gets really broken down
- display league stats
- display list of teams


# INVEST criteria

- independent
  - stories don't overlap
  - then, team work is really easy, less chance of conflict
 
- Negotiable
	- go back and change things
	- but still reaches end goal
		- add remaining features in next sprint 

- Testable
	- create a definition on what it means to be done
		- test until criteria is met


# New (or not) Templates

- function
	```
		int add(int x, int y){
			return x + y;
		}
	```
	- this function sux Lol
	- only one data type
		- what if we want to add doubles?
		```
		double add(double x, double y){
			return x + y;
		}
		```
		- function overloading
		- functions are uniquely identified by **NAME**, and **PARAMETER LIST**
			- so, the double function has a different signature
---
- template allows a generic type of program
	- in our add function, the body is the same; only the types of data change
	- so, what if we could pass in the data type of the parameters?
	- ex)
	```
	template <typename T>
	// T is it's own type
	T add(T x, T y){
		return x + y;
	}
	```
	- we can call add:
		```
		add<int>(2,3);
		add<double>(5.4, 3.566);
		add<string>("Hello","World");
		```
		- gives us more generic programming
---
- what happens if we don't specify anything?
	- int and double seem to run...?
		- so, sometimes it **can** be inferred
		- in the string example, however, it didn't work
			- a string literal is not interpretted as a string class
			- it is interpretted as a const character array
---
- What is actually happening?
	- when the compiler sees a template
		- It cann detect all the different overloads for add functions
		- the compiler generates these 3 add functions for us
			- **COMPILE TIME**
		- so, it saves us time

---
- This is where it gets interesting...
	- we can create a template for...
	- A class!
	```
	template <typename T>
	class Array{	
		private:
			T* ptr;
			int size
			
		public:
			Array(T arr[], int size);
			void print();
	};
	
	
	template <typename T>
	Array<T>::Array(T arr[], int size){
		ptr = new T[size];
		this->size = size;
		for (int i = 0; i < size; i++){
			ptr[i] = arr[i];
		}
	}
	```
	---
	in the .cpp......
	---
	```
	template <typename T>
	void Array<T>::print(){
		for (int i = 0; i < size; i++){
			cout << *(ptr + i) << endl;
			//actual data at the i^th position
		}
	}
	```
	- need to write template before every function
	- arrays of int, double, etc can be held by the same class, printed by the same function
		- ability to repurpose code
	
---
- we can create classes that take in multiple types
---
- question?
	- now that we have templates, is there even a point for overloading?
		- from the developers perspective...?
			- Yes! it's subtle
			- if the code is identical, use a template
				- need overloading if logic changes when types change
	- Static Variable:
	  - Remembers data over multiple calls
	  - not true for a regular variable
	  - implies that it does not belong in the scope where it is defined
	  	- ex) `int countHowManyTimesThisFunctionHasBeenCalled`
	  	- don't want a new instance of this every time the funciton is called
	- Knowing this... static variables in templated class... how many static variables?
		- one for each type
		- because as stated earlier, the compiler generates a new class for us
		- so for each new type used, a new static variable is created