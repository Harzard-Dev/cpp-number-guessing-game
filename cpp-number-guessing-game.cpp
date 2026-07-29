#include <iostream>
#include <ctime>

void difficulty(int &hints, int &chances, int menuchoice); 
void gameorsum(int hints, int chances, int num, int usernum);

int main(){
    int num;
    int usernum;
    int menuchoice;
    int hints = 0;
    int chances = 0;


    srand(time(0));

    std::cout << "Welcome to the Number Guessing Game!\n";
    std::cout << "I'm thinking of a number between 1 and 100.\n";

    do {
        std::cout << "\nPlease select the difficulty level:\n";
        std::cout << "1. Easy (10 Chances, 1 Hint)\n";
        std::cout << "2. Medium (5 Chances, 1 Hint)\n";
        std::cout << "3. Hard (3 Chances, 1 Hint)\n";
        std::cout << "4. Quit\n";
        std::cout << "Enter your choice: ";
        std::cin >> menuchoice;

        if(menuchoice >= 1 && menuchoice <= 3){
            difficulty(hints, chances, menuchoice);
            
            // TODO: finish the actual game thingy functions here with chance and hints if your dumb self forgets, (Edit) I think i did it
            gameorsum(hints, chances, num, usernum);
            
        } else if (menuchoice == 4) {
            std::cout << "Goodbye!\n";
        } else {
            std::cout << "Please type in a valid response!\n";
        }

        // idk ig it just clears the thing and like ignores the trash so, all i need to know that it stops looping 😁
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
    } while(menuchoice != 4);

    return 0;
}

// realized my stupid ah used int even though we just changed the variables without returning anything, *changed to void*
void difficulty(int &hints, int &chances, int menuchoice){
        switch(menuchoice){
        case 1:
            std::cout << "You chose Easy! You get 10 Chances and 1 Hint.\n";
            hints = 1;
            chances = 10;
            break;
        case 2:
            std::cout << "You chose Medium! You get 5 Chances and 1 Hint\n";
            hints = 1;
            chances = 5;
            break;
        case 3:
            std::cout << "You chose Hard... You only get 3 Chances and 1 Hint\n";
            hints = 1;
            chances = 3;
            break;
        default:
            std::cout << "It seems like you've hit a wall, try again!\n";
            break;
    }
}

void gameorsum(int hints, int chances, int num, int usernum){
    std::cout << "Try and guess my number, it's between 1-100...\n";

    num = rand() % 100 + 1;

    int chancesDIFF = chances;

    do{
        std::cout << "Enter the number '0' for a hint!\n";
        std::cin >> usernum;

        if(usernum == 0 && hints > 0 && chances != 0){
            if(num >= 50){
                std::cout << "The number is between 50-100...\n";
                hints -= 1;
                std::cout << "You have " << hints << " hints left.\n";
            } else if(num < 50){
                std::cout << "The number is between 1-49...\n";
                hints -= 1;
                std::cout << "You have " << hints << " hints left.\n";
            }
        } else if(usernum == 0 && hints == 0){
            std::cout << "You're out of hints, sorry!\n";
        } else if(usernum == num){
            std::cout << "You guessed the number! It was, " << num << "!\n";
            chances -= 1;
            std::cout << "It took you " << chancesDIFF - chances << " attempts.\n";
            break;
        } else if(usernum > num){
            std::cout << "Too High!\n";
            chances -= 1;
        } else if(usernum < num){
            std::cout << "Too Low!\n";
            chances -= 1;
        }
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }while(usernum != num && chances != 0);
}
