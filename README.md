03_Queue_Lab
============

Implement an array-based queue in C++

Note: When you create your project, do NOT add ArrayQueue.ipp to the list of source files, add it to the list of include files. You will see that ArrayQueue.ipp is #included at the bottom of ArrayQueue.h. See ArrayQueue.h for more explanation.

Requirements
------------

1. remove takes O(1) time
2. add takes O(1) time, unless it calls grow (in that case O(n) is okay)
3. grow is only called if the number of items == backingArraySize, and the size of the array is doubled during grow
4. grow takes O(n) time
5. Do not leak memory (make sure grow and the destructor do the right thing)
6. getNumItems is O(1) time
7. add and remove throw excpetions as appropriate
8. You must use the array in a circular fashion. If you don't do this you probably won't be able to get #1, #2 and #3 to all be true.

Reading
=======
"Open Data Structures," Chapter 2, up through section 2.4 (ArrayDequeue). http://opendatastructures.org/ods-cpp/2_Array_Based_Lists.html

Information about the Von Neumann computing model may be helpful. This optional reading is section 2.2 of "Algorithms and Data Structures: A Basic Toolbox" by Melhorn and Sanders. A free copy may be found here: http://www.mpi-inf.mpg.de/~mehlhorn/ftp/Toolbox/Introduction.pdf

Questions
=========

#### 1. Which of the above requirements work, and which do not? For each requirement, write a brief response.

1. Works, remove function simply takes the variable at the front of the array and removes it, so it's constant time.
2. Works, add simply adds one more to the tail end of the array. Takes more than constant if needs to grow first.
3. Works, grow makes a new array that's twice the size of the first and then moves all the original data over.
4. Works, grow depends on how many items are in the array when growing because all of the items need to transfer to the new array.
5. Works, at the end of grow, the unused array is deleted and also the destructor successfully deletes the backing array at the end.
6. Works, just returns the variable numItems.
7. Works, remove tells the user when the array is empty, add grows the array if neccessary before adding.
8. Works, the array only ever grows when numItems == backingArraySize.

#### 2. If we did a Stack instead of a Queue, which of the private methods and variables would we need to keep, and which could we get rid of? Explain your answer.
		We would need to keep grow method, as the array would still need to grow if there becomes too many variables for it to hold. We would need
		to keep backingArray as it needs to keep track of the array. We don't need front any longer because you don't need to retrieve the variable at
		the front of the array. We would still need numItems as that also can tell us where the end of the array is which we would need to know to
		remove the last variable in the array. We would need to keep backingArraySize to know when to grow the array.

#### 3. What is one question that confused you about this excercise, or one piece of advice you would share with students next semester?
		My advice would be to google weird errors because I had a really weird error that kept showing up no matter what
		but I found the answer of how to fix it when I googled it and it made me much happier than trying to figure out
		how to fix it myself.

#### 4. In Java you might write "class ArrayQueue extends Queue" ... how do you write the same thing in C++?
		You have to use #include and then whatever the name of the header file is that you want to "extend".

#### 5. What is the purpose of "templates" in C++?
		Templates allow for the designer to design code that can be used for any sort of variable type without requiring the
		designer to specify a certain variable type each time the code is written. It is similar to an interface in java.

#### 6. What would the syntax be for dynamically allocating an array of 10 ints, in C++?

#### 7. What is the purpose of a class destructor in C++? Why don't you need them in Java?
