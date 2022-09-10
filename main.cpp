/*
* By 0Ruix on github
* 11.09.2022
* Carefull its a mess
*/

#include <iostream>
#include <ctime>

std::string convert(int a);
std::string compare(int a, int b);

int rounds = 1; 

int main(){

    std::cout << "Welcome to the Rock, Papper, Scissors game!" << "\n";
    std::cout << "Select the amount of rounds you want to play (Default is 1, max is 3) " << "\n";
    std::cin >> rounds;

    if (rounds > 3 || rounds < 0) {rounds = 1;} //If the max round is in valid it sets it to 1. You can edit this line to make the game infinite.

    for(int i = 0; i < rounds; i++){ //Game Loop
        std::cout << "----------------ROUND START---------------- \n";
        srand(time(0));
        int userChoice = 0;

        while (userChoice == 0) //Ask the user for a chice repeat if invalid
        {
            std::cout << "Choose your type (0 for rock, 1 for paper, 2 for scissor) \n";
            std::cin >> userChoice;

            if (userChoice < 0 || userChoice > 2) {std::cout << "Invalid \n"; userChoice = 0;} //If the user choice is invalid the program sets it back to 0 in order to keep the loop going.
            else{break;} 
        }

        std::string uStr = convert(userChoice); 
        std::cout << "Player have choosen " << uStr << " ! \n";

        int aiChoice = 0;
        aiChoice = rand()%3;
        std::string aiStr = convert(aiChoice);
        std::cout << "The Mighty AI have choosen " << aiStr << " !! \n";
        
        std::string result = compare(userChoice, aiChoice);
        
        //Compares the uStr to result In order to determine the winner
        if(result == "Tie"){std::cout << "That's a tie! \n";}
        else if(uStr == result){std::cout << "Player won! \n";}
        else {std::cout << "AI won! \n";}

        if (i == rounds){std::cout << "Thanks for playing";}

    }
    

    return 0;
}

std::string compare(int a, int b){
    std::string rtn = "";
    if (a == b) {rtn = "Tie";}
    else if (a == 0 && b == 2) {rtn = "Rock";}      //Rock wins
    else if (a == 2 && b == 1) {rtn = "Scissors";} //Scissors wins
    else if (a == 1 && b == 0) {rtn = "Paper";}   //paper

    return rtn;
}

std::string convert(int a){ 

    std::string x = " ";
    switch (a)
    {
    case 0:
        x = "Rock";
        break;
    case 1:
        x = "Paper";
        break;
    case 2:
        x = "Scissors";
        break;
    default:
        x = "Huh";
    }

    return x;
}