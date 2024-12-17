#include<iostream>
#include<stdlib.h>
#include<ctime>

using namespace std;

class game
{
    private:
    int round;
    string name;
    int champscore=0;
    int userscore=0;



public:
//constracture
game()
{
    cout << "Enter your Name :" << endl;
    cin >> name;

    cout << name <<" how many round :" << endl;
    cin >> round;


}
//method
int champchoice()
{
    srand(time(0)); // here is we used time() function to seed in srand().
    int champchoice = rand() % 3 + 1; //here we create auto choice for computer with rand() from 1 to 3(Rock , Paper , Scissor).
    return champchoice;
}
//function
void gameround()
{
    for(int i=1; i<=round; i++)
    {
        int userchoice;
        int champchoice;

        cout << "-------GAME-------";

        cout <<"round no" <<i <<"/" <<round <<endl;
        cout <<name << "score=" <<userscore <<endl;
        cout << "computer score="<<champscore <<endl;

        cout <<" rock" <<endl;
        cout <<"paper" <<endl;
        cout <<"scissor" <<endl;

        cout <<"select your choice is " ;
        cin >>userchoice;
        champchoice= compchoice();

        cout << "computer choice is" <<champchoice<<endl;

        //condision
        if (userchoice==champchoice)
        {
                cout <<"draw";
        }

        else
        {
            if (userchoice==1 && champchoice==3)
            {
                userscore++;
            }
            else if(userchoice==2 && champchoice==1)
            {
                userscore++;
            }   
            else if(userchoice==3 && champchoice ==2)
            {
                userscore++;
            }
            else
            {
                champscore++;
            }
        }
    }
}
//function
void result()
{
    if (userscore > champscore)
    {
        cout << "\t\t---Winner is " << name;
    }
    else if (userscore < champscore)
    {
        cout << "\t\t---Winner is Computer";
    }
    else
    {
        cout << "\t\t---Game is Drawn";
    }

}  
};

int main()
{
    game g;
    g.gameround();
    g.result();
    return 0;
}
