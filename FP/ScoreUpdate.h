GLint Easy=1,Normal=0,Hard=0;


void DesendinOrderScore()
{
	FILE *fp;
	int p,q,count;
    char AName[10][20],ALevel[10][20];
	char TempName[20],TempLevel[8];
	int AScore[6],TempScore;

	fp=fopen("RoadRunnerScore.txt","r");
	count=0;
	while(1)
	{
	    fscanf(fp,"%s %d %s\n",TempName,&TempScore,TempLevel);
	    strcpy(AName[count],TempName);
		AScore[count]=TempScore;
		strcpy(ALevel[count],TempLevel);
		count++;
		if(feof(fp))break;
	}
	fclose(fp);  
	
	for(p=1;p<count;p++)
	{
		for(q=0;q<count-p;q++)
		{
			if(AScore[q]<=AScore[q+1])
			{
				strcpy(TempName,AName[q]);
				TempScore=AScore[q];
				strcpy(TempLevel,ALevel[q]);


				strcpy(AName[q],AName[q+1]);
				AScore[q]=AScore[q+1];
				strcpy(ALevel[q],ALevel[q+1]);

				strcpy(AName[q+1],TempName);
				AScore[q+1]=TempScore;
				strcpy(ALevel[q+1],TempLevel);
			}
		}
	}

  fp=fopen("RoadRunnerScore.txt","w");
  if(count>4) count=4;
  for(q=0;q<count;q++)
	{
		strcpy(TempName,AName[q]);
		TempScore=AScore[q];
		strcpy(TempLevel,ALevel[q]);
		fprintf(fp,"%s %d %s\n",TempName,TempScore,TempLevel);
		
	}
	fclose(fp);
}

void SocreUpdateToFile(int score)
{
	char Level;
	FILE *fp;
    
	if(Easy==1){Level='E';}
	if(Normal==1){Level='N';}
	if(Hard==1){Level='H';}

        fp=fopen("RoadRunnerScore.txt","r");
		if(fp==NULL)
		{
			fp=fopen("RoadRunnerScore.txt","a+b");
			fprintf(fp,"%s %d %c",PlayerName,score,Level);
			fclose(fp);
		}
		else
		{
			fclose(fp);
			fp=fopen("RoadRunnerScore.txt","a+b");
			fprintf(fp,"\n%s %d %c",PlayerName,score,Level);
		    fclose(fp);
			DesendinOrderScore();
		}
}

void DisplaySoreListOnScreen()
{
	FILE *fp;
	int i=0;
	char TempName[20],TempLevel[2],TempScore[10];
	fp=fopen("RoadRunnerScore.txt","r");
	if(fp==NULL){return;}
	
	glBegin(GL_POLYGON);
	glColor3f(0.53,0.3, 0.73);
	glVertex3i(340,490,1);	
	glVertex3i(940,490,1);
    glColor3f(0.1,0.1, 0.1);
	glVertex3i(940,280,1);
	glVertex3i(340,280,1);
	glEnd();
    selectFont(2);
	f1b(11);

	 while(1)
		 {
			fscanf(fp,"%s %s %s\n",TempName,TempScore,TempLevel);
           	
           	Sprint(365,450+i,TempName);
			Sprint(695,450+i,TempScore);
			Sprint(899,450+i,TempLevel);
			i-=50;
			if(feof(fp))break;
		 }
	 fclose(fp);



}