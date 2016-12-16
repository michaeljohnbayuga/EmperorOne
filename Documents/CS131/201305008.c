#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main ()
{
	int  row,counter,length,i,y;
	char infile[256];
	char name[256][256];
	char slash[256][256];
	char coy[256][256];
	char result[256][256];
	int xcoord[256];
	int ycoord[256];
	FILE *fdel=fopen("201305008.txt","w");
	fprintf(fdel,"\0");
	fclose(fdel);
	FILE *fp=fopen("mp3.txt","r");
	{
	
		if(fp==NULL)
		{
			printf("File does not exist");
			exit(1);
		}
		else
		{
			while(fgets(infile,1000,fp))
			{
				for(counter=0;counter<strlen(infile);counter++)
				{			
					if(infile[counter]=='\n')
					{
						row=row+1;	
					}
					
				}
				
			}
				
		}

	}
	fclose(fp);
	row=row+1;
	length = 3*row;
	FILE *fread=fopen("mp3.txt","r");
	int j=0;
	while(j<row)
	{
		fscanf(fread,"%s %d %s %d",name[j],&xcoord[j],slash[j],&ycoord[j]);
		j++;
	}
	fclose(fread);
	xcoord[row+1]=0;
	ycoord[row+1]=0;
	int m,n,z;
	z=1;
	FILE *fwrite=fopen("201305008.txt","a");
	counter=0;
	y=z;
	while(z<row+1)
	{	
		if(xcoord[z]==0 && ycoord[z]==0)
		{			
			for(i=y;i<z;i++)
			{
				for(j=i+1;j<z;j++)
				{
				if(ycoord[i]>ycoord[j])
					{
						m=xcoord[i];
						xcoord[i]=xcoord[j];
						xcoord[j]=m;
						n=ycoord[i];
						ycoord[i]=ycoord[j];
						ycoord[j]=n;
						strcpy(coy[i],name[i]);
						strcpy(name[i],name[j]);
						strcpy(name[j],coy[i]);
					}
				}
			}
			y=z;
		}
	z++;
	}
	j=1;
	int timein,timeout,loop,noclas,nom;
	int cas[256];
	timeout=600;
	timein=2100;
	loop=600;
	y=1;
	nom=1;
	while(j<row+1)
	{	
		timeout=600;
		noclas=0;
		
		if(xcoord[j]==0 && ycoord[j]==0)
		{	
			
				for(i=y;i<j;i++)
				{
					if(xcoord[i]>=timeout)
					{
						timeout=ycoord[i];
						noclas++;
					}
				}
				fprintf(fwrite,"CASE %d: %d\n",nom,noclas);
				timeout=600;
				for(z=y;z<j;z++)
				{
					if(xcoord[z]>=timeout)
					{
						fprintf(fwrite,"%s\n",name[z]);
						timeout=ycoord[z];
					}
				}
	
			nom++;	
			y=j;
			
		}
		j++;
	}
	fclose(fwrite);	
	return 0;
}

