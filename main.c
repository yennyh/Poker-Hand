////  main.c
////  ClassProject_CardShufflingDealing
////  Created by Yen My Huynh on 7/13/17.
//
//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//#include <stdbool.h>
//
//#define CARDS 52
//#define FACES 13
//#define SUITS 4
//#define HAND 5
//
//// card structure definition
//struct card{
//    const char *face; // define pointer face
//    const char *suit; // define pointer suit
//};
//
//typedef struct card Card;
//
//// function prototypes
//void fillDeck(Card * const wDeck, const char *wFace[], const char *wSuit[]);
//void shuffle(Card * const wDeck);
//void dealAHand(Card * const wDeck, const char *wFace[], const char *wSuit[]);
//void dealTwoHand(Card * const wDeck, const char *wFace[], const char *wSuit[]);
//bool isPair(Card * const hand);
//bool isTwoPairs(Card * const hand);
//bool isThreeOfAKind(Card * const hand);
//bool isFourOfAKind(Card * const hand);
//bool isFlush(Card * const hand);
//void bubbleSort(int * const arr, int size);
//bool isStraight(Card * const hand, const char * wFace[]);
//bool isDrawn(Card * const wDeck);
//
//int main(void) {
//    Card deck[CARDS]; // define array of Cards
//    
//    // initialize array of pointers
//    const char *face[FACES] = {"Ace", "Deuce", "Three", "Four", "Five", "Six", "Seven", "Eight",
//        "Nine", "Ten", "Jack", "Queen", "King"};
//    
//    const char *suit[SUITS] = { "Clubs", "Diamonds", "Hearts", "Spades"};
//    srand(time(NULL)); // randomize
//    
//    for (int i = 0; i < 10; i++){
////    fillDeck(deck, face , suit); // load the deck with Cards
////    shuffle(deck); // put Cards in random order
////    dealAHand(deck, face, suit); // deal 5 Cards
//    dealTwoHand(deck, face, suit);
////    if (isPair(deck)){
////        printf("This has a pair\n");
////    }
//    //        isTwoPairs(deck);
//    //        isThreeOfAKind(deck);
//    //        isFlush(deck);
//    //        isStraight(deck, face);
//    //        isFourOfAKind(deck);
//    puts("---------------------------------------------------");
//    }
//}
//
//// place strings into Card structures
//void fillDeck(Card * const wDeck, const char * wFace[],const char * wSuit[] ){
//    // loop through the deck
//    for (size_t i = 0; i < CARDS; i++){
//        wDeck[i].face = wFace[i % FACES];
//        wDeck[i].suit = wSuit[i / FACES];
//    }
//}
//bool isDrawn(Card * const wDeck){
//    for (int i = 0; i < CARDS-1; i++) {
//        for (int j = i + 1; j < CARDS; j++) {
//            if (wDeck[i].face != wDeck[j].face && wDeck[i].suit != wDeck[j].suit){
//                return false;
//            }
//        }
//    }
//    return true;
//}
//
//// shuffle cards
//void shuffle(Card * const wDeck){
//    // loop through the deck randomly swapping Cards
//    for (int i = 0; i < CARDS; i++){
//        if (!(isDrawn(wDeck))){
//        size_t j = rand() % CARDS;
//        Card temp = wDeck[i];
//        wDeck[i] = wDeck[j];
//        wDeck[j] = temp;
//        }
//    }
//}
//
//// deal a hand of cards
//void dealAHand(Card * const wDeck, const char *wFace[], const char *wSuit[]){
//    for (int i = 0; i < 5; i++){
//        printf("%s of %s \n", wDeck[i].face, wDeck[i].suit);
//    }
//    puts("---------------------------------------------------");
//}
//;
//// deal two hands of cards
//void dealTwoHand(Card * const wDeck, const char *wFace[], const char *wSuit[]){
//    Card hand1[HAND] = {0};
//    Card hand2[HAND] = {0};
//    for (int player = 0; player < 2; player++){
//        fillDeck(wDeck, wFace, wSuit);
//        shuffle(wDeck);
//        for (int card = 0; card < HAND; card++){
//            if (player == 0){
//                hand1[card].face = wDeck[card].face;
//                hand1[card].suit = wDeck[card].suit;
//                printf("%s of %s \n", hand1[card].face, hand1[card].suit);
//                
//            }
//            else if (player == 1){
//                hand2[card].face = wDeck[card].face;
//                hand2[card].suit = wDeck[card].suit;
//                printf("%s of %s \n", hand2[card].face, hand2[card].suit);
//            }
//        }
//        puts("");
//    }
//    //four, flush, straight, three, pairs, pair high card
//    if (isFourOfAKind(hand1) && !(isFourOfAKind(hand2))){
//        printf("Player 1 has a better hand with four-of-a-kind.\n");
//    }
//    else if (isFlush(hand1) && !(isFourOfAKind(hand2))){
//        printf("Player 1 has a better hand with a flush. \n");
//    }
//    else if (isStraight(hand1, wFace) && !(isFourOfAKind(hand2)) && !(isFlush(hand2))){
//        printf("Player 1 has a better hand with a straight.\n");
//    }
//    else if (isThreeOfAKind(hand1) && !(isFourOfAKind(hand2)) && !(isFlush(hand2)) && !(isStraight(hand2, wFace))){
//        printf("Player 1 has a better hand with a three-of-a-kind.\n");
//    }
//    else if (isTwoPairs(hand1) && !(isFourOfAKind(hand2)) && !(isFlush(hand2)) && !(isStraight(hand2, wFace)) && !(isThreeOfAKind(hand2))){
//        printf("Player 1 has a better hand with two pairs. \n");
//        int count1 = 0;
//        int pair1[HAND] = {0};
//        for (int card = 0; card < HAND; card++) {
//            for (int card2 = card+1; card2 < HAND; card2++) {
//                // compares faces with the current and the following card
//                if (hand1[card2].face == hand1[card].face) {
//                    // keep count and using the index for display
//                    count1++;
//                    pair1[card] = card2;
//                }
//            }
//        }
//        int k1[5] = {0};
//        if (count1 == 2){
//            for (int card = 0; card < HAND; card++){
//                // value corresponds with the index
//                if (pair1[card] != 0){
//                    k1[card] = pair1[card];
//                }
//            }
//        }
//        int high1 = 0;
//        for (int i = 0; i < HAND; i++){
//            if (hand1[k1[i]].face > hand1[high1].face){
//                high1 = k1[i];
//            }
//        }
//    }
//    else if (isPair(hand1) && !(isFourOfAKind(hand2)) && !(isFlush(hand2)) && !(isStraight(hand2, wFace)) && !(isThreeOfAKind(hand2)) && !(isTwoPairs(hand2)) && !(isPair(hand2))){
//        printf("Player 1 has a better hand with a pair.\n");
//    }
//    else if (isFourOfAKind(hand2) && !(isFourOfAKind(hand1))){
//        printf("Player 2 has a better hand with four-of-a-kind.\n");
//    }
//    else if (isFlush(hand2) && !(isFourOfAKind(hand1))){
//        printf("Player 2 has a better hand with a flush. \n");
//    }
//    else if (isStraight(hand2, wFace) && !(isFourOfAKind(hand1)) && !(isFlush(hand1))){
//        printf("Player 2 has a better hand with a straight.\n");
//    }
//    else if (isThreeOfAKind(hand2) && !(isFourOfAKind(hand1)) && !(isFlush(hand1)) && !(isStraight(hand1, wFace))){
//        printf("Player 2 has a better hand with a three-of-a-kind.\n");
//    }
//    else if (isTwoPairs(hand2) && !(isFourOfAKind(hand1)) && !(isFlush(hand1)) && !(isStraight(hand1, wFace)) && !(isThreeOfAKind(hand1))){
//        printf("Player 2 has a better hand with two pairs. \n");
//        int count2 = 0;
//        int pair2[HAND] = {0};
//        for (int card = 0; card < HAND; card++) {
//            for (int card2 = card+1; card2 < HAND; card2++) {
//                // compares faces with the current and the following card
//                if (hand2[card2].face == hand2[card].face) {
//                    // keep count and using the index for display
//                    count2++;
//                    pair2[card] = card2;
//                }
//            }
//        }
//        int k2[5] = {0};
//        if (count2 == 2){
//            for (int card = 0; card < HAND; card++){
//                // value corresponds with the index
//                if (pair2[card] != 0){
//                    k2[card] = pair2[card];
//                }
//            }
//    
//        }
//        int high2 = 0;
//        for (int i = 0; i < HAND; i++){
//            if (hand2[k2[i]].face > hand2[high2].face){
//                high2 = k2[i];
//            }
//        }
//    }
//    else if (isTwoPairs(hand1) && isTwoPairs(hand2)){
//        int count1 = 0;
//        int pair1[HAND] = {0};
//        int count2 = 0;
//        int pair2[HAND] = {0};
//        for (int card = 0; card < HAND; card++) {
//            for (int card2 = card+1; card2 < HAND; card2++) {
//                // compares faces with the current and the following card
//                if (hand1[card2].face == hand1[card].face) {
//                    // keep count and using the index for display
//                    count1++;
//                    pair1[card] = card2;
//                }
//            }
//            for (int card2 = card+1; card2 < HAND; card2++) {
//                // compares faces with the current and the following card
//                if (hand2[card2].face == hand2[card].face) {
//                    // keep count and using the index for display
//                    count2++;
//                    pair2[card] = card2;
//                }
//            }
//        }
//
//        int k1[2] = {0};
//        int k2[2] = {0};
//        
//        if (count1 == 2){
//            for (int card = 0; card < HAND; card++){
//                // value corresponds with the index
//                if (pair1[card] != 0){
//                    k1[card] = pair1[card];
//                }
//            }
//        }
//        if (count2 == 2){
//            for (int card = 0; card < HAND; card++){
//                // value corresponds with the index
//                if (pair2[card] != 0){
//                    k2[card] = pair2[card];
//                }
//            }
//        }
//        int high1 = 0;
//        int high2 = 0;
//        for (int i = 0; i < HAND; i++){
//            if (hand1[k1[i]].face > hand1[high1].face){
//                high1 = k1[i];
//            }
//        }
//        for (int i = 0; i < HAND; i++){
//            if (hand2[k2[i]].face > hand2[high2].face){
//                high2 = k2[i];
//            }
//        }
//        if (hand1[high1].face > hand2[high2].face){
//            printf("Player 1 has a better hand with two higher pairs.\n");
//            printf("k1: %s k2: %s\n", hand1[high1].face, hand2[high2].face);
//        }
//        else if (hand2[high2].face > hand1[high1].face){
//            printf("Player 2 has a better hand with two higher pairs.\n");
//            printf("k1: %s k2: %s\n", hand1[high1].face, hand2[high2].face);
//        }
//        else if (hand1[high1].face == hand2[high2].face && hand1[high1].suit > hand2[high2].suit){
//            printf("Player 1 has a better hand with two higher pairs.\n");
//        }
//        else{
//            printf("Player 2 has a better hand with two higher pairs.\n");
//        }
//    }
//    else if (isPair(hand2) && !(isFourOfAKind(hand1)) && !(isFlush(hand1)) && !(isStraight(hand1, wFace)) && !(isThreeOfAKind(hand1)) && !(isTwoPairs(hand1)) && !(isPair(hand1))){
//        printf("Player 2 has a better hand with a pair.\n");
//    }
//    else if (isPair(hand1) && isPair(hand2)){
//        int count1 = 0;
//        int pair1[HAND] = {0};
//        int count2 = 0;
//        int pair2[HAND] = {0};
//        for (int card = 0; card < HAND; card++) {
//            for (int card2 = card+1; card2 < HAND; card2++) {
//                // compares faces with the current and the following card
//                if (hand1[card2].face == hand1[card].face) {
//                    // keep count and using the index for display
//                    count1++;
//                    pair1[card] = card2;
//                }
//            }
//            for (int card2 = card+1; card2 < HAND; card2++) {
//                // compares faces with the current and the following card
//                if (hand2[card2].face == hand2[card].face) {
//                    // keep count and using the index for display
//                    count2++;
//                    pair2[card] = card2;
//                }
//            }
//        }
//        int k1 = 0;
//        int k2 = 0;
//        
//        if (count1 == 1){
//            for (int card = 0; card < HAND; card++){
//                // value corresponds with the index
//                if (pair1[card] != 0){
//                    k1 = pair1[card];
//                }
//            }
//        }
//        if (count2 == 1){
//            for (int card = 0; card < HAND; card++){
//                // value corresponds with the index
//                if (pair2[card] != 0){
//                    k2 = pair2[card];
//                }
//            }
//        }
//
//        if (hand1[k1].face > hand2[k2].face){
//            printf("Player 1 has a better hand with a higher pair.\n");
//        }
//        else if (hand2[k2].face > hand1[k1].face){
//            printf("Player 2 has a better hand with a higher pair.\n");
//        }
//        else if (hand1[k1].face == hand2[k2].face && hand1[k1].suit > hand2[k2].suit){
//            printf("Player 1 has a better hand with a higher pair.\n");
//        }
//        else{
//             printf("Player 2 has a better hand with a higher pair.\n");
//        }
//    }
//    else{
//        Card highCard1 = hand1[0];
//        for (int card = 0; card < HAND; card++){
//            if (hand1[card].face > highCard1.face){
//                highCard1 = hand1[card];
//            }
//        }
//        Card highCard2 = hand2[0];
//        for (int card = 0; card < HAND; card++){
//            if (hand2[card].face > highCard2.face){
//                highCard2 = hand2[card];
//            }
//        }
//        Card highestCard = hand1[0];
//        if (highCard1.face > highCard2.face){
//            highestCard = highCard1;
//            printf("Player 1 has a better hand with a higher card of %s of %s.\n", highestCard.face, highestCard.suit);
//        }
//        else if (highCard1.face == highCard2.face && highCard1.suit > highCard2.suit){
//            highestCard = highCard1;
//            printf("Player 1 has a better hand with a higher card of %s of %s.\n", highestCard.face, highestCard.suit);
//        }
//        else if (highCard1.face == highCard2.face && highCard1.suit < highCard2.suit){
//            highestCard = highCard2;
//            printf("Player 2 has a better hand with a higher card of %s of %s.\n", highestCard.face, highestCard.suit);
//        }
//        else{
//            highestCard = highCard2;
//            printf("Player 2 has a better hand with a higher card of %s of %s.\n", highestCard.face, highestCard.suit);
//        }
//    }
//}
//
//// determine whether the hand contains a pair
//bool isPair(Card * const hand) {
//    int count = 0;
//    int pair[HAND] = {0};
//    for (int card = 0; card < HAND; card++) {
//        for (int card2 = card+1; card2 < HAND; card2++) {
//            // compares faces with the current and the following card
//            if (hand[card2].face == hand[card].face) {
//                // keep count and using the index for display
//                count++;
//                pair[card] = card2;
//            }
//        }
//    }
//    // print the results
//    if (count == 1){
//        return true;
//    }
//    return false;
//}
//
//// determine whether the hand contains two pairs
//bool isTwoPairs(Card * const hand){
//    int count = 0;
//    int pair[HAND] = {0};
//    for (int card = 0; card < HAND; card++) {
//        for (int card2 = card+1; card2 < HAND; card2++) {
//            // compares faces with the current and the following card
//            if (hand[card2].face == hand[card].face) {
//                // keep count and using the index for display
//                count++;
//                pair[card] = card2;
//            }
//        }
//    }
//    if (count == 2){
//        return true;
//    }
//    return false;
//}
//
//// determine whether the hand contains three of a kind
//bool isThreeOfAKind(Card * const hand){
//    int count = 0;
//    int triple[3] = {0};
//    // first for loop using the max length of 3-of-a-kind
//    for (int card = 0; card < 3; card++){
//        for (int card2 = card+1; card2 < HAND; card2++){
//            if (hand[card].face == hand[card2].face){
//                for (int card3 = card2+1; card3 < HAND; card3++){
//                    // execute if card == card2 == card3
//                    if (hand[card2].face == hand[card3].face){
//                        // using count and arrays for display
//                        count++;
//                        triple[0] = card;
//                        triple[1] = card2;
//                        triple[2] = card3;
//                    }
//                }
//            }
//        }
//    }
//    // print the results
//    if (count == 1){
//        return true;
//    }
//    return false;
//}
//
//// determine whether the hand contains four of a kind
//bool isFourOfAKind(Card * const hand){
//    int count = 0;
//    int quad[5] = {0};
//    
//    // first for loop is the max length to test 4-of-a-kind
//    for(int card = 0; card < 2; card++){
//        for(int card2 = card + 1; card2 < HAND; card2++){
//            if(hand[card].face == hand[card2].face){
//                // keep count and initialize all indexes that have
//                // equal faces to 1
//                count++;
//                if(count == 2){
//                    quad[card2 - 1] = 1;
//                }
//                quad[card2] = 1;
//            }
//        }
//        // if count is 4, stop, if not count goees back to 0 and so indexes
//        if(count == 4)
//            break;
//        else{
//            count = 0;
//            for(int i = 0; i < HAND; i++)
//                quad[i] = 0;
//        }
//    }
//    // print the results
//    if(count == 4){
//        return true;
//    }
//        return false;
//}
//    
//// determine whether the hand contains a flush
//bool isFlush(Card * const hand){
//        // count the first card
//    int count = 1;
//    for (int card = 1; card < HAND; card++) {
//        // compares the first card's suit with all other cards
//        if (hand[0].suit == hand[card].suit) {
//            count++;
//    }
//}
//    // print the results
//    if (count == 5){
//        return true;
//    }
//    return false;
//}
//    
//    // determine whether the hand contains a straight
//bool isStraight(Card * const hand, const char * wFace[]){
//    int count = 1;
//    int cardValue[5] = {0};
//        
//    //locate face value and store in an array
//    for(int card = 0 ; card < HAND; card++){
//        for(int com = 0 ; com < 13; com++){
//            if(hand[card].face == wFace[com]){
//                cardValue[card] = com;
//            }
//        }
//    }
//        
//    //sort the card values in ascending order using bubble sort
//    bubbleSort(cardValue, HAND);
//    
//    //check if the hand contains a straight
//    for(int i = 0; i < 4; i++){
//        if(cardValue[i] + 1 != cardValue[i+1]){
//            count = 0;
//        }
//        count++;
//    }
//    if (count == 5){
//        return true;
//    }
//    return false;
//}
//
//// sort the array
//void bubbleSort(int * const arr, int size){
//    // function prototype, no other function can use swap except this
//    void swap(int *element1Ptr, int *element2Ptr);
//    // using size-1 to keep to loop in bound
//    for(int card = 0; card < size-1; card++){
//        for(int card2 = 0; card2 < size-1; card2++){
//            if(arr[card2] > arr[card2+1]){
//                //swap
//                swap(&arr[card2], &arr[card2+1]);
//            }
//        }
//    }
//}
//
//// swap values at memory locations to which element1Ptr and element2Ptr point
//void swap(int *element1Ptr, int *element2Ptr){
//    int temp = *element1Ptr;
//    *element1Ptr = *element2Ptr;
//    *element2Ptr = temp;
//}
//


//  main.c
//  ClassProject_CardShufflingDealing
//  Created by Yen My Huynh on 7/13/17.
//  Card game that can either be played by 1 or two players.
//  Can check for highest card, pair, pairs, 3-of-a-kind, 4-of-a-kind,
//  flush, or a straight hand.
//  Can evaluate and determine which hand is better if played by 2 players.

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
