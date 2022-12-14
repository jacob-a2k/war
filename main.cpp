#include <iostream>
#include <limits>
#include "utils.h"
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
void display(Card cards[]);
void create_deck_of_cards(Card cards[]);
void shuffle_cards(Card cards[]);
bool rand_shuffle(Card cards[],Card temp[],int n, int t);
void deal_cards_out(Card cards[], Card f_deck[], Card s_deck[]);
void do_move(Card f_deck[], Card s_deck[]);
void winner_take_cards(Card winer[], Card loser[],int &total,int &t);
void new_line_validation();

int main()
{
    Card cards[24];
    create_deck_of_cards(cards);
    shuffle_cards(cards);
    Card f_deck[24], s_deck[24];
    deal_cards_out(cards,f_deck,s_deck);
    do_move(f_deck, s_deck);



   // display(f_deck);
    //cout << endl;
    //display(s_deck);

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
void deal_cards_out(Card cards[], Card f_deck[], Card s_deck[]){
    int i = 0, j = 0, t = 0;
    while(t < 24){
        if(t%2 == 0){
            f_deck[i]= cards[t];    //nie uzywaj jakis f_deck nie wiadomo o co chodzi uzywaj pe??nych nazw zeby kod by?? czytelny
            i++;
        }
        else{
            s_deck[j] = cards[t];
            j++;
        }
        t++;
    }
}
void do_move(Card f_deck[], Card s_deck[]){
    int rand = 0;
    int total = 12, t = 12, licznik = 0;
    cout << "Aby wystawic karty napisnij ENTER!" << endl;
    while(total != 24 && t != 24){
        cout << endl;
        new_line_validation();
        cout << f_deck[0].figure << " " << f_deck[0].sign << " ";
        new_line_validation();
        cout << s_deck[0].figure << " " << s_deck[0].sign << endl;
        if(f_deck[0].weight > s_deck[0].weight){
            winner_take_cards(f_deck,s_deck,total,t);
            cout << "Zabiera gracz I" << endl;
        }
        else if(f_deck[0].weight < s_deck[0].weight){
            winner_take_cards(s_deck,f_deck,t,total);
            cout << "Zabiera gracz II" << endl;
        }
        else if(f_deck[0].weight == s_deck[0].weight){
            if(rand % 2 == 0){
                winner_take_cards(s_deck,f_deck,t,total);
                cout << "Zabiera gracz II" << endl;
            }
            else{
                winner_take_cards(f_deck,s_deck,total,t);
                cout << "Zabiera gracz I" << endl;
            }
            rand++;
        }
        licznik ++;
    }
    if(total == 0) cout << "Wygrywa gracz II w rundzie: " << licznik << " !" << endl;
    else cout << "Wygrywa gracz I w rundzie: " << licznik << " !" << endl;
}
void winner_take_cards(Card winer[], Card loser[],int &total, int &t){
    Card temp[2];
    temp[0] = winer[0];
    temp[1] = loser[0];
    for(int i = 0; i < total-1; i++){
        winer[i] = winer[i+1];
    }
    winer[total-1] = temp[0];
    winer[total] = temp[1];

    for(int j = 0; j < t; j++){
        loser[j] = loser[j+1];
    }
    total++;t--;
}
void new_line_validation(){
    char sign;
    sign = getch();
    while(sign != '\n'){
        cout << "\nPress fucking ENTER!" << endl;
        cin.clear();
        sign = getch();
    }
}


void display(Card cards[]){
    for(int y = 0; y < 24; y++){
        cout << cards[y].figure << ", ";
        cout << cards[y].sign << " ";
        cout << cards[y].weight << " ";
    }
}
