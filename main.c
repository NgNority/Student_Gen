//Student Generator By:NgNority

//This is a simple generator which picks a random age,name and grade and writes to a file
//You are free to use this but when using this code please make sure to credit the owner
//Thanks, NgNority
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <time.h>


struct student{
    char Name[15];
    char Grade[5];
    char Age[5];
};

void GenerateStudent(int numOfStudents){

    //Setting struct
    struct student sdv[numOfStudents];

    //Setting Default Values

    //Just a list of names I pulled off the internet
    char names[50][15] = {
        "Daniel",
        "Olivia",
        "Blair",
        "Charley",
        "Tom",
        "Jim",
        "Peter",
        "Liam",
        "Tasha",
        "Marissa",
        "Alexa",
        "Ben",
        "Kylie",
        "Jasmin",
        "Jaz",
        "Merik",
        "Nathan",
        "William",
        "Lucas",
        "Mason",
        "Logan",
        "Alexander",
        "Jack",
        "Owen",
        "James",
        "Oliver",
        "Jackson",
        "Carter",
        "Ryan",
        "Matthew",
        "Emma",
        "Ava",
        "Sophia",
        "Charlotte",
        "Emily",
        "Abigail",
        "Chloe",
        "Isabella",
        "Avery",
        "Ella",
        "Lily",
        "Amelia",
        "Hannah",
        "Sofia",
        "Grace",
        "Victoria",
        "Maya",
        "Audrey",
        "Evelyn",
        "Nolan",

    };
    const char grades[5][3] = {"A","B","C","D","F"};
    const int ages[] = {5,6,7,8,9,10,11,12,13,14,15,16,17};
    
    int nameNum,gradeNum,ageNum;

    //Getting Rand seed using time
    time_t t;

    srand((unsigned) time(&t));

    for(int i = 0;i <= numOfStudents;i++){
        //Generating Rand #
        nameNum = rand() % 50;
        gradeNum = rand() % 5;
        ageNum = rand() % 13;

        //Writing Values to Array
        strcpy(sdv[i].Name, names[nameNum]);
        strcpy(sdv[i].Grade, grades[gradeNum]);
        sprintf(sdv[i].Age, "%d", ages[ageNum]);
    }

    //Makes a file called student_records.txt so you get the output of this app
    FILE * fpointer = fopen("school_records.txt", "a");

    printf("Writing to file...\n");

    for(int n = 0;n < numOfStudents;n++){
        //Printing Records into the file        
        fprintf(fpointer, "Name: %s     Age: %s     Avg Grade: %s\n", sdv[n].Name,sdv[n].Age,sdv[n].Grade);
    }
  
    printf("Done!\n");
    //Removing the file from memory and saving changes
    fclose(fpointer);
};


//some pre-built screens that can be re-used
void mainMenu(){
    printf("---------------Main Menu---------------\n");
    printf("█████▒▒ 1.Generate Students\n");
    printf("█████▒▒ 2.Clear Records\n");
    printf("█████▒▒ 3.Exit\n");
    printf("---------------------------------------\n");
}

void genMenu(){
    printf("-------------Generate Menu-------------\n");
    printf("Enter # of records you want to make\n");
    printf("---------------------------------------\n");
}

void cleanMenu(){
    printf("--------------Clear Menu---------------\n");
    printf("Are you sure that you want to delete\nall information from the file?\n[Y]es or [N]o\n");
    printf("-------------------------------------\n");
}


int main(){
    //Declaring Variables
    //We cant leave this one unasigned just becuase it can cause an error if the use types 0
    int recordRequests = 1;
    int i;
    char entOption;
    int exitNum = 0;
    while(exitNum == 0){
        //Displays Main Menu and waits for user input
        mainMenu();
        printf("Enter Option: ");
        scanf(" %c", &entOption);

        if(entOption == '1'){
            //Gets the # of records to generate and feeds them into the generator
            printf("\n");
            genMenu();
            printf("Enter Value: ");
            scanf("%d", &recordRequests);

            GenerateStudent(recordRequests);
        }else if(entOption == '2'){
            char ans;
            int loopExit = 0;
            //Displays Clear Menu and waits for user input
            cleanMenu();
            printf("Enter Value: ");
            scanf(" %c", &ans);
                
            if(ans == ('Y' | 'y')){
                //Cleans the file by making it blank
                printf("Cleaning file...\n");
                FILE * fpointer = fopen("school_records.txt", "w");
                //Printing Records into the file        
                fprintf(fpointer,"");
                //Removing the file from memory and saving changes
                fclose(fpointer);
                printf("Clean sucsessful!\nReturning to menu...\n");
                loopExit = 0;
            }else if(ans == ('N' | 'n')){
                    //This sends the user back to the Main Menu if they declined to clear the file
                    printf("Sending back to main menu...\n");
                    loopExit = 1;
                }else{
                    printf("Invalid Option Please type Y for yes or N for no\n");
                }
            }else if(entOption == '3'){
                //This just brakes the loop by not making it true and then the code ends
                printf("Exiting App...\n");
                exitNum = 1;
            }else{
                printf("Please enter valid number\n");
            }

    }

    return 0;
}