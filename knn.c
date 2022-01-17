#include<stdio.h>
#include<conio.h>
#include<math.h>

#define n 90 // Maximum number of training data points
#define k 90 // Number of nearest neighbors to consider
#define w 35 // Maximum length of fruit name string

struct boolean1
{
	int no;
	int n1;
	int n2;
	char c[20];
};

struct boolean2
{
	int no;
	float dis;
};

// Find the Euclidean distance between the training dataset and the test dataset
float dist(int p1,int p2,int t1,int t2)
{
	
	float r;
	int i;
	r=sqrt(pow((t1-p1),2)+pow((t2-p2),2));
	return (r);
}


// Sorts a list of arrays	
void quicksort(float a[], int left, int right) {
	int i = left, j = right;
	float pivot = a[(left + right) / 2];
	float temp;
	while (i <= j) {
		while (a[i] < pivot)
			i++;
		while (a[j] > pivot)
			j--;
		if (i <= j) {
			temp = a[i];
			a[i] = a[j];
			a[j] = temp;
			i++;
			j--;
		}
	}
	if (left < j)
		quicksort(a, left, j);
	if (i < right)
		quicksort(a, i, right);
}
	


int main()
{
	FILE *fp,*fp1,*fp2;
	int i,j,r,min,l,count_f=0,count_p=0,count_v=0;
	float distance[100];
	struct boolean1 a[100],t[50];
	struct boolean2 s[100];
	fp=fopen("dataset.csv","r");
	if(fp==NULL)
	{
		printf("\nError,Cannot open file.");

	}
	printf("\n");
	for (i=1;i<=n;i++)
	{
		fscanf(fp,"%d %d %d %s[^\n]",&a[i].no,&a[i].n1,&a[i].n2,a[i].c);

	}
	
	
fclose(fp);

fp1=fopen("dataset_test.csv","r");
if(fp1==NULL)
{
	printf("\nError, Can't read file.");
}
else
{
	printf("\t\t\t\t\t   K NEAREST NEIGHBOUR ALGORITHM EXAMPLE \t\t\t\t\t");
	printf("\t\t\t\t\t\t   ------------------------------------- \t\t\t\t\t");
	printf("\n\n\nEnter the data point to be tested for class calculation:\n");
	for(i=1;i<=w;i++)
	{
		fscanf(fp1,"%d %d[^n]",&t[i].n1,&t[i].n2);
	}
	
}
fclose(fp1);
fp2=fopen("result.csv","w");
for(r=1;r<=w;r++)
{
	count_f=0;
	count_v=0;
	count_p=0;	
	for(i=1;i<=n;i++)
	{
		distance[i]=(dist(a[i].n1,a[i].n2,t[r].n1,t[r].n2));
		
		s[i].dis=distance[i];
		s[i].no=i;
	}
	quicksort(distance,n);
	for(i=1;i<=k;i++)
	{
		for(j=1;j<=n;j++)
	 	{
			if(distance[i]==s[j].dis)
			{
				l=s[j].no;		
				if(strcmp(a[l].c,"fruit")==0)
				{
					count_f=count_f+1;
				}
				if(strcmp(a[l].c,"protein")==0)
					count_p=count_p+1;
				if(strcmp(a[l].c,"vegetable")==0)
					count_v=count_v+1;
				
			}
				
		}
	
	}

		if(count_f>count_p&&count_f>count_v)
		{
			printf("\nX(P1=%d,P2=%d) belongs to class = %s",t[r].n1,t[r].n2,"fruit");
			printf("\n");
			fprintf(fp2,"%d\t%d\t",t[r].n1,t[r].n2);
			fprintf(fp2,"Fruit");
			fprintf(fp2,"\n");
			
		}
		
		else if(count_p>count_v&&count_p>count_f)
		{
			printf("\nX(P1=%d,P2=%d) belongs to class = %s",t[r].n1,t[r].n2,"protein");
			printf("\n");
			fprintf(fp2,"%d\t%d\t",t[r].n1,t[r].n2);
			fprintf(fp2,"Protein");
			fprintf(fp2,"\n");
		
		}
		else
		{
			printf("\nX(P1=%d,P2=%d) belongs to class = %s",t[r].n1,t[r].n2,"vegetable");
			printf("\n");
			fprintf(fp2,"%d\t%d\t",t[r].n1,t[r].n2);
			fprintf(fp2,"Vegetable");
			fprintf(fp2,"\n");
		}	
		
		
}
fclose(fp2);

getch();
return 0;
}
