#include<stdlib.h>
#include<stdio.h>
void system();
char a[10]={'0','1','2','3','4','5','6','7','8','9'};
void playboard()
{
    system("cls");
    printf("      TIC TAC TOE GAME      \n");
    printf("\n");
    printf("       |          |       \n");
    printf("   %c   |     %c    |   %c  \n",a[1],a[2],a[3]);
    printf("_______|__________|_______\n");
    printf("       |          |       \n");
    printf("   %c   |     %c    |   %c  \n",a[4],a[5],a[6]);
    printf("_______|__________|_______\n");
    printf("       |          |       \n");
    printf("   %c   |     %c    |   %c  \n",a[7],a[8],a[9]);
    printf("       |          |       \n");
}
int checkwin()
{
    if(a[1]==a[2]&&a[2]==a[3])
    return 1;
    if(a[4]==a[5]&&a[5]==a[6])
    return 1;
    if(a[7]==a[8]&&a[8]==a[9])
    return 1;
    if(a[1]==a[4]&&a[4]==a[7])
    return 1;
    if(a[2]==a[5]&&a[5]==a[8])
    return 1;
    if(a[3]==a[6]&&a[6]==a[9])
    return 1;
    if(a[1]==a[5]&&a[5]==a[9])
    return 1;
    if(a[7]==a[5]&&a[5]==a[3])
    return 1;
    int i,count=0;
    for(i=1;i<10;i++)
    {
        if(a[i]=='X'||a[i]=='O')
        count+=1;
    }
    if(count==9)
    return 0;
    else
    return -1;
}
void main()
{
    playboard();
    int player=1,status=-1;
    int input;
    while(status=-1)
    {
        if(player%2==0)
        player=2;
        else
        player=1;
        char mark;
        if(player==1)
        mark='X';
        else
        mark='O';
        printf("Enter number for player %d \n",player);
        scanf("%d",&input);
        if(input<1||input>9)
        printf("invalid number\n");
        a[input]=mark;
        playboard();
        int result=checkwin();
        if(result==1)
        {
        printf("PLAYER %d WON\n",player);
        break;
        }
        if(result==0)
        {
        printf("MATCH DRAW\n");
        break;
        }
        player+=1;
    }
}