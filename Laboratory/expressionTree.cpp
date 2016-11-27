#include <iostream>
#include <stack>
#include <string>
#include <cmath>
#include <list>
#include <vector>
#include <cstdlib>

using namespace std;

template <class T>
class Node{
public:
    T item;
    Node<T> *left;
    Node<T> *right;
	Node<T> *root;
	    
    Node(){
    item = 0;
    left = right = root = NULL;
    }
    Node(T x){
    item = x;
    left = right = root= NULL;
	}
};


Node<string>* addToTree(string);
vector<string>  postFix(Node<string>*, vector<string>);
int evaluation(vector<string>string);	


int main() {
    string str;
    stack<int> s;
	Node<string> *root = NULL;
	vector<string> Estr;
     int n;
    
	cin>>n;
	
    for(int i =0;i<n; i++){
		cin>>str;
    	
		root = addToTree(str);
   		Estr = postFix(root,Estr);

		cout<<evaluation(Estr)<<endl;
	}
    
    return 0;
}




Node<string> * addToTree(string st){
	string oper = "+-*/^";
	int p;
	 for(int i = 0; i < oper.length(); i++){
   		if(i == 1){
            p = st.find_last_of(oper[i]);
        } else{
            p = st.find(oper[i]);
        }
        if(p != string::npos){
            break;
        }
    }
    	if(p != string::npos){
    		
			Node<string> *r = new Node<string>(st.substr(p, 1));
        	r->left = addToTree(st.substr(0, p));
        	r->left->root = r;
        	r->right = addToTree(st.substr(p + 1));
        	r->right->root = r;
		
		return r;    
    	}
	
	return ( new Node<string>(st) );
}

 vector<string> postFix(Node<string>* r,vector<string> str){
	
	if(r!=NULL){
		str = postFix(r->left,str);
		str = postFix(r->right,str);
		str.push_back(r->item);
	}	
	return str;
}

int evaluation(vector<string> str){
	stack<int> s;
	int num1, num2;
	string oper = "+-*/^";
	
	for(int i=0, n=str.size(); i<n; i++){
		 //int p = str.find(oper[i]);
		if(oper.find(str[i])!=string::npos){
			num2 = s.top();
			s.pop();
			num1 = s.top();
			s.pop();
			
			if(str[i]=="+")
			s.push(num1+num2);
			else if(str[i]=="-")
			s.push(num1-num2);
			else if(str[i]=="*")
			s.push(num1*num2);
			else if(str[i]=="/")
			s.push(num1/num2);
			else if(str[i]=="^")
			s.push((int)pow(num1,num2));
		}
		else
			s.push(atoi(str[i].c_str()));
		
	}
	return s.top();
	
}