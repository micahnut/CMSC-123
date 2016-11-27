
#include <iostream>


using namespace std;
template<class T>
class Heap{
    private:
    T *items;
    int size;
    public:
    void insert(T);
    void display();
    ~Heap();
    Heap(int);
};

template<class T>
Heap<T>::Heap(int n){
    items = new T[n+1];
    size = 0;
}

template<class T>
Heap<T>::~Heap(){
    delete items;
}

template<class T>
void Heap<T>::display(){
    for(int i=1;i<=size;i++){
        cout<<items[i]<<" ";
    }
    cout<<endl;
}

template<class T>
void Heap<T>::insert(T item){
    items[++size] = item;
    
    int parent, curr;
    curr = size;
    parent = curr/2;
    
     int tmp;
    while(parent!=0){    
       if(items[curr]< items[parent]){
           tmp=items[curr];
           items[curr] = items[parent];
           items[parent] = tmp;
           
           curr= parent;    
           parent = curr/2;
       } 
        else
            break;
        
        
    }
    
}



int main() {
    int n;
    int m;
    int x;
    
    cin>>n;
    while(n!=0){  
        cin>>m;
        
        Heap<int> h(m);
   
        while(m!=0){
           
           cin>>x;
           h.insert(x); 
           h.display();
           m--;
        }
        
        n--;
    }
    
    return 0;
}