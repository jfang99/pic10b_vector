This is the implementation of my own class "vector" under the namespace "pic10b".
The class "vector" is templated in order to cope with three types of variable types - int, double, and string.

# Functions of class pic10b::vector
Just like std::vector, my own class pic10b::vector can handle different types of operations, such as "*", "+", "+=", "<", etc.
It is also implemented with the big 4 - default constructor, copy constructor, assignment operator, destructor.
Basic functions are also handled by my pic10b::vector, such as push_back(), pop_back().

# Test cases
All the functions have been tested and work as expected. Here some examples of test cases:
 1) Test of default constructor
 vector <string> v1;
 
 2)Test of operator "+"
 vector <int> v1;
 vector <int> v2;
 vector <int> v3;
 v1 = v2 + v3;
  
 3)Test of push_back();
 vector <double> v1;
 v1.push_back(0.1);
  
 

Overall, my pic10b::vector doesn't have as many helpful functions as std::vector does, but the implementation of my pic10b vector may give the reader some idea how inner structure of the container "vector" works.


