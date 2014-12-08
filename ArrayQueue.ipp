//You will need this so you can make a string to throw in
// remove
#include <string>

//Syntax note: This uses the pre-processor to create a constant
// You could also use "const static" to make a constant, as in Java.
// Notice, however, that START_SIZE is NOT a variable! Instead, any
// place that the pre-processor sees "START_SIZE" it will replace it with
// 10 ... so this is like a global "find and replace".
#define START_SIZE 10

//Syntax note: C++ is not very good at figuring out which methods belong
// to which classes. That is why we have to use the scope operator to
// tell the compiler that this ArrayQueue() method belongs to the
// ArrayQueue<T> class.
template <class T>
ArrayQueue<T>::ArrayQueue(){
	backingArray = new T[START_SIZE];
	backingArraySize = START_SIZE;
	front = 0;
	numItems = 0;
}

template <class T>
ArrayQueue<T>::~ArrayQueue() {
	delete[] backingArray;
	backingArray = NULL;
	backingArraySize = 0;
	numItems = 0;
	front = 0;
}

template <class T>
void ArrayQueue<T>::add(T toAdd){
	if(numItems + 1 > backingArraySize) grow();
	backingArray[(front + numItems) % backingArraySize] = toAdd;
	numItems++;
}

template <class T>
T ArrayQueue<T>::remove(){
	if (numItems < 1){
		throw std::string("Queue is already empty, attempted to remove an element.");
	}
   T x = backingArray[front];
   front = (front + 1) % backingArraySize;
   numItems--;
   return x;
}

template <class T>
unsigned long ArrayQueue<T>::getNumItems(){
	return numItems;
}

template <class T>
void ArrayQueue<T>::grow(){
	T* tempArray = new T[backingArraySize * 2];
	for(unsigned int i = 0; i < backingArraySize; i++)
		tempArray[i] = backingArray[(front + i) % backingArraySize];
	backingArray = tempArray;
	backingArraySize = backingArraySize * 2;
	front = 0;
	tempArray = NULL;
	delete[] tempArray;
}
