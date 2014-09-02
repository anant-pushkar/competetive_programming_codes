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
dfa * createDFA(char *regex){
	nfa* automata=createNFA(regex);
	int i=0;
	//printf("Creating DFA with %d states\n\t",automata->nStates);
	dfa *deter_auto=(dfa*)malloc(sizeof(dfa));//deterministic automata
	deter_auto->nStates= automata->nStates;
	deter_auto->states = (int **)calloc(automata->nStates,sizeof(int*));
	deter_auto->quants = (int * )calloc(automata->nStates,sizeof(int ));
	if(automata==NULL){
		//printf("No automata found\n");
		return;
	}
	int index;
	for(;i<automata->nStates;i++){
		//printf("state #%d : ",i);
		index=1;
		deter_auto->states[i]=(int*)calloc(automata->states[i]->size+1,sizeof(int));
		deter_auto->states[i][0]=automata->states[i]->size;
		deter_auto->quants[i]=automata->quants[i];
		while(automata->states[i]->size!=0){
			//printf("%c ",getFront(automata->states[i]));
			deter_auto->states[i][index++]=getFront(automata->states[i]);
			dequeue(automata->states[i]);
		}
		//printf(" | ");
		//printf("  -  quant : %d\n\t",automata->quants[i]);
	}
	return deter_auto;
}
bool match(int*q , char c){
	//printf("\n\nLooking for match for %c in queue of size %d\n",c,q->size);
	int i=0 , lookup;
	for(;i<=q[0];i++){
		lookup=q[i];
		//printf("Matching with %c\n",lookup);
		if(lookup==c-0){
			//printf("Match found\n");
			return true;
		}
	}
	//printf("Match not found\n");
	return false;
}
static bool checkDFA(dfa *automata , char *str){
	int state=0,i=0,quant,l=strlen(str),len;
	for(;state<automata->nStates;++state){
		len=l-i;
		quant = automata->quants[state];
		//printf("read head at #%d (len=%d) \n",i,len);
		if(state==automata->nStates-1) {
			if(len==0)return true;
			else if(quant!=STAR) return false;
		}
		if(str[i]=='\0'){
			//printf("input exhausted (at begining)\n");
			return false;
		}
		//printf("Switching quant #%d os state#%d\n",quant,state);
		switch(quant){
		case STAR:
			//printf("Found star\n");
			while(match(automata->states[state],str[i])){
				++i;
				if(str[i]=='\0' && state==automata->nStates-1){
					//printf("Input exhausted (at star)\n");
					return true;
				}
			}
			break;
		case PLUS:
			if(!match(automata->states[state],str[i])){
				return false;
			}
			while(match(automata->states[state],str[i])){
				++i;
				if(str[i]=='\0' && state==automata->nStates-1){
					//printf("Input exhausted(at plus)\n");
					return true;
				}
			}
			break;
		case NONE:
			//printf("No quantifier found\n");
			if(match(automata->states[state],str[i]) && state<=automata->nStates-1){
				//printf("Match found\n");
				++i;
				//printf("Moving to next input\n");
			}else{
				//printf("No match found. Returning\n");
				return false;
			}
			break;
		case OR:
			//printf("Found or\n");
			if(match(automata->states[state],str[i])){
				i++;
				//printf("Conditional match successful\n");
				do{
					state++;
					//printf("Moving to next state #%d\n",state);
					if(state==automata->nStates-1) return true;
				}while(automata->quants[state]!=OR);
			}
			break;
		}
	}
	if(len==0 && quant==STAR)return true;
	return false;
}
bool matchRegex(char *regex , char *str){
	return checkDFA(createDFA(regex),str);
}




















