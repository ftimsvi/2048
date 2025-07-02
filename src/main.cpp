#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#define MAX_SIZE 40
using namespace std;

void write(char a[2][100]);
bool read(char b[2][100]);
void startgame();
void play_game(int g_size);
int generate_random_block();
void show_board(struct game g);
void zero(int arr[][MAX_SIZE]);
bool check_lose(struct game g);
bool check_win(struct game g);

struct game
{
    int size;
    int board[MAX_SIZE][MAX_SIZE];
    int score;
//    int maxx;
//    string difficulty;
};

int main()
{
    srand(time(NULL));
    int choice;
    //play_game(4);
    cout << "******************** LOGIN ********************\n";
    cout << "1.Register";
    cout << "\n2.Login";
    cout << "\n3.Exist";
    cout << "\nEnter your choice :";
    cin >> choice;
    if(choice==1){
        char up[2][100];
        char upp[2][100];
        bool flag=0;
        system("cls");
        cout << "Enter the username :";
        cin >> up[0];
        cout << "Enter the password :";
        cin >> up[1];
        FILE *fp;
        fp = fopen("d:\\myfile.txt", "r+");
        while(1){
            fscanf(fp, "%s", &upp[0]);
            if(feof(fp)){
                break;
            }
            fscanf(fp,"%s",&upp[1]);
            if(strcmp(upp[0],up[0])==0)
                flag=1;
        }
        if(flag==1){
            cout << "Sorry, this username has already been selected";
            main();
        }
        else{
            write(up);
            cout << "Registration completed successfully";
            main();
        }
    }
    else if(choice==2){
        char pu[2][100];
        system("cls");
        cout << "Enter the username :";
        cin >> pu[0];
        cout << "Enter the password :";
        cin >> pu[1];
        if(read(pu)){
            system("cls");
            cout << "Hello " << pu[0] << "\nWe're glad that you're here\n";
            startgame();
        }
    }
    else if(choice==3){
        cout << "Thanks for using the login page\n";
        return 0;
    }
    else{
        cout << "Sorry, wrong choice selected\n";
        main();
    }
    return 0;
}

void write(char a[2][100])
{
    FILE *fp;
    fp = fopen("d:\\myfile.txt", "a+");
    fprintf(fp, "%s %s\n", a[0], a[1]);
}

bool read(char b[2][100])
{
    char u[2][100];
    FILE *fp;
    fp = fopen("d:\\myfile.txt", "r");
    while(1){
        fscanf(fp, "%s", &u[0]);
        if(feof(fp)){
            break;
        }
        fscanf(fp,"%s",&u[1]);
        if(strcmp(u[0],b[0])==0 && strcmp(u[1],b[1])==0)
            return true;
    }
    return false;
}

void startgame()
{
    game g;
    int choice;
    cout << "******************** GAME MENU ********************\n";
    cout << "1.New game";
    cout << "\n2.Load game";
    cout << "\n3.Change password";
    cout << "\n4.Log out";
    cout << "\nEnter your choice :";
    cin >> choice;
    if(choice==1){
        int choice;
        system("cls");
        cout << "1.Easy";
        cout << "\n2.Intermediate";
        cout << "\n3.Difficult";
        cout << "\n4.Custom mode";
        cout << "\nEnter your choice :";
        cin >> choice;
//        if(choice==1)
//            g.difficulty="Easy";
//        else if(choice==2)
//            g.difficulty="Intermediate";
//        else if(choice==3)
//            g.difficulty="Difficult";
//        else if(choice==4)
//            g.difficulty="Custom mode";
        switch (choice)
        {
        case 1:
            play_game(6);
            break;
        case 2:
            play_game(5);
            break;
        case 3:
            play_game(4);
            break;
        case 4:{
            int size_board;
            cout << "\nEnter the size:";
            cin >> size_board;
            play_game(size_board);
            break;
        }
        default:
            cout << "Sorry, wrong choice selected\n";
            startgame();
            break;

        }

    }
//    else if(choice==2)
    else if(choice==3){
        char change[2][100], bch[2][100], c;
        FILE *ffp, *ggp;
        system("cls");
        cout << "Enter your username:";
        cin >> change[0];
        cout << "\nEnter new password:";
        cin >> change[1];
        ffp = fopen("d:\\myfile.txt", "r");
        ggp = fopen("d:\\replacefile.txt", "w");
        while(1){
            fscanf(ffp, "%s", &bch[0]);
            if(feof(ffp)){
                break;
            }
            fscanf(ffp,"%s",&bch[1]);
            if(strcmp(bch[0],change[0])==0)
                strcpy(bch[1], change[1]);
            fprintf(ggp, "%s %s\n", bch[0], bch[1]);
        }
        fclose(ffp);
        fclose(ggp);
        ggp = fopen("d:\\replacefile.txt", "r");
        ffp = fopen("d:\\myfile.txt", "w");
        c = fgetc(ggp);
        while (c != EOF)
        {
            fputc(c, ffp);
            c = fgetc(ggp);
        }
        ggp = fopen("d:\\replacefile.txt", "w");
    }
    else if(choice==4){
        system("cls");
        main();
    }
    else{
        cout << "Sorry, wrong choice selected\n";
        startgame();
    }
}

