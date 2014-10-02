void crashcondition()
{
	if(y<=-15.11 && m>=1.10 && crash==2)
		{
			//body='r';
			mcar=0;
			c=1;
			View=0;
		}	
	else if(y<=-15.11 && m<=1.85 && crash==1)
		{
			//body='r';
			mcar=0;
			c=1;
			View=0;
		}
	 else c=0;
		
		glutPostRedisplay();	
}



void levels()
{
	float e,n,h;
	if(Easy==1){e=-0.3,n=0,h=0;}
	else if(Normal==1){e=0,n=0,h=0;}
	else if(Hard==1){e=0,n=0,h=0.3;}
	if(l<=3)level=1;
	else if(score<=10)level=2;
	else if(score<=30)level=3;
	else if(score<=70)level=4;
	else if(score<=85)level=5;
	else level=6;
	switch(level)
	{
	case 1:
			if(mcar==1)
			{
			y-=(0.5+e+n+h);
			if(y<-25.11){ y=35.11;newobstacle=1;score+=5;l++;}
			yy-=(0.5+e+n+h);
			if(yy<-26.25) {yy=13.9;}
			}
			break;
	case 2:
			if(mcar==1)
			{
			y-=0.7+e+n+h;
			if(y<-25.11){ y=35.11;newobstacle=1;score+=5;l++;}
			yy-=0.7+e+n+h;
			if(yy<-26.25) {yy=13.9;}
			}
			break;
	case 3:
			if(mcar==1)
			{
			y-=0.8+e+n+h;
			if(y<-25.11){ y=35.11;newobstacle=1;score+=5;l++;}
			yy-=0.8+e+n+h;
			if(yy<-26.25) {yy=13.9;}
			}
			break;
	case 4:
			if(mcar==1)
			{
			y-=1.0+e+n+h;
			if(y<-25.11){ y=35.11;newobstacle=1;score+=5;l++;}
			yy-=1.0+e+n+h;
			if(yy<-26.25) {yy=13.9;}
			}
			break;
	case 5:
			if(mcar==1)
			{
			y-=1.5+e+n+h;
			if(y<-25.11){ y=35.11;newobstacle=1;score+=5;l++;}
			yy-=1.5+e+n+h;
			if(yy<-26.25) {yy=13.9;}
			}
			break;
	case 6:
			if(mcar==1)
			{
			y-=2.2+e+n+h;
			if(y<-25.11){ y=35.11;newobstacle=1;score+=5;l++;}
			yy-=2.2+e+n+h;
			if(yy<-26.25) {yy=13.9;}
			}
			break;
	}
}

