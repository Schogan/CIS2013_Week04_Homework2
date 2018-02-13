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
	/*bool player_stay = false;
	bool player_bust = false;
	bool Dealer_turn = false;
	bool keep_playing = false;*/

	
	if(Player_Start == 1){ 
		char stay_hit = 'a';
		char yes_no = 'a';
		int player_first_card = rand() % 10 + 1;
		int player_second_card = rand() % 10 + 1;
		
			cout << "your first cards are " << player_first_card <<" and " 
				<< player_second_card << endl;
			player_total = player_first_card + player_second_card;
			cout << " for a total of: " << player_total << endl;
			
		
		while ((player_stay == false) && (player_bust == false)) {
					cout << "Do you want to stay or hit? (s or h)" << endl;
					cin >> stay_hit;
					
					int player_hit = rand() % 10 + 1;
					
					if (stay_hit == 'h'){
						cout << "You chose to hit your new card is a " << player_hit << endl;
						player_total = player_total + player_hit;
						cout << " for a new total of " << player_total << endl;
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
				//Evaluation(player_total);
			}
	}		
}
int Dealer_hand(int Dealer_Start){
	/*bool dealer_stay = false;
	bool dealer_bust = false;
	bool keep_playing = false;*/
	int dealer_first_card = rand() % 10 + 1;
	int dealer_second_card = rand() % 10 + 1;
	//int dealer_total = 0;
	char yes_no = 'a';
	
	if (Dealer_Start == 1){
		cout << "The dealers first card is " << dealer_first_card << endl;
	
		while ((dealer_stay == false) && (dealer_bust == false)){
					
				cout << "Dealer's next card is " << dealer_second_card << endl;
				dealer_total = dealer_first_card + dealer_second_card;
				cout << "For a total of " << dealer_total << endl;
				while (dealer_total <= 16){
							
					int dealer_hit = rand() % 10 + 1;
							
					cout << "Dealer hits dealer's next card is a " << dealer_hit << endl;
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
	//int player_total = 0;
	//int dealer_total = 0;
	//int player_total = 0;
	//int dealer_total = 0;
	
		if (Eval == 1){
				cout << "Your total is: " << player_total << endl;
				cout << "The Dealer's total is: " << dealer_total << endl;
				if (player_total <= dealer_total){
					cout << "DEALER WINS!!!" << endl;
					cout << "Would you like to play again? y or n" << endl;
					cin >> yes_no;
					/*bool player_bust = false;
					bool dealer_bust = false;
					bool player_stay = false;
					bool dealer_stay = false;
					bool Dealer_turn = false;
					bool Run_Eval = false;
					//int player_total = 0;
					int dealer_total = 0;*/
					}
				if (player_total > dealer_total){
					cout << "!!!YOU WIN!!!" << endl;
					cout << "Would you like to play again? y or n" << endl;
					cin >> yes_no;
					/*bool player_bust = false;
					bool dealer_bust = false;
					bool player_stay = false;
					bool dealer_stay = false;
					bool Dealer_turn = false;
					bool Run_Eval = false;
					//int player_total = 0;
					int dealer_total = 0;*/
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
	
	/*bool keep_playing = true;
	bool player_bust = false;
	bool dealer_bust = false;
	bool Dealer_turn = false;*/
	while (keep_playing) {
		
		srand(time(NULL));
		
		
		
		//int player_total = 0;
		int Eval = 1;
		int Player_Start = 1;
		int Dealer_Start = 1;
		char Start = 'a';
				
		cout << "Would you like to play a game? y or n" << endl;
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
		//if ((player_bust == false) && (dealer_bust == false)){
			
		//}
		
		
						
	}
	
	return 0;
}