#include<iostream>
#include<fstream>
#include<bitset>
#include<list>
#include<string>
#include<sstream>


using namespace std;

class Packet{
	private:
	 int datalength;
	 string sourceAddress;
	 string destinationAddress;
	 int sequenceNumber;
	 bitset<16> checksum;
	 string data;
	 
public:
	 Packet();
	 string getSA();
	 string getDA();
	 int getSN();
	 int getLength();
	 string getData();
	 void display();
	 bool checkSumAlgo(string);
	 void addPackets(string);
	 bool operator==(Packet);
	 bool operator<(Packet);	 	

};

int total_number(list<Packet>);
string get_data(list<Packet>,int);
Packet::Packet(){
	datalength = 0;
	sourceAddress = "";
	destinationAddress="";
	data = "";
	
	//can i initialiaze the sequence num??  yes ^^
}

string Packet::getSA(){
	return sourceAddress;
	
}

string Packet::getDA(){
	return destinationAddress;
}

int Packet::getSN(){
	return sequenceNumber;
}

string Packet::getData(){
	return data;
}

int Packet::getLength(){  //naa nay built in ani
	return datalength;
}

void Packet::display(){
	cout<<"Source Address: "<<sourceAddress<<endl;
	cout<<"Destination Address: "<<destinationAddress<<endl;
	cout<<"checksum: "<<checksum<<endl;
	cout<<"datalength: "<<datalength<<endl;
	cout<<"data: "<<data<<endl;
}

bool Packet::checkSumAlgo(string str){
	bitset<17> sum;
	bitset<16> tmp1(string(str.substr(0,16)));
	bitset<16> tmp2;
	int padding = datalength%16;
	
	//16 bits: maximum representable value 216 - 1 = 65,535
	
	
	
	str.replace(80,16,"0000000000000000");
	
	for(int i =16; i<112 + datalength + padding; i = i+16 ){
		tmp2 = bitset<16>(string(str.substr(i,16)));	
		sum = bitset<17>(tmp1.to_ulong() + tmp2.to_ulong());
		
		if(sum[16]==1){
			tmp1 = bitset<16>((sum.to_ulong() - 65536) + 1);	
			
		}
		else
			tmp1 = bitset<16>(sum.to_ulong());	
		
	}
	cout<<"sum: "<<sum<<endl;
		
	tmp1.flip();
	
	if(tmp1 == checksum)
		return true;
	else
		return false;	
	
}

 void Packet::addPackets(string str){
 	stringstream ss;
	bitset<8> tmp1;
	bitset<16> tmp2;

	for(int i = 0; i<32; i+=8){ 
		tmp1 = bitset<8>(string(str.substr(i,8)));
		stringstream tmpss;
		tmpss<<tmp1.to_ulong();
		sourceAddress+= tmpss.str();
		if(i<24)
			sourceAddress+=	".";

	}
		
	for(int i=32;i<64;i+=8){	
		tmp1 = bitset<8>(string(str.substr(i,8)));
		stringstream tmpss;
		tmpss<<tmp1.to_ulong();
		destinationAddress+= tmpss.str();
		
		if(i<56)
			destinationAddress+=".";


	}
	
	
	tmp2 = bitset<16>(string(str.substr(64,16)));
	sequenceNumber = tmp2.to_ulong();
	if(sequenceNumber>1000)
		sequenceNumber = (short)(tmp2.to_ulong());

	tmp2 = bitset<16>(string(str.substr(80,16)));
	checksum = tmp2;

	tmp2 = bitset<16>(string(str.substr(96,16)));
	datalength = tmp2.to_ulong();


	if(checkSumAlgo(str)){
		for(int j = 112,i=8; i<=datalength; j+=8,i+=8 ){
			tmp1 = bitset<8>(string(str.substr(j,i)));
			int tmp = tmp1.to_ulong();
			data += (char)tmp;
		}
	}
	
	else
		data = "[line corrupted]";
	
	/* int datalength;
	 string sourceAddress;
	 string destinationAddress;
	 int sequenceNumber;
	 bitset<16> checksum;
	 string data;
	 */
	
	// cout<<"data length:"<<datalength<<endl;
	// //cout<<"sourceadd:"<<sourceAddress<<endl;
	// //cout<"destiAdd:"<<destinationAddress<<endl;
	// cout<<"seque:"<<sequenceNumber<<endl;
	// cout<<"checksum:"<<checksum<<endl;
	// cout<<"data:"<<data<<endl;
 
 }
 
 bool Packet::operator<(Packet p){
 	
    if (sequenceNumber < p.sequenceNumber)
        return true;
        
    if(datalength<p.datalength)
		return true;    

    else
        return false;
}
 
 
 bool Packet::operator==(Packet p){
    if (sequenceNumber == p.sequenceNumber)
        return true;

    else
        return false;
}

