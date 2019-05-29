#include<bits/stdc++.h>
using namespace std;
int main()
{
	ifstream rp;
	rp.open("abs_input.txt",ios::in);
	ofstream wp;
	wp.open("abs_output.txt",ios::out);
	string s;
	int start;
	do{
		rp>>s;
		if(s[0]=='T'){
			rp>>s;
			start=stoi(s,nullptr,16);
			start--;
			rp>>s;   //just to ignore next field
			getline(rp,s,'\n');	//take whole line into string starting from current pointer
			string temp="";
			for(int i=0;i<s.length();++i){
				if(!isspace(s[i])){
					temp+=s[i];
					if(temp.length()==2){
						wp<<std::hex<<++start<<"\t"<<temp<<"\n";
						temp="";
					}
				}
			}
		}
	}while(s[0]!='E');
	
	wp.close();
	rp.close();
	
	return 0;
}
