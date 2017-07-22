/*
 * The tic-tac-toe emulator
 */
#include <cstdio>
using namespace std;
int board[9] = {-1, -1, -1, -1, -1, -1, -1, -1, -1};
bool check(void);
bool check()
{
    bool flag = false;
    if ((board[0] == board[1]) and (board[0] == board[2]) and (board[0] != -1))
        flag = true;
    if ((board[3] == board[4]) and (board[3] == board[5]) and (board[3] != -1))
        flag = true;
    if ((board[6] == board[7]) and (board[6] == board[8]) and (board[6] != -1))
        flag = true;
    if ((board[0] == board[3]) and (board[0] == board[6]) and (board[0] != -1))
        flag = true;
    if ((board[1] == board[4]) and (board[1] == board[7]) and (board[1] != -1))
        flag = true;
    if ((board[2] == board[5]) and (board[2] == board[8]) and (board[2] != -1))
        flag = true;
    if ((board[0] == board[4]) and (board[0] == board[8]) and (board[0] != -1))
        flag = true;
    if ((board[2] == board[4]) and (board[2] == board[6]) and (board[2] != -1))
        flag = true;
    return flag;
}
void end(bool);
FILE *fp;
int gamecount = 0;
void end(bool who) 
{
    gamecount++;
    fprintf(fp, "GAME %d\n", gamecount);
    for (int i = 0;i<9;i++)
        fprintf(fp, "%c%s", board[i] == -1 ? '.':board[i] == 0 ? 'O':'X', i % 3 == 2 ? "\n":"");
    fprintf(fp, "%s won\n\n", who ? "black":"white");
}
void search(bool);
void search(bool who)
{
    for (int i = 0;i<9;i++)
    {
        if (board[i] == -1)
        {
            board[i] = who;
            check() ?end(who):search(!who);
            board[i] = -1;
        }
    }
}

int main()
{
    fp = fopen("output.txt","wb");
    search(0);
    fclose(fp);
    return 0;
}