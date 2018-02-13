#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

bool Start_Game = false;
bool keep_playing = true;
bool player_bust = false;
bool dealer_bust = false;
bool player_stay = false;
bool dealer_stay = false;
bool Dealer_turn = false;
bool Run_Eval = false;
int player_total = 0;
int dealer_total = 0;


int Player_hand(int Player_Start){
		
	if(Player_Start == 1){ 
		char stay_hit = 'a';
		char yes_no = 'a';
				
			cout << "your first cards are ";
			
				int player_first_card = rand() % 13 + 1;
				
				if (player_first_card == 10){
					cout << "J";
					player_first_card = 10;
				}
				if (player_first_card == 11){
					cout << "Q";
					player_first_card = 10;
				}
				if (player_first_card == 12){
					cout << "K";
					player_first_card = 10;
				}
				if ((player_first_card == 13) || (player_first_card == 1)){
					cout << "A";
					player_first_card = 11;
				}
				if ((player_first_card <= 9) && (player_first_card >= 2)){
					cout << player_first_card;
				}
				
				cout <<" and ";
				
				int player_second_card = rand() % 13 + 1;
				
				if (player_second_card == 10){
					cout << "J";
					player_second_card = 10;
				}
				if (player_second_card == 11){
					cout << "Q";
					player_second_card = 10;
				}
				if (player_second_card == 12){
					cout << "K";
					player_second_card = 10;
				}
				if ((player_second_card == 13) || (player_second_card == 1)){
					cout << "A";
					player_second_card = 11;
				}
				if ((player_second_card <= 9) && (player_second_card >= 2)){
					cout << player_second_card;
				}
				
			player_total = player_first_card + player_second_card;
				
				if ((player_total > 21) && (player_first_card == 11)){
					player_first_card = 1;
					
				}
				if ((player_total > 21) && (player_second_card == 11)){
					player_second_card = 1;
					
				}
			player_total = player_first_card + player_second_card;
			cout << " for a total of: " << player_total << endl;
			
		
		while ((player_stay == false) && (player_bust == false)) {
					cout << "Do you want to stay or hit? (s or h)" << endl;
					cin >> stay_hit;
					
					
					
					if (stay_hit == 'h'){
						cout << "You chose to hit your new card is a "; 
						
						int player_hit = rand() % 13 + 1;
						
						if (player_hit == 10){
							cout << "J";
							player_hit = 10;
						}
						if (player_hit == 11){
							cout << "Q";
							player_hit = 10;
						}
						if (player_hit == 12){
							cout << "K";
							player_hit = 10;
						}
						if ((player_hit == 13) || (player_hit == 1)){
							cout << "A";
							int player_hit_test = 11;
							
							int player_total_test = player_total + player_hit_test;
							if (player_total_test > 21){
								player_hit = 1;
							}
							if (player_total_test <= 21){
								player_hit = 11;
							}
						}
											
						if ((player_hit <= 9) && (player_hit >= 2)){
							cout << player_hit;
						}
						cout << endl;
						
						player_total = player_total + player_hit;
						if (player_total <= 21){
							cout << " for a new total of " << player_total << endl;
						}
						if (player_total > 21){
							cout << "You bust!!!" << endl;
							player_bust = true;
							cout << "Would you like to play again? (y or n)" << endl;
							cin >> yes_no;
						}
						
					}
					
					
					if (stay_hit == 's'){
						cout << "You chose to stay. Dealer's turn. " << endl;
						player_stay = true;
					}
					if (player_total == 21){
						cout << "Blackjack!!! YOU WIN!!!" << endl;
						player_bust = true;
						cout << "Would you like to play again? (y or n)" << endl;
						cin >> yes_no;
					}
					if (yes_no == 'n'){
						keep_playing = false;
					}
					if (yes_no == 'y'){
						keep_playing = true;
					}
					
		}
			if ((player_stay == true) && (player_bust == false)) {
				Dealer_turn = true;
			}
	}		
}


