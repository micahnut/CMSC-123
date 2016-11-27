
#include <iostream>

using namespace std;

template<class T>
    
class vector{
    private:   
        T *items;
        int size;
        int max;
        void expand();
    public:
        vector();
        ~vector();
        vector(const vector<T>&);
        int getSize();
	    T at(int);
        bool insert(T, int);
        bool remove(int);
        T& operator[](int);
        void display();
        
       
};

template <class T>
vector<T>::vector(){
     size=0;
     max =5;
     items= new T[max];
}

template <class T>
void vector<T>::expand(){
    
    T *tmp = new T[max];
    
    for(int i=0;i<size;i++)
        tmp[i] = items[i];
    
    
    delete[]items;
    max+=5;
    items= new T[max];
    
    for(int i=0;i<size;i++)
        items[i]=tmp[i];
    
    delete[]tmp;
    
}

template<class T>
vector<T>::vector(const vector<T>& a){
    size = a.size;
    max = a.max;
    items = new T[max];
    
    copy(a.items,a.items+size,items);
}

    
template <class T>
int vector<T>::getSize(){
	return size;
}

template <class T>
vector<T>::~vector(){
    delete[] items;
    
}

template <class T>
T vector<T>::at(int i){
	return items[i];
}

template <class T>
T & vector<T>::operator[](int i){
    
    return items[i];
}

template <class T>
void vector<T>::display(){
    for(int i=0;i<size;i++)
        cout<<items[i]<<" ";
    
    cout<<endl;
}

template <class T>
bool vector<T>::insert(T n , int pos){
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

template <class T>
bool vector<T>::remove(int pos){
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

bool isSorted1(vector<int> arr){
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

bool isSorted2(vector<string> arr ){
    int flag=1;
    
    for(int i=0;i<arr.getSize()-1;i++){
        if(arr[i].compare(arr[i+1])>0){
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
bool duplicate1(vector<int> &arr){
    int flag=0;
    
    for(int i=0;i<arr.getSize()-1;i++){
        for(int j=i+1;j<arr.getSize();j++){
            if(arr[i]==arr[j]){
                arr.remove(j);
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

bool duplicate2(vector<string> &arr){
    int flag=0;
    
    for(int i=0;i<arr.getSize()-1;i++){
        for(int j=i+1;j<arr.getSize();j++){
            if(arr[i].compare(arr[j])==0){
                arr.remove(j);
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
    int n,type,x;
    string y;
    
    
    cin>>n;
    
     
    while(n>0){
        cin>>type;
    
        if(type==1){
             vector<int> arr;
            
          for(int i=0;i<10;i++){
            cin>>x;
            arr.insert(x,i);
 
          }
        
        bool frank = isSorted1(arr);
            if(frank)
                cout<<"YES"<<endl;
            else
                cout<<"NO"<<endl;
        
         bool hanika = duplicate1(arr);
                arr.display();

        }
        else{
            vector<string> arr;
            for(int i=0;i<10;i++){
            cin>>y;
            arr.insert(y,i);
 
        }
        
        bool frank = isSorted2(arr);
        if(frank)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
        
        bool hanika = duplicate2(arr);
                arr.display();

            
        }
        
        n--;
    }
}