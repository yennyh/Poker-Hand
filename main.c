#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// constants for 2d arrays
#define SUITS 4
#define FACES 13
#define CARDS 52
#define HAND 5

// function prototypes
void shuffle(unsigned int deck[][FACES] );
// functions for the first hand only
void deal(unsigned int deck[][FACES], unsigned int hand[][2], char *suit[], char *face[]);
void highCard(unsigned int hand[][2], char *suit[], char *face[]);
void pair(unsigned int hand[][2], char *suit[], char *face[]);
void threeOfKind(unsigned int hand[][2], char *suit[], char *face[]);
void fourOfKind(unsigned int hand[][2], char *suit[], char *face[]);
void straightHand(unsigned int hand[][2], char *suit[], char *face[]);
void flushHand(unsigned int hand[][2], char *suit[], char *face[]);
// functions for the second hand only, separate b/c dealing with
// different positions of the 2d arrays, easier to handle and compare
void deal2(unsigned int deck[][FACES], unsigned int hand2 [][2], char *suit[], char *face[]);
void highCard2(unsigned int hand[][2], char *suit[], char *face[]);
void pair2(unsigned int hand[][2], char *suit[], char *face[]);
void threeOfKind2(unsigned int hand[][2], char *suit[], char *face[]);
void fourOfKind2(unsigned int hand[][2], char *suit[], char *face[]);
void straightHand2(unsigned int hand[][2], char *suit[], char *face[]);
void flushHand2(unsigned int hand[][2], char *suit[], char *face[]);
void emptyDeck(unsigned int deck[][FACES]);

// global variables to keep track of what kinds the hand has
int count;
int count2;

int main( void ){
    char *suit[SUITS] = { "Hearts", "Diamonds", "Clubs", "Spades" };
    char *face[FACES] ={ "Ace", "Deuce", "Three", "Four",
        "Five", "Six", "Seven", "Eight",
        "Nine", "Ten", "Jack", "Queen", "King" }; // assumes the largest card is King
    
    unsigned int deck[SUITS][FACES] = {0}; // represents deck of cards
    unsigned int hand[5][2]; // represents the first hand
    unsigned int hand2[5][2]; //represents the second hand
    srand(time(NULL)); // randomizes the shuffling
    
    // if only deals a five-card poker hand
//    for (int i = 0; i < 100; i++){
//        shuffle(deck);
//        deal(deck, hand, suit, face);
//        pair(hand, suit, face);
//        threeOfKind(hand, suit, face);
//        fourOfKind(hand, suit, face);
//        flushHand(hand, suit, face);
//        straightHand(hand, suit, face);
//        if (count == 0){
//            highCard(hand, suit, face);
//        }
//        emptyDeck(deck);
//        count = 0;
//        puts("------------------------------------------------");
//    }
    
    // if deals two five-card poker hands, evaluates each, and
    // determines which is the better hand
    for (int i = 0; i < 100; i++){
        // shuffles only once each time
        shuffle(deck);
        // deal and analyze the first hand
        deal(deck, hand, suit, face);
        pair(hand, suit, face);
        threeOfKind(hand, suit, face);
        fourOfKind(hand, suit, face);
        flushHand(hand, suit, face);
        straightHand(hand, suit, face);
        // if has nothing else, high card will determine the hand
        if (count == 0){
            highCard(hand, suit, face);
        }
        puts("");
        // deal and analyze the second hand
        deal2(deck, hand2, suit, face);
        pair2(hand2, suit, face);
        threeOfKind2(hand2, suit, face);
        fourOfKind2(hand2, suit, face);
        flushHand2(hand2, suit, face);
        straightHand2(hand2, suit, face);
        // if has nothing else, high card will determine the hand
        if (count2 == 0){
            highCard2(hand2, suit, face);
        }
        // empty the deck each time for re-shufffling
        emptyDeck(deck);
        puts("");
        
        // determine which hand is better
        if (count > count2){
            printf("The first hand has a better hand.\n");
        }
        else if (count2 > count){
            printf("The second hand has a better hand.\n");
        }
        else {
            printf("Same kind for both hands, the higher hand wins.\n");
        }
        // reset both counts to compare both hands again
        count = 0;
        count2 = 0;
        puts("------------------------------------------------");
    }
}

// shuffle cards in deck, only shuffle one time for each deck
void shuffle(unsigned int deck[][FACES]){
    int row;
    int col;
    // fill up empty deck with random cards
    for (int card = 1; card <= CARDS; card++ ){
        do{
            row = rand() % SUITS;
            col = rand() % FACES;
        } while (deck[row][col] != 0);
        deck[row][col] = card;
    }
}

