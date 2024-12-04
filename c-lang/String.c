#include<stdio.h>
#include<string.h>

//This is function declaration
void strInput();
void strConcatinate();
void strPalindrome();
void strFrequency();
void strCharVowel_Consonant();
void strSpaceDigit();

// here we Declared Global Variables //we used global variable bcoz in c lang we cann't return string normally
    char str1[50];
    char str2[50];

int main()
{
     int choice;
     // here we used do while loop to show menu
    do
    {

        printf("\n");
        printf("\n-------------MAIN MENU-----------");
    
        //these are menus of program
        printf("\n1. REVERSE");
        printf("\n2. CONCATINATE");
        printf("\n3. PALINDROME");
        printf("\n4. COPY STRING");
        printf("\n5. LENGHT OF STRING");
        printf("\n6. Frequency of Character in STRING");
        printf("\n7. Find Number of Vowels and Consonants");
        printf("\n8. Find Number of Blank Spaces and Digits");
        printf("\n9. Exit");

        printf("\nChoose your operation from above : ");
        scanf("%d", &choice);

        //this (if--condition) is used to exit the program
        if (choice == 9)
        {
            printf("------Thank you------");
            break;
        }

        //here we used switch case for what do when user choose option from menu
        switch (choice)
        {
        case 1:
            strInput();  //function call for input
            printf("\n\t--Reverse string : %s",strrev(str1));  //here we used in built function strrev() for REVERSE the string
            break;
        case 2:
            strConcatinate();  //function call for concatinate 2 string
            break;
        case 3:
            strInput();
            strPalindrome();  //function call for palidrome
            break;
        case 4:
            strInput();
            strcpy(str2,str1);  //here we used in built function strcpy() for Copy string
            printf("\n\t--Entered String : %s",str1);
            printf("\n\t--String after copy is %s",str2);
            break;
        case 5:
            strInput();
            printf("\n\t--lenght of string : %d",strlen(str1));  //here we used in built function strlen() to find string lenght
            break;
        case 6:
            strFrequency();  //function call for frequency
            break;
        case 7:
            strCharVowel_Consonant(); //functin call for vowel & consonant
            break;
        case 8:
            strSpaceDigit();  //function call for blank spaces & Digits
            break;
        default:
            printf("!INVALID INPUT <ENTER VALID INPUT>");
            break;
        }

        //here  we asking user to continue or exit
        int conti=0;
        printf("\n\n\tDo you want to Continue<Press 1 to continue> ");
        scanf(" %d",&conti);
        if(conti==1)
        {
            continue;
        }
        else
        {
            printf("------Thank you------");
            break;
        }        
    } while (1);

    return 0;
}


//Function defination
void strInput()
{
    //this function take input string for users.
    printf("\nPlease Enter the String : ");
    fflush(stdin);  //here we used function fflush for clear buffer like unnecessary spaces 
    gets(str1);
}

void strPalindrome()
{
    // strcpy(str2,str1);
    // strrev(str2);
    //printf("\n\t--Enter string is %s ",str1);
    //printf("\n\t--Enter string is %s ",str2);
    //printf("\nlenght is %d",lenght);
    //printf("\n%d",palin);

    //this function is to check string is palindrome or not
    //here we get length of string and run for loop till length
    int lenght,palin=1;
    lenght=strlen(str1);
    lenght-=1;
    for (int i = 0; i < lenght; i++)
    {
        //string is not palindrome then this if--condition assing 0 in palin variable 
        if(str1[lenght]!=str1[i])
            palin=0;
        lenght--;
    }
    //this if--condition for output (if palin variable has 1 means string is palindrome else not palindrome
    if(palin==1)
    {
        printf("\n\t--%s is Palindrome String.",str1);
    }
    else
    {
        printf("\n\t--%s is not Palindrome String.",str1);
    }
    
}

void strConcatinate()
{
    //in this function we join 1 string to unother string using in built function strcat()
    strInput();
    printf("Please Enter Second String to concate : ");
    gets(str2);
    strcat(str1,str2);

    printf("\n\t--Concatinated string : %s",str1);
}

void strFrequency()
{
    //in this function we check the charcter given by user is how many times appears in string
    char ch,count=0;
    strInput();
     printf("Enter a character to find its frequency : "); //asking for character
    scanf(" %c", &ch);

    //this for loop runs untill null character
    //here we check every character of string to given character by user
    for (int i = 0; str1[i] != '\0'; i++)
    {
        //if given character match with string character then it add 1 in count variable
        if (str1[i]==ch)
        {
            count++;
        }
        
    }
    printf("\n\t--Frequency of Character %c is %d",ch,count);
}

void strCharVowel_Consonant()
{
    //in this function we count numbers of vowels and consonant in string
    strInput();
    int vowel=0,consonant=0;
    //this for loop runs untill null character
    //here we check every character of string to vowels if character is vowel then add 1 in variable vowel else add 1 in variable consonant
    for (int j = 0; str1[j] != '\0'; j++)
    {
        if ((str1[j]=='a' || str1[j]=='A') || (str1[j]=='e' || str1[j]=='E') || (str1[j]=='i' || str1[j]=='I') || (str1[j]=='o' || str1[j]=='O') || (str1[j]=='u' || str1[j]=='U'))
        {
            vowel++;
        }
        else if (str1[j]==' ')
        {
            continue;
        }
        else
        {
            consonant++;
        }
        
    }
    printf("\n\t--Total Vowel : %d",vowel);
    printf("\n\t--Total Consonant : %d",consonant);
    
}

void strSpaceDigit()
{
    //in this function we count numbers of Blank spaces and Digits in string
    int space=0,digit=0;
    strInput();
    //this for loop runs untill null character
    //here we check every character of string to digits and space
    // if character is digit then add 1 in variable digit if there was a space then add 1 in variable space
    for (int i = 0; str1[i]!='\0' ; i++)
    {
        if (str1[i]=='1' || str1[i]=='2' || str1[i]=='3' || str1[i]=='4' || str1[i]=='5' || str1[i]=='6' || str1[i]=='7' || str1[i]=='8' || str1[i]=='9' || str1[i]=='0')
        {
            digit++;
        }
        else if (str1[i]==' ')
        {
            space++;
        }
    }
    
    printf("\n\t--Total Blank Spaces : %d",space);
    printf("\n\t--Total Digits : %d",digit);
} 