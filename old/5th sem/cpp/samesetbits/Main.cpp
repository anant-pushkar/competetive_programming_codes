#include<iostream>
using namespace std;
/*
	 A number is given say n, find the minimum number which is 
	 greater than n and has same no. of set bits in it.
*/
class Number{
	int val;
	int nShifts;
	void shiftRight(){
		val=val>>1;
		nShifts++;
	}
	void shiftLeft(int offset){
		val=val<<1;
		val+=offset;
		nShifts--;
	}
	int getR(){
		return val&1;
	}
public:
	Number(int n):
	val(n),nShifts(0){}
	void goToNext(){
		int i1,i2;
		while(!getR())shiftRight();//pass all 0s
		i1=nShifts;
		while(getR())shiftRight();//passall 1s
		i2=nShifts;
		val++;
		shiftLeft(0);
		while(nShifts!=i1)shiftLeft(1);
		if(nShifts!=0 && i2-i1>1){
			while(getR() && nShifts!=0){
				val--;
				shiftLeft(1);
			}
		}else{
			while(nShifts!=0)shiftLeft(0);
		}
	}
	int getVal(){
		return val;
	}
};
int main()
{
	int n,T;
	cin>>T;
	for(int t=0;t<T;t++){
		cin>>n;
		Number num(n);
		num.goToNext();
		cout<<num.getVal()<<endl;
	}
	return 0;
}
