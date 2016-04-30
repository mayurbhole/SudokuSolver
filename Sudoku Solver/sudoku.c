
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int n,m;
int **p;  //Double pointer as we want to create 2D array.

//Function Declarations
int rule1(int **p, int m);
int rule2(int **p,int m);
int can_place(int**p,int,int,int);
int backtrack(int**p);
int available(int **p,int *row,int *col);
int filled_values(int **p);
void print_sudoku(int **p);

void main()
{	
	int i,j,init_filled,final_filled;

	scanf("%d",&n);

	m=n*n;
	
	// To allocate memory vertically
	p=(int**)malloc(sizeof(int *) * m); 	
	
	//To allocate memory horizontally
	for(i=0;i<m;i++)	
	{
		p[i] = (int*) malloc(sizeof(int) * (m));	
	}
		
	//Scan the input	
	for(i=0;i<m;i++)
	{	for(j=0;j<m;j++)
		{
			scanf("%d",&p[i][j]);
		}
	}

	// Initially Filled Values
	init_filled= filled_values(p);
	
	//printf("Initially Filled:%d\n",init_filled);
	printf("Solving...\n");
		
	// Apply Rule1 & Rule2 and then Backtrack
	while(i<(m))
	{
		rule1(p,m);
		rule2(p,m);
		i++;
	}
	
	backtrack(p);
	
	
	// Finally filled values
	final_filled= filled_values(p);
	
	//printf("Final Filled:%d\n",final_filled);
	
	print_sudoku(p);
}

// Find Filled Values
int filled_values(int **p)
{
	int cnt,i,j;

	for(i=0;i<m;i++)
	{	
		for(j=0;j<m;j++)
		{
			if(p[i][j]==0)
			{
				cnt++;
			}
		}
	}
	return ((m*m)-cnt);

}


// Print Sudoku
void print_sudoku(int **p)
{
	int i,j;
	printf("Solved Sudoku:\n");
	char line[] = "|------------------------------------------------------------------------|\0";
    for(i=0; i<m; ++i) 
    {
        if ((i % n) == 0) puts(line);
        for(j=0; j<m; ++j) 
        {
			if ((j % n) == 0) printf("| ");
			{	if(p[i][j]<10)
				{	
					printf(" %d  ", p[i][j]);
				}
				else
				{
					printf(" %d ", p[i][j]);
				}
			}
        }
        puts(" |");
    }
    puts(line);
	
}


// Rule 1
int rule1(int **p, int m)
{
	int i,j,row,col,count,t;
	
	for(row=0;row<m;row++)
	{
		for(col=0;col<m;col++)
		{	
			count=0;		
			if(p[row][col]==0)
			{
				for(i=0;i<m;i++)
				{
					if(can_place(p,row,col,i+1)==1)
					{	
						t=i+1;
						count++;	

					}
					else
					{
						continue;
					}		
				}
				
				if(count>1)
				{
					continue;
				}
				
				else if(count==1)
				{
					p[row][col]=t;
	
					row=0;
					col=0;
							
				}
			}
		
		}
		
	}
	
}


// Rule 2
int rule2(int **p,int m)
{
	int i,j,s,row,col,count,t,k,index,box_row,box_col;
	
	// Check in Row
	for(row=0;row<m;row++)
	{
		for(i=0;i<m;i++)
		{	
			count=0;
				for(col=0;col<m;col++)
				{
							
					if(p[row][col]==0)
					{
						if(can_place(p,row,col,i+1)==1)
						{	
							t=col;
							count++;	
						}
						else
						{
							continue;
						}		
					}
				}
				if(count>1)
				{
					continue;
				}
				
				else if(count==1)
				{
					p[row][t]=i+1;	
					row=0;
							
				}
				
		}
		
	}
	
	// Check in column
	for(col=0;col<m;col++)
	{
		for(i=0;i<m;i++)
		{	
				count=0;
				for(row=0;row<m;row++)
				{
							
					if(p[row][col]==0)
					{
						if(can_place(p,row,col,i+1)==1)
						{	
							s=row;
							count++;	
						}
						else
						{
							continue;
						}		
					}
				}
				if(count>1)
				{
					
					continue;
				}
				
				else if(count==1)
				{
					
					p[s][col]=i+1;	
					col=0;
							
				}		
					
		}	
		
	}


	// Check in Grid
	row = 0;
	col = 0;

	for(k = 0; k < n; k++)                          // For row-grid
	{
		row = (k*n);

		for(index = 0; index < n; index++)          // For col-grid
		{
			col = (index*n);
			
			for(i=0;i<m;i++)                        // For numbers
			{

				count=0;

				for(j=0;j<m;j++)                    // For cells in a grid
				{

					box_row= (((row/n)*(n)) + (j/n));
					box_col= (((col/n)*(n)) + (j%n));

					if(p[box_row][box_col]==0)
					{

						if(can_place(p,box_row,box_col,i+1)==1)
						{
							s=box_row;
							t = box_col;
							count++;	
						}
						else
						{
							continue;
						}			
					}
				}
				if(count>1)
				{

					continue;
				}

				else if(count==1)
				{

					p[s][t]=i+1;	

				}

			}
		}
	}

}

// To Find if the number can be placed
int can_place(int**p,int r,int c,int i)
{	
	int x,y;
	int box_row,box_col,k;

	//Check for Row
	for(k=0;k<m;k++)
	{	
		if(p[r][k]==(i))
			{
				return 0;
			}	
	}

	//Check for Column
	for(k=0;k<m;k++)
	{	
		if(p[k][c]==(i))
			{
				return 0;
			}	
	}

	//Check for Box
	for(x=0;x<m;x++)
	{	
		box_row= (((r/n)*(n)) + (x/n));
		box_col= (((c/n)*(n)) + (x%n));

			{  
				if(p[box_row][box_col]==(i))
					{
						return 0;
					}
			}
	}
	
	return 1;
}


// Backtracking
int backtrack(int **p)
{
	int row,col,i, temp_row = 0, temp_col = 0, flag = 0, temp = 0;
	
	if(is_available(p,&row,&col)==0)
		return 1;
	
	for(i=0;i<m;i++)
	{
		if(can_place(p,row,col,i+1)==1)
		{
			p[row][col]=i+1;
			if(backtrack(p) == 1)
			{
				return 1;
			}
			
			p[row][col]= 0;
		}
	}
	
	return 0;
}


// Check if the position is available
int is_available(int **p,int *row,int *col)
{
	for((*row)=0;(*row)<m;(*row)++)
	{
		for((*col)=0;(*col)<m;(*col)++)
		{
			if(p[(*row)][(*col)] == 0)
			{	
				return 1;
			}
		}
	}
	
	return 0;
}
