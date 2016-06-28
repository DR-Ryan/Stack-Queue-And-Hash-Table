#include <iostream>
#include <cassert>
#include <string>
#include <stdexcept>
#include <exception>

using namespace std;

template <class Type> class DynStack{
	private:
	//Data Members
		Type * array;		  //pointer to array
		int count;			 //counts the number of elements
		int initialSize;	//inital size of the array
		int arraySize;	   //current size of the array
	public:

	//Constructor
		DynStack():initialSize(13),arraySize(0),count(-1){
			array = new Type[initialSize];
			arraySize = initialSize;
		}
		DynStack(int sz):arraySize(0),count(-1){
			initialSize = sz;
			if(initialSize == 0 || initialSize < 0){
				initialSize = 1;
				array = new Type[initialSize];
			}
			else{
				array = new Type[initialSize];
			}
			arraySize = initialSize;
		}
	//Destructor
		~DynStack(){
			delete[] array;
		}

	//Accessors
		Type top() const{
		if (this->empty()) throw underflow_error("Stack is Empty");
        return array[count];
		}
		int size()const{
			return count;
		}
		bool empty()const{
			return count == -1;
		}
		int capacity()const{
			return arraySize;
		}
		void display()const{ // O(N) 
			int id = count;
			for(int i = count; i >= 0; --i){
				cout << "Array[" << id << "]: " << array[i] << endl;
				id--;
			}
		}

	//Mutators
		void push(Type const & data){ // O(1) average
			if(count < arraySize){
			count++;
			array[count] = data;
			}else{
				arraySize *= 2;
				push(data);
			}
		}
		
		Type pop(){ // O(1) average
			if (this->empty()) throw underflow_error("Stack is Empty");
			
			Type tmp = top();
			count--;
			
			if( count <= (arraySize / 4) && arraySize > initialSize){
				arraySize /= 2;
			}
			return tmp;
		}

		void clear(){
			count = -1;
			array = new Type[initialSize];
			arraySize = initialSize;
		}

		int erase(Type const & data){
			if (this->empty()) throw underflow_error("Stack is Empty");
			Type * tmp = new Type[arraySize];
			int tmpcount = -1;
			int loopCount = count;
			int del = 0;
			
			for(int i = -1; i < loopCount; i++){	
				if(top() == data){
					del++;
					pop();
				}else{
					tmpcount++;
					tmp[tmpcount] = pop();
				}
			}
			if( count <= (arraySize / 4) && arraySize > initialSize){
				arraySize /= 2;
			}
			for(int i = tmpcount; i >= 0; --i){
				string data = tmp[i];
				push(data);
			}
			cout << "Number of elements deleted: " << del << endl;
			return del;	
		}
};