// empty the deck every time it shuffles, or the program won't run
void emptyDeck(unsigned int deck[][FACES]){
    for (int row = 0; row < SUITS; row++){
        for (int col = 0; col < FACES; col++){
            deck[row][col] = 0;
        }
    }
}

// deal the first hand
void deal(unsigned int deck[][FACES], unsigned int hand [][2], char *suit[], char *face[]){
    int counter = 0;
    printf("The first hand is: \n");
    // loop through the first 5 cards for the first hand
    for (int card = 1; card <= HAND; card++) {
        // loop through for the compatible suit
        for (int row = 0; row < SUITS; row++) {
            // loop through for the compatible face
            for (int col = 0; col < FACES; col++) {
                // assign the compatible suit and face to the hand for each card
                if (deck[row][col] == card) {
                    hand[counter][0] = row;
                    hand[counter][1] = col;
                    printf("%5s of %-8s\n", face[col], suit[row]);
                    counter++;
                }
            }
        }
    }
    puts("");
}

// check for the highest card in the first hand if the hand has nothing else
void highCard(unsigned int hand[][2], char *suit[], char *face[]){
    unsigned int arr[HAND] = {0};
    int high = arr[0];
    // copy hand to the array to sort
    for (int row = 0; row < HAND; row++){
        arr[row] = hand[row][1];
    }
    // loop for the highest card
    for (int card = 0; card < HAND; card++){
        if (arr[card] > high){
            high = arr[card];
        }
    }
    printf("The hand contains a high card of %s.\n", face[high]);
}

// determine whether the first hand contains a pair or two pairs.
void pair(unsigned int hand[][2], char *suit[], char *face[]){
    // counter that records how many cards of each rank in the hand
    unsigned int counter[FACES] = {0};
    // record how many cards of each rank are in the hand
    for (int row = 0; row < HAND; row++){
        counter[hand[row][1]]++;
    }
    // print result if there is a pair/two pairs
    for (int f = 0; f < FACES; f++){
        if (counter[f] == 2){
            printf("The hand contains a pair of %ss.\n", face[f]);
            count++;
        }
    }
}

// determine whether the first hand contains three of a kind
void threeOfKind(unsigned int hand[][2], char *suit[], char *face[]){
    // counter that records how many cards of each rank in the hand
    unsigned int counter[FACES] = {0};
    // record how many cards of each rank are in the hand
    for (int row = 0; row < HAND; row++){
        counter[hand[row][1]]++;
    }
    // print result if there is a three of a kind
    for (int f = 0; f < FACES; f++){
        if (counter[f] == 3){
            printf("The hand contains three %ss.\n", face[f]);
            count = 3;
        }
    }
}

// determine if the first hand contains four of a kind
void fourOfKind(unsigned int hand[][2], char *suit[], char *face[]){
    // counter that records how many cards of each rank in the hand
    unsigned int counter[FACES] = {0};
    // record how many cards of each rank are in the hand
    for (int row = 0; row < HAND; row++){
        counter[hand[row][1]]++;
    }
    // print result if there is a four of a kind
    for (int f = 0; f < FACES; f++){
        if (counter[f] == 4){
            printf("The hand contains four %ss.\n", face[f]);
            count = 4;
        }
    }
}

// determine whether the first hand contains a flush
void flushHand(unsigned int hand[][2], char *suit[], char *face[]){
    // counter that records how many cards of each suit in the hand
    unsigned int counter[SUITS] = {0};
    // record how many cards of each suit are in the hand
    for (int row = 0; row < HAND; row++){
        counter[hand[row][0]]++;
    }
    // print result if there is a flush
    for (int s = 0; s < SUITS; s++){
        if (counter[s] == 5){
            printf("The hand contains a flush of %s.\n", suit[s]);
            count = 5;
        }
    }
}

// determine whether the first hand contains a straight
void straightHand(unsigned int hand[][2], char *suit[], char *face[]){
    unsigned int arr[HAND] = {0};
    unsigned int temp;
    // copy hand to the array to sort
    for (int row = 0; row < HAND; row++){
        arr[row] = hand[row][1];
    }
    // bubble sort in ascending order
    for (int card = 1; card < HAND; card++){
        for (int card2 = 0; card2 < 4; card2++){
            if (arr[card2] > arr[card2+1]){
                temp = arr[card2];
                arr[card2] = arr[card2+1];
                arr[card2+1] = temp;
            }
        }
    }
    
    // check if sorted columns are a straight
    if (arr[4] - 1 == arr[3] && arr[3] - 1 == arr[2] && arr[2] - 1 == arr[1] && arr[1] - 1 == arr[0]){
        printf("The hand contains a straight from %s to %s.\n", face[arr[0]], face[arr[4]]);
        count = 6;
    }
}

