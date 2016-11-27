#include <iostream>
#include <typeinfo>
#include <stack>
#include <queue>
#include <fstream>

	using namespace std;
	
	class square{
		public:
			char type;
			int x,y; //row//col
			bool flag;
			square();
			square(int,int,char);
			
	};
	
	square::square(){
		
	}
	square::square(int x,int y,char type){
		this->x = x;
		this->y = y;
		this->type = type;
		flag= false;
	}
	
	class maze{
	public:
		square **themaze;
		int row;
		int col;
		//maze(char **, int, int);
		maze(int,int);
		~maze();
		string tostring();
		void display();
	};
	
//	maze::maze(char **mazeP, int row, int col){
//		this->row = row;
//		this->col = col
//		
//			/*dynamic allocation*/
//		themaze = new square*[row];
//		//this allocates memory for n rows
//		//the next step is allocate the size of each row
//		for(int i=0;i<row;i++){
//			themaze[i]= new square[col]//allocating m elements for each row
//		}
//		//themaze is now ready to assigned with individual values
//		
//		for(int i=0;i<row;i++){
//			for(int j =0;j<col;j++){
//				themaze[i][j].type = mazeP[i][j];
//				themaze[i][j].flag = false;
//				themaze[i][j].x = i;
//				themaze[i][j].y = j;
//			}
//		}
//		
//	}

	maze::maze(int row,int col){
		this->row = row;
		this->col = col;
				/*dynamic allocation*/
			themaze = new square*[row];
		//this allocates memory for n rows
		//the next step is allocate the size of each row
		for(int i=0;i<row;i++){
			themaze[i]= new square[col];//allocating m elements for each row
		}
		//themaze is now ready to assigned with individual values
		
	}
	
	maze::~maze(){
		//free each row first
	for(int i=0; i<row; i++)
	    delete[] themaze[i];
		
		//finally, free themaze
		delete[] themaze; 
	}	
	
	void maze::display(){
		for(int i=0;i<row;i++){
			for(int j=0;j<col;j++){
				cout<<themaze[i][j].type;
			}
			cout<<endl;
		}
	}
	
	string maze::tostring(){
		
		string mazeToString = "";
		
		for(int i =0; i<row; i++){
			for(int j=0;j<col;j++){
				mazeToString = mazeToString + themaze[i][j].type;
			}
			mazeToString = mazeToString + "\n";
		}
		return mazeToString;	
			
	}
	
	template <class T>
	class agenda{
	private:
	    T *adt;
	    int type; //1 for stack, 2 for queue
	public:
	    agenda();
	    ~agenda(){delete adt;}
	    void add(square);
	    bool remove();
	    bool isempty();
	    int getsize();
	    square peek();
	};
	
	template <class T>
	agenda<T>::agenda(){
	    adt = new T();
	    string t1 = typeid(*adt).name();
	    string t2 = typeid(stack<square>).name();
	    string t3 = typeid(queue<square>).name();
	    //cout<<t1<<endl<<t2<<endl;
	    if(t1.compare(t2)==0)
	        type = 1;
	    else
	    if(t1.compare(t3)==0)
	        type = 2;
	}
	
	/*add - a facility to add an item depending on the adt used
	remove - a facility to remove an item depending on the adt used
	isempty - returns true if the adt is emply, false otherwise
	peek - returns the accessible item (top for the stack, front for the queue)
	getsize - returns the size of the adt*/
	template<class T>
	void agenda<T>::add(square s){
		adt->push(s);
	}
	
	template<class T>
	bool agenda<T>::remove(){
		if(!adt->empty()){
			adt->pop();
			return true;
		}
		else{
			return false;
		}
	}
	
	template<class T>
	bool agenda<T>::isempty(){
		return adt->empty();
	}
	
	template<class T>
	int agenda<T>::getsize(){
		return adt->size();
	}
	
	template<class T>
	square agenda<T>::peek(){
		if(type==1){
			return ((stack<square>*)adt)->top();
		}	
		else{
			return ((queue<square>*)adt)->front();
		}
	}
	
	template <class T>
	class mazesolver{
	private:
	    agenda<T> *a;
	    maze *m;
	    stack<square> *backtracker;
	    
	public:
	    mazesolver();
	    mazesolver(maze*);
	    ~mazesolver();
	    void solve();
	    void writesolution();
	};
	
	template<class T>
	mazesolver<T>::mazesolver(maze *m){
		this->m = m;
		a = new agenda<T>();
		backtracker = new stack<square>();
		
	}
	template<class T>
	mazesolver<T>::~mazesolver(){
		delete a;
		delete m;
		delete backtracker;
	}
	
	
	template <class T>
   void	mazesolver<T>::solve(){
		int x;
		int y;
		
		for(int i=0; i< m->row; i++){
			for(int j=0; j<m->col;j++){
				if(m->themaze[i][j].type == 'o'){
					x= i;
					y= j;
				}
			}
		}
		
		backtracker->push(m->themaze[x][y]);
		//m->themaze[x][y].flag = true;

		while(m->themaze[x][y].type!='*'){
			m->themaze[x][y].flag = true;
			
			
			a->add(m->themaze[x][y-1]); //left 
			a->add(m->themaze[x-1][y]); //top 
			a->add(m->themaze[x][y+1]); //right
			a->add(m->themaze[x+1][y]); //bottom
			
			while(a->peek().type == '#' || a->peek().flag == true ){
				a->remove();
				
				if(a->isempty()){
					break;
				}
			}
	
			
			if(a->isempty()){
				backtracker->pop();
			}
			else{
				backtracker->push(a->peek());
			}
			
			while(a->getsize()!=0){
				a->remove();
			}
			
			x = backtracker->top().x;
			y = backtracker->top().y;
			
		
		}
		
		backtracker->pop();
		
		
	}
	
	template <class T>
	void mazesolver<T>::writesolution(){
	ofstream outputfile("outputmicah.txt", std::ios_base::app);


		while(backtracker->size()!=0){
			if(backtracker->size()==1){
				backtracker->pop();
				break;
			}
			else{
				square a;

				a = backtracker->top();
				a.type = 'x';

				m->themaze[a.x][a.y] = a;

				backtracker->pop();
				}

			}

			for(int i=0;i<m->row;i++){
				for(int j=0; j<m->col; j++){
					cout<< m->themaze[i][j].type;
					outputfile<< m->themaze[i][j].type;
				}

				cout<<endl;
				outputfile<<endl;
			}
				cout<<endl;
				outputfile<<endl;


		outputfile.close();
	}
	
	
	int main(){
	int tcases;

	ifstream inputfile("maze.in");


	if(inputfile.is_open()){
		while(!inputfile.eof()){
			inputfile>>tcases;
			while(tcases!=0){
				int row;
				int col;
				
				inputfile>>row;
				inputfile>>col;
							
				maze *m1 = new maze(row,col);
				maze *m2 = new maze(row,col);
	
				char squaretype;

				for(int i=0;i<row;i++){
					for(int j=0;j<col;j++){
						inputfile>>squaretype;
						square sq(i,j,squaretype);
						m1->themaze[i][j] = sq;
						m2->themaze[i][j] = sq;

					}
				}
				//m1->display();
				//cout<<endl;
				//m2->display();
				
	
				
				mazesolver<queue<square> > msqueue(m1);
				msqueue.solve();
				msqueue.writesolution();

				mazesolver<stack<square> > msstack(m2);
				msstack.solve();
				msstack.writesolution();

				tcases--;
				
			}
		}
		inputfile.close();
	}
	else{
		cout <<"File not found"<<endl;
	}


	return 0;

}
		
	
	
	
	

