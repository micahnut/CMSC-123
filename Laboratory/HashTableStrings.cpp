
#include <vector>
#include <iostream>
#include <cmath>
#include <limits>

const int MAX = 1024;

using namespace std;
//template<class T>
class HashTable{
	private:
		vector<string> table[1<<10];
		int size;
		double inf;
        int hashfunction;
	public:
		HashTable(int);
		int insert(string);
		int search(string);
		int hash(unsigned int);	
        unsigned int hashcode1(string);
        unsigned int hashcode2(string);
		//void display();
};

HashTable::HashTable(int x){
	size = 0;
    
   if(x==1){
       hashfunction =1;
   }
    else
        hashfunction =2;
    
}

unsigned int HashTable::hashcode1(string st){
    int len = st.length();
    unsigned int h = 0;
    for(int i=0; i<len;i++){
        h = 31*h + st[i];
    }
    
    return h;
}

unsigned int HashTable::hashcode2(string st){
    unsigned int h=0,i=0,high;
    
    while(st[i]!='\0'){
        h= (h <<4) + st[i++];
        if(high = (h & 0xF0000000))
            h^=high>>24;
            
        h&=~high;
        
   }
           return h;
 }
           

int HashTable::hash(unsigned int x){
	int z = 60147, d=10,w=31;
	
	int themod=1<<w, thediv=2<<(w-d);
	
	return ((z*x)%themod)>>w-d;
	
}

int HashTable::insert(string st){

        int index;
        unsigned int x;
        if(hashfunction==1){
            x = hashcode1(st);
            index = hash(x);
        }
        else{
            x = hashcode2(st);
             index = hash(x);
        }      
		int count=0;
				
        table[index].push_back(st);
		size++;
		return table[index].size();
	
    
}

int HashTable::search(string st){
        int index;
        unsigned int x;
        if(hashfunction ==1){
            x = hashcode1(st);
            index = hash(x);
        }
        else{
            x = hashcode2(st);
            index = hash(x);        
        }
    
        int count=0;
        
        if(table[index].size() ==0 )
            return 1;
        
        else{
            int i=0;
            
            while(i<table[index].size()){
                if(st.compare(table[index][i])==0)
                    return i+1;
                
                i++;
            }
            return i+1;
        }
    
   
}



int main(){
	int numcases;
	int numwords;
	
	string words;
	int count;
	
	cin>>numcases;
	while(numcases!=0){
        HashTable t(1), g(2);	

		cin>>numwords;
		
		while(numwords!=0){
			cin>>words;
            
			count = t.insert(words);
            g.insert(words);
            cout<<count<<" ";
			//cout<<count<<" ";
			numwords--;
		}
        int h1, h2;
        cin>>words;            
		h1 = t.search(words);
        h2 = g.search(words);
		cout<<h1<<" ";
        cout<<h2<<endl;
		//cout<<count<<endl;
		numcases--;
	}
}
//	if(found==1)
//	 cout<<"FOUND"<<endl;
//	 else
//	 cout<<"NOT FOUND"<<endl;	
	
