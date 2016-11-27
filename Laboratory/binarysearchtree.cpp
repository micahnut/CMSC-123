
#include <iostream>

using namespace std;

template<class T>
class bstnode{
public:
   T item;
   bstnode<T> *left;
    bstnode<T> *right;
	bstnode<T> *parent;
	    
    bstnode(){
    item = 0;
    left = right = parent = NULL;
    }
    bstnode(T x){
    item = x;
    left = right = parent= NULL;
	} 
    
};

template<class T>
class bst{
private:
    bstnode<T> *root;
    
    public:
    bst();
    //~bst();
    //provide the necessary arguments
    void insert(T); 
    bool remove(T);
    int search(T);
    void display();
    //you may include other auxilliary operations if need be
};

template<class T>
bst<T>::bst(){
    root = NULL;
}

template<class T>
void bst<T>::insert(T item){
    bstnode<T> *n = new bstnode<T>(item);
    
    if(root == NULL){
        root = n;
    }
    else{
        bstnode<T> *tmp = root;
        
        while(tmp!=NULL){
            if(n->item > tmp->item){
                if(tmp->right==NULL){
                        tmp->right  = n;
                   break;
                }
                else
                   tmp = tmp->right;
                
            }
            else if(n->item<tmp->item){
                if(tmp->left==NULL){
                        tmp->left = n;
                    break;
                }
                    else
                       tmp = tmp->left;
                
            }
        }
    }

    }

template<class T>
int bst<T>::search(T item){
    int count=1;
    
    bstnode<T> *tmp = root;
    while(tmp!=NULL){
        
      if(tmp->item == item)
          return count;
      else if(tmp->item < item)
            tmp = tmp->right;
             
          else
            tmp = tmp->left;
            
      count++;
        
  }
    return -count;
}

 //bool remove(T);




int main() {
   int testcases;
   int numbers;
   int item;
   int check;
    
    cin>>testcases;
    
    while(testcases>0){
        bst<int> tree;
        cin>>numbers;
        while(numbers>0){
            cin>>item;
            tree.insert(item);
            numbers--;
        }
        cin>>item;
      check = tree.search(item);
          if(check>0)
          cout<<check<<" FOUND"<<endl;
          else{
              
           check++;
           check = check*(-1);
          cout<<check<<" !FOUND"<<endl;
          }
          
        
        testcases--;
    }
    
    return 0;
}