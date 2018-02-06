#include<stdio.h>
#include<malloc.h>
/*
Author: Ashley Lobo
*/

//Function to add 2 Matrices
int** add(int** a,int** b, int n){
	int i,j;
	//Initializing a Matrix
	int** ans=(int**)(malloc(n*sizeof(int*)));
	for(i=0;i<n;i++)
	  ans[i]=(int *)(malloc(n*sizeof(int)));
	  
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			ans[i][j]=a[i][j]+b[i][j];
	}
	return ans;
}
//Function to subtract 2 Matrices
int** sub(int** a,int** b, int n){
	int i,j;
//Initializing a Matrix
	int** ans=(int**)(malloc(n*sizeof(int*)));
	for(i=0;i<n;i++)
	  ans[i]=(int *)(malloc(n*sizeof(int)));
	  
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			ans[i][j]=a[i][j]-b[i][j];
	}
	return ans;
}

//Function to break a Matrix into parts
 void split(int **p, int** c, int iB, int jB,int n) 
{	int i1,j1,j2,i2;

  for( i1 = 0, i2 = iB; i1 < n; i1++, i2++)
    for(j1 = 0, j2 = jB; j1 < n; j1++, j2++)
      c[i1][j1] = p[i2][j2];

}
//Function to join a Matrix into parts  
void join(int**c, int** p, int iB, int jB,int n) 
{	int i1,j1,j2,i2;

  for( i1 = 0, i2 = iB; i1 < n; i1++, i2++)
    for( j1 = 0, j2 = jB; j1 < n; j1++, j2++)
      p[i2][j2] = c[i1][j1];
} 

