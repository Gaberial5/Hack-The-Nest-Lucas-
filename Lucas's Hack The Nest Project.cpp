/*
Lucas.C
12/9/2023
Programing 1 
Period 8
*/

#include<iostream>

#include<string>

#include<ctime>

#include<math.h>

using namespace std;

const double quarter = 0.25; 

int main(){
	
	// "srand(time(0));" seeds the random number with how much time has passed in miliseconds (since 1980 or something) currently is which will be random
	srand(time(0));
	int EndProgram;
	int numOfGuesses;
	int guess;
	int map[] = {0,0,0,0,0,0,0,0,0,0};
	int Npc;
	int RPSInput;
	int slots[3];
	int playAgainInput1;
	double roundWinnings = 0;
	double balance = 2.00;
	double numberOfRounds = 1.00;
	double numberOfWins = 0.00;
	
	do{
		cout << "What game do you want to play?" << endl << "1)treasure Island" << endl << "2)Rock Paper scissors" << endl << "3)Slot machine" << endl << "4)Quit" << endl;
		cin >> EndProgram;
		cout << endl << endl;
		
		if(EndProgram == 1){
			
			do{
	
				for(int i = 0; i<3; i++){
					map[rand()%10] = 9;
				}
				numOfGuesses = 3;
		
				for(int i = numOfGuesses; i>0; i--){
				
					cout << "Guess where the treasure is in your map of locations 0-9!" << endl;
					cout << "Matey!!! You have " << i << " guesses remaining" << endl;
					numOfGuesses--;
					cout << "Enter guess: " ;
					cin >> guess ;
			
					if(map[guess] == 9){
						cout << "You found a treasure!" << endl << endl;
					}
					else{
						cout << "Nope!" << endl << endl;
					}
			
					while (guess>9 || guess<0){
						cout << "Enter guess: " ;
						cin >> guess;
					}

				}
				cout << "The map revealed: ( nines represent treasure )" << endl;
				cout << "[" << map[0] << "]" << "[" << map[1] << "]" << "[" << map[2] << "]" << "[" << map[3] << "]" << "[" << map[4] << "]" << "[" << map[5] << "]" << "[" << map[6] << "]" << "[" << map[7] << "]" << "[" << map[8] << "]" << "[" << map[9] << "]" << endl;                                                                           
				cout << "Play again? 1-yes / 2-no "; 
				cin >> playAgainInput1;
				cout << endl << endl;
			}while(playAgainInput1 != 2);	
		}
		
		if(EndProgram == 2){
			
			cout << "Welcome to rock paper scissors against a bot" << endl << endl;
			
			do{
				cout << "Enter 1 for Rock , 2 for paper , 3 for Scissors";
				cin >> RPSInput;
				cout << endl << endl;
				Npc = (rand()%3 + 1);
			
				if(RPSInput == 1 && Npc == 2){
					cout << "You played Rock and the bot played Paper. You lost!" << endl << endl;
				}
				else if(RPSInput == 1 && Npc == 3){
					cout << "You played Rock and the bot played Scissors. You won!" << endl << endl;
				}
				else if(RPSInput == 1 && Npc == 1){
					cout << "You and the bot both played Rock. Draw!" << endl << endl;
				}
				else if(RPSInput == 2 && Npc == 1){
					cout << "You played Paper and the bot played Rock. You won!" << endl << endl;
				}
				else if(RPSInput == 2 && Npc == 2){
					cout << "You and the bot both played Paper. Draw!" << endl << endl;
				}
				else if(RPSInput == 2 && Npc == 3){
					cout << "You played Paper and the bot played Scissors. You lost!" << endl << endl;
				}
				else if(RPSInput == 3 && Npc == 1){
					cout << "You played Scissors and the bot played Rock. You lost! " << endl << endl;
				}
				else if(RPSInput == 3 && Npc == 2){
					cout << "You played Scissors and the bot played paper. You Won!" << endl << endl;
				}
				else if(RPSInput == 3 && Npc == 3){
					cout << "You and the both played Scissors. Draw!" << endl << endl;
				}
				else{
					cout << "You must've misInputed your choice please play again and enter one of the possible options." << endl << endl;
				}
				cout << "Play again? 1-yes / 2-no "; 
				cin >> playAgainInput1;
				cout << endl << endl;
			
			}while(playAgainInput1 !=2);	
			
			
		}
		
		if(EndProgram == 3){
				
			do{	
				cout << "insert your quarter! (Hit Enter)" << endl << endl;
				cin.get();
				roundWinnings = 0.00;
		
				balance -= quarter; 
		
				if(balance !=0){

					for(int i = 0 ; i < 3; i++){
						slots[i] = rand()%10;
					}
		
					cout << "****SLOTS****" << endl ; 
					cout << "| " << slots[0] << " | " << slots[1] << " | " << slots[2] << " |"<< endl;
					cout << "*************" << endl << endl;
		
		
	
				if((slots[0] == slots[1] && slots[0] == slots[2] && slots[1] == slots[3]) && slots[0] == 0){
					balance += 100;
					roundWinnings = 100;
					numberOfWins++;
				}
			
				else if(slots[0] == slots[1] && slots[0] == slots[2] && slots[1] == slots[3]){
					balance += (slots[0*3]);
					roundWinnings = (slots[0*3]);
					numberOfWins++;		
				}
		
				else if((slots[0] == slots[1] || slots[0] == slots[2] || slots[1] == slots[2]) && (slots[0] == 0 || slots[1] == 0 || slots[2] == 0  ) && !(slots[0] == 0 && slots[1] == 0 || slots[0] == 0 && slots[2] == 0 || slots[1] == 0 && slots[2] == 0)){                                                         
					balance += (slots[0] + slots[1]);
					roundWinnings = (slots[0] + slots[1] + slots[2] + 20);
					numberOfWins++;
				}
		
				else if((slots[0] == slots[1]) && (slots[0] != slots[2]) && (slots[0] != 0 || slots[1] != 0 || slots[2] != 0)){
					balance += (slots[0] + slots[1]);
					roundWinnings = (slots[0] + slots[1]);
					numberOfWins++;
				}
					
				else if((slots[0] == slots[2]) && (slots[0] != slots[1]) && (slots[0] != 0 || slots[1] != 0 || slots[2] != 0)){
					balance += (slots[0] + slots[2]);
					roundWinnings = (slots[0] + slots[2]);
					numberOfWins++;
				}
		
				else if((slots[1] == slots[2]) && (slots[1] != slots[0]) && (slots[0] != 0 || slots[1] != 0 || slots[2] != 0)){
					balance += (slots[1] + slots[2]);
					roundWinnings = (slots[1] + slots[2]);
					numberOfWins++;
				}

					cout << "amount won this round: " << roundWinnings << endl;
					cout << "you've won " << numberOfWins/numberOfRounds << "% of the time" << endl;
					cout << "You now have " << balance << endl << endl;
			
					cout << "play again? 1-yes, 2-no: " ;
					cin >> playAgainInput1;
					cout << endl << endl << endl;
					cin.ignore();
				}
				else if(balance == 0){
					cout << "You've run out of money" << endl << endl;
				}
				numberOfRounds++;
		}while(playAgainInput1 != 2);
			
		
	}
	
}while(EndProgram !=4);
	
	
	
	
	return 0;
}
