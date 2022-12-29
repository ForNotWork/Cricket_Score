#include <stdio.h>
#include <stdlib.h>
#include <time.h>
double Win_Status(int AI_SCORE,int PLAYER_SCORE,int REMAINING_PLAYERS,int Balls)
{
    int Over=Balls;
    int AI_Score = AI_SCORE,player_Score=PLAYER_SCORE,Remaining_Players=REMAINING_PLAYERS;
    if(AI_Score< player_Score)
    {
        return 1;
    }
    else if(Remaining_Players == 0)
    {
        return 0;
    }
    else if(Over>6)
    {
        return 0;
    }
    else
        return -1;
}
void AI_Score_Board(int RunI,int WicketI)
{
    int Score_Run=RunI,Score_Wicket=WicketI;
    printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
    printf("\xcd\xcd\xcd SCORE BOARD \xcd\xcd\xcd\xcd\xcd\n");
    printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd");
    printf("______________________\n");
    printf("|RUN:   |%d\t\t",Score_Run);
    printf("|WICKET:|%d\t\n",Score_Wicket);
    printf("______________________");
}
void Player_Score_Board(int Run_P,int Balls,int wICKETS,int Ai_SCORE)
{
    int over=Balls;
    int Score_RunP = Run_P;
    int Score_Wicket = wICKETS;
    int Remaining_Runs =Ai_SCORE-Score_RunP; 
    printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
    printf("\xcd\xcd\xcd SCORE BOARD xcd\xcd\xcd\xcd\xcd\n");
    printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd");
    printf("\n");
    printf("RUN:%d\t\t",Score_RunP);
    printf("Balls:%d",over);
    printf("WICKET:%d\t\n",Score_Wicket);
    printf("REMAINING RUNS:%d",Remaining_Runs);
}
int run()
{
    int points;
    time_t t2;
    srand((unsigned)time(&t2));
    points = rand()%6;
    return points;
}
int Wicket()
{
    int out;
    time_t t1;
    srand((unsigned)time(&t1));
    out = rand()%6;
    return out;
}

void Result(int P_Score,int Com_Score,int P_WIcket,int Com_Wicket,int over);
int main()
{
    int AI_Wicket[10]={1,5,3,7,4};
    int AI_SCORE[10]={24,20,15,6,8,12,6,11,9};
    time_t t,t3;
    int TURN=0;
    int Runs[10]={0,1,2,4,6},PLAYER_SCORE=0;
    char out[500]={'R','B','L','C','H'};
    char *Player_Status;
    int PR,PO,hit;
    double win=-1;
    int RI,OI,Remaining_Player=4;
    srand((unsigned)time(&t));
    RI = rand()%10;
    OI = rand()%6;
    int Com_Score=AI_SCORE[RI];
    int Com_Wicket=AI_Wicket[OI];
    AI_Score_Board(Com_Score,Com_Wicket);
   do
    {
        //hit = getch();
        srand((unsigned)time(&t3));
        hit = rand()%2;
        if (hit == 0)
        {
            PO = Wicket();
            Player_Status = out[PO];
            printf("%s",Player_Status);
            Remaining_Player-=1;
        }
        else
        {
            PR =run();
            int RUNS= Runs[PR];
            PLAYER_SCORE += RUNS;
        }
        ++TURN;
        Player_Score_Board(PLAYER_SCORE,TURN,Remaining_Player,Com_Score);
        win = Win_Status(Com_Score,PLAYER_SCORE,Remaining_Player,TURN);
    } while (win == -1);
    Result(int P_Score,int Com_Score,int P_WIcket,int Com_Wicket,int over);     
    //Player_Score_Board(PLAYER_SCORE,TURN,Remaining_Player,);
    return 0;
}

void Result(int P_Score,int Com_Score,int P_WIcket,int Com_Wicket,int over)
{
    if((p_score >Com_Score) && (over <= 6))
    {
        printf("PLAYER WON!!");
    }
    else if(P_WIcket>4)
    {
        printf("PLAYER LOAST!!");
    }
    else
    {
        printf("PLAYER LOAST!!");
    }
}
