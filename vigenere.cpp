/*Vigenere cipher
	A method of encrypting alphabetic text by using a series of interwoven Caesar ciphers, based on the letters of a keyword. 
	It employs a form of polyalphabetic substitution
	Input : String (a-z,A-Z,space)
	Limit : string.max_size()
*/
#include<bits/stdc++.h>
#include<fstream>
using namespace std;

string vigenere(string key,int pl){
	string newkey=key;
	while(newkey.size() < pl){
		newkey+=key;
	}
	newkey.erase(pl,newkey.size());
	return newkey;
}


void encry(string plain,string key ){
	for(int i=0;i<plain.length();i++){
		int ak = (key[i]-'0') %26;
		int ps = ak + (plain[i]-'0');		
		if(plain[i]-'0' == (-16)){
			continue;
		}else if(isupper(plain[i])){
			
			if(ps<=42){
				plain[i]+=ak;
			}else{
				plain[i] = 'A' + (ps % 42) - 1;
			}
		}else{
			
			if(ps<=74){
				plain[i]+=ak;
			}else{
				
				plain[i] = 'a' + (ps % 74) - 1;
			}
		}
	}
	cout<<plain;
}

void decry(string plain,string key){
	for(int i=0;i<plain.length();i++){
		int ak = (key[i]-'0') %26;
		int ps = (plain[i]-'0') - ak;		
		if(plain[i]-'0' == (-16)){
			continue;
		}else if(isupper(plain[i])){
			
			if(ps>=17){
				plain[i]-=ak;
			}else{
				plain[i] = 'Z' - (17 % ps) + 1;
			}
		}else{
			
			if(ps>=49){
				plain[i]-=ak;
			}else{
				
				plain[i] = 'z' - (49 % ps) + 1;
			}
		}
	}
	cout<<plain;
}

int main(){
	string plain,key;
	int pil;
	cout<<"\t\tVigenere Cipher\n1.Encrypt\n2.Decrypt\nChoice : ";
	cin>>pil;
	cout<<"Text : ";
	cin>>plain;
	cout<<"Key : ";
	cin>>key;

	if(pil==1){
		encry(plain,vigenere(key,plain.size()));
	}else{
		decry(plain,vigenere(key,plain.size()));
	}

	
}