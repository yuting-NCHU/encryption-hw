#include<stdio.h>
#include <iostream>
#include <string>
#include<math.h>
using namespace std;

char w[]="abcdefghijklmnopqrstuvwxyz";
string s;
float a;
char key_str[26];
int c_i=0;
int key;
int index;
int choice;

int stack[100];
int s_i=0;
bool has_neg=false;
int stack_to_num(){
	if(s_i==0) return -1;
	int num=0;
	for(int i=0;i<s_i;++i){
		num+=stack[i]*pow(10,s_i-i-1);
//		printf("%d\n",num);
	}
	if(has_neg){
		num=-num;
		has_neg=false;
	}
	printf("%d",num);
	num=num%26;
	if(num<0) num+=26;
	printf("(%d) ",num);
	s_i=0;
	return num;
} 
void input_key(){
	bool mark[26];
	c_i=0;
	int n=-1;
	
	printf("請輸入key: ");
// 可輸入帶有空格的字串,空格防呆 
	getline(cin,s);
	printf("切出來的字串: ");

	for(int i=0;i<s.length();++i){
		//		大寫轉小寫 
		if('A'<=s[i] && s[i]<='Z'){
			s[i]+=32;
		}
		
		if('a'<=s[i] && s[i]<='z'){
			n=stack_to_num();//把stack存的數字取出
			if(n!=-1){ //如果stack有數字的話 
				key_str[c_i++]=w[n];
//				mark[n]=true;
			}
			
			key_str[c_i++]=s[i];
//			mark[s[i]-97]=true;
			
			printf("%c ",s[i]);
		}
		else if(s[i]==','){
				n=stack_to_num();
//				printf("%d\n",n);
				if(n!=-1){ 
					key_str[c_i++]=w[n];
//					mark[n]=true;
				}
		}else if('0'<=s[i] && s[i]<='9'){//放入stack
			stack[s_i++]=s[i]-48;//放入stack 
			if(i==s.length()-1){//如果是最後一個字元 
				n=stack_to_num();
				if(n!=-1){ 
					key_str[c_i++]=w[n];
//					mark[n]=true;
				}
			}
		}
		else if(s[i]=='-'){
			has_neg=true;
		}
	}
	printf("\nkey_str=",key_str);
	for(int i=0;i<c_i;++i){
		printf("%c",key_str[i]);
	}
	cout<<endl;
}
void encryption(){
	printf("請輸入要加密的plaintext:\n");
// 可輸入帶有空格的字串,空格防呆 
	getline(cin,s);
		
	int i;
	for(i=0;i<s.length();++i){
//		大寫轉小寫，大寫防呆 
		if('A'<=s[i] && s[i]<='Z'){
			s[i]+=32;
		}
//		只加密小寫英文字，其餘字不加密防呆 
		if('a'<=s[i] && s[i]<='z'){
//			printf("%d\n",s[i]-97);
//			printf("%d\n",key_str[i%c_i]-97);
			index=((s[i]-97)+(key_str[i%c_i]-97))%26;
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
		
	int i;
	for(i=0;i<s.length();++i){
//		大寫轉小寫，大寫防呆 
		if('A'<=s[i] && s[i]<='Z'){
			s[i]+=32;
		}
//		只加密小寫英文字，其餘字不加密防呆 
		if('a'<=s[i] && s[i]<='z'){
			index=((s[i]-97)-(key_str[i%c_i]-97)+26)%26;
			s[i]=w[index];
		}
	}
	printf("您的plaintext是:\n");
	cout<<s<<endl;
	
}
int main(){
	printf("預設以字元和整數(可輸入負數)之間隔開\n如果有加 ',' 會用','優先隔開\n");

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
				input_key();
				encryption();
				break;
			}else if(choice==2){
				cin.get();
				input_key();
				decryption();
				break;
			}else{
				cout << "請輸入1(加密) or 2(解密)喔\n"; 
			}
		}
		
	}
	
}
