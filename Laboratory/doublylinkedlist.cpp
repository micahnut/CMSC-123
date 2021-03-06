
#include <iostream>

using namespace std;

template<class T>
    
class node{
    public:
        T item;
        node *next, *prev;
    
    node(){
        item = 0;
        next = NULL;
        prev = NULL;
    }
    node(int x){
        item = x;
        next = NULL;
        prev = NULL;
    }
};
    
template<class T>    
class Linkedlist{
    public:
    struct iterator{
        node<T> *pointer;
        iterator& operator++(int){
        pointer = pointer->next;
        return(*this);
    }
    T operator*(){
        return pointer->item;
    }
    bool operator!=(const iterator& it){
        return pointer!=it.pointer;
    }
    
    
};
    private:
        int size;
        node<T> *head,*tail;
        iterator iter;
    
    public:
        Linkedlist();
        Linkedlist(const Linkedlist&);
        ~Linkedlist();
        bool insert(T, int);
        bool remove(int);
        bool setItem(T,int);
        T getItem(int);
        int getSize();
        iterator begin(){
            iter.pointer=head;
            return iter;
        }
        iterator end(){
            iter.pointer = tail->next;
            return iter;
        }

};

void display(Linkedlist<int>);

template<class T>
Linkedlist<T>::Linkedlist(){
    size=0;
    head = NULL;
    tail = NULL;
}


template<class T>
bool Linkedlist<T>::setItem(T y,int pos){
    if(pos<0 || pos>=size)
        return false;
    
    else{
        int mid = size/2;
        node<T> *tmp;
        
        if(pos>mid){
            tmp= tail;
            int x = size-1;
            
            while(x>pos){
                tmp = tmp->prev;
                x--;
            }
        }
        else{
        
             tmp = head;
             int i=0;
        
             while(i<pos-1){
                tmp = tmp->next;
                i++;
            }
        }
        
        tmp->item = y;
       
    }
    return true;
}

template<class T>
Linkedlist<T>::Linkedlist(const Linkedlist& l){
    size = 0;
    head = NULL;
    tail = NULL;
    
    node<T> *tmp = l.head;
    
    for(int i=0;i<l.size;i++){
        insert(tmp->item,i);
        tmp=tmp->next;
    }
    
    
}

template<class T>
Linkedlist<T>::~Linkedlist(){
    
    while(size!=0){
        remove(0);
    }
    
    
}

template<class T>
bool Linkedlist<T>::insert(T x, int pos){
    
    if(pos<0 || pos>size)
        return false;
    
    else{
         node<T> *n = new node<T>(x);

        if(size==0){
            head=tail=n;
        }
    
        else if(pos==0){
            n->next = head;
            head->prev= n;
            head = n;
            
           
           
        }
        else if(pos == size){
            tail->next = n;
            n->prev = tail;
            tail = n;
            
        }
        else{
            node<T> *tmp = head;
            node<T> *tmp2;
            int i = 0;
        
            while(i<pos-1){
               tmp = tmp->next;
                i++;
            }
        
        tmp2 = tmp->next;
        n->next = tmp2;
        tmp2->prev = n;
        tmp->next = n;
        n->prev = tmp;
            
                    
        }
              
    }
           size++;

     return true;
 }

template<class T>
int Linkedlist<T>::getSize(){
    
    return size;
}

 /*
 void display(Linkedlist<int> l){
      
     int i=0;
     while(i<l.getSize()){
        cout<<l.getItem(i)<<" ";
        i++;
     }
     cout<<endl;
 }
*/
void display(Linkedlist<int> l){
    if(l.getSize()!=0){
    for(Linkedlist<int>::iterator i=l.begin(); i!=l.end(); i++)
        cout<<*i<<" ";
    cout<<endl;
    }
    else{
        cout<<" ";
    cout<<endl;
    }
}

template<class T>
bool Linkedlist<T>::remove(int pos){
    if(pos<0 || pos>size-1)
        return false;
    
    else{
    
         if(pos==0){
              node<T> *del;
              del = head;
              head = del->next;
             if(head!=NULL)
                head->prev = NULL;   
             del->next = NULL;
             del->prev = NULL;
              
             
             delete del;
         }
        
         else{
              node<T> *tmp = head;
              node<T> *del;
              node<T> *tmp2;
              int i=0;
            
             while(i<pos-1){
                tmp = tmp->next;
                i++;
             }
             
             del = tmp->next;
                      
           if(del == tail){
               tail = tmp;
               tail->next = NULL;
             
             }
        else{
              tmp2 = del->next;
             tmp->next = tmp2;
             tmp2->prev = tmp;
        }
             del->next = NULL;
             del->prev = NULL;
               
       delete del;
               
         }
          size--;         

    }     
       return true;
}

template<class T>
 T Linkedlist<T>::getItem(int pos){
        
      if(pos < 0 || pos >= size)
	       	throw 123;
       else{
           node<T> *tmp;
            int mid = size/2;
           
           if(pos > mid){
               tmp=tail;
               int x = size-1;
               
               while(x>pos){
                   tmp= tmp->prev;
                   x--;
               }
           }
           else{
                 int i=0;
                 tmp=head;
         
                 while(i<pos){
                   tmp=tmp->next;
                   i++;
                 }
         }
         return tmp->item;
      }
 }

int main() {
    Linkedlist<int> l;
    int testcases, x;
    int item=0, pos=0;
    int type=0;
    
    cin>>testcases;
        while(testcases>0){
            cin>>type;
            if(type==1){ //insert
                cin>>pos;
                cin>>item;    
            
                l.insert(item,pos);
                 display(l); 
            }
            else if(type==2){
                //remove  
                cin>>pos;
                l.remove(pos);
                 display(l);
            }
            else if(type==3){
                cin>>pos;
                try{
                    //l.getItem(pos);
                    cout<<l.getItem(pos)<<"\n";
                }
                catch(int err){
                    cout<<"POSITION OUT OF BOUNDS\n";
                }
            }
            else if(type==4){
                cin>>pos;
                cin>>item;
            
                l.setItem(item,pos);
                
                display(l);
             }
                
                     
         testcases--;     
        }
     
    
     return 0;
}