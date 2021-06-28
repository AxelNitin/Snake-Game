#include <iostream>
#include <cstdlib>
#include <conio.h>
using namespace std;
bool gameover;
const int width=40;
const int height=30;
int x,y;
int fruitx,fruity;
int tailX[100],tailY[100];
int nTail;
int score=0;
enum eDirection{STOP=0, LEFT, RIGHT, UP, DOWN};
eDirection dir;
void Setup()
{
	gameover=false;
	dir=STOP;
	x=width/2;
	y=height/2;
	fruitx=rand()%width;
	fruity=7;
	score=0;
}
void Draw()
{
    system("cls");
    for(int i=0;i<width;i++)
    cout<<"#";
    cout<<endl;
    
    for(int i=0;i<height;i++)
    {
    	for(int j=0;j<width;j++)
    	{
    		if(j==0||j==width-1)
    		cout<<"#";
    		else if(i==y&&j==x)
    		cout<<"O";
    		else if(i==fruity&&j==fruitx)
    		cout<<"F";
    		else
    		{
    			bool print=false;
    			for(int k=0;k<ntail;k++)
    			{
    				if(tailX[k]==j&&tailY[k]==i)
					{
    					cout<<"o";
    					print=true;
					}
				}
				if(!print)
				cout<<" ";
			}
    		
		}
		cout<<endl;
	}
	
	for(int i=0;i<width;i++)
    cout<<"#";
    cout<<endl;
	cout<<"YOUR SCORE:"<<score<<endl;
    
}
void Input()
{
	if(_kbhit())
    {
    	switch (_getch())
    	{
    		case 'a':
    			dir=LEFT;
    			break;
    		case 's':
    			dir=DOWN;
    			break;
			case 'd':
    			dir=RIGHT;
    			break;
			case 'w':
    			dir=UP;
    			break;	
			case 'x':
    			gameover=true;
    			break;			
		}
	}
	
}
void Logic()
{
	tailX[0]=x;
	tailY[0]=y;
	int prevX=tailX[0];
	int prevY=tailY[0];
	int prev2X,prev2Y;
	for(int i=1;i<nTail;i++)
	{
		prev2X=tailX[i];
		prev2Y=taiY[i];
		tailX[i]=prevX:
		tailY[i]=prevY;
		prevX=prev2X;
		prevY=prev2Y;	
		
	}	
	switch(dir)
	{
		case LEFT:
			x--;
			break;
		case RIGHT:
		    x++;
			break;
		case UP:
		    y--;
			break;
		case DOWN:
		    y++;
			break;
		deafult:
		    break;		 		
	}
	if(x>width||x<0||y>height||y<0)
	gameover=true;
	
	for(int i=0;i<nTail;i++)
	if(x==tailX[i]&&y==tailY[i])
	gameover=true;
	
	
	if(x==fruitx&&y==fruity)
	{
		score+=10;
		fruitx=rand%width;
		fruity=rand()%height;
		nTail++;
		
		
	}
}
int main()
{
	Setup();
	while(!gameover)
	{
		Draw();
		Input();
		Logic();
	}
	return 1;
}
