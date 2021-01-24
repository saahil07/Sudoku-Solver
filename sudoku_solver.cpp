#include<bits/stdc++.h>
using namespace std;

bool canplace(int a[9][9], int i, int j, int num)
{ for(int x=0;x<9;x++)
  { if(a[i][x]==num or a[x][j]==num)
     return false;
  }
  
  int rn=sqrt(9);
  int row=(i/rn)*rn;
  int col=(j/rn)*rn;
  
  for(int x=row; x<row+rn; x++)
  { for(int y=col;y<col+rn;y++)
    { if(a[x][y]==num)
      return false;
    }
  }
  return true;
}

bool solvesudoku(int a[9][9], int i, int j)
{ if(i==9)
  return true;
  
  if(j==9)
  return solvesudoku(a,i+1,0);
  
  //skip pre filled cells
  if(a[i][j]==0)
  { for(int num=1;num<=9;num++)
    { if(canplace(a,i,j,num))
      { a[i][j]=num;
        bool couldwesolve=solvesudoku(a,i,j+1);
        if(couldwesolve)
        return true;
        else
         a[i][j]=0;
      }
    }
    return false;
  }
  else
  return solvesudoku(a,i,j+1);
}
  
int main()
{ int n;
  cin>>n;
  int a[9][9];
  
  for(int i=0;i<9;i++)
  { for(int j=0;j<9;j++)
     cin>>a[i][j];
  }
  
  if(solvesudoku(a,0,0))
  { for(int i=0;i<9;i++)
    { for(int j=0;j<9;j++)
      { cout<<a[i][j]<<" ";
      }
      cout<<endl;
    }
  }
  else
  cout<<"-1";
    return 0;
}