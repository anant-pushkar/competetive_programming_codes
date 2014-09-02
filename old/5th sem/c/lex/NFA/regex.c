#include "regex.h"
#include <string.h>
#include <stdbool.h>
#define STAR 2
#define PLUS 1
#define NONE 0
#define OR  -1
static nfa* initNFA(int n){
	//printf("\nInitialising NFA with %d states\n",n);
	
	nfa* nfaPtr=(nfa*)malloc(sizeof(nfa));
	
	//printf("Setting nStates\n");
	nfaPtr->nStates=n;
	
	//printf("Allocating states\n");
	nfaPtr->states=(queue**)calloc(n,sizeof(queue*));
	
	//printf("Allocating quants\n");
	nfaPtr->quants=(int*)calloc(n,sizeof(int));
	
	//printf("Returning pointer\n\n");
	return nfaPtr;
}
static int getStateCount(char *regex){
	//printf("\nCounting number of states for regex : %s\n",regex);
	int len=strlen(regex),i=0;
	int count=0;
	while(i<len){
		if(regex[i]=='['){
			count++;
			while(regex[i]!=']') i++;
			i++;
		}else if(regex[i]!='+' || regex[i]!='*' || regex[i]!='-' || regex[i]!='[' || regex[i]!=']'
					|| regex[i]!='(' || regex[i]!=')'){
			count++;
		}
		i++;
	}
	//printf("Count found to be %d\n\n",count);
	return count;
}
nfa* createNFA(char *regex){
	//printf("Creating NFA for |%s|\n",regex);
	int len=strlen(regex),i=0,j=0,temp;
	nfa* automata=initNFA(getStateCount(regex));
	while(i<automata->nStates && j<len){
		//printf("Innitialising state #%d\n",i);
		automata->states[i]=initQ();
		
		//printf("Reading regex at #%d\n",j);
		if(regex[j]!='['){
			//printf("Enqeueing terminal %c to state %d(line 51)\n",regex[j],i);
			enqueue(automata->states[i],regex[j]-0);
		}else{
			//printf("Found segment start\n");
			j++;
			if(regex[j]!='('){
				//printf("Enqeueing terminal %c to state %d(line 57)\n",regex[j],i);
				enqueue(automata->states[i],regex[j]-0);
			}
			j++;
			while(regex[j]!=']'){
				if(regex[j]!='(' && regex[j]!=')' && regex[j]!='-'){
					//printf("Enqeueing terminal %c to state %d(line63)\n",regex[j],i);
					enqueue(automata->states[i],regex[j]-0);
				}
				if(regex[j]=='-'){
					//printf("Found range marker\n");
					temp=getBack(automata->states[i])+1;
					while(temp!=regex[j+1]+1){
						//printf("Enqeueing terminal %c to state %d(line 70)\n",temp,i);
						enqueue(automata->states[i],temp);
						temp++;
					}
					j++;
				}
				j++;
			}
		}
		if(j<len-1 && regex[j+1]=='*' && i<automata->nStates){
			//printf("Found kleene star\n");
			automata->quants[i]=STAR;
			j++;
		}
		else if(j<len-1 && regex[j+1]=='+' && i<automata->nStates){
			//printf("Found plus\n");
			automata->quants[i]=PLUS;
			j++;
		}else if(j<len-1 && regex[j+1]=='|' && i<automata->nStates){
			//printf("Found or\n");
			automata->quants[i]=OR;
			j++;
		}
		else if(i<automata->nStates){
			//printf("No quantifiers found\n");
			automata->quants[i]=NONE;
		}
		j++;
		if(j<len){
			i++;
			//printf("Creating state #%d\n",i); 
		}
	}
	automata->nStates=i+1;
	//printf("\n\n");
	return automata;
}
bool match(queue *q , char c){
	//printf("\n\nLooking for match for %c in queue of size %d\n",c,q->size);
	int i=0 , lookup;
	for(;i<q->size;i++){
		lookup=getFront(q);
		//printf("Matching with %c\n",lookup);
		dequeue(q);
		enqueue(q,lookup);
		if(lookup==c-0){
			//printf("Match found\n");
			return true;
		}
	}
	//printf("Match not found\n");
	return false;
}
static bool checkNFA(nfa *automata , char *str){
	//printf("\n\nMatching %s in automata with %d states\n",str,automata->nStates);
	queue *stateQ=initQ() , *readQ=initQ();
	enqueue(stateQ,0);
	enqueue(readQ ,0);
	//printf("Enqueuing state#%d with read head #%d\n",getFront(stateQ),getFront(readQ));
	bool final_check=false , match_check=false;
	int state,i,quant,l=strlen(str),len;
	while(stateQ->size!=0){
		//printf("Getting head from state queue\n");
		state = getFront(stateQ);
		
		//printf("Dequeueing state queue\n");
		dequeue(stateQ);
		//printf("Simulating on state#%d ",state);
		
		i = getFront(readQ);
		dequeue(readQ);
		len=l-i;
		quant = automata->quants[state];
		//printf(" with read head at #%d (len=%d) \n",i,len);
		if(state==automata->nStates-1) {
			if(len==0)return true;
			else if(quant!=STAR) return false;
		}
		match_check=match(automata->states[state],str[i]);
		
		//printf("Switching quant #%d os state#%d\n",quant,state);
		switch(quant){
		case STAR:
			//printf("Found star\n");
			if(state<automata->nStates-1){
				enqueue(stateQ,state+1);//printf("Enqued state\n");
				enqueue(readQ , i+1);//printf("Enqiued read head\n");
			}
			
			if(match_check){
				enqueue(stateQ,state);
				enqueue(readQ , i+1);
			}
			break;
		case PLUS:
			//printf("Found Plus\n");
			if(match_check){
				if(state<automata->nStates-1){
					enqueue(stateQ,state+1);//printf("Enqued state\n");
					enqueue(readQ , i+1);//printf("Enqiued read head\n");
				}
				
				enqueue(stateQ,state);
				enqueue(readQ , i+1);
			}
			break;
		case NONE:
			//printf("No quantifier found\n");
			if(match_check && state<=automata->nStates-1){
				//printf("Enqueing next state : ");
				dequeue(stateQ);
				dequeue(readQ);
				enqueue(stateQ,state+1);
				enqueue(readQ , i+1);
				//printf("%d\n",getFront(stateQ));
			}	
			break;
		case OR:
			//printf("Found or\n");
			if(match_check){
				i++;
				//printf("Conditional match successful\n");
				do{
					state++;
					//printf("Moving to next state #%d\n",state);
					if(state==automata->nStates-1) return true;
				}while(automata->quants[state]!=OR);
			}else{
				state++;
				//printf("Moving to next state #%d\n",state);
				enqueue(readQ , i);
				enqueue(stateQ,state);
			}
			if(state<automata->nStates){
				enqueue(stateQ,state);
				enqueue(readQ , i);
			}
			break;
		}
		
	}
	if(len==0 && quant==STAR)return true;
	return false;
}
bool matchRegex(char *regex , char *str){
	return checkNFA(createNFA(regex),str);
}
void printNFA(nfa *automata){
	int i=0;
	//printf("Printing NFA with %d states\n\t",automata->nStates);
	if(automata==NULL){
		//printf("No automata found\n");
		return;
	}
	for(;i<automata->nStates;i++){
		//printf("state #%d : ",i);
		while(automata->states[i]->size!=0){
			//printf("%c ",getFront(automata->states[i]));
			dequeue(automata->states[i]);
		}
		//printf(" | ");
		//printf("  -  quant : %d\n\t",automata->quants[i]);
	}
}



















