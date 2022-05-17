#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 120


typedef struct {
    int id;
    char movieName[35];
    char moviesDirector[30];
    int year;
    char movieType[30];
}movie;



int main()
{


    FILE*file1;

    file1 = fopen("movies.csv","r");
    int movieCount = 60;
    movie allMovies[movieCount];
    int countOfMovie=0;
    int a=1;

    char keyboard[15];



    while(countOfMovie!=60){

        char fullLine[SIZE];
        fgets(fullLine,120,file1);
        char checkName[30];
        char checkDirector[30];

        allMovies[countOfMovie].id=a;
        strcpy(allMovies[countOfMovie].movieName,strtok(fullLine,","));
        strcpy(checkName,strtok(NULL,","));

        if(checkName[0]==' '){

            strncat(allMovies[countOfMovie].movieName,checkName,20);
            strcpy(allMovies[countOfMovie].moviesDirector,strtok(NULL,","));
            strcpy(checkDirector,strtok(NULL,",")); //else atoi
            if(checkDirector[0]==' '){
                strncat(allMovies[countOfMovie].moviesDirector,checkDirector,20);
                allMovies[countOfMovie].year = atoi(strtok(NULL,","));
            }else{
                allMovies[countOfMovie].year = atoi(checkDirector);
            }
        }else {

            strcpy(allMovies[countOfMovie].moviesDirector,checkName);
            strcpy(checkDirector,strtok(NULL,",")); // else atoi
            if(checkDirector[0]==' '){
                strncat(allMovies[countOfMovie].moviesDirector,checkDirector,20);
                allMovies[countOfMovie].year = atoi(strtok(NULL,","));

            }else{
                allMovies[countOfMovie].year = atoi(checkDirector);
            }
        }
        strcpy(allMovies[countOfMovie].movieType,strtok(NULL,","));
        int lengtthOfType = strlen(allMovies[countOfMovie].movieType);

        allMovies[countOfMovie].movieType[lengtthOfType-1] = '\0';

        a++;
        countOfMovie++;

    }
fclose(file1);



    while(strcmp(keyboard,"exit")!=0){
        printf("Please enter a command: ");
        gets(keyboard);

        if(strcmp(keyboard,"print")==0){

           for(int b=0;b<countOfMovie;b++){
           printf("%d. %s, %s, %d, %s\n",allMovies[b].id,allMovies[b].movieName,allMovies[b].moviesDirector,allMovies[b].year,allMovies[b].movieType);
            }
        }
        if(strcmp(keyboard,"update")==0){

            char idd[2];
            char name[15];
            char director[15];
            char year[15];
            char genre[15];
            char wholeData[35];

            printf("ID: ");
            gets(idd);
            printf("New info: ");
            gets(wholeData);
            strcpy(name,strtok(wholeData,","));
            strcpy(director,strtok(NULL,","));
            strcpy(year,strtok(NULL,","));
            int newYear = atoi(year);
            strcpy(genre,strtok(NULL,","));


            int id=atoi(idd);
            if(strcmp(name," ")!=0){
                strcpy(allMovies[id-1].movieName,name);
            }
            if(strcmp(director," ")!=0){
                strcpy(allMovies[id-1].moviesDirector,director);
            }
            if(strcmp(year," ")!=0){
                allMovies[id-1].year=newYear;
            }
            if(strcmp(genre," ")!=0){
                strcpy(allMovies[id-1].movieType,genre);
            }
        }
        if(strcmp(keyboard,"search")==0){

                printf("Search condition: ");
            char definiton[15];
            char condition[5];
            char searching[15];
            char wholeSearchingData[30];
            gets(wholeSearchingData);
            strcpy(definiton,strtok(wholeSearchingData," "));
            strcpy(condition,strtok(NULL," "));
            strcpy(searching,strtok(NULL," "));

            if(strcmp(definiton,"genre")==0){

                if(strcmp(condition,"==")==0){

                    for(int k=0;k<60;k++){

                            if(strcmp(allMovies[k].movieType,searching)==0){
                                 printf("%d. %s, %s, %d, %s\n",allMovies[k].id,allMovies[k].movieName,allMovies[k].moviesDirector,allMovies[k].year,allMovies[k].movieType);
                            }

                    }
                }

                if(strcmp(condition,"!=")==0){
                    for(int k=0;k<60;k++){

                            if(strcmp(allMovies[k].movieType,searching)!=0){
                                 printf("%d. %s, %s, %d, %s\n",allMovies[k].id,allMovies[k].movieName,allMovies[k].moviesDirector,allMovies[k].year,allMovies[k].movieType);
                            }

                    }
                }
            }else if(strcmp(definiton,"year")==0){

                if(strcmp(condition,"==")==0){
                    for(int k=0;k<60;k++){

                            if(allMovies[k].year==atoi(searching)){
                                 printf("%d. %s, %s, %d, %s\n",allMovies[k].id,allMovies[k].movieName,allMovies[k].moviesDirector,allMovies[k].year,allMovies[k].movieType);
                            }

                    }

                }

                if(strcmp(condition,"!=")==0){
                    for(int k=0;k<60;k++){

                            if(allMovies[k].year!=atoi(searching)){
                                 printf("%d. %s, %s, %d, %s\n",allMovies[k].id,allMovies[k].movieName,allMovies[k].moviesDirector,allMovies[k].year,allMovies[k].movieType);
                            }

                    }

                }

                 if(strcmp(condition,"<")==0){
                    for(int k=0;k<60;k++){

                            if(allMovies[k].year<atoi(searching)){
                                 printf("%d. %s, %s, %d, %s\n",allMovies[k].id,allMovies[k].movieName,allMovies[k].moviesDirector,allMovies[k].year,allMovies[k].movieType);
                            }

                    }

                }

                if(strcmp(condition,">")==0){
                    for(int k=0;k<60;k++){

                            if(allMovies[k].year>atoi(searching)){
                                 printf("%d. %s, %s, %d, %s\n",allMovies[k].id,allMovies[k].movieName,allMovies[k].moviesDirector,allMovies[k].year,allMovies[k].movieType);
                            }

                    }

                }



            }



        }

    }
    printf(" Exiting program.");


return 0;


}
