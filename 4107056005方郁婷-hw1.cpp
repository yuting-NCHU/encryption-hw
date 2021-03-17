#include<stdio.h>
#include <iostream>
#include <string>
using namespace std;

char w[]="abcdefghijklmnopqrstuvwxyz";
string s;
float a;
int key;
int index;
int choice;

void encryption(){
	printf("請輸入要加密的plaintext:\n");
// 可輸入帶有空格的字串,空格防呆 
	getline(cin,s);
	
//	key不是整數的防呆 
	printf("請輸入你的key(整數):");
	while(!(cin >> a) || a-int(a)>0) { 
		cin.clear();
    	cin.sync();
	    cout << "輸入的不是整數喔，請再輸一次:"; 
	}
	key=int(a);
	char out[10000];
	int i;
	for(i=0;i<s.length();++i){
//		大寫轉小寫，大寫防呆 
		if('A'<=s[i] && s[i]<='Z'){
			s[i]+=32;
		}
//		只加密小寫英文字，其餘字不加密防呆 
		if('a'<=s[i] && s[i]<='z'){
			index=(s[i]-97+26+key)%26;
			s[i]=w[index];
			
		}
		
	}
	printf("您的ciphertext是:\n");
	cout<<s<<endl;
}

void decryption(){
	printf("請輸入要解密的ciphertext:\n");
// 可輸入帶有空格的字串,空格防呆 
	getline(cin,s);
	
//	key不是整數的防呆 
	printf("請輸入你的key(整數):");
	while(!(cin >> a)  || a-int(a)>0) { 
		cin.clear();
    	cin.sync();
	    cout << "輸入的不是整數喔，請再輸一次:"; 
	}
	key=int(a);
	char out[10000];
	int i;
	for(i=0;i<s.length();++i){
//		大寫轉小寫，大寫防呆 
		if('A'<=s[i] && s[i]<='Z'){
			s[i]+=32;
		}
//		只加密小寫英文字，其餘字不加密防呆 
		if('a'<=s[i] && s[i]<='z'){
			index=(s[i]-97+26-key)%26;
			s[i]=w[index];
		}
		
	}

	printf("您的plaintext是:\n");
	cout<<s<<endl;
}
int main(){

	
	
//	非數字的防呆
	while(true){
		printf("您好，請問要加密還是解密?\n");
		printf("請輸入數字1(加密) or 2(解密):");
		while(true){
			if((cin >> choice)==0){
				cin.clear();
	    		cin.sync();
		    	cout << "請輸入數字1(加密) or 2(解密)喔\n"; 
			}else if(choice==1){
				cin.get();
				encryption();
				break;
			}else if(choice==2){
				cin.get();
				decryption();
				break;
			}else{
				cout << "請輸入1(加密) or 2(解密)喔\n"; 
			}
		}
		
	}
	
}