void play_game(int g_size)
{
    //////////////////////////
    //initializing the game
    game g;
    zero(g.board);
    g.score=0;
    g.size=g_size;

    int x=rand()%g_size;
    int y=rand()%g_size;
    g.board[x][y]=generate_random_block();
    while(g.board[x][y]!=0){
        x=rand()%g_size;
        y=rand()%g_size;
    }
    g.board[x][y]=generate_random_block();
    //////////////////////////
    while(1){
        system("cls");
        show_board(g);
        //options up_arrow:up down_arrow:right left_arrow:left down_arrow:down s:save q:quit r:reset
        bool moved=0;
        //movment checker if blocks move it toggles
        char command;
        //input
        command=getch();
        if (command == 224) {
        //getting arrow as input
        getch();
        command=getch(); }

        int changed[MAX_SIZE][MAX_SIZE];
        //a matrix to check if number of block is changed this turn
        zero(changed);
        switch(command)
        {
        //////////////////////////////////////
        case 's':
            //save
            break;

        case 'r':
            //reset
            play_game(g.size);
            break;

        case 'q':
            //quit
            system("cls");
            main();
            break;
        //////////////////////////////////////
        case 72:
            //up
            for(int i=0; i<g.size; i++)
                for(int j=0; j<g.size; j++){
                    int temp=j;
                    if(g.board[temp][i]==0)
                            continue;
                    while(temp>0){
                        if(g.board[temp-1][i]==0){
                            g.board[temp-1][i]=g.board[temp][i];
                            g.board[temp][i]=0;
                            moved=1;
                            }
                        else if(g.board[temp-1][i]==g.board[temp][i] && !changed[temp-1][i]){
                            //if number of two adjacent blocks are same and neither of them was changed this turn
                            g.board[temp-1][i]*=2;
                            g.score+=g.board[temp-1][i];
                            changed[temp-1][i]=1;
                            //this block is changed this turn
                            g.board[temp][i]=0;
                            moved=1;
                            break;
                        }
                        else
                            break;
                        temp--;
                    }
                    }
            break;
        /////////////////////////////////////
        case 75:
            //left
            for(int i=0; i<g.size; i++)
                for(int j=0; j<g.size; j++){
                    int temp=j;
                    if(g.board[i][temp]==0)
                            continue;
                    while(temp>0){
                        if(g.board[i][temp-1]==0){
                            g.board[i][temp-1]=g.board[i][temp];
                            g.board[i][temp]=0;
                            moved=1;
                            }
                        else if(g.board[i][temp-1]==g.board[i][temp] && !changed[i][temp-1]){
                            g.board[i][temp-1]*=2;
                            g.score+=g.board[i][temp-1];
                            changed[i][temp-1]=1;
                            g.board[i][temp]=0;
                            moved=1;
                            break;
                        }
                        else
                            break;
                        temp--;
                    }
                    }
            break;
        /////////////////////////////////////
        case 77:
            //'right
            for(int i=0; i<g.size; i++)
                for(int j=g.size-1; j>=0; j--){
                    int temp=j;
                    if(g.board[i][temp]==0)
                            continue;

                    while(temp<g.size-1){


                        if(g.board[i][temp+1]==0){
                            g.board[i][temp+1]=g.board[i][temp];
                            g.board[i][temp]=0;
                            moved=1;
                            }
                        else if(g.board[i][temp+1]==g.board[i][temp] && !changed[i][temp+1]){
                            //cout<<"Here";
                            g.board[i][temp+1]*=2;
                            g.score+=g.board[i][temp+1];
                            changed[i][temp+1]=1;
                            g.board[i][temp]=0;
                            moved=1;
                            break;
                        }
                        else
                            break;
                        temp++;
                    }
                    }

            break;
        /////////////////////////////////////
        case 80:
            //down
            for(int i=0; i<g.size; i++)
                for(int j=g.size-1; j>=0; j--){
                    int temp=j;
                    if(g.board[temp][i]==0)
                            continue;
                    while(temp<g.size-1){
                        if(g.board[temp+1][i]==0){
                            g.board[temp+1][i]=g.board[temp][i];
                            g.board[temp][i]=0;
                            moved=1;
                            }
                        else if(g.board[temp+1][i]==g.board[temp][i] && !changed[temp+1][i]){
                            g.board[temp+1][i]*=2;
                            g.score+=g.board[temp+1][i];
                            changed[temp+1][i]=1;
                            g.board[temp][i]=0;
                            moved=1;
                            break;
                        }
                        else
                            break;
                        temp++;
                    }
                    }
            break;

        }
    /////////////////////////////////////
    //generating new block
    if(moved){
    x=rand()%g.size;
    y=rand()%g.size;
    while(g.board[x][y]!=0){
        //checking if new random position is valid
        x=rand()%g.size;
        y=rand()%g.size;
    }
    g.board[x][y]=generate_random_block();}

    /////////////////////////////////////
    //checking win or lose
    if(check_win(g)){
        int ch;
        system("cls");
        cout << "Congratulations you won";
        cout << "\n1.Continue";
        cout << "\n2.Exist";
        cout << "\nEnter your choice:";
        cin >> ch;
        if(ch==1)
            continue;
        else if(ch==2){
            system("cls");
            startgame();
        }
    }

    if(check_lose(g)){
        int choice;
        system("cls");
        cout << "Game over";
        cout << "\n1.Exist";
        cout << "\nEnter your choice:";
        cin >> choice;
        system("cls");
        startgame();
    }
    /////////////////////////////////////
    }

}

