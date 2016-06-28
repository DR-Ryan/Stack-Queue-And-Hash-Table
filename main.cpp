#include <iostream>
#include <string>
#include "Stack.h"
#include "Queue.h"
#include "HashTable.h"

using namespace std;

int main(){
	string del;
	int op = 0; 
	bool flag = false;
	DynStack<string> DSlist;
	DynQueue<string> DQlist;
	HashTable<int>* test = new HashTable<int>();
	while(true){
        cout << "******Menu Program******" << endl;
        cout << "Please select an option." << endl;
        cout << "1. Stack." << endl;
        cout << "2. Queue." << endl;
        cout << "3. Hash Table." << endl;
        cout << "4. Exit." << endl;
        cout << "--> ";
        cin >> op;
        if (op==4) break;
        else if (op==1){
        	    flag = true;
        	    cout << endl << "Stack created." << endl;
        	while(true){
        	cout << "******Menu Program******" << endl;
        	cout << "Please select an option." << endl;
        	cout << "1. Insert." << endl;
        	cout << "2. Delete." << endl;
        	cout << "3. Print." << endl;
        	cout << "4. Exit." << endl;
        	cout << "--> ";
        	cin >> op;
        	if (op==4) break;
    	    	else if (op==1){
    	    	string data;
                cout << "Enter value to be inserted" << endl;
                cin >> data;
            		DSlist.push(data);
           		}
        		
        		else if (op==2){
        		string data;
        		int op_i;
                cout << "Do you want to delete or clear the list?(1.Delete, 2.Clear)\n-->";
                cin >> op_i;
                if (op_i==1){
                	cout << "Do you want to erase or pop the front?(1.Erase, 2.pop)\n-->";
                	cin >> op_i;
                	if (op_i==1){
                		cout << "What do you want to erase?"<<endl;
                		cin >> del;
                			try{
								DSlist.erase(del);
							}catch(const exception & e){
								cout << "error-->" << e.what() << endl;
							}
                		}else{
							try{
								DSlist.pop();
							}
							catch(const exception & e){
								cout << "error-->" << e.what() << endl;
							}
                		}
                	}else{
            				DSlist.clear();
            		}
            	}
        		else if (op==3){
        				cout << endl;
        					if(DSlist.empty()== true){
        						cout << "List is empty" << endl;
        						cout << endl;
        					}
        					else{	
            				DSlist.display();
            				}
            		}
            }
        }
        else if (op==2){
        	flag = true;
        	cout << endl << "Queue created." << endl;
        	while(true){
        	cout << "******Menu Program******" << endl;
        	cout << "Please select an option." << endl;
        	cout << "1. Insert." << endl;
        	cout << "2. Delete." << endl;
        	cout << "3. Print." << endl;
        	cout << "4. Exit." << endl;
        	cout << "--> ";
        	cin >> op;
        	if (op==4) break;
    	    	else if (op==1){
    	    		string data;
                	cout << "Enter value to be inserted" << endl;
                	cin >> data;
            		DQlist.enqueue(data);
           		}
        		else if (op==2){
        		string data;
        		int op_i;
                cout << "Do you want to delete or clear the list?(1.Delete, 2.Clear)\n-->";
                cin >> op_i;
                if (op_i==1){
                	cout << "Do you want to erase or dequeue the front?(1.Erase, 2.Dequeue)\n-->";
                	cin >> op_i;
                	if (op_i==1){
                		cout << "What do you want to erase?"<<endl;
                		cin >> del;
                			try{
								DQlist.erase(del);
							}catch(const exception & e){
								cout << "error-->" << e.what() << endl;
							}
                		}else{
							try{
								DQlist.dequeue();
							}
							catch(const exception & e){
								cout << "error-->" << e.what() << endl;
							}
                		}
                	}else{
            				DQlist.clear();
            		}
        		}
        		else if (op==3){
        				cout << endl;
        					if(DQlist.empty()== true){
        						cout << "List is empty" << endl;
        						cout << endl;
        					}
        					else{	
            				DQlist.display();
            				}
            		}
            }		
    	}else if (op==3){
        	    flag = true;
        	    cout << endl << "Hash Table created." << endl;
        		while(true){
        		cout << "******Menu Program******" << endl;
        		cout << "Please select an option." << endl;
        		cout << "1. Insert." << endl;
        		cout << "2. Delete." << endl;
        		cout << "3. Print." << endl;
        		cout << "4. Search." << endl;
        		cout << "5. Exit." << endl;
        		cout << "--> ";
        		cin >> op;
        		if (op==5) break;
    	    	else if (op==1){
    	    		int val;
    	    		cout << "What value do you want to enter" << endl;
    	    		cin >> val;
    	    		test->addValue(val);
           		}
        		else if (op==2){
					cout << "IS NOT FUNCTIONAL YET" << endl;
        		}
        		else if (op==3){
        			test->display();
        		}
        		else if (op==4){
        			int val;
        			cout << "What index do you want to look at?" << endl;
        			cin >> val;
         			cout << test->retrieveValue(val) << endl;
        		}
    			}
    		}
    	}
    return 0;
}