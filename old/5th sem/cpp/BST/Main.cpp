#include<iostream>
#include "BST.h"
using namespace std;
int main()
{
	BST bt;
	int q;
	string key,val;
	do{
		cin>>q;
		switch(q){
		case 0:	
			cout<<"Exiting loop"<<endl;
			break;
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
		case 5:
			cout<<bt.min()<<endl;
			break;
		case 6:
			cout<<bt.max()<<endl;
			break;
		case 7:
			cin>>key;
			cout<<bt.floor(key)<<endl;
			break;
		case 8:
			cin>>key;
			cout<<bt.ceiling(key)<<endl;
			break;	
		default :
			cout<<"Invalid Command"<<endl;
			break;
		}
		cout.flush();
	}while(q>0 && q<10);
	return 0;
}
