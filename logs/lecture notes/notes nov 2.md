# Why do we have to import the .h and .cpp file in main?
  
  - template casses aren't real classes
  - compiler doesn't generate a class until `List<int> myList{};` is called
  	- what the compiler does, is it builds an entire class replacing `T` with whatever datatype you specified
  - it can't build the class, it is unable to link the implementation of the functions with the header file
  	- so, either include .cpp file in main or copy and paste the cpp file at the bottom of the h file
  