int Dealer_hand(int Dealer_Start){
	
	
	
	if (Dealer_Start == 1){
		char yes_no = 'a';
		
		cout << "Dealer's first cards are ";
		while ((dealer_stay == false) && (dealer_bust == false)){	
				int dealer_first_card = rand() % 13 + 1;
				
				if (dealer_first_card == 10){
					cout << "J";
					dealer_first_card = 10;
				}
				if (dealer_first_card == 11){
					cout << "Q";
					dealer_first_card = 10;
				}
				if (dealer_first_card == 12){
					cout << "K";
					dealer_first_card = 10;
				}
				if ((dealer_first_card == 13) || (dealer_first_card == 1)){
					cout << "A";
					dealer_first_card = 11;
				}
				if ((dealer_first_card <= 9) && (dealer_first_card >= 2)){
					cout << dealer_first_card;
				}
				
				cout <<" and ";
				
				int dealer_second_card = rand() % 13 + 1;
				
				if (dealer_second_card == 10){
					cout << "J";
					dealer_second_card = 10;
				}
				if (dealer_second_card == 11){
					cout << "Q";
					dealer_second_card = 10;
				}
				if (dealer_second_card == 12){
					cout << "K";
					dealer_second_card = 10;
				}
				if ((dealer_second_card == 13) || (dealer_second_card == 1)){
					cout << "A";
					dealer_second_card = 11;
				}
				if ((dealer_second_card <= 9) && (dealer_second_card >= 2)){
					cout << dealer_second_card;
				}
				
			dealer_total = dealer_first_card + dealer_second_card;
				
				if ((dealer_total > 21) && (dealer_first_card == 11)){
					dealer_first_card = 1;
					
				}
				if ((dealer_total > 21) && (dealer_second_card == 11)){
					dealer_second_card = 1;
					
				}
			dealer_total = dealer_first_card + dealer_second_card;
			cout << " for a total of: " << dealer_total << endl;
			
		
				while (dealer_total <= 16){
						
					cout << "Dealer hits dealer's next card is a ";
						
					int dealer_hit = rand() % 13 + 1;
						if (dealer_hit == 10){
							cout << "J";
							dealer_hit = 10;
						}
						if (dealer_hit == 11){
							cout << "Q";
							dealer_hit = 10;
						}
						if (dealer_hit == 12){
							cout << "K";
							dealer_hit = 10;
						}
						if ((dealer_hit == 13) || (dealer_hit == 1)){
							cout << "A";
							int dealer_hit_test = 11;
							
							int dealer_total_test = dealer_total + dealer_hit_test;
							if (dealer_total_test > 21){
								dealer_hit = 1;
							}
							if (dealer_total_test <= 21){
								dealer_hit = 11;
							}
						}
						if ((dealer_hit <= 9) && (dealer_hit >= 2)){
							cout << dealer_hit;
						}
					 cout << endl;
					dealer_total = dealer_total + dealer_hit;
					cout << " for a new total of " << dealer_total << endl;
				}
				if(dealer_total > 21){
					cout << "Dealer busts YOU WIN!!!"<< endl;
					dealer_bust = true;
					cout << "Would you like to play again? (y or n)" << endl;
					cin >> yes_no;
				}
				if (dealer_total >= 17){
					cout << "Dealer Stays." << endl;
					dealer_stay = true;
				}
				if (yes_no == 'n'){
					keep_playing = false;
				}
				if (yes_no == 'y'){
					keep_playing = true;
				}	
					
		}	
			
	}		
}

int Evaluation(int Eval){
	
	char yes_no = 'a';
	
	
		if (Eval == 1){
				cout << "Your total is: " << player_total << endl;
				cout << "The Dealer's total is: " << dealer_total << endl;
				if (player_total <= dealer_total){
					cout << "DEALER WINS!!!" << endl;
					cout << "Would you like to play again? y or n" << endl;
					cin >> yes_no;
				}
				if (player_total > dealer_total){
					cout << "!!!YOU WIN!!!" << endl;
					cout << "Would you like to play again? y or n" << endl;
					cin >> yes_no;
				}
			
			if (yes_no == 'n'){
				keep_playing = false;
			}
			if (yes_no == 'y'){
				keep_playing = true;
			}
			
		}
}


int main() {
	
	while (keep_playing) {
		
		srand(time(NULL));
		
		
		
		
		int Eval = 1;
		int Player_Start = 1;
		int Dealer_Start = 1;
		char Start = 'a';
				
		cout << "WOULD YOU LIKE TO PLAY A GAME? y or n" << endl;
		cin >> Start;
		
		player_bust = false;
		dealer_bust = false;
		player_stay = false;
		dealer_stay = false;
		Dealer_turn = false;
		Run_Eval = false;
		
		if (Start == 'y'){
			Start_Game = true;
		}
		if (Start == 'n'){
			keep_playing = false;
		}
		
		if (Start_Game == true){
			Player_hand(Player_Start);
		}
		
		if (Dealer_turn == true){	
			Dealer_hand(Dealer_Start);
		}
		if ((dealer_stay == true) && (dealer_bust == false)) {
			Evaluation(Eval);
		}
								
	}
	
	return 0;
}