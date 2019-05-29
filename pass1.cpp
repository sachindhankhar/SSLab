#include<bits/stdc++.h>
using namespace std;
int main(){
	ifstream fin;
	fin.open("pass1_input.txt");
	ofstream fout1,fout2;
	fout1.open("pass1_output.txt");
	fout2.open("symtab.txt");
	string label,opcode,operand;
	fin>>label>>opcode>>operand;
	fout1<<"-"<<"\t"<<label<<"\t"<<opcode<<"\t"<<operand<<endl;
	
	int locctr=stoi(operand,nullptr,16);
	string ptr=operand;
	while(fin>>label>>opcode>>operand){
		
		if(opcode=="RESW"){
			locctr+=stoi(operand)*3;
		}else if(opcode=="RESB"){
			locctr+=stoi(operand);
		}else if(opcode=="BYTE"){
			if(operand[0]=='C'){
				locctr+=operand.length()-3;
			}else{
				locctr+=1;
			}
		}else{
			locctr+=3;
		}
		
		
		if(label!="-"){
			fout2<<label<<"\t"<<ptr<<endl;
		}
		fout1<<ptr<<"\t"<<label<<"\t"<<opcode<<"\t"<<operand<<endl;
		stringstream ss;
		
		ss<<hex<<locctr;
		ss>>ptr;
	}

	
	fout1.close();
	fout2.close();
	fin.close();
	return 0;
}
