
#include <map>
#include <set>

#include <iostream>

using namespace std;

template<class T>
    
class node{
    public:
        T item;
        node *next;
    
    node(){
        item = 0;
        next = NULL;
    }
    node(int x){
        item = x;
        next = NULL;
    }
};
    
    
template<class T>    
class Queue{
    private:
        int size;
        node<T> *front,*rear;
    public:
        Queue();
        Queue(const Queue&);
        ~Queue();
        bool dequeue();
        bool enqueue(T);
        T getFront();
        T getRear();
        int getSize();
        void display();

};

template<class T>
Queue<T>::Queue(){
    size=0;
    front = NULL;
    rear = NULL;
}


template<class T>
Queue<T>::Queue(const Queue& l){
    size = 0;
    front = NULL;
    rear = NULL;
    
    node<T> *tmp = l.front;
    
    for(int i=0;i<l.size;i++){
        insert(tmp->item);
        tmp=tmp->next;
    }
    
    
}

template<class T>
Queue<T>::~Queue(){
    
    while(size!=0){
        dequeue();
    }
}

template<class T>
int Queue<T>::getSize(){
    
    return size;
}

 template<class T>
 void Queue<T>::display(){
    
     int i=0;
      node<T> *tmp = front;
     while(i<size){
        cout<<tmp->item<<" ";
         tmp= tmp->next;
        i++;
     }
     cout<<endl;

 }

template<class T>
bool Queue<T>::enqueue(T x){
    
   node<T> *n = new node<T>(x);

        if(size==0){
            front=rear=n;
        }
    
        else if(size==1){
            front->next = n;
            rear = n;
            rear->next = NULL;
        }
        
        else{
            rear->next = n;
            rear = n;
            rear->next = NULL;
            
        }
           size++;

     return true;
 }

template<class T>
bool Queue<T>::dequeue(){ 
        
    if(size==0){
        //cout<<"queue is empty."<<endl;
        return false;    
    }
    else{
              node<T> *del;
              del = front;
              front = del->next;
              del->next = NULL;
         
             delete del;
    }
       size--;
       return true;
}

template<class T>
  T Queue<T>::getFront(){
      if(size==0){
          throw 123;
      }
      return front->item;
  }


template<class T>
  T Queue<T>::getRear(){
      if(size==0){
          throw 123;
      }
      return rear->item;
  }


int main() {
    Queue<int> l;
    int testcases, x;
    int item=0, pos=0;
    int type=0;
    
    cin>>testcases;
        while(testcases>0){
            cin>>type;
            if(type==1){ //enqueue
                cin>>item;    
            
                l.enqueue(item);
                 l.display(); 
            }
            else if(type==2){
                //dequeue 
                l.dequeue();
                 l.display();
            }
 
           else if(type==3){
                //front
                try{
                    cout<<l.getFront()<<endl;
                }
               catch(int err){
                    if(err==123)
                       cout<<"queue is empty."<<endl;
                }
               
            }
            else if(type==4){
                //rear
                try{
                  cout<<l.getRear()<<endl;
                }
                catch(int err){
                    if(err==123)
                       cout<<"queue is empty."<<endl;
                }
                
             }
            else{
                l.display();
            }
                
                     
         testcases--;     
        }
     
    
     return 0;
}
