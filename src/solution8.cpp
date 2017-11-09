#include <iostream>
#include <cmath>

int res = 0;

void pave(int n){
	if(n<=0){
		if(n==0) res++;
		return;
	}
	pave(n-1);
	pave(n-2);
}

int main(){
	int n;
	std::cin>>n;
	if(n<=0){
		std::cout<<"0";
	} else{
		pave(n);
	}
	std::cout<<res;
	return 0;
}