// deal the second hand
void deal2(unsigned int deck[][FACES], unsigned int hand2 [][2], char *suit[], char *face[]){
    int counter = 6;
    printf("The second hand is: \n");
    // move up the card value to get the next 5 cards
    // loop through the next 5 cards for the second hand
    for (int card = 6; card <= HAND*2; card++) {
        // loop through for the compatible suit
        for (int row = 0; row < SUITS; row++) {
            // loop through for the compatible face
            for (int col = 0; col < FACES; col++) {
                 // assign the compatible suit and face to the hand for each card
                if (deck[row][col] == card) {
                    hand2[counter][0] = row;
                    hand2[counter][1] = col;
                    printf("%5s of %-8s\n", face[col], suit[row]);
                    counter++;
                }
            }
        }
    }
    puts("");
}

// check for the highes card in the second hand if the hand has nothing else
void highCard2(unsigned int hand[][2], char *suit[], char *face[]){
    unsigned int arr[HAND] = {0};
    int high = arr[0];
    // copy hand to the array to sort
    // move up the card value to get the next 5 cards
    for (int row = 6; row <= HAND*2; row++){
        arr[row-6] = hand[row][1];
    }
    // loop for the highest card
    for (int card = 0; card < HAND; card++){
        if (arr[card] > high){
            high = arr[card];
        }
    }
    printf("The hand contains a high card of %s.\n", face[high]);
}

// determine whether the second hand contains a pair or two pairs.
void pair2(unsigned int hand[][2], char *suit[], char *face[]){
    // counter that records how many cards of each rank in the hand
    unsigned int counter[FACES] = {0};
    // record how many cards of each rank are in the hand
    // move up the card value to get the next 5 cards
    for (int row = 6; row <= HAND*2; row++){
        counter[hand[row][1]]++;
    }
    // print result if there is a pair/two pairs
    for (int f = 0; f < FACES; f++){
        if (counter[f] == 2){
            printf("The hand contains a pair of %ss.\n", face[f]);
            count2++;
        }
    }
}

// determine whether the second hand contains three of a kind
void threeOfKind2(unsigned int hand[][2], char *suit[], char *face[]){
    // counter that records how many cards of each rank in the hand
    unsigned int counter[FACES] = {0};
    // record how many cards of each rank are in the hand
    // move up the card value to get the next 5 cards
    for (int row = 6; row <= HAND*2; row++){
        counter[hand[row][1]]++;
    }
    // print result if there is a three of a kind
    for (int f = 0; f < FACES; f++){
        if (counter[f] == 3){
            printf("The hand contains three %ss.\n", face[f]);
            count2 = 3;
        }
    }
}

// determine if the second hand contains four of a kind
void fourOfKind2(unsigned int hand[][2], char *suit[], char *face[]){
    // counter that records how many cards of each rank in the hand
    unsigned int counter[FACES] = {0};
    // record how many cards of each rank are in the hand
    // move up the card value to get the next 5 cards
    for (int row = 6; row <= HAND*2; row++){
        counter[hand[row][1]]++;
    }
    // print result if there is a four of a kind
    for (int f = 0; f < FACES; f++){
        if (counter[f] == 4){
            printf("The hand contains four %ss.\n", face[f]);
            count2 = 4;
        }
    }
}

// determine whether the second hand contains a flush
void flushHand2(unsigned int hand[][2], char *suit[], char *face[]){
    // counter that records how many cards of each suit in the hand
    unsigned int counter[SUITS] = {0};
    // record how many cards of each suit are in the hand
    // move up the card value to get the next 5 cards
    for (int row = 6; row <= HAND*2; row++){
        counter[hand[row][0]]++;
    }
    // print result if there is a flush
    for (int s = 0; s < SUITS; s++){
        if (counter[s] == 5){
            printf("The hand contains a flush of %s.\n", suit[s]);
            count2 = 5;
        }
    }
}

// determine whether the second hand contains a straight
void straightHand2(unsigned int hand[][2], char *suit[], char *face[]){
    unsigned int arr[HAND] = {0};
    unsigned int temp;
    // copy hand to the array to sort
    // move up the card value to get the next 5 cards
    for (int row = 6; row <= HAND*2; row++){
        arr[row-6] = hand[row][1];
    }
    // bubble sort in ascending order
    for (int card = 1; card < HAND; card++){
        for (int card2 = 0; card2 < 4; card2++){
            if (arr[card2] > arr[card2+1]){
                temp = arr[card2];
                arr[card2] = arr[card2+1];
                arr[card2+1] = temp;
            }
        }
    }
    
    // check if sorted columns are a straight
    if (arr[4] - 1 == arr[3] && arr[3] - 1 == arr[2] && arr[2] - 1 == arr[1] && arr[1] - 1 == arr[0]){
        printf("The hand contains a straight from %s to %s.\n", face[arr[0]], face[arr[4]]);
        count2 = 6;
    }
}
