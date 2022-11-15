#include <iostream>

using namespace std;


string Color[4] = {"pik","kier","karo","trefl"};
string Figure[6] = {"A", "K","Q","W","10","9"};
int Weight[6] = {6,5,4,3,2,1};

struct Card{
    string sign;
    string figure;
    int weight;
};
void create_deck_of_cards(Card deck[]);
//void wyswietl(Card deck[]);

int main()
{
    Card deck[24];
    create_deck_of_cards(deck);
    //wyswietl(deck);

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
/*
void wyswietl(Card deck[]){
    for(int i = 0; i < 24; i++){
        cout << deck[i].figure << " ";
        cout << deck[i].sign << " ";
        cout << deck[i].weight << endl;
    }
}
*/
