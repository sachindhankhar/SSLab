#include<bits/stdc++.h>
using namespace std;
int main(){
	
	ifstream fin;
	fin.open("pass2_output.txt");
	ofstream fout;
	fout.open("object_program.txt");
	
	string location,label,opcode,operand,code;
	
	fin>>location>>label>>opcode>>operand>>code;
	string progname=label;
	progname.append(6-progname.length(),' ');
	string staraddr=operand;
	staraddr.insert(0,6-staraddr.length(),'0');
	string codes;
	string finaladdr;
	map<string,string> loc;
	while(fin>>location>>label>>opcode>>operand>>code){
		loc[code]=location;
		finaladdr=location;
		if(opcode!="END"){
			codes.append(code+"*");
		}
	}
	
	string objlength;
	stringstream ss;
	ss<<hex<<(stoi(finaladdr,nullptr,16)-stoi(staraddr,nullptr,16));
	ss>>objlength;
	objlength.insert(0,6-objlength.length(),'0');
	
	//header block----->
	fout<<"H"<<"^"<<progname<<"^"<<staraddr<<"^"<<objlength<<endl;
	//----------------->
	
	//text block----->
	int count=0;
	string si,sf;
	string startloc;
	for(int i=0;i<codes.length();++i){
		if(codes[i]!='*'){
			if(codes[i]!='-'){
				si.append(1,codes[i]);
				count++;
			}	
			if(count==30 && codes[i+1]!='*'){
				stringstream ss1;
				ss1<<hex<<count-si.length();
				ss1>>objlength;
				fout<<"T"<<"^"<<startloc<<"^"<<objlength<<"^"<<sf<<endl;
				sf="";
				count=0;
			}
		}else{
			if(sf.length()==0){
				startloc=loc[si];
				startloc.insert(0,6-startloc.length(),'0');
			}
			sf.append(si);
			si="";	
			if(count==30 ||i==codes.length()-1){
				stringstream ss1;
				ss1<<hex<<count;
				ss1>>objlength;
				fout<<"T"<<"^"<<startloc<<"^"<<objlength<<"^"<<sf<<endl;
				sf="";
				count=0;
			}
		}
		
	}
	//--------------->
	
	//end block------>
	fout<<"E"<<"^"<<staraddr<<endl;
	//--------------->
	
	fout.close();
	fin.close();
	return 0;
}
