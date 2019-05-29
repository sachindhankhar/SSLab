#include<bits/stdc++.h>
using namespace std;
int main(){
	ifstream fin;
	fin.open("rel_loader_input.txt");
	ofstream fout;
	fout.open("rel_loader_output.txt");
	
	cout<<"enter address\t";
	string s;
	cin>>s;
	int staraddr=stoi(s,nullptr,16);
	
	fin>>s;
	while(s!="E"){

		if(s=="H") fin>>s>>s>>s;
		if(s=="T"){
			fin>>s;
			int addr=stoi(s,nullptr,16)+staraddr;
			fin>>s>>s;
			string bits=bitset<12>(stoi(s,nullptr,16)).to_string();
			
			fin>>s;
			int i=0;
			while(s!="T" && s!="E"){
		
				if(bits[i]=='1'){
					int last=stoi(s.substr(s.length()-4),nullptr,16)+staraddr;
					fout<<hex<<addr<<"\t"<<s.substr(0,2)<<last<<endl;
				}else{
					fout<<hex<<addr<<"\t"<<s<<endl;
				}

				addr+=s.length()/2;
				fin>>s;
				i++;		
			}
		}
	}
	fout.close();
	fin.close();
	return 0;
}
