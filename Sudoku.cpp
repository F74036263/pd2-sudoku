#include<iostream>
#include"Sudoku.h"
#include<iomanip>
#include<ctime>
#include<cstdlib>

using namespace std;

Sudoku::Sudoku()
{
	int i ;
	for(i=0;i<size;i++)
		map[i]=0;
}
Sudoku::Sudoku(int *sm)
{
	int i ;
	for(i=0;i<size;i++)
		map[i]=sm[i];
}
void Sudoku::GiveQuestion()
{
    srand(time(0));
    int i;
    int j;
    int sexyA;
    int sexyB;
    const int max=12;
    int Sudoku1[max][max]=
{
    {4,2,6,8,7,3,9,5,1,-1,-1,-1},
    {8,7,3,9,5,1,6,2,4,-1,-1,-1},
    {9,5,1,6,2,4,8,7,3,-1,-1,-1},
    {-1,-1,-1,1,3,2,4,8,7,9,5,6},
    {-1,-1,-1,7,8,5,1,9,6,4,2,3},
    {-1,-1,-1,4,9,6,2,3,5,8,7,1},
    {1,3,7,2,4,8,-1,-1,-1,6,9,5},
    {2,8,4,5,6,9,-1,-1,-1,1,3,7},
    {6,9,5,3,1,7,-1,-1,-1,2,8,4},
    {3,1,2,-1,-1,-1,7,4,8,5,6,9},
    {7,4,8,-1,-1,-1,5,6,9,3,1,2},
    {5,6,9,-1,-1,-1,3,1,2,7,4,8},
};
    int Sudoku2[max][max];
    for(i=0;i<max;i++)
    {
        for(j=0;j<max;j++)
        {
            Sudoku2[i][j]=0;
        }
    }
    sexyA=1+rand()%9;
    while(1)
    {
        sexyB=1+rand()%9;
        if(sexyA!=sexyB)
        {
            break;
        }
    }
    for(i=0;i<max;i++)
    {
        for(j=0;j<max;j++)
        {
            Sudoku2[i][j]=Sudoku1[i][j];
            if(Sudoku1[i][j]==sexyA)
            {
                Sudoku2[i][j]=sexyB;
            }
             if(Sudoku1[i][j]==sexyB)
            {
                Sudoku2[i][j]=sexyA;
            }
        }
    }

    Sudoku2[11][11]=0;
    for(i=0;i<max;i++)
    {
        for(j=0;j<max;j++)
        {
            cout<<setw(3)<<Sudoku2[i][j];
        }
        cout<<endl;
    }
}

void Sudoku::ReadIn()
{
	int i ;
	for (i = 0;i<144;i++)
	{
		cin >> map[i];
	}
}





int Sudoku::Solve()
{
        int index;
        int result[150];
        int answer = 0;
        int pos[150];
        int posindex = 0;
        index=getzero();
        do
        {
          map[index]++;
          if(map[index]>9)
          {
          map[index]=0;
          index=pop(pos,posindex);
          }
          else
          {
                if(checkcolumn(index)==0 && checkrow(index)==0 && checkgrid(index)==0)
                {
                push(pos,posindex,index);
                index=getzero();
                        if(index==-1)
                        {
                                for(int i=0; i<144;i++)
                                {
                                        result[i]=map[i];
                                }
				answer++;
				index = pop (pos,posindex);
                        }
                }
          }
        }
	while(index>=0&&answer<2);
        	if(answer==0)
        	{
            		cout << '0' << endl;
        	}
        else
        {
            if(answer==1)
            {
                for(int i=0; i<144; i++)
                {
                    map[i] = result[i];
                }

                cout << '1' << endl;
                for(int i=0;i<12;i++)
		{
			for(int j =0;j<12;j++)
				cout<<map[i*12+j]<<' ';
			cout<<endl;
        	}    
	}
            else
               cout << '2' << endl;
    }
    return answer;	 
}

int Sudoku::getzero()
{
	int i ;
	for(i = 0 ;i < size;i++)
	{
		if(map[i]==0)
			return i;
	}
	return -1;
}

void Sudoku::push(int *pos,int &posindex,int index)
{
	pos[posindex]=index;
	posindex++;
}

int Sudoku::pop(int *pos,int &posindex)
{
	if(posindex<=0)
		return -1;
	else
		posindex--;
		return pos[posindex];
}


bool Sudoku::checkcolumn(int index)
{
	int i , j;
	i = index % 12 ;
	j = map[index];

	for (;i<144;i = i +12)
	{
		if((map[i]==j)&&(i!=index))
			return 1 ;
	}

	return 0 ;
}






bool Sudoku::checkrow(int index)
{

	int i , j ,k;
	i = index /12 *12 ;
	j = map[index];
	k = i + 12;
	for (;i<k;i++)
	{
		if ((map[i]==j)&&(i!=index))
			return 1 ;
	}
	
	return 0 ;
}







bool Sudoku::checkgrid(int index)
{

	int i , j , k , l;
	i = index % 12 / 3 * 3 + index / 12 / 3 * 3 * 12;
	j = map[index];
	
	for(k = 0 ;k<9;k++)
	{
		l = i + k % 3 + k / 3 * 12 ;
		if ((map[l]==j)&&(l!=index))
			return 1 ; 
	}

	return 0 ;
}


