//Function Multiply the sub matrices 
int** multiply(int **a,int **b,int n){
	int i;

	int** r=(int**)(malloc((n)*sizeof(int*)));
	for(i=0;i<n;i++)
	r[i]=(int *)(malloc((n)*sizeof(int)));

  //If value of n is 1 
  //It means only a single value if present 
  //Hence simply multiplt the values
	if(n==1)
	r[0][0]=a[0][0]*b[0][0];
	
	else{
	  
    //Initializing sub matrices for matrix a 
  	int** a11=(int**)(malloc((n/2)*sizeof(int*)));
  	for(i=0;i<n/2;i++)
  	a11[i]=(int *)(malloc((n/2)*sizeof(int)));
  	
  	int** a12=(int**)(malloc((n/2)*sizeof(int*)));
  	for(i=0;i<n/2;i++)
  	a12[i]=(int *)(malloc((n/2)*sizeof(int)));
  	
  	int** a21=(int**)(malloc((n/2)*sizeof(int*)));
  	for(i=0;i<n/2;i++)
  	a21[i]=(int *)(malloc((n/2)*sizeof(int)));
  	
  	int** a22=(int**)(malloc((n/2)*sizeof(int*)));
  	for(i=0;i<n/2;i++)
  	a22[i]=(int *)(malloc((n/2)*sizeof(int)));
	
	
    //Initializing sub matrices for matrix b
  	int** b11=(int**)(malloc((n/2)*sizeof(int*)));
  	for(i=0;i<n/2;i++)
  	b11[i]=(int *)(malloc((n/2)*sizeof(int)));
  	
  	int** b12=(int**)(malloc((n/2)*sizeof(int*)));
  	for(i=0;i<n/2;i++)
  	b12[i]=(int *)(malloc((n/2)*sizeof(int)));
  	
  	int** b21=(int**)(malloc((n/2)*sizeof(int*)));
  	for(i=0;i<n/2;i++)
  	b21[i]=(int *)(malloc((n/2)*sizeof(int)));
  	
  	int** b22=(int**)(malloc((n/2)*sizeof(int*)));
  	for(i=0;i<n/2;i++)
  	b22[i]=(int *)(malloc((n/2)*sizeof(int)));
  
    //Split the Matrix A into 4 parts
  	split(a,a11,0,0,n/2);
  	split(a,a12,0,n/2,n/2);
  	split(a,a21,n/2,0,n/2);
  	split(a,a22,n/2,n/2,n/2);
  	
  	//Split the Matrix B into 4 parts
  	split(b,b11,0,0,n/2);
  	split(b,b12,0,n/2,n/2);
  	split(b,b21,n/2,0,n/2);
  	split(b,b22,n/2,n/2,n/2);
  	
  	//Initializing the P matrices
  	int** p1=(int**)(malloc((n/2)*sizeof(int*)));
  	for(i=0;i<n/2;i++)
  	p1[i]=(int *)(malloc((n/2)*sizeof(int)));
  	int** p2=(int**)(malloc((n/2)*sizeof(int*)));
  	for(i=0;i<n/2;i++)
  	p2[i]=(int *)(malloc((n/2)*sizeof(int)));
  	int** p3=(int**)(malloc((n/2)*sizeof(int*)));
  	for(i=0;i<n/2;i++)
  	p3[i]=(int *)(malloc((n/2)*sizeof(int)));
  	int** p4=(int**)(malloc((n/2)*sizeof(int*)));
  	for(i=0;i<n/2;i++)
  	p4[i]=(int *)(malloc((n/2)*sizeof(int)));
  	int** p5=(int**)(malloc((n/2)*sizeof(int*)));
  	for(i=0;i<n/2;i++)
  	p5[i]=(int *)(malloc((n/2)*sizeof(int)));
  	int** p6=(int**)(malloc((n/2)*sizeof(int*)));
  	for(i=0;i<n/2;i++)
  	p6[i]=(int *)(malloc((n/2)*sizeof(int)));
  	int** p7=(int**)(malloc((n/2)*sizeof(int*)));
  	for(i=0;i<n/2;i++)
  	p7[i]=(int *)(malloc((n/2)*sizeof(int)));
  	
  	
  
    p1 = multiply(add(a11, a22,n/2), add(b11, b22,n/2),n/2);
    p2 = multiply(add(a21, a22,n/2), b11,n/2);
    p3 = multiply(a11, sub(b12, b22,n/2),n/2);
    p4 = multiply(a22, sub(b21, b11,n/2),n/2);
    p5 = multiply(add(a11, a12,n/2), b22,n/2);
    p6 = multiply(sub(a21, a11,n/2), add(b11, b12,n/2),n/2);
   	p7 = multiply(sub(a12, a22,n/2), add(b21, b22,n/2),n/2);
  	
    //Initializing 4 matrices to store final result of submatrices of answer
  	int** c1=(int**)(malloc((n/2)*sizeof(int*)));
  	for(i=0;i<n/2;i++)
  	c1[i]=(int *)(malloc((n/2)*sizeof(int)));
  	int** c2=(int**)(malloc((n/2)*sizeof(int*)));
  	for(i=0;i<n/2;i++)
  	c2[i]=(int *)(malloc((n/2)*sizeof(int)));
  	int** c3=(int**)(malloc((n/2)*sizeof(int*)));
  	for(i=0;i<n/2;i++)
  	c3[i]=(int *)(malloc((n/2)*sizeof(int)));
  	int** c4=(int**)(malloc((n/2)*sizeof(int*)));
  	for(i=0;i<n/2;i++)
  	c4[i]=(int *)(malloc((n/2)*sizeof(int)));
  
    //Stroe value of result  	
    c1 = add(sub(add(p1, p4,n/2), p5,n/2), p7,n/2);
    c2 = add(p3, p5,n/2);
    c3 = add(p2, p4,n/2);
    c4 = add(sub(add(p1, p3,n/2), p2,n/2), p6,n/2);
  
    //Join the matrices to create the final Matrix
    join(c1, r, 0 , 0,n/2);
    join(c2, r, 0 , n/2,n/2);
    join(c3, r, n/2, 0,n/2);
    join(c4, r, n/2, n/2,n/2);
  	}
  	return r;
}
   

int main(){
	int i=1,j,n,n1;
	printf("Enter n\n");
	scanf("%d",&n);
	//n1 is a pseudo size of matrix 
	n1=1;
	//This loop is for making the value of n1 into a divisible matrix of size 2 ,4 , 8 ,16
	while(i<n){
	  i=i*2;
	}
	n1=i;
	
	
	int** a=(int**)(malloc((n1)*sizeof(int*)));
	for(i=0;i<n1;i++)
	a[i]=(int *)(malloc((n1)*sizeof(int)));
	
	int** b=(int**)(malloc((n1)*sizeof(int*)));
	for(i=0;i<n1;i++)
	b[i]=(int *)(malloc((n1)*sizeof(int)));
	
	int** ans=(int**)(malloc((n1)*sizeof(int*)));
	for(i=0;i<n1;i++)
	ans[i]=(int *)(malloc((n1)*sizeof(int)));
	
	for(i=0;i<n1;i++)
	  for(j=0;j<n1;j++)
	    {
	      a[i][j]=0;
	      b[i][j]=0;
	      ans[i][j]=0;
	    }
	
	printf("Enter Matrix 1 \n");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++)
		scanf("%d",&a[i][j]);
	}
	
	printf("Enter Matrix 2 \n");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++)
		scanf("%d",&b[i][j]);
	}
	
	ans=multiply(a,b,n1);

	for(i=0;i<n;i++){
		for(j=0;j<n;j++)
		printf("%d ",ans[i][j]);
		printf("\n");
	}
	return 0;
}
