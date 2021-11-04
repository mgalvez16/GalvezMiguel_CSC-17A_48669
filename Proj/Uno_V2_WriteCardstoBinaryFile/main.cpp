/* 
 * File:   main.cpp
 * Author: Miguel Galvez
 * Created on October 29th 2021, 7:22PM
 * Purpose: To Play Uno 
 */

//System Libraries Here
#include <cstdlib>  //rand()
#include <iostream> //cin,cout,endl
#include <cstring>  //strcpy, strstr
#include <iomanip>  //setprecision,fixed,showpoint
#include <fstream>  //fstream,ios::binary|ios::in|ios::out
using namespace std;
//User Libraries Here
//Structures
struct Uno{                 //Deck of Uno Cards
    char *color;            //Color associated with uno card
    unsigned short value;   //Value associated with the card
};
struct Deck{        //Structure of structure containing deck of uno cards
    unsigned short size;        //Size of Uno Deck
    Uno *all;                   //Data of all uno cards
};
//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions
enum Values{        //Card Values
    ZERO,ONE,TWO,THREE,FOUR,    //0-4
    FIVE,SIX,SEVEN,EIGHT,NINE,  //5-9
    SKIP,           //Skip Next Player's Turn
    REVERSE,        //Reverse The Turn Order
    DRAW,           //Next Person Draws a Card
    WILD,           //Wildcard
    DRAWWILD        //Wildcard Draw +4 Cards
};
//Function Prototypes Here
Deck *cards();          //Creates a pointer to dynamically allocated deck
void define(Deck *);    //Define each card according to color
void destroy(Deck *);   //Deallocate memory
//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    fstream out;         //File where deck of uno cards will be written
    fstream in;          //File where deck of uno cards will be read
    Deck *set;           //Pointer to deck of uno cards
    Deck *player;        //Pointer to player's hand of uno cards
    //Input or initialize values Here
    set=cards();          //Create deck of uno cards
    //Create player's hand of uno cards
    player=new Deck;
    player->all=new Uno [7];
    player->all->color=new char [8];
    define(set);          //Define each uno card
    //Write cards to binary file
    out.open("unoCards.dat",ios::out|ios::binary);
    if(out){
    out.write(reinterpret_cast<char *>(set),sizeof(set));
    }else{
        cout<<"Error: Could not create unoCards.dat\n";
    }
    out.close();
    //Read cards to player's cards
    in.open("unoCards.dat",ios::in|ios::binary);
    
    in.close();
    //Display Cards
    for(int i=0;i<set->size;i++){
        cout<<"Element "<<i<<": \n"
            <<"Color: "<<set->all[i].color<<endl
            <<"Value: "<<set->all[i].value<<endl;
    }
    //Exit
    destroy(set);
    delete [] player->all->color;
    delete [] player->all;
    delete player;
    return 0;
}
Deck *cards(){
    Deck *ptr;
    ptr=new Deck;
    ptr->size=108;
    //Dynamically Create Deck of Uno Cards
    ptr->all=new Uno [ptr->size];
    //Dynamically Create size of strings in Uno Cards
    for(int i=0;i<ptr->size;i++){
        ptr->all[i].color=new char [8];
    }
    return ptr;
}
void define(Deck *set){
    for(int i=0;i<set->size;i++){
        //First 25 cards are Green
        if(i<25){
            strcpy(set->all[i].color, "Green");
            i==ZERO?set->all[i].value=ZERO:
            i<=TWO?set->all[i].value=ONE:
            i<=FOUR?set->all[i].value=TWO:
            i<=SIX?set->all[i].value=THREE:
            i<=EIGHT?set->all[i].value=FOUR:
            i<=10?set->all[i].value=FIVE:
            i<=12?set->all[i].value=SIX:
            i<=14?set->all[i].value=SEVEN:
            i<=16?set->all[i].value=EIGHT:
            i<=18?set->all[i].value=NINE:
            i<=20?set->all[i].value=SKIP:
            i<=22?set->all[i].value=REVERSE:
            set->all[i].value=DRAW;
        //Next 25 are Blue
        }else if(i<50){
            strcpy(set->all[i].color, "Blue");
            i==25?set->all[i].value=ZERO:
            i<=27?set->all[i].value=ONE:
            i<=29?set->all[i].value=TWO:
            i<=31?set->all[i].value=THREE:
            i<=33?set->all[i].value=FOUR:
            i<=35?set->all[i].value=FIVE:
            i<=37?set->all[i].value=SIX:
            i<=39?set->all[i].value=SEVEN:
            i<=41?set->all[i].value=EIGHT:
            i<=43?set->all[i].value=NINE:
            i<=45?set->all[i].value=SKIP:
            i<=47?set->all[i].value=REVERSE:
            set->all[i].value=DRAW;
        //Next 25 are Red
        }else if(i<75){
            strcpy(set->all[i].color, "Red");
            i==50?set->all[i].value=ZERO:
            i<=52?set->all[i].value=ONE:
            i<=54?set->all[i].value=TWO:
            i<=56?set->all[i].value=THREE:
            i<=58?set->all[i].value=FOUR:
            i<=60?set->all[i].value=FIVE:
            i<=62?set->all[i].value=SIX:
            i<=64?set->all[i].value=SEVEN:
            i<=66?set->all[i].value=EIGHT:
            i<=68?set->all[i].value=NINE:
            i<=70?set->all[i].value=SKIP:
            i<=72?set->all[i].value=REVERSE:
            set->all[i].value=DRAW;
        //Next 25 are Yellow
        }else if(i<100){
            strcpy(set->all[i].color, "Yellow");
            i==75?set->all[i].value=ZERO:
            i<=77?set->all[i].value=ONE:
            i<=79?set->all[i].value=TWO:
            i<=81?set->all[i].value=THREE:
            i<=83?set->all[i].value=FOUR:
            i<=85?set->all[i].value=FIVE:
            i<=87?set->all[i].value=SIX:
            i<=89?set->all[i].value=SEVEN:
            i<=91?set->all[i].value=EIGHT:
            i<=93?set->all[i].value=NINE:
            i<=95?set->all[i].value=SKIP:
            i<=97?set->all[i].value=REVERSE:
            set->all[i].value=DRAW;
        //Last 8 are Black wildcards
        }else{
            strcpy(set->all[i].color, "Black");
            i<=103?set->all[i].value=WILD:
            set->all[i].value=DRAWWILD;
        }
    }
}
void destroy(Deck *set){
    for(int i=0;i<set->size;i++){
        delete [] set->all[i].color;
    }
    delete [] set->all;
    delete set;
}