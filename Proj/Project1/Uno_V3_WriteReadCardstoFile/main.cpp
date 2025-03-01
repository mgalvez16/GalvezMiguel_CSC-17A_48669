/* 
 * File:   main.cpp
 * Author: Miguel Galvez
 * Created on October 29th 2021, 7:22PM
 * Purpose: Read and Write the entire deck of Uno Cards. 
 *          I had to change from pointers to structures 
 *          to regular structures and modify my create
 */

//System Libraries Here
#include <iostream> //cin,cout,endl
#include <cstring>  //strcpy, strstr
#include <iomanip>  //xprecision,fixed,showpoint
#include <fstream>  //file operations
using namespace std;
//User Libraries Here
//Structures
struct Uno{                 //Deck of Uno Cards
    char color[8];          //Color associated with uno card
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
void create(Deck&,Deck&,short);
void define(Deck *);
void destroy(Deck&,Deck&);
void display(Deck *);
//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const short SZE=108;    //Uno Deck Size
    fstream in;         //input file
    fstream out;        //output file
    Deck set;          //Pointer to deck of uno cards
    Deck fSet;         //Pointer to deck of uno cards from file
    //Input or initialize values Here
    create(set,fSet,SZE);
    //Define Uno Cards
    define(&set);
    //Write Uno cards to file
    out.open("unoCards.dat",ios::out|ios::binary);
    out.write(reinterpret_cast<char *>(&set),sizeof(set)*set.size);
    out.close();
    //Read Uno cards to separate variable
    in.open("unoCards.dat",ios::in|ios::binary);
    in.read(reinterpret_cast<char *>(&fSet),sizeof(fSet)*fSet.size);
    in.close();
    //Display Uno Cards
    display(&fSet);
    //Cleanup
    destroy(set,fSet);
    //Exit
    return 0;
}
void create(Deck &set,Deck &fSet,short SZE){
    set.all=new Uno [SZE];
    set.size=SZE;
    fSet.all=new Uno [SZE];
    fSet.size=SZE;
}
void define(Deck *x){
    //Define x of Uno cards
    for(int i=0;i<x->size;i++){
        //First 25 cards are Green
        if(i<25){
            strcpy(x->all[i].color, "Green");
            i==ZERO?x->all[i].value=ZERO:
            i<=TWO?x->all[i].value=ONE:
            i<=FOUR?x->all[i].value=TWO:
            i<=SIX?x->all[i].value=THREE:
            i<=EIGHT?x->all[i].value=FOUR:
            i<=10?x->all[i].value=FIVE:
            i<=12?x->all[i].value=SIX:
            i<=14?x->all[i].value=SEVEN:
            i<=16?x->all[i].value=EIGHT:
            i<=18?x->all[i].value=NINE:
            i<=20?x->all[i].value=SKIP:
            i<=22?x->all[i].value=REVERSE:
            x->all[i].value=DRAW;
        //Next 25 are Blue
        }else if(i<50){
            strcpy(x->all[i].color, "Blue");
            i==25?x->all[i].value=ZERO:
            i<=27?x->all[i].value=ONE:
            i<=29?x->all[i].value=TWO:
            i<=31?x->all[i].value=THREE:
            i<=33?x->all[i].value=FOUR:
            i<=35?x->all[i].value=FIVE:
            i<=37?x->all[i].value=SIX:
            i<=39?x->all[i].value=SEVEN:
            i<=41?x->all[i].value=EIGHT:
            i<=43?x->all[i].value=NINE:
            i<=45?x->all[i].value=SKIP:
            i<=47?x->all[i].value=REVERSE:
            x->all[i].value=DRAW;
        //Next 25 are Red
        }else if(i<75){
            strcpy(x->all[i].color, "Red");
            i==50?x->all[i].value=ZERO:
            i<=52?x->all[i].value=ONE:
            i<=54?x->all[i].value=TWO:
            i<=56?x->all[i].value=THREE:
            i<=58?x->all[i].value=FOUR:
            i<=60?x->all[i].value=FIVE:
            i<=62?x->all[i].value=SIX:
            i<=64?x->all[i].value=SEVEN:
            i<=66?x->all[i].value=EIGHT:
            i<=68?x->all[i].value=NINE:
            i<=70?x->all[i].value=SKIP:
            i<=72?x->all[i].value=REVERSE:
            x->all[i].value=DRAW;
        //Next 25 are Yellow
        }else if(i<100){
            strcpy(x->all[i].color, "Yellow");
            i==75?x->all[i].value=ZERO:
            i<=77?x->all[i].value=ONE:
            i<=79?x->all[i].value=TWO:
            i<=81?x->all[i].value=THREE:
            i<=83?x->all[i].value=FOUR:
            i<=85?x->all[i].value=FIVE:
            i<=87?x->all[i].value=SIX:
            i<=89?x->all[i].value=SEVEN:
            i<=91?x->all[i].value=EIGHT:
            i<=93?x->all[i].value=NINE:
            i<=95?x->all[i].value=SKIP:
            i<=97?x->all[i].value=REVERSE:
            x->all[i].value=DRAW;
        //Last 8 are Black wildcards
        }else{
            strcpy(x->all[i].color, "Black");
            i<=103?x->all[i].value=WILD:
            x->all[i].value=DRAWWILD;
        }
    }
}
void destroy(Deck &set,Deck &fSet){
    delete [] set.all;
    delete [] fSet.all;
}
void display(Deck *x){
    for(int i=0;i<x->size;i++){
        cout<<"Card: "<<i<<endl
            <<"Color: "<<x->all[i].color<<endl
            <<"Value: "<<x->all[i].value<<endl;
    }
}