
#include <iostream>


using namespace std;
template<class T>
class Heap{
    private:
    T *items;
    int size;
    public:
    void insert(T);
    void remove();
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

template<class T>
   void Heap<T>::remove(){
       int parent, curr,tmp=1,flag=0;
       curr = size;
       int tmpcurr;
       //int next;
       //cout<<items[curr]<<endl;
       items[tmp] =items[curr];
       tmpcurr = items[curr];
       
       size--;
       while(tmp<size/2){
       
           
       if(items[tmp*2]<items[tmp*2+1]){
            //next = tmp*2;
            //items[next] = items[tmp];
            items[tmp] = items[tmp*2];
            flag=0;
       }
       else{
           items[tmp] = items[tmp*2+1];
           flag=1;
        }
           
           if(flag==0){
               tmp = tmp*2;
           }
           else{
               tmp = tmp*2+1;
           }          
     }
       //size--;
       //cout<<items[curr]<<endl;
       items[tmp] = tmpcurr;
       //cout<<items[tmp]<<endl;
       //break;
       //cout<<items[tmp]<<endl;
       
       
       
   }



int main() {
    int n;
    int m;
    int x;
    int r;
    
    cin>>n;
    while(n!=0){  
        cin>>m;
        
        Heap<int> h(m);
   
        while(m!=0){
           
           cin>>x;
           h.insert(x); 
          
           m--;
        }
        cin>>r;
        while(r!=0){
            h.remove();
            h.display();
            r--;
        }
        n--;
    }
    
    return 0;
}