int main(){
	list<list<Packet> > poems;
	string st;
	list<Packet> poem;
	list<Packet>::iterator itr;
	list<list<Packet > >::iterator it;
	
	ifstream file("cases_in_order.in");
	ofstream out("outputmicah.out");
	
	if(file.is_open()){
		while(!file.eof()){
			getline(file, st);
			cout<<"read from file: "<<st<<endl;
			Packet pac;
			if(st.length()!=0)
				pac.addPackets(st);

			if(poems.empty()){   //checks if poemlist is empty
				list <Packet> poem;
				poem.push_back(pac);
				poems.push_back(poem);				
				//pac.display();

			}
			
			else{		//if there is a poem, traverse
				int flag=0;	//cbecker if have to make a new poem 
				for(it = poems.begin(); it!=poems.end(); it++){
					if(pac.getSA().compare(it->front().getSA())==0){
						flag=1;
						it->push_back(pac);
						//pac.display();
						break;
					}
				}

				if(flag==0){
					list <Packet> poem;
					poem.push_back(pac);
					poems.push_back(poem);
					//pac.display();
				}


			}
			
			
					
		}
		
		// for(it = poems.begin(); it != poems.end(); it++){
  //      	 	it->sort();
  //       	it->unique();
  //   	}

		// cout<<"HEEEEY"<<endl;
		// for(it = poems.begin(); it!=poems.end(); it++){
		// 	for(itr = it->begin(); itr!=it->end(); itr++){
		// 		// itr->display();
		// 		out<<itr->getData()<<endl;
		// 		cout<<itr->getData()<<endl;
		// 	}
		// }
		// cout<<"HEEEEY"<<endl;
	
		for(it = poems.begin(); it!=poems.end(); it++){
			// list<Packet>::iterator itr = it->begin();			
			// itr = it->begin();
			// itr++;
			
			int pl = total_number(*it);
			//itr++;			
			for(int i=0; i<pl; i++){
				cout<<get_data(*it,i)<<endl;
				out<<get_data(*it,i)<<endl;		
							
						
			}
			out<<"--------------------------------------------------------------"<<endl;
		} 
		
		
		file.close();
		out.close();

	}
	return 0;
}

int total_number(list<Packet> l){
	for(list<Packet>::iterator it=  l.begin(); it!=l.end(); it++){
		if(it->getSN() < 0){
			return -(it->getSN());
		}
	}
}

string get_data(list<Packet> l, int i){	
	for(list<Packet>::iterator it = l.begin(); it != l.end(); it++){
		string st;
		
		cout<<"Sequence Number: "<<it->getSN()<<endl;
		if(it->getSN() == i){
			
			if(i==1){
				st= it->getSA() + "/" + it->getDA()+"\n";
				return st + it->getData();
			}
			return it->getData();
			}
	}
	
	if(i==0){
		return "[title missing]";
		cout<<"qwerty"<<endl;
	}
	return "[line missing]";
		cout<<"qwerty"<<endl;
}
