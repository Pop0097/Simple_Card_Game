#include <iostream>
#include <string>

using namespace std;

string faces[] = {"Ace", "Deuce", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King" };
string suits[] = {"Hearts", "Diamonds", "Clubs", "Spades"};
string cards[52];
string hand1[5][2];
string hand2[5][2];
string hand3[5][2];

void makeDeck();
void shuffleDeck();
void dealHands();
void displayHands();
int determineHand(int handNumber);

int main() {

	makeDeck(); //makes deck
	shuffleDeck(); //shuffles deck
	dealHands(); //deals hands to each player
	displayHands(); //prints hands for all the players to see

	//determines hand of each player
	int handNum = 0;
	int playerScore[3];
	playerScore[0] = determineHand(handNum);
	handNum++;
	playerScore[1] = determineHand(handNum);
	handNum++;
	playerScore[2] = determineHand(handNum);

	//Determines winner
	cout << endl;
	if(playerScore[0] > playerScore[1] && playerScore[0] > playerScore[2]){

		cout << "Player 1 Wins!" << endl;

	} else if(playerScore[1] > playerScore[0] && playerScore[1] > playerScore[2]){

		cout << "Player 2 Wins!" << endl;

	} else if(playerScore[2] > playerScore[1] && playerScore[2] > playerScore[0]){

		cout << "Player 3 Wins!" << endl;

	} else if(playerScore[0] == playerScore[1] && playerScore[0] > playerScore[2]){

		cout << "Player 1 and Player 2 are tied!" << endl;

	} else if(playerScore[0] > playerScore[1] && playerScore[0] == playerScore[2]){

		cout << "Player 1 and Player 3 are tied!" << endl;

	} else if(playerScore[1] == playerScore[2] && playerScore[2] > playerScore[0]){

		cout << "Player 2 and Player 3 are tied!" << endl;

	} else if(playerScore[0] == playerScore[1] && playerScore[0] == playerScore[2]){

		cout << "Everyone tied!" << endl;

	}

	return 0;
}

void makeDeck(){

	int j = 0, k = 0, counter = 0;
	for (int i = 0; i < 52; i++) {

		counter++;
		cards[i] = faces[j] + " " + suits[k]; //concatenates strings to make cards
		k++; //k is increased so that the face has all possible suits

		if(counter%4 == 0) { //once four cards are created...

			j++; //j increases so that a new face can be made
			k = 0; //k is zeroed so that the new face will have all possible suits.

		}
	}
}

void shuffleDeck(){

	int card1, card2;
	string temporary = "";
	srand(time(0));
	for(int i = 0; i<=52; i++) { //cards will be switched 52 times

		card1 = 0 + (rand()%51);
		card2 = 0 + (rand()%51);
		temporary = cards[card1];
		cards[card1] = cards[card2];
		cards[card2] = temporary;

	}
}

void dealHands(){

	int j = 0, k = 0, l = 0, m = 0, faceIndex = 0, suitIndex = 0;

	string face = "";
	string suit = "";
	for(int i = 0; i < 15; i++){ //deals fifteen cards, five to each player. Deals to player 1 first, then player 2, then player 3.

		size_t spaceIndex = cards[i].find(" ");
		faceIndex = spaceIndex;
		suitIndex = spaceIndex + 1;
		face = cards[i].substr(0, faceIndex);
		suit = cards[i].substr(suitIndex);
		j = i + 1;
		if(j%3 == 0){


			hand3[k][0] = face;
			hand3[k][1] = suit;
			k++;

		} else if(j%2 == 0 && j != 6 && j != 12){

			hand2[l][0] = face;
			hand2[l][1] = suit;
			l++;

		} else{

			hand1[m][0] = face;
			hand1[m][1] = suit;
			m++;

		}
	}
}

void displayHands(){

	cout << "Player 1 Hand:" << endl;
	for(int i = 0; i < 5; i++){

		cout << hand1[i][0] << " " << hand1[i][1] << endl;

	}
	cout << endl;
	cout << "Player 2 Hand:" << endl;
	for(int i = 0; i < 5; i++){

		cout << hand2[i][0] << " " << hand2[i][1] << endl;

	}
	cout << endl;
	cout << "Player 3 Hand:" << endl;

	for(int i = 0; i < 5; i++){

		cout << hand3[i][0] << " " << hand3[i][1] << endl;

	}
}

int determineHand(int handNumber){

	int score = 0;
	string suits[5];
		//suits[0] = "Spades";suits[1] = "Spades";suits[2] = "Hearts";suits[3] = "Spades";suits[4] = "Spades";
	string faces[5];
		//faces[0] = "Ten";faces[1] = "Nine";faces[2] = "King";faces[3] = "Ace";faces[4] = "Ace";

	for(int i = 0; i < 5; i++){
		if(handNumber == 0){

			suits[i] = hand1[i][1];
			faces[i] = hand1[i][0];

		} else if(handNumber == 1){

			suits[i] = hand2[i][1];
			faces[i] = hand2[i][0];

		} else{

			suits[i] = hand3[i][1];
			faces[i] = hand3[i][0];

		}
	}


	//Checks the faces that are present
	int facePresence[13];
	for(int i = 0; i < 13; i++){ //initialize all indeces in the array

		facePresence[i] = 0;

	}
	for(int i = 0; i < 5; i++){
		if(faces[i] == "Deuce"){

			facePresence[0]++;

		} else if(faces[i] == "Three"){

			facePresence[1]++;

		} else if(faces[i] == "Four"){

			facePresence[2]++;

		} else if(faces[i] == "Five"){

			facePresence[3]++;

		} else if(faces[i] == "Six"){

			facePresence[4]++;

		} else if(faces[i] == "Seven"){

			facePresence[5]++;

		} else if(faces[i] == "Eight"){

			facePresence[6]++;

		} else if(faces[i] == "Nine"){

			facePresence[7]++;

		} else if(faces[i] == "Ten"){

			facePresence[8]++;

		} else if(faces[i] == "Jack"){

			facePresence[9]++;

		} else if(faces[i] == "Queen"){

			facePresence[10]++;

		} else if(faces[i] == "King"){

			facePresence[11]++;

		} else {

			facePresence[12]++;

		}
	}

	//checks if faces are in ascending order
	bool ascendingOrder = false;
	for(int i = 0; i < 9; i++){
		if(facePresence[i] > 0){
			if(facePresence[i+1] > 0 && facePresence[i+2] > 0 && facePresence[i+3] > 0 && facePresence[i+4] > 0){

				ascendingOrder = true;

			}
		}
	}

	//Checks if there are pairs, three of a kind or four of a kind and which cards make the set.
	int pairs = 0, three = 0, four = 0;

	int doubleCard[3] = {0,0,0};
	int tripleCard[3] = {0,0,0};
	int quadrupleCard[3] = {0,0,0};
	int highCard[3] = {0,0,0};

	for(int i = 0; i < 13; i++){
		if(facePresence[i] == 2){

			pairs++;
			doubleCard[handNumber]= i; //stores the card that has the pair. If there are two pairs, pair with the best face is stored.

		} else if(facePresence[i] == 3){

			three++;
			tripleCard[handNumber] = i;//scores the card that has three occurrences

		} else if(facePresence[i] == 4){

			four++;
			quadrupleCard[handNumber] = i;//stores the card that has four occurrences

		}
	}

	//checks for the high Card
	if(pairs == 0 && three == 0 && four == 0){
		for(int i = 12; i > -1; i--){
			if(facePresence[i] > 0){

				highCard[handNumber] = i;
				break;

			}
		}
	}

	//Checks the suits that are present
	int suitPresence[4];
	for(int i = 0; i < 4; i++){

		suitPresence[i] = 0;

	}
	for(int i = 0; i < 5; i++){
		if(suits[i] == "Spades"){

			suitPresence[0]++;

		}else if(suits[i] == "Hearts"){

			suitPresence[1]++;

		}else if(suits[i] == "Diamonds"){

			suitPresence[2]++;

		}else {

			suitPresence[3]++;

		}
	}

	//checks if all suits are the same
	bool fiveOfSameSuit = false;
	for(int i = 0; i < 4; i++){
		if(suitPresence[i] == 5){

			fiveOfSameSuit = true;

		}
	}

	//Determining the hand present. Scores take the face of the cards into account in order to break ties. Deuce is the lowest (+0 to the base score of the hand) and Ace is the highest (+12 points to the base score of the hand).
	string hand = "";
	if(fiveOfSameSuit == true){
		if(facePresence[12] == 1 && ascendingOrder == true){ //Royal Flush

			score = 106;
			hand = "Royal Flush";

		} else if(ascendingOrder == true && facePresence[12] == 0){ //Straight Flush

			score = 98 + highCard[handNumber] - 4; //room for 8 if need to diffrentiate
			hand = "Straight Flush";

		} else if(ascendingOrder == false){ //Flush

			score = 60 + highCard[handNumber];
			hand = "Flush";

		}
	}else{
		if(four == 1){ //Four of a Kind

			score = 85 + quadrupleCard[handNumber];
			hand = "Four of a Kind";

		} else if(three == 1 && pairs == 1){ //Full House
			if(tripleCard[handNumber] < doubleCard[handNumber]){

				score = 73 + doubleCard[handNumber];

			} else{

				score = 73 + tripleCard[handNumber];

			}
			hand = "Full House";

		} else if(ascendingOrder == true){ //Straight

			score = 51 + highCard[handNumber] - 4;
			hand = "Straight";

		} else if(three == 1 && pairs == 0){//Three of a Kind

			score = 38 + tripleCard[handNumber];
			hand = "Three of a Kind";

		} else if(pairs == 2){ //Two Pair

			score = 26 + doubleCard[handNumber];
			hand = "Two Pair";

		} else if(pairs == 1 && three == 0){//Pair

			score = 13 + doubleCard[handNumber];
			hand = "Pair";

		}else{//High Card

			score = highCard[handNumber];
			hand = "High Card";

		}
	}

	cout << endl;
	cout << "Player " << (handNumber + 1) << " Hand: " << hand << endl;
	cout << "Player " << (handNumber + 1) << " Score: " << score << endl;

	return score;
}
