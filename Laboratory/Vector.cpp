#include <iostream>

using namespace std;

class vector{
    private:   
	   int *items;
        int size;
        int max;
        void expand();
    public:
        vector();
        int getSize();
	   int at(int);
        bool insert(int, int);
       bool remove(int);
        int operator[](int);
        void display();
       
};


vector::vector(){
     size=0;
     max =5;
     items= new int[max];
}

void vector::expand(){
    
    int *tmp = new int[max];
    
    for(int i=0;i<size;i++)
        tmp[i] = items[i];
    
    
    delete[]items;
    max+=5;
    items= new int[max];
    
    for(int i=0;i<size;i++)
        items[i]=tmp[i];
    
    delete[]tmp;
    
}

    

int vector::getSize(){
	return size;
}
	
int vector::at(int i){
	return items[i];
}

int vector::operator[](int i){
    
    return items[i];
}

void vector::display(){
    for(int i=0;i<size;i++)
        cout<<items[i]<<" ";
    
    cout<<endl;
}

bool vector::insert(int n , int pos){
    if(pos<0 || pos>size)
        return false;
    
    if(pos==size){
        expand();
    }
    
        int i;
           for ( i=size;i>pos;i--)
             {
                  items[i] = items[i-1];
                 
                }
            items[i]=n;
            size++;
            return true;
        
  
}
    
bool vector::remove(int pos){
    if(pos<0 || pos>size)
        return false;
    
    else{ 
        for(int i =pos;i<size-1;i++){
            items[i]=items[i+1];
        }
        size--;
   }
    return true;
}

bool isSorted(vector arr){
    int flag=1;
        
    for(int i=0;i<arr.getSize()-1;i++){
        if(arr[i]>arr[i+1]){
           flag=0;
            break;
        }
    }
    
    if(arr[0] == arr[arr.getSize()-1])
        flag=0;
    
    
    if(flag==1)
        return true;
    else
        return false;
}

bool duplicate(vector *arr){
    int flag=0;
    
    for(int i=0;i<arr->getSize()-1;i++){
        for(int j=i+1;j<arr->getSize();j++){
            if((*arr)[i]==(*arr)[j]){
                arr->remove(j);
                j--;
                flag=1;
            }
        }
    }
    if(flag==1)  
         return true;
    else
        return false;
}



int main() {
    int n,t,x;
    
    
    cin>>n;
    
    while(n>0){
        vector arr;
        
        for(int i=0;i<10;i++){
            cin>>x;
            arr.insert(x,i);
 
        }
        
        bool frank = isSorted(arr);
        if(frank)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
        
        bool hanika = duplicate(&arr);
                arr.display();

        n--;
    }
}
