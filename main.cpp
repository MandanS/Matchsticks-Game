//
//  main.cpp
//  Assignment 4
//
//  Created by Mandan Sharma on 1/20/16.
//  Copyright © 2016 mandan sharma. All rights reserved.
//
#include<iostream>
#include<string>
#include<cstdlib>
#include<stdlib.h>
#include<ctime>
using namespace std;

// declaring the functions
int computer_turn_first(int box,int range);
int computer_turn(int box,int range,int sticks_user,int BOX_FIXED);

int main() {
    int box , sticks,range=4,BOX_FIXID;
    char firstChance;
    cout << "Welcome! To the game match stick challenge! \n       Rules and settings:\n" ;
    cout << "The person who is left to choose the last matchstick will loose the game. \nenter the initial number of sticks in the box\n";
    cin >> box;
    BOX_FIXID=box;
    cout << "\nOk at start there will be "<<box<<" Matchsticks in the box \nEnter Range of mathsticks which can be drawn out of the box\n";
    cin >>range;
    cout <<"you must choose number between 1 and"<<range<<" \n  Enter Y if you want to take first chance: \n";
    cin >> firstChance ;
    
    if (firstChance == 'Y' || firstChance == 'y') {
        
        cout << "Your chance first.\n";
        for (; box > 1;){
            // Players Turn
            
        chooseagain:
            cout << "Choose a number that is between 1 and "<<range << endl;
            cin >> sticks;
            if (sticks <= range && sticks > 0) {
                box -= sticks;
                cout <<  "Sticks remaining are: " << box << endl;
                if (box==1) {
                    cout << "\nYou won the Game\nComputer lost the game because he is the last person to choose the matchstick\n";
                    break;
                }
                
                // Computers Turn
                
                sticks = computer_turn (box, range,sticks,BOX_FIXID);
                box -= sticks;
                cout <<"The computer choose: "<<sticks<<"\nThe Remaining stick in the box are: "<< box <<"\nYour turn now\n";
                if (box==1) {
                    cout << "\nComputer wins\nYou loose the game because it is your chance and only one stick is left\n";
                    break;
                }
            }
            else{
                cout<< "Try entering a valid number\n";
                goto chooseagain;
            }
            
            BOX_FIXID=box;
        }
    }
    else {
        cout << "Computer's chance first \n";
        sticks=computer_turn_first(box,range);
        box-=sticks;
        cout <<"The computer choose: "<<sticks<<"\nThe Remaining stick in the box are: "<< box <<"\nYour turn now\n";
        BOX_FIXID=box;
        goto chooseagain;
        
    }
    
    cout<<"\n    GAME OVER \n\n\n Press enter to exit the Game \n\n\n\n\n\n\n\n";
    getchar();
    return 0;
}

// Computers thought process functions

// if computers turn is first
int computer_turn_first(int box,int range){
    int sticks_Comp, adjustment=box %(range+1);
    if (adjustment>1) {
        sticks_Comp=adjustment-1;
    }
    else if (adjustment==1){
        sticks_Comp=range/2;                               // Chances that computer can loose
    }
    else if(adjustment<1){
        sticks_Comp=range;
    }
    //  Final check on comuters algorithm
    
    if (sticks_Comp>0 && sticks_Comp<=range) {
        return sticks_Comp;
    }
    else {
        cout<<"ERROR function computer_turn_first(return 0)\nSorry sir cannot make a decision here please check my brain \nCheck computer as first decision function";
        return 0;
    }
}

// if computers turn is not first

int computer_turn(int box,int range,int sticks_user,int BOX_FIXED){  // Sticks_user can enter in the range interval [1,range]
    int sticks_Comp;
    int adjustment=BOX_FIXED % (range+1);
    // no need to do adjustment
    if (adjustment==1){
        sticks_Comp=range-sticks_user+1;
        //cout<<"\nYou Fell into trap\n";
    }
    // cases that need adjustment
    else if (adjustment>1){
        if ((range+adjustment-sticks_user)>0 && (range+adjustment-sticks_user)<=range) {
            sticks_Comp=range+adjustment-sticks_user;
            //cout<<"\nYou Fell into trap\n";
        }
        else if ((range+adjustment-sticks_user)==(range+1)){
            sticks_Comp=sticks_user;                                 //chances that computer can loose
        }
        else if((range+adjustment-sticks_user)>(range+1) && (range+adjustment-sticks_user)<=(2*range-1)) {
            sticks_Comp=range+adjustment-sticks_user;
            sticks_Comp-=(range+1);
            //cout<<"\nYou Fell into trap\n";
        }
        
        else{
            
            cout<<"\nERROR Missing Code\n left one section of code\n";
            /*this message shouldnt be displayed because all possible casses have been considered */
        }
    }
    else if (adjustment<1){
        if (sticks_user>0 && sticks_user<range){
            sticks_Comp=range - sticks_user;
            //cout<<"\nYou Fell into trap\n";
            
        }
        else if(sticks_user==range){                      //chances computer can loose
            sticks_Comp=sticks_user;
        }
        else{
            cout<<"\nERROR Missing Code\n left one section of code\n";
            /*this message shouldnt be displayed because all possible casses have been considered */
        }
    }
    
    // Final check on comuters algorithm
    
    if (sticks_Comp>0 && sticks_Comp<=range) {
        return sticks_Comp;
    }
    else {
        cout<<"ERROR function computer_turn (return 0)\nSorry sir cannot make a decision here please check game code\nSpecifically check computer as not a first decision function";
        return 0;
    }
    
}
