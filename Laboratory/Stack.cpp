
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
class Stack{
    private:
        int size;
        node<T> *top;
    public:
        Stack();
        Stack(const Stack&);
        ~Stack();
        bool push(T);
        bool pop();
        T peek();
        int getSize();
        void display();
};

void display(Stack<int>);
void revertStack(Stack<int>);


template<class T>
Stack<T>::Stack(){
    size=0;
    top = NULL;
 }

template<class T>
void revertStack(Stack<int> s) {
   node<T> *tmp;
    Stack<T> tmpstack;
    int item;
    
    while(s.getSize()!=0){
        item = s.top();
        s.pop();
        tmpstack.push(item);
        
    }
    while(tmpstack.getSize()!=0){
        item = tmpstack.top();
        tmpstack.pop();
        s.push(item);
    }
    s=tmpstack;
}




template<class T>
Stack<T>::Stack(const Stack& l){
    size = 0;
    top = NULL;
    
    node<T> *tmp = l.top;
    for(int i=0;i<l.size;i++){
        push(tmp->item);
        tmp=tmp->next;
    }
    
}



template<class T>
Stack<T>::~Stack(){
    
    while(size!=0){
        pop();
    }
}

template<class T>
int Stack<T>::getSize(){
    
    return size;
}

 template<class T>
 void Stack<T>::display(){
    
     int i=0;
      node<T> *tmp = top;
     while(i<size){
        cout<<tmp->item<<" ";
         tmp= tmp->next;
        i++;
     }
     cout<<endl;

 }

void display(Stack<int> l){
    l.display();
}


template<class T>
bool Stack<T>::push(T x){
    
   node<T> *n = new node<T>(x);

        if(size==0){
            top=n;
        }
    
        else{
            n->next = top;
            top = n;            
        }
           size++;

     return true;
 }

template<class T>
bool Stack<T>::pop(){ 
        
    if(size==0){
        //cout<<"queue is empty."<<endl;
        return false;    
    }
    else{
              node<T> *del;
              del = top;
              top = del->next;
              del->next = NULL;
         
             delete del;
    }
       size--;
       return true;
}

template<class T>
  T Stack<T>::peek(){
      if(size==0){
          throw 123;
      }
      return top->item;
  }




int main() {
    Stack<int> l;
    int testcases, x;
    int item=0;
    int type=0;
    
    cin>>testcases;
        while(testcases>0){
            cin>>type;
            if(type==1){ //push
                cin>>item;    
            
                l.push(item);
                 l.display();
//display(l);

            }
            else if(type==2){
                //pop
                l.pop();
                 l.display();
                 //display(l);

            }
 
           else if(type==3){
                //peek
                try{
                    cout<<l.peek()<<endl;
                }
               catch(int err){
                    if(err==123)
                       cout<<"stack is empty."<<endl;
                }
               
            }
           
                
            else{
                l.display();
                //display(l);
            }
                
                     
         testcases--;     
        }
     
    //display(l);
     return 0;
}