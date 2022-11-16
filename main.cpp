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
struct Player_One{
    Card deck_one;
};
struct Player_Two{
    Card deck_two;
};
void create_deck_of_cards(Card deck[]);
bool is_in_pack(Card deck[],int a, int b,Player_One player_one[]);
void passing_cards_out(Card deck[]);
bool second_player_pack(Card deck[], Player_One player_one[], int i);

int main()
{
    Card deck[24];
    create_deck_of_cards(deck);
    passing_cards_out(deck);

    return 0;
}
void create_deck_of_cards(Card deck[]){
    int n = 0;
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 6; j++){
            deck[n].sign = Color[i];
            deck[n].figure = Figure[j];
            deck[n].weight = Weight[j];
            n++;
        }
    }
}
void passing_cards_out(Card deck[]){
    srand(time(NULL));
    Player_One player_one[12];
    int i = 0;
    while(i < 12){
        int number = rand()%24;
        if( !is_in_pack(deck,number,i,player_one)){
            player_one[i].deck_one.sign = deck[number].sign;
            player_one[i].deck_one.figure = deck[number].figure;
            player_one[i].deck_one.weight = deck[number].weight;
            i++;
        }
    }
   /* for(int i = 0; i < 12; i++){
        cout << player_one[i].deck_one.figure << " ";
        cout << player_one[i].deck_one.sign << " ";
        cout << player_one[i].deck_one.weight << endl;
    */
    Player_Two player_two[12];
    int total = 0;
    while(total < 12){
        for(int i = 0; i < 24; i++){
            if(!second_player_pack(deck,player_one,i)){
                player_two[total].deck_two.figure = deck[i].figure;
                player_two[total].deck_two.sign = deck[i].sign;
                player_two[total].deck_two.weight = deck[i].weight;
                total++;
            }
        }
    }
   /* cout << endl;
    for(int i = 0; i < 12; i++){
        cout << player_two[i].deck_two.figure << " ";
        cout << player_two[i].deck_two.sign << " ";
        cout << player_two[i].deck_two.weight << endl;
    }*/
}
bool is_in_pack(Card deck[],int a, int b, Player_One player_one[]){
    for(int i = 0; i < b; i++){
        if(player_one[i].deck_one.sign == deck[a].sign &&
           player_one[i].deck_one.figure == deck[a].figure &&
           player_one[i].deck_one.weight == deck[a].weight)
           return true;
    }
    return false;
}

bool second_player_pack(Card deck[], Player_One player_one[], int i){
    for(int j = 0; j < 12; j++){
        if(deck[i].figure == player_one[j].deck_one.figure &&
            deck[i].sign == player_one[j].deck_one.sign &&
            deck[i].weight == player_one[j].deck_one.weight)
            return true;
    }
    return false;
}

