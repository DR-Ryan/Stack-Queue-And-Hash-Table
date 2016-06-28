#include <iostream>
#include <cassert>
#include <string>
#include <stdexcept>
#include <exception>

using namespace std;

template<class Type> class DynQueue{
	private:
	//Data Memebers
		Type * array;			 //pointer to array
		int ihead;		   		//head index
		int itail;			   //tail index
		int count;			  //counts the number of elements
		int initialSize;	 //initial size of the array
		int arraySize;		//current size of the array
	public:

	//Constructor
		DynQueue():initialSize(13),arraySize(0),count(-1){
			array = new Type[initialSize];
			arraySize = initialSize;
		}
		DynQueue(int sz):arraySize(0),count(-1){
			initialSize = sz;
			if(initialSize == 0 || initialSize < 0){
				initialSize = 1;
				array = new Type[initialSize];
			}
			else{
				array = new Type[initialSize];
			}
		}
		~DynQueue(){
			delete[] array;
		}
	//Accessors	
		Type front()const{
			if (this->empty()) throw underflow_error("Queue is Empty");
			return array[ihead];
		}
		Type back()const{
			if (this->empty()) throw underflow_error("Queue is Empty");
			return array[itail];
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
		void display(){
			int id = count;
			for(int i = itail; i >= ihead; --i){
				cout << "Array[" << id << "]: " << array[i] << endl;
				id--;
			}
		}

	//Mutators
		void enqueue(Type const & data){
			if(count < arraySize){
				count++;
				array[count] = data;
				if(count == 0){
					ihead = count;
					itail = count;
				}else{

					itail = count;
				}	
			}else{
				arraySize *= 2;
				enqueue(data);
			}
		}
		Type dequeue(){
			if (this->empty()) throw underflow_error("Queue is Empty");
			
			Type tmp = front();
			++ihead;
			--count;
			
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
			if (this->empty()) throw underflow_error("Queue is Empty");
			Type * tmp = new Type[arraySize];
			int tmpcount = -1;
			int loopCount = count;
			int del = 0;

			for(int i = -1; i < loopCount; i++){	
				if(front() == data){
					del++;
					dequeue();
				}else{
					tmpcount++;
					tmp[tmpcount] = dequeue();
				}
			}
			if( count <= (arraySize / 4) && arraySize > initialSize){
				arraySize /= 2;
			}
			for(int i = 0; i <= tmpcount; ++i){
				string data = tmp[i];
				enqueue(data);
			}
			cout << "Number of elements deleted: " << del << endl;
			return del;							
		}
};

