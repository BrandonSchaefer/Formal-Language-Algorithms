#include "finStateIO.h"
#include "lib.h"

void alg5_6(char* pathIn, char* pathOut);
void removeNonDeterminism(std::set<char*>* finiteState);
char* getY(char* letter, std::set<char*> statesX, std::set<char*>* finiteState);
bool noArc(std::set<char*> states, std::set<char*>* finiteState);
bool transitionExist(char* state, char* letter, std::set<char*> transitions);

std::set<char*> inputTransitionFunction(char* state, char* letter, std::set<char*>* finiteState);
std::set<char*> lambdaClosure(char* tran, std::set<char*> transitions);
std::set<char*> canReachLetter(char* letter, std::set<char*> reach, std::set<char*> transitions);

using namespace std;
int main(){

	alg5_6("dfa.txt", "dfaOut.txt");

}





void alg5_6(char* pathIn, char* pathOut){

	set<char*> finiteState[4];
	parseFiniteState(pathIn, finiteState);
	
	removeNonDeterminism(finiteState);

	vector<char*> split;
	set<char*> tmp;	

	vector<char*>::iterator itVec;

	set<char*>::iterator itState;
	set<char*>::iterator itAlph;

	//displaySet(lambdaClosure("q0", finiteState[TRANSITIONS]));
/*
	for( itState = finiteState[STATES].begin(); itState != finiteState[STATES].end(); itState++){
		for( itAlph = finiteState[ALPHABET].begin(); itAlph != finiteState[ALPHABET].end(); itAlph++){
			displaySet(inputTransitionFunction(*itState, *itAlph, finiteState));
			cout << "--" << *itAlph << endl;
		}	
		cout << "####" << *itState << endl;
	}
*/
}







void removeNonDeterminism(std::set<char*>* finiteState){

	set<char*> Q = lambdaClosure("q0", finiteState[TRANSITIONS]);
	set<char*> statesX;
	set<char*>::iterator X = Q.begin();
	set<char*>::iterator itAlph;
	char* Y;
	bool done = false;


	do{
		if( noArc(Q, finiteState) && X != Q.end()){
			statesX = parseStateString(*X);
			for(itAlph = finiteState[ALPHABET].begin(); itAlph != finiteState[ALPHABET].end(); itAlph++){
				Y = getY(*itAlph, statesX, finiteState);
				cout << "########## " << Y << " ########" << endl;
				cout << *X << "--" << *itAlph << endl;
				insertIntoSet(Q, Y);
			}

			X++;
			
		}
		else{
			done = true;
		}
		
	}while(!done);

	displaySet(Q);
}



char* getY( char* letter, set<char*> statesX, set<char*>* finiteState){

	set<char*> Y;
	set<char*>::iterator itState;
	char* statesY;

	for( itState = statesX.begin(); itState != statesX.end(); itState++){
		unionSet(Y, inputTransitionFunction(*itState, letter, finiteState));
	}	

	return convertSetToString(Y);
}

// Returns true if it is not a DFA yet, hence that there is a state
// that does not have an arc for all the alphabet letters
bool noArc(set<char*> states,  set<char*>* finiteState){
	
	set<char*>::iterator itState;
	set<char*>::iterator itAlph;

	for( itState = states.begin(); itState != states.end(); itState++){
		for( itAlph = finiteState[ALPHABET].begin(); itAlph != finiteState[ALPHABET].end(); itAlph++){
			if(!transitionExist(*itState, *itAlph, finiteState[TRANSITIONS])){
				return true;
			}
		}
	}
	return false;
}

// Finds a trasition for the given state a letter, if none exist return false
bool transitionExist(char* state, char* letter, set<char*> transitions){
	vector<char*> splitTran;
	set<char*>::iterator itTran;
	

	for( itTran = transitions.begin(); itTran != transitions.end(); itTran++){
		splitTran = splitTransition(*itTran);
		if( strcmp(state, splitTran[0]) == 0 && strcmp(letter, splitTran[1]) == 0){
			return true;
		}
	}

	return false;


}
// ###################### Input Transition Function ##################################
/*

t(qi, a) = U lambdaClosure(d(qj,a)), qj (exist in) lambdaClosure(qi)

*/
set<char*> inputTransitionFunction(char* state, char* letter, set<char*>* finiteState){

	vector<char*> splitTran;
	set<char*> lambdaSet;
	set<char*> reachable;
	set<char*>::iterator itState;
		
	
	lambdaSet = lambdaClosure(state, finiteState[TRANSITIONS]);
		
	unionSet(reachable, canReachLetter(letter, lambdaSet, finiteState[TRANSITIONS]));
	
	return reachable;
}

// What qi can reach with out processing any chars
// Lambda Closure
set<char*> lambdaClosure(char* state, set<char*> transitions){
	
	vector<char*> splitTran;
	set<char*>::iterator itTran;	
	set<char*> reachable;
	char* newState;
	int size;
	
	reachable.insert(state);

	for( itTran = transitions.begin(); itTran != transitions.end(); itTran++){
		splitTran = splitTransition(*itTran);
		if( strcmp(splitTran[1], NULL_CHAR) == 0 && strcmp(state, splitTran[0]) == 0){
			unionSet(reachable, lambdaClosure(splitTran[2], transitions));
		}
	}
	
	return reachable;
}

set<char*> canReachLetter(char* letter, set<char*> lambdaSet, set<char*> transitions){
	
	vector<char*> splitTran;
	set<char*> reachable;
	set<char*>::iterator itTran;
	set<char*>::iterator itReach;
	char* newState;
	int size;

	for( itReach = lambdaSet.begin(); itReach != lambdaSet.end(); itReach++){
		for( itTran = transitions.begin(); itTran != transitions.end(); itTran++){
			splitTran = splitTransition(*itTran);
			
			// U lambdaClosure(d(state, letter)), state (exist in) lambdaClosure of qi
			if(strcmp(*itReach, splitTran[0]) == 0 && strcmp(letter, splitTran[1]) == 0){
				unionSet(reachable, lambdaClosure(splitTran[2], transitions));
			}
		}		
	}
	
	return reachable;
}
