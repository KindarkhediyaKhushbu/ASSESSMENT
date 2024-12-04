#include<iostream>
#include<stdlib.h>
#include<ctime>

using namespace std;

class game
{
    //this is private data members
    private:
    int rounds;
    string name;
    int compScore=0;
    int userScore=0;
//here is public metbods and constructors.
public:
//this is constructor called automatically when class object will create.
// constructor take input from user.
game()
{
    cout << "-----------------------------------------*\n";
    cout << " \t\t\t\tNAME\n";  
    cout << "-----------------------------------------*\n";
    cout << "Enter your name : ";
    cin >> name;
    cout << "-----------------------------------------*\n";
    cout << " \t\t\t\tROUNDS\n";
    cout << "-----------------------------------------*\n";
    cout << name << " How Many Rounds You Want To Play?  : ";
    cin >> rounds;   
}

//this is method function to create auto choice for computer using inbluid function.
int compchoice()
{
    std::srand(std::time(0)); // here is we used time() function to seed in srand().
    int comchoice = std::rand() % 3 + 1; //here we create auto choice for computer with rand() from 1 to 3(Rock , Paper , Scissor).
    return comchoice;//this will return computer choice.
}
//this function is to play rounds entered by users.
void gameRounds()
{
    //this for loop start from 1 runs till the entered rounds by user.
    for (int i = 1; i <=rounds; i++)
    {    
        int userChoice;
        int compChoice;
        cout << "-----------------------------------------*\n";
        cout << " \t\t\t\tGAME\n";
        cout << "-----------------------------------------*\n";
        cout << "Round No : " << i <<"/" << rounds << endl <<endl; // this will show current runnig round.
        cout << name <<"'s Score = "<< userScore <<endl; // this shows user score.
        cout << "Computer's Score = "<< compScore << endl; // this shows computer score.

        cout << "\n1) ROCK" << endl;
        cout << "2) PAPER" << endl;
        cout << "3) SCISSOR" << endl;

        cout << "-> Select Your Choice : ";
        cin >> userChoice;
        compChoice=compchoice();//here we calling commputer choice function and assign value to variable.
        cout << "-> Computer Choice Is : " << compChoice << endl;
        //this if conditon runs to check score and add score accordingly.
        if (userChoice==compChoice)
        {
            cout << "\tDRAW\n\n";
        }
        else
        {
            if (userChoice == 1 && compChoice == 3)
            {
                userScore++;
            }
            else if (userChoice == 2 && compChoice == 1)
            {
                userScore++;
            }
            else if (userChoice == 3 && compChoice == 2)
            {
                userScore++;
            }
            else
            {
                compScore++;
            }
            
        }

    }
}
//this is result function
void result()
{   
    //this if condition checks final score and show winner on screen.
    if (userScore > compScore)
    {
        //if users final score is greater then user is winner.
        cout << "\t\t---Winner is " << name;
    }
    else if (userScore < compScore)
    {
        //if users final score is less them computer is winner.
        cout << "\t\t---Winner is Computer";
    }
    else
    {
        //else both score are equal then Draw.
        cout << "\t\t---Game is Drawn";
    }
    
}
};


int main()
{
    //this object of class game.
    game g;

    g.gameRounds();//here we are calling gameround function of class game.
    g.result();//here we are calling result function of class game.
    return 0;
}