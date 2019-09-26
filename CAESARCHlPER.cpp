/*Method in which each letter in the plaintext is replaced by a letter some fixed number of positions down the alphabet.
	The method is named after Julius Caesar, who used it in his private correspondence.
	Input : String (a-z,A-Z,space)
	Limit : string.max_size()

*/
#include<bits/stdc++.h>
using namespace std;

void encr(int key,string kata){
	//plaintext to chipertext
	int ps;
	for(int i=0;i<kata.length();i++){
		ps = key + (kata[i]-'0');
		if(kata[i]-'0' == (-16)){
			continue;
		}else if(isupper(kata[i])){
			if(ps<=42){
				kata[i]+=key;
			}else{
				kata[i] = 'A' + (ps % 42) - 1;
			}
		}else{
			if(ps<=74){
				kata[i]+=key;
			}else{
				kata[i] = 'a' + (ps % 74) - 1;
			}
		}
		
	}
	cout<<kata;
}

void decr(int key,string kata){
	//chipertext to plaintext
	int ps;
	for(int i=0;i<kata.length();i++){
		ps = (kata[i]-'0') - key;	
		if(kata[i]-'0' == (-16)){
			continue;
		}else if(isupper(kata[i])){
			if(ps>=17){
				kata[i]-=key;
			}else{
				kata[i] = 'Z' - (17 % ps) + 1;
			}
		}else{
			if(ps>=49){
				kata[i]-=key;
			}else{
				kata[i] = 'z' - (49 % ps) + 1;
			}
		}	
	}
	cout<<kata;

}
int main(){
	int rot,pil;
	string kata;

	cout<<"1. encrypt ?\n2. decrypt ?\nChoice : ";
	cin>>pil;
	cout<<"Key  : ";
	cin>>rot;
	cout<<"Text :";
	cin.ignore();
	getline(cin,kata);
	rot%=26;
	(pil==1) ? encr(rot,kata) : decr(rot,kata) ;
	

	return 0;
}