#include<bits/stdc++.h>
using namespace std;
int main(){
	
	ifstream fin1;
	fin1.open("pass1_output.txt");
	ifstream fin2;
	fin2.open("optab.txt");
	ifstream fin3;
	fin3.open("symtab.txt");
	ofstream fout;
	fout.open("pass2_output.txt");
	
	map<string,string>optab;
	string opcode,value;
	while(fin2>>opcode>>value){
		optab[opcode]=value;
	}fin2.close();
	
	map<string,string>symtab;
	string label,location;
	while(fin3>>label>>location){
		symtab[label]=location;
	}fin3.close();
	
	string operand;
	fin1>>location>>label>>opcode>>operand;
	fout<<location<<"\t"<<label<<"\t"<<opcode<<"\t"<<operand<<"\t"<<"-"<<endl;
	while(fin1>>location>>label>>opcode>>operand){
		string code;
		
		if(opcode=="RESW"){
			code="-";	
		}else if(opcode=="RESB"||opcode=="WORD"){
			stringstream ss;
			ss<<hex<<stoi(operand);
			ss>>code;
			code.insert(0,6-code.length(),'0');
		}else if(opcode=="BYTE"){
			if(operand[0]=='X'){
				code=operand.substr(2,operand.length()-3);
			}else{
				stringstream ss;
				code=operand.substr(2,operand.length()-3);
				for(int i=0;i<code.length();++i){
					ss<<hex<<int(code[i]);
				}
				ss>>code;
			}
		}else if(operand[operand.length()-2]==','){
			int x=stoi(symtab[operand.substr(0,operand.length()-2)].substr(0,1),nullptr,16);
			if(x<=7){
				string s;
				stringstream ss;
	
				ss<<hex<<x+8;
				ss>>s;
				s.append(symtab[operand.substr(0,operand.length()-2)].substr(1));
				code=optab[opcode]+s;
			}else{
				code=optab[opcode]+symtab[operand.substr(0,operand.length()-2)];
			}
			
		}else{
			if(opcode!="END"){
				code=optab[opcode]+symtab[operand];
				code.append(6-code.length(),'0');
			}else code="-";
			
		}
		
		fout<<location<<"\t"<<label<<"\t"<<opcode<<"\t"<<operand<<"\t"<<code<<endl;
		}
		fin1.close();
		fout.close();
	return 0;
}
