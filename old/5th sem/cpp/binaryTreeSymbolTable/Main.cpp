#include<iostream>
#include "bTree.h"
using namespace std;
int main()
{
	BinaryTree bt;
	int q;
	string key,val;
	do{
		cin>>q;
		switch(q){
		case 1:
			cout<<bt.size()<<endl;
			break;
		case 2:
			cin>>key>>val;
			bt.put(key,val);
			cout<<bt.size()<<endl;
			break;
		case 3:
			cin>>key;
			bt.remove(key);
			cout<<bt.size()<<endl;
			break;
		case 4:
			cin>>key;
			cout<<bt.search(key)<<endl;
			break;
		case -1:	
			cout<<"Exiting loop"<<endl;
			break;
		default :
			cout<<"Invalid Command"<<endl;
			break;
		}
	}while(q>-1 && q<5);
	return 0;
}
