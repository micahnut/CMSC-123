
#include <iostream>
#include <cmath>
#include <limits>

const int MAX = 512;

using namespace std;
//template<class T>
class HashTable{
	private:
		int table[MAX];
		int size;
		double inf;
	public:
		HashTable();
		int insert(int);
		int search(int);
		int hash(int);			
		//bool exists(int);
		//~Hashtable();
		void display();
};

HashTable::HashTable(){
	size = 0;
	
	//table = new int[size];
	inf = std::numeric_limits<int>::infinity();
	for(int i =0;i<MAX;i++){
		table[i] = inf;
	}
}


int HashTable::hash(int x){
	int z = 60147, d=9,w=16;
	
	int themod=1<<w, thediv=2<<(w-d);
	
	return ((z*x)%themod)>>w-d;
	
}

int HashTable::insert(int x){

	if((size>MAX) || (hash(x)> pow(2,16)-1))
		return 0;
		
	else{
		int index = hash(x);
		int count=0;
		
			while(table[index]!=inf){
			 	if(table[index]==inf){
			 		break;
				}
                
                index = (index+1) % MAX;  
				count++;		
			 }
		
        table[index] = x;
		size++;
		return count;
	
		
    }
}

int HashTable::search(int x){
	//int index = x% size;
		if((size>MAX) || (hash(x)> pow(2,16)-1))
			return 0;
	else{
        int index = hash(x);
	    int count=0;
	    
        if(table[index]==inf){
	       	return 0;
        }
    	else if(table[index]!=inf && table[index]== x){
            return 0;
        }
	   
        else{
		
		  while(table[index]!=inf && table[index]!=x){
			
            if(table[index]==inf){
				return 0;
			}
           
            index = (index+1) % MAX;
            count++;
		  }
         return count;
		
        }
        
    }		
}

void HashTable::display(){
	for(int i =0;i<size;i++){
		cout<<table[i]<<" ";
		
	}
	cout<<endl;
}


int main(){
	int numcases;
	int num;
	int found;
	
	int x;
	int search;
	
	HashTable t;
	int count;
	
	cin>>numcases;
	while(numcases!=0){
		HashTable t;	
		cin>>num;
	
		//HashTable t;	
		while(num!=0){
			cin>>x;
			
			count = t.insert(x);
			//t.display();
			cout<<count<<" ";
			num--;
		}
        cout<<endl;
		
		cin>>search;
	
		found = t.search(search);
	
		cout<<found<<endl;
		//cout<<count<<endl;
		numcases--;
	}
}
//	if(found==1)
//	 cout<<"FOUND"<<endl;
//	 else
//	 cout<<"NOT FOUND"<<endl;	
	