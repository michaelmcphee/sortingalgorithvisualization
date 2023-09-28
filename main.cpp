#include "array.h"
#include <iostream>
#include <windows.h>
#include <conio.h>


void start(array UI);
void run();

int main(){
    while(true){
        array UI(0);
        start(UI);
        char ch = getch();
        if (ch == '1') run();
        else if (ch == '2') return 0;
    }

    return 0;
}

void start(array UI){
    system("cls");
    UI.setxy(10,2); std::cout<<" -------------------------- ";
    UI.setxy(10,3); std::cout<<" | C++ Sorting Algorithms | ";
    UI.setxy(10,4); std::cout<<" |    by Michael McPhee   | ";
    UI.setxy(10,5); std::cout<<" -------------------------- ";
    UI.setxy(10,6); std::cout<<"1. Start"; 
    UI.setxy(10,7); std::cout<<"2. Quit";
    UI.setxy(10,8); std::cout<<"Select option: ";
}

void run(){
    
    unsigned int size = 0;
    
    while(!size){
        system("cls");
        std::cout<<"Enter array size: ";
        std::cin>>size;
        if (size > 50 ) {
            std::cout<<"Stop trying to break my laptop. Try again";
            size = 0;
        }
    }
    array arr(size);
    arr.sort();
}