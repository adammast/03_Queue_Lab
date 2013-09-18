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
    
}

template <class T>
ArrayQueue<T>::~ArrayQueue() {
    front = 0;
    numItems = 0;
    backingArraySize = START_SIZE;
    
    backingArray = new T[backingArraySize];

}

template <class T>
void ArrayQueue<T>::add(T toAdd){
    //if the backing array is full, create a larger one and copy in the elements
    
    if(numItems == backingArraySize){
        grow();
        }

        backingArray[(front+1)%backingArraySize

}

template <class T>
T ArrayQueue<T>::remove(){
  
}

template <class T>
unsigned long ArrayQueue<T>::getNumItems(){

}

template <class T>
void ArrayQueue<T>::grow(){
    
    backingArrayTemp = new T[2 * backingArraySize];
    
    for (i = 0; i < backingArraySize; i++) {
        backingArrayTemp[i] = backingArray[i];
    }
    
    delete[] backingArray;
    backingArray = backingArrayTemp;
    

}