int generate_random_block()
{
int num=rand()%100+1;
    if(num<=65)
        return 2;
    else if(num<=90)
        return 4;
    else if(num<=96)
        return 8;
    else if(num<=98)
        return 16;
    else
        return 32;

}

void show_board(game g)
{
    cout<<g.score<<endl;
    for(int i=0;i<g.size;cout<<endl,i++)
        for(int j=0;j<g.size;j++)
            cout<<g.board[i][j]<<" ";
}

void zero(int arr[][MAX_SIZE])
{
    for(int i=0; i<MAX_SIZE; i++)
        for(int j=0; j<MAX_SIZE; j++)
            arr[i][j]=0;

}

bool check_lose(struct game g)
{
    int ans=0, ans1=0;
    for(int i=0; i<g.size; i++)
        for(int j=0; j<g.size; j++)
            if(g.board[i][j]==0)
                ans++;
    if(ans!=0)
        return false;
    else{
        for(int i=0; i<g.size; i++){
            if(i==0)
                for(int j=0; j<g.size; j++){
                    if(j==0)
                        if(g.board[i][j]==g.board[i+1][j] || g.board[i][j]==g.board[i][j+1])
                            ans1++;
                    else if(j==g.size-1)
                        if(g.board[i][j]==g.board[i+1][j] || g.board[i][j]==g.board[i][j-1])
                            ans1++;
                    else
                        if(g.board[i][j]==g.board[i+1][j])
                            ans1++;
                }

            else if(i==g.size-1)
                for(int j=0; j<g.size; j++){
                    if(j==0)
                        if(g.board[i][j]==g.board[i-1][j] || g.board[i][j]==g.board[i][j+1])
                            ans1++;
                    else if(j==g.size-1)
                        if(g.board[i][j]==g.board[i-1][j] || g.board[i][j]==g.board[i][j-1])
                            ans1++;
                    else
                        if(g.board[i][j]==g.board[i-1][j])
                            ans1++;
                }
            else
                for(int j=0; j<g.size; j++){
                    if(j==0)
                        if(g.board[i][j]==g.board[i+1][j] || g.board[i][j]==g.board[i][j+1])
                            ans1++;
                    else if(j==g.size-1)
                        if(g.board[i][j]==g.board[i+1][j] || g.board[i][j]==g.board[i][j-1])
                            ans1++;
                    else{
                        if(g.board[i][j]==g.board[i+1][j])
                            ans1++;
                        else if(g.board[i][j]==g.board[i-1][j])
                            ans1++;
                        else if(g.board[i][j]==g.board[i][j-1])
                            ans1++;
                        else if(g.board[i][j]==g.board[i][j+1])
                            ans1++;
                    }
                }
        }
    if(ans1==0)
        return true;
    else
        return false;
    }
}

bool check_win(struct game g)
{
    int maxx=0;
    for(int i=0; i<g.size; i++)
        for(int j=0; j<g.size; j++)
            if(g.board[i][j]>maxx)
                maxx=g.board[i][j];
//    g.maxx=maxx;
    if(maxx==2048)
        return true;
    else
        return false;
}
