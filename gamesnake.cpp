#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>
using namespace std;

struct Obiect
{
int x;
int y;
};
enum Directii
{
 STOP,
 LEFT,
 RIGHT,
 DOWN,
 UP,
};
bool gameover;
int inaltime;
int latime;
Obiect snake;
Obiect punct;
Obiect coada[100];
Directii dir;
int scor=0;
int ncoada=0;
void Setup()
{
gameover=false;
inaltime=15;
latime=30;
snake.x=5;
snake.y=5;
punct.x=rand() % latime;
punct.y=rand() % inaltime;
dir=STOP;
}
void Draw()
{
system("cls");
int i,j;
for(i=0;i<=latime;i++)cout<<"#";
cout<<endl;
for(i=0;i<=inaltime;i++)
    {
     for(j=0;j<=latime;j++)
        if(j==0 || j==latime)cout<<"#";
            else if( snake.x==j && snake.y==i )cout<<"O";
                else if(punct.x==j && punct.y==i)cout<<"*";
                    else
                    {
                     bool estecoada=false;
                    for(int k=0;k<= ncoada;k++)
                        if(coada[k].x==j && coada[k].y==i){estecoada=true;break;}
                            if(!estecoada)cout<<" ";
                                else cout<<"o";
                    }
  cout<<endl;
    }
for(i=0;i<latime;i++)cout<<"#";
cout<<endl;
cout<<"Scor = "<<scor;
}
void Input()
{
if(_kbhit())
{
    switch(getch())
        {
            case 'a' : dir=LEFT; break;
            case 's' : dir=DOWN; break;
            case 'd' : dir=RIGHT; break;
            case 'w' : dir=UP; break;
        }
}
}
void Logic()
{
        switch(dir)
        {
            case LEFT: snake.x--;
                break;
            case RIGHT:snake.x++;
                break;
            case DOWN:snake.y++;
                break;
            case UP:snake.y--;
                break;
        }
int xprev,yprev,xprev2,yprev2;
xprev=snake.x;
yprev=snake.y;
for(int i=0;i<= ncoada;i++)
{
xprev2=coada[i].x;
yprev2=coada[i].y;
coada[i].x=xprev;
coada[i].y=yprev;
xprev=xprev2;
yprev=yprev2;
}
if(snake.x == punct.x && snake.y == punct.y)
{
    scor++;
    ncoada++;
    punct.x=rand() % latime;
    punct.y=rand() % inaltime;
}
if(snake.x==0)gameover=true;
if(snake.x==latime)gameover=true;
if(snake.y==0)gameover=true;
if(snake.y==inaltime)gameover=true;
for(int i=1;i<=ncoada;i++)
if(snake.x==coada[i].x && snake.y ==coada[i].y){gameover=true;break;}
}
int main()
{
Setup();
while(!gameover)
{
    Input();
    Logic();
    Draw();
    Sleep(50);
}
}
