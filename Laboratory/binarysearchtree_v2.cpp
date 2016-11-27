	
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
	    ~bst();
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
	bst<T>::~bst(){
	    while(root!=NULL)
	        remove(root->item);
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
	                    n->parent = tmp;
	                   break;
	                }
	                else
	                   tmp = tmp->right;
	                
	            }
	            else if(n->item<tmp->item){
	                if(tmp->left==NULL){
	                        tmp->left = n;
	                        n->parent = tmp;
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
	
	template<class T>
	bool bst<T>::remove(T item){
	       
		bstnode<T> *del = root;
		int flag=0;
	    
		while(del!=NULL){
	        
			if(del->item == item){
				flag=1;
	            break;
	     	}
			else if(del->item < item)
	            del = del->right;
	             
			else
	            del = del->left;
	    	}
	        
	        if(flag==1){
	
				if(del->left == NULL && del->right == NULL){
					if(del==root){
	                    root = NULL;
	                }       
	                
	                else
	                if(del->item< del->parent->item){
	                    del->parent->left = NULL;
	                    
	                }
	                else{
	                    del->parent->right = NULL;
	                   
	                    }
					
					del->parent = NULL;
				//	if(del!=NULL)
					delete del;
	            }
	                    
	            
	
			else if(del->left != NULL && del->right !=NULL){
	          bstnode<T> *p = del->right;
	         
			  while(p->left!=NULL)
	              p = p->left;
	             
	          int tmp2 = p->item;
	          remove(tmp2);
	          del->item = tmp2;
	    
	          // p->parent->left = NULL;
	           //p->parent = NULL;
	    //delete p;
	
	       }
			
			else if(del->right !=NULL && del->left==NULL){
	    
				if(del != root){
	      
	    			if(del->parent->right == del){ 
	    				del->parent->right = del->right;
	                
	    			}
	    
	    		else{
	    			del->parent->left = del->right;
	    
	    		}
	    
				del->right->parent = del->parent;
				del->right = NULL;
				del->parent = NULL;
	    		delete del;
	    
	   			 }
	   			
				else{
					root = del->right;  
					del->right->parent = NULL;
				}
	    
	    
			}
	
	        else if(del->left !=NULL && del->right == NULL ){
				if(del!=root){
	  
					if(del->parent->left == del){
						del->parent->right = del->left;
	   				 }
	    			else
						del->parent->left = del->left;
	                
	    
					del->left->parent = del->parent;
					del->left = NULL;
					del->parent = NULL;
					delete del;
	            }
	    	else{
				root = del->left; 
				del->left->parent = NULL;
			} 
	  
	  
			}
	           
	           return true; 
	        }
	        
	        
	        return false;
	    }
	
	
	
	
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
	        
	        //cout<<check<<endl;
	          if(check>0){
	              //cout<<"waa"<<endl;	
	            tree.remove(item);
	            cout<<check<<" DELETED"<<endl;
	          }
	         else{
	              //cout<<"lol"<<endl;
	           check++;
	           check = check*(-1);
	          cout<<check<<" !FOUND"<<endl;
	          }
	          
	        
	        testcases--;
	    }
	    
	    return 0;
	}
