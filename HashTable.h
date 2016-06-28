#include <iostream>
#include <cassert>
#include <string>
#include <stdexcept>
#include <exception>

using namespace std;

template <class Type> class HashTable{
	private:
		Type * array;
		int arraySize;
		int initialSize;
		int hash(const Type & key){
			return key % 67;
		}
	public:
		HashTable():initialSize(67),arraySize(0){
			array = new Type[initialSize];
			arraySize = initialSize;
			memset(array, 0, sizeof(*array));
		}
		~HashTable(){
			delete[] array;
		}
		void addValue(const Type & data){
			int index = hash(data);
			if(array[index] == 0){
			array[hash(data)] = data;
			}
			else{
				bool notDone = true;
				while(notDone){
					index++;
					if(!array[index]){
						array[index] = data;
						notDone = false;
					}
				}
			}
		}
		Type retrieveValue(int index){
			return array[index];
		}
		bool contains(const Type & data){
			if(array[hash(data)]) return true;
			else return false;
		}
		void display()const{
			for(int i = 0; i < 67; i++){
				cout << array[i] << endl;
			}
		}
};