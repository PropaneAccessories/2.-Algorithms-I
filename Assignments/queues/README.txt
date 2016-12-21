Assignment 2: Queues

- Completed the Dequeue and Randomized Queue in C++. 
- Code::Blocks used as the IDE.
- Had trouble with the isEmpty function since as long as the object exists there is at least one 
	node in the list. What I did later with the randomized queue was initialize the data value 
	to -1, using that to signify a null value, and removing the overloaded constructor that
	allows for an integer input to set the value of the first node.
- Did not make these data structures generic. My experience is limited with templates in C++, while
	the book for this course covers the Java equivalent. Something to revisit later on.
- There were also some requirments to throw some specific Java exceptions in some cases, which I
	couldn't include. Could possibly include something similar later on when I learn more on
	C++ error handling. 