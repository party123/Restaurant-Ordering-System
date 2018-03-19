#include<iostream>
#include<string.h>
using namespace std;
int main(){
	int a[10]={1,2,3,4,5,6,7,8,9,10};
	int * p=a;
	cout<<*p+8<<endl;
	return 0;
}