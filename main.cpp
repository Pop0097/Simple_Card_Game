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

	makeDeck(); //makes the deck of cards
	shuffleDeck(); //shuffles the deck
	dealHands(); //deals a hand to each player
	displayHands(); //displays the hands for all the players to see

	//determines each player's hand
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
	}
	else if(playerScore[1] > playerScore[0] && playerScore[1] > playerScore[2]){
		cout << "Player 2 Wins!" << endl;
	}
	else if(playerScore[2] > playerScore[1] && playerScore[2] > playerScore[0]){
		cout << "Player 3 Wins!" << endl;
	}
	else if(playerScore[0] == playerScore[1] && playerScore[0] > playerScore[2]){
		cout << "Player 1 and Player 2 are tied!" << endl;
	}
	else if(playerScore[0] > playerScore[1] && playerScore[0] == playerScore[2]){
		cout << "Player 1 and Player 3 are tied!" << endl;
	}
	else if(playerScore[1] == playerScore[2] && playerScore[2] > playerScore[0]){
		cout << "Player 2 and Player 3 are tied!" << endl;
	}
	else if(playerScore[0] == playerScore[1] && playerScore[0] == playerScore[2]){
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

	for(int i = 0; i < 15; i++){ //deals fifteen cards (five to each player)
		size_t spaceIndex = cards[i].find(" ");
		faceIndex = spaceIndex;
		suitIndex = spaceIndex + 1;
		face = cards[i].substr(0, faceIndex);
		suit = cards[i].substr(suitIndex);
		j = i + 1;
		//depending on the value of the counter j, different players recieve the current card.
		if(j%3 == 0){ //if the counter is a multiple of 3, the dealer gives a card to Player 3
			hand3[k][0] = face;
			hand3[k][1] = suit;
			k++;
		}
		else if(j%2 == 0 && j != 6 && j != 12){ //if the counter is a multiple of 2, but not a multiple of 3. the dealer gives a card to Player 2
			hand2[l][0] = face;
			hand2[l][1] = suit;
			l++;
		}
		else{ //if the counter is not a multiple of 2 or 3, then the dealer gives a card to Player 1
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
	string faces[5];

	//creates the hands. handNumber is the player whose hand is being identified
	for(int i = 0; i < 5; i++){
		if(handNumber == 0){ //player 1
			suits[i] = hand1[i][1];
			faces[i] = hand1[i][0];
		}
		else if(handNumber == 1){ //player 2
			suits[i] = hand2[i][1];
			faces[i] = hand2[i][0];
		}
		else{ //player 3
			suits[i] = hand3[i][1];
			faces[i] = hand3[i][0];
		}
	}
	//Checks the faces that are present
	int facePresence[13]; //each element represents one face in the deck
	for(int i = 0; i < 13; i++){ //initialize all indeces in the array
		facePresence[i] = 0;
	}

	//checks the presence of each face in the player's hand
	for(int i = 0; i < 5; i++){
		if(faces[i] == "Deuce"){
			facePresence[0]++;
		}
		else if(faces[i] == "Three"){
			facePresence[1]++;
		}
		else if(faces[i] == "Four"){
			facePresence[2]++;
		}
		else if(faces[i] == "Five"){
			facePresence[3]++;
		}
		else if(faces[i] == "Six"){
			facePresence[4]++;
		}
		else if(faces[i] == "Seven"){
			facePresence[5]++;
		}
		else if(faces[i] == "Eight"){
			facePresence[6]++;
		}
		else if(faces[i] == "Nine"){
			facePresence[7]++;
		}
		else if(faces[i] == "Ten"){
			facePresence[8]++;
		}
		else if(faces[i] == "Jack"){
			facePresence[9]++;
		}
		else if(faces[i] == "Queen"){
			facePresence[10]++;
		}
		else if(faces[i] == "King"){
			facePresence[11]++;
		}
		else {
			facePresence[12]++;
		}
	}

	//checks if faces are in ascending order (this is useful for identifying hands such as the Royal Flush)
	bool ascendingOrder = false;
	for(int i = 0; i < 9; i++){
		if(facePresence[i] > 0){
			if(facePresence[i+1] > 0 && facePresence[i+2] > 0 && facePresence[i+3] > 0 && facePresence[i+4] > 0){
				ascendingOrder = true;
			}
		}
	}

	int pairs = 0, three = 0, four = 0;	//Checks if there are pairs, three of a kind or four of a kind.
	//these variables represent the face of the cards that are in pairs, etc.
  int doubleCard = 0;
	int tripleCard = 0;
	int quadrupleCard = 0;

	for(int i = 0; i < 13; i++){
		if(facePresence[i] == 2){
			pairs++;
			doubleCard = i;
		}
		else if(facePresence[i] == 3){
			three++;
			tripleCard = i;
		}
		else if(facePresence[i] == 4){
			four++;
			quadrupleCard = i;
		}
	}

  int highCard = 0;
  //checks for the high Card only if the player has no pairs, three of a kind, or four of a kinds.
	if(pairs == 0 && three == 0 && four == 0){
		bool found = false;
		int counter = 12;
		while(!found){
			if(facePresence[counter] > 0){
				highCard = counter;
				found = true;
			}
			counter--;
		}
	}

	int suitPresence[4];
	for(int i = 0; i < 4; i++){
		suitPresence[i] = 0;
	}

  //checks the presence of each suit in the player's hand
  for(int i = 0; i < 5; i++){
		if(suits[i] == "Spades"){
			suitPresence[0]++;
		}
		else if(suits[i] == "Hearts"){
			suitPresence[1]++;
		}
		else if(suits[i] == "Diamonds"){
			suitPresence[2]++;
		}
		else {
			suitPresence[3]++;
		}
	}

	//checks if all suits in the hand are the same
	bool fiveOfSameSuit = false;
	for(int i = 0; i < 4; i++){
		if(suitPresence[i] == 5){
			fiveOfSameSuit = true;
		}
	}

	/*
	 * The following code determines the player's hand and assigns them a score.
	 * The scores take both the hand and face of the cards into account (the latter is done to resolve ties)
	 * How scores are calculated:
	 *      - each hand has a base score
	 *      - Depending on the face of the card that is associated with the hand, additional bonus points are added
	 *           - Deuce has the smallest bonus [+0 points to the base score of the hand] and Ace has the highest bonus [+12 points to the base score of the hand]
	 */
	string hand = "";
	if(fiveOfSameSuit == true){
		if(facePresence[12] == 1 && ascendingOrder == true){ //Royal Flush
			score = 106;
			hand = "Royal Flush";
		}
		else if(ascendingOrder == true && facePresence[12] == 0){ //Straight Flush
			score = 98 + highCard - 4; //room for 8 if need to diffrentiate
			hand = "Straight Flush";
		}
		else if(ascendingOrder == false){ //Flush
			score = 60 + highCard;
			hand = "Flush";
		}
	}
	else{
		if(four == 1){ //Four of a Kind
			score = 85 + quadrupleCard;
			hand = "Four of a Kind";
		}
		else if(three == 1 && pairs == 1){ //Full House
			if(tripleCard < doubleCard){
				score = 73 + doubleCard;
			}
			else{
				score = 73 + tripleCard;
			}
			hand = "Full House";
		}
		else if(ascendingOrder == true){ //Straight
			score = 51 + highCard - 4;
			hand = "Straight";
		}
		else if(three == 1 && pairs == 0){//Three of a Kind
			score = 38 + tripleCard;
			hand = "Three of a Kind";
		}
		else if(pairs == 2){ //Two Pair
			score = 26 + doubleCard;
			hand = "Two Pair";
		}
		else if(pairs == 1 && three == 0){//Pair
			score = 13 + doubleCard;
			hand = "Pair";
		}
		else{//High Card
			score = highCard;
			hand = "High Card";
		}
	}

	//prints the player's hand
	cout << endl;
	cout << "Player " << (handNumber + 1) << " Hand: " << hand << endl;

	return score; //returns the score so the winner can be determined in main()
}
