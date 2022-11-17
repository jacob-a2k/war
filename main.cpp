#include <iostream>
//#include <time.h>

using namespace std;

string Color[4] = {"pik","kier","karo","trefl"};
string Figure[6] = {"A","K","Q","W","10","9"};
int Weight[6] = {6,5,4,3,2,1};

struct Card{
    string sign;
    string figure;
    int weight;
};
struct Deck{
    Card deck;
};
void display(Card cards[]);
void create_deck_of_cards(Card cards[]);
void shuffle_cards(Card cards[]);
bool rand_shuffle(Card cards[],Card temp[],int n, int t);

int main()
{
    Card cards[24];
    create_deck_of_cards(cards);
    shuffle_cards(cards);
    //display(cards);

    return 0;
}
void create_deck_of_cards(Card cards[]){
    int n = 0;
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 6; j++){
            cards[n].sign = Color[i];
            cards[n].figure = Figure[j];
            cards[n].weight = Weight[j];
            n++;
        }
    }
}
void shuffle_cards(Card cards[]){
    srand(time(NULL));
    int total = 0;
    Card temp[24];
    while(total < 24){
        int number = rand()%24;
        if(!rand_shuffle(cards,temp,number,total)){
            temp[total].figure = cards[number].figure;
            temp[total].sign = cards[number].sign;
            temp[total].weight = cards[number].weight;
            total++;
        }
    }
    for(int i = 0; i < 24; i++){
        cards[i].figure = temp[i].figure;
        cards[i].sign = temp[i].sign;
        cards[i].weight = temp[i].weight;
    }
}
bool rand_shuffle(Card cards[],Card temp[],int n, int t){
    for(int i = 0; i < t; i++){
        if(temp[i].figure == cards[n].figure &&
           temp[i].sign == cards[n].sign &&
           temp[i].weight == cards[n].weight)
            return true;
    }

    return false;
}



void display(Card cards[]){
    for(int y = 0; y < 24; y++){
        cout << cards[y].figure << " ";
        cout << cards[y].sign << " ";
        cout << cards[y].weight << endl;
    }
}
