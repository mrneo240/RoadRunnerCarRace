#include<conio.h>


void GameOver()
{
	EnableOrtho();
	selectFont(5);
	EnableOrtho();
	glBegin(GL_POLYGON);
	glColor3f(0.3,0.53, 0.73);
	glVertex3i(410,560,1);	
	glVertex3i(720,560,1);
    glColor3f(0.1,0.1, 0.1);
	glVertex3i(720,500,1);
	glVertex3i(410,500,1);
	glEnd();
	glColor3f(1.0,0.0,0.0);
	Sprint(420, 540, "You lost the game...!");
	Sprint(420, 510, "Use Enter or Esc key to contin...!");
	DisableOrtho();
	glFlush();
}

void SelectNextCarOption()
{
	glPushMatrix();	
	selectColor(14+AddRight);
	glPointSize(11.0);
	glBegin(GL_POLYGON);
	glVertex3i(1220,400,1);
	glVertex3i(1220,350,1);
	glVertex3i(1270,375,1);
	glEnd();
	glPopMatrix();

	selectColor(12+AddLeft);
	glPointSize(11.0);
	glBegin(GL_POLYGON);
	glVertex3i(140,400,1);
	glVertex3i(140,350,1);
	glVertex3i(90,375,1);
	glEnd();


}

void DisplayCarModelSelection()
{
	EnableOrtho();

	selectFont(2);
	f1b(11);
	Sprint(510, 680, "Car Model Selection");
	f1b(4);
	Sprint(500, 100, "Back [BackSpace]");
	f1b(12);
	Sprint(800, 100, "Select [Enter]");
	f1b(14);
	selectFont(6);
	Sprint(490, 60, "* Use  LEFT & RIGHT ARROW keys to change car colore....!");
	SelectNextCarOption();

	DisableOrtho();
}

void DisplayLogoRoadRunner()
{
    EnableOrtho();

	selectFont(5);
	selectColor(7);
	Sprint(92, 100, "Road Runner");

	DisableOrtho();
}

void DisplayMainMenuScreen()
{
	EnableOrtho();
 
	selectFont(2);
	//selectColor(8);6,
	f1b(11);
	Sprint(569, 680, "Menu");
	f1b(13);
	Sprint(560, 480, "Start Game");
	Sprint(560, 440, "Instruction");
	Sprint(560, 400, "Quit");
	f1b(14);
	selectFont(6);
	Sprint(350, 60, "* Use UP & DOWN ARROW keys to move,Enter key to select nd Esc key to quit the game....!");
	DisableOrtho();
}

void DisplayStartGameOption()
{
	EnableOrtho();

	selectFont(2);
	f1b(11);
	Sprint(560, 680, "Start Game");
	f1b(15);
	Sprint(560, 480, "Play Game");
	Sprint(560, 440, "Car Model");
	Sprint(560, 400, "Level");
	Sprint(560, 360, "Score");
	Sprint(1150, 100, "Back");
	f1b(14);
	selectFont(6);
	Sprint(350, 60, "* Use UP & DOWN ARROW keys to move,Enter key to select nd Backspace key to move previous menu....!");
		
	DisableOrtho();
}

void DisplayGameLevelOption()
{
	EnableOrtho();

	selectFont(2);
	f1b(11);
	Sprint(558, 680, "Level");
	f1b(4);
	Sprint(560, 480, "Easy");
	Sprint(560, 440, "Normal");
	Sprint(560, 400, "Hard");
	Sprint(1150, 100, "Back");
	glColor3f(0.58,0.0,0.77);
	if(Easy==1){glBegin(GL_POINTS);glVertex3i(535,488,1);glEnd();}
	if(Normal==1){glBegin(GL_POINTS);glVertex3i(535,448,1);glEnd();}
	if(Hard==1){glBegin(GL_POINTS);glVertex3i(535,410,1);glEnd();}
	f1b(14);
	selectFont(6);
	Sprint(350, 60, "* Use UP & DOWN ARROW keys to move,Enter key to select nd Backspace key to move previous menu....!");
			
	DisableOrtho();
}

void DisplayInstruction()
{
	EnableOrtho();

	selectFont(2);
	
	f1b(11);
	Sprint(560, 680, "Instruction");
	glColor3f(0.93,0.53,0.23);
	//Sprint(280, 560, "Its a time pass game, if u wanna waste time please follow the instruction to play..");
	Sprint(280, 410, "Drive the car without disturbing the obstacles, if the car");
	Sprint(280, 370, "Crashes with any of it; the game ENDS. ");
	Sprint(280, 340, "Run the car with changing levels or speed to HIGH SCORE and");
	Sprint(280, 310, "RECORD in the list.");
	f1b(4);
	Sprint(280, 510, "  * Use UP ARROW to drive the car.");
	Sprint(280, 480, "  * Use DOWN ARROW to stop the car.");
	Sprint(280, 450, "  * Use  LEFT & RIGHT ARROW to turn.");
	f1b(3);
	Sprint(280, 260, " Use 'V' for different view and 'F' for Fullscreen mode.");
	selectColor(7);
	Sprint(1150, 100, "Back");
			
	f1b(14);
	selectFont(6);
	Sprint(350, 60, "* Use Backspace for previous menu....!");
	DisableOrtho();
}

void DisplayScroe()
{
	EnableOrtho();

	f1b(11);
	Sprint(560, 680, "Score");
	glBegin(GL_POLYGON);
	glColor3f(0.53,0.3, 0.73);
	glVertex3i(340,585,1);	
	glVertex3i(940,585,1);
    glColor3f(0.1,0.1, 0.1);
	glVertex3i(940,490,1);
	glVertex3i(340,490,1);
	glEnd();
	selectFont(2);
	selectColor(1);
	f1b(2);
	Sprint(358, 540, "Player Name");
	Sprint(675, 540, "Score");
	Sprint(870, 540, "Level");
	
	/*Display score here*/
	DisplaySoreListOnScreen();
	
	glColor3f(1.0,1.0,0.0);
	Sprint(1150, 100, "Back");
	f1b(14);
	selectFont(6);
	Sprint(350, 60, "* Use Backspace for previous menu....!");
	
			
	DisableOrtho();
}




void PlayGameBackOption()
{
	selectFont(5);
	EnableOrtho();
	glBegin(GL_POLYGON);
	glColor3f(0.53,0.3, 0.73);
	glVertex3i(1000,770,1);	
	glVertex3i(1370,770,1);
glColor3f(0.1,0.1, 0.1);
	glVertex3i(1370,650,1);
	glVertex3i(1000,650,1);
	glEnd();
	glColor3f(0.53,0.70, 0.0);
	Sprint(1020, 740, "Player Name: ");
	Sprint(1020, 710, "Level: ");
	Sprint(1020, 680, "Score: ");
	glColor3f(0.0,1.0,1.0);
Sprint(1139, 740, PlayerName);
	
if(Easy==1)Sprint(1084, 710, "Easy");if(Normal==1)Sprint(1084, 710, "Normal");if(Hard==1)Sprint(1084, 710, "Hard");
    temp=score;
	k=0;
	while (score!=0)					//display of score
		{
			rem=score%10;
			S[k]=48+rem;  
			score=score/10;
			k++;
		}
		score=temp;
        strrev(S);
Sprint(1084, 680,S);

	glColor3f(0.1, 0.1, 0.1);
	if(flag==6)
	{
		glColor3f(1.0, 1.0, 0.0);
	}
	glBegin(GL_POLYGON);
	glVertex3i(38,725,1);
	glVertex3i(99,725,1);
	glVertex3i(99,695,1);
	glVertex3i(38,695,1);
	glEnd();

	glColor3f(0.73, 0.53, 0.23);
	Sprint(50,705, "Back");
    if(c==1) GameOver();
	DisableOrtho();
}

	

void DisplayPlayGameScreen()
{
	
	float i;
	glClearColor(0.1,0.1,0.1,0.5);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT );
	glLoadIdentity();

	 if(View==1)
	 {
		 glMatrixMode (GL_PROJECTION);
         glLoadIdentity();
         gluPerspective(25.0, 1.0, 3.0, 1000.0);
         glMatrixMode(GL_MODELVIEW);
         glLoadIdentity();
	     gluLookAt(3.9, -18.0, 11.0, 6.0,19.0, 0.5,0, 0, 4.0);
	 }
	 if(View==0)
	 {
		 glMatrixMode (GL_PROJECTION);
         glLoadIdentity();
         gluPerspective(38.0, 1, 3.0, 1000.0);
         glMatrixMode(GL_MODELVIEW);
         glLoadIdentity();
		 gluLookAt( rx, -18.0, ry, 6.0,19.0, 0.5,0, 0, 4.0);
	 }
     glPushMatrix();

glPushMatrix(); //Main Road
	glColor3f(0.1,0.1,0.13);
	footpathAndRoad(2.2,-6.5,2.0,220,7.0);
glPopMatrix();


glPushMatrix(); 
//i=-4.8;
i=-40;
	while(i<220)
	{
	 glColor3f(1.0,1.0,0.0);
	 SideRoad(2.0,i,2.2,2.2,2.2);
	 SideRoad(2.2,i,2.2,2.32,2.0);
	 SideRoad(2.0,i,2.2,1.9,2.0);
	 i=i+0.5;
	 glColor3f(0.5,0.5,0.5);
	 SideRoad(2.0,i,2.2,2.2,2.2);
	 SideRoad(2.2,i,2.2,2.32,2.0);
	 SideRoad(2.0,i,2.2,1.9,2.0);
	 i=i+0.5;
	}
//i=-5.1;
i=-40;
	while(i<220)
	{
	 glColor3f(1.0,1.0,.0);
	 SideRoad(7.0,i,2.2,7.2,2.2);
	 SideRoad(7.2,i,2.2,7.33,2.0);
	 SideRoad(7.0,i,2.2,6.9,2.0);
	 i=i+0.5;
	 glColor3f(0.5,0.5,0.5);
	 SideRoad(7.0,i,2.2,7.2,2.2);
	 SideRoad(7.2,i,2.2,7.33,2.0);
	 SideRoad(7.0,i,2.2,6.9,2.0);
	 i=i+0.5;
	}
glPopMatrix();
glPushMatrix();
obstacle();

glPopMatrix();

glPushMatrix();										//road direction  Whte lnes
	glBegin(GL_QUADS);
	glColor3f(1.0,1.0,1.0);
	i=0;
	while(i<190)
	{
	glVertex3f(4.5,-4.6+i+yy,2.01);
	glVertex3f(4.6,-4.6+i+yy,2.01);
	glVertex3f(4.6,i+(i/30)+yy,2.01);
	glVertex3f(4.5,i+(i/30)+yy,2.01);
	i+=13;
	}
	glEnd();
glPopMatrix();

glPushMatrix();
   glColor3f(0.0,0.53,0.0);
   footpathAndRoad(-0.1,-6.4,2.0,220,2.0);
   footpathAndRoad(7.2,-6.8,2.0,220,10.0);
glPopMatrix();

glPushMatrix();
light();
glPopMatrix();

glPushMatrix();
telepole();
glPopMatrix();

glPushMatrix();
roadway();
glPopMatrix();

//---------------------------------------------------------------------------- 
	glPushMatrix();
	glTranslatef(m,0,0);
	if(mcar==0 && crash==1 && c==1){
		glTranslatef(-0.5,3,4.2);
		glRotatef(360,4,0.,0);
		glRotatef(270,4,0,0);
		glRotatef(25,0,1,0.1);
		glScalef(1,0.5,1);}
	else if(mcar==0 && crash==2 && c==1){
		glTranslatef(0,3,4.2);
		glRotatef(360,4,0.,0);
		glRotatef(270,4,0,0);
		glRotatef(25,0,1,0.1);
		glScalef(1,0.5,1);}
	f1();
		glPopMatrix();

		glPushMatrix();
		crashcondition();
		glPopMatrix();
PlayGameBackOption();
	glFlush();
	glutSwapBuffers();
}

void DisplayBeforeQuitGame()
{
	EnableOrtho();

	selectFont(2);
	f1b(11);
	Sprint(350, 680, "RAJIV GANDHI INSTITUTE OF TECHNOLOGY");
	glBegin(GL_LINES);glVertex3f(345,675,1);glVertex3f(900,675,1);glEnd();
	Sprint(1161, 100, "OK");
	f1b(14);
	Sprint(410, 640, "Department of Computer Science");
	
	/*Display About here*/
	f1b(12);
	selectFont(0);
	Sprint(250, 550, "Submitted by : ");
	Sprint(810, 300, "Under the Guidance");
	f1b(4);
   selectFont(2);
	Sprint(300, 500, "* Rohith B [1RG08CS082]");
	Sprint(300, 450, "* Naveen Kumar BV [1RG08CS066]");
	f1b(4);
	Sprint(800, 260, "Mr. SANTOSH E");
	f1b(14);
	selectFont(0);
	Sprint(780, 220, "Lecturer, Dept. of C.S.E ");

	f1b(1);
	selectFont(0);
	Sprint(840, 110, "Thank you.....");
			
	DisableOrtho();
}


void CheckXYposition(int x,int y)
{
	x=x+(1366-glutGet(GLUT_WINDOW_WIDTH));
	y=y+(768-glutGet(GLUT_WINDOW_HEIGHT));
	if(x>=550 && x<=676 &&y>= 475 && y<=500) flag=1;
	if(x>=550 && x<=669 &&y>= 435 && y<=460) flag=2;
	if(x>=550 && x<=676 &&y>= 395 && y<=425) flag=3;
	if(x>=550 && x<=610 &&y>= 355 && y<=390) flag=4;
	if(x>=1130 && x<=1200 &&y>= 80 && y<=130) flag=5;
	if(x>=35 && x<=135 && y>=695 && y<=725) flag=6;
	if(x>=400 && x<=600 &&y>= 80 && y<=130) flag=7;//back
	if(x>=700 && x<=900 &&y>= 80 && y<=130) flag=8;//selct
	if(x>=1150 && x<=1400 &&y>= 250 && y<=500){ flag=9;AddRight=1;}//Right
	if(x>=10 && x<=200 &&y>= 250 && y<=500) {flag=10,AddLeft=1;};//left
	
	if(!(((x>=400 && x<=600 &&y>= 80 && y<=130)||(x>=700 && x<=900 &&y>= 80 && y<=130)||(x>=1150 && x<=1400 &&y>= 250 && y<=500)||(x>=10 && x<=200 &&y>= 250 && y<=500)||(x>=35 && x<=135 && y>=695 && y<=725||x>=550 && x<=610 &&y>= 355 && y<=390)||(x>=1130 && x<=1200 &&y>= 80 && y<=130))||(x>=550 && x<=676 &&y>= 395 && y<=425)||((x>=550 && x<=676 &&y>= 475 && y<=500)||(x>=550 && x<=669 &&y>= 435 && y<=460)))) {flag=0,AddRight=0,AddLeft=0;}
}
void SelectCar()
{
	
		
	/*DisableOrtho();

	selectFont(2);
	selectColor(8);
	Sprint(560, 680, "Road Runner");
	Sprint(560, 480, "Play Game");

	Sprint(560, 360, "Run");
	Sprint(1150, 100, "Back");*/
	//EnableOrtho();
		
	glClearColor(1,1,1,1);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT );
	glLoadIdentity();
	//glLoadIdentity();
	//body=l;
//	exit(0);
	//EnableTextureAndDepth();
		//EnableTextureAndDepth();
		 glMatrixMode (GL_PROJECTION);
         glLoadIdentity();
         //gluPerspective(25.0, 1.0, 3.0, 1000.0);
		 glOrtho(0, WINDOWWIDTH, 0, WINDOWHEIGHT, -100, 100);
         glMatrixMode(GL_MODELVIEW);

		 glLoadIdentity();
		/*
		glMatrixMode(GL_PROJECTION);
		 glLoadIdentity();
			
		 glMatrixMode(GL_MODELVIEW);
	
		 glLoadIdentity();*/
	 glPushMatrix();
	 glTranslatef(1,1,2);
	 
	 f1();
	 glPopMatrix();
	//DisableTextureAndDepth();
	 
}


void AskePlayerName()
{
	EnableOrtho();
  
	//Sprint(350, 100, "Max length 10 character.. nd no space b/w any two character");
	glColor3f(1.0, 1.0, 0.0);
	selectFont(2);
	Sprint(400,400, "Enter your Name : ");
	glColor3f(0.0, 1.0, 1.0);
	Sprint(594, 400, PlayerName);

	DisableOrtho();
}

void LoadXYpicture()
{
	glClearColor(0.0, 0.0, 0.0,0.0);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT );
	glLoadIdentity();
	BorderStyle();
	if(displayMainMenuScreen==1)
	{
		if(flag==1){LoadPicture(3,-1.3,3.4,5);}//Start Game
		if(flag==2){LoadPicture(6,-1.4,2.0,5);}//Instruction
		if(flag==3){LoadPicture(2,-1.8,0.8,4);}//Quit
		LoadPicture(14,-1.5,9.8,3);
		DisplayMainMenuScreen();
		LoadPicture(13,-9.8,-9.0,6);
	}

	if(displayStartGameOption==1)
	{
		if(flag==1){LoadPicture(3,-1.3,3.4,5);}//Play Game
		if(flag==2){LoadPicture(7,-1.4,2.0,5);}//car model
		if(flag==3){LoadPicture(4,-1.8,0.7,5);}//level
		if(flag==4){LoadPicture(7,-1.8,-0.5,5);}//score
		if(flag==5){LoadPicture(2,9,-9.0,4);}//back
		LoadPicture(10,-1.3,9.8,3);
		DisplayStartGameOption();
		LoadPicture(12,-9.8,-9.0,6);
	}

	if(displayGameLevelOption==1)
	{
		if(flag==1){LoadPicture(6,-1.8,3.4,5);}//Easy
		if(flag==2){LoadPicture(4,-1.6,2.0,5);}//Normal
		if(flag==3){LoadPicture(7,-1.8,0.8,5);}//hard
		if(flag==5){LoadPicture(2,9,-9.0,4);}//back
		LoadPicture(3,-1.8,9.8,3);
		DisplayGameLevelOption();
		LoadPicture(14,-9.8,-9.0,6);
	}

	if(displayInstruction==1)
	{
		if(flag==5){LoadPicture(2,9,-9.0,4);}//back
		LoadPicture(7,-1.3,9.8,3);
		DisplayInstruction();
		LoadPicture(4,-9.8,-9.0,6);
	}

	if(displayScroe==1)
	{
		if(flag==5){LoadPicture(2,9,-9.0,5);}//back
		LoadPicture(10,-1.7,9.8,3);
		DisplayScroe();
		LoadPicture(13,-9.8,-9.0,6);
	}

	if(displayBeforeQuitGame==1)
	{
		if(flag==5){LoadPicture(2,9,-9.0,5);}//exit
		LoadPicture(10,-1.7,9.8,3);
		DisplayBeforeQuitGame();
		LoadPicture(9,-9.8,-9.0,6);
	}
	if(displayAskePlayerName==1)
	{
		AskePlayerName();
		LoadPicture(9,-9.8,-9.0,6);
	}

	if(displayCarModelSelection==1)
	{
		glDisable(GL_TEXTURE_2D);
		glPushMatrix();	
		glTranslatef(5.4,5,2.3);
		glScalef(0.65,0.65,0.65);
		glRotatef(angle,0,0.001,0.1);
		f1();
		glPopMatrix();
		glEnable(GL_TEXTURE_2D);
		if(flag==7){LoadPicture(2,-2.9,-9.0,2);}//back
		if(flag==8){LoadPicture(3,2.6,-9.0,4);}//select
		LoadPicture(10,-1.7,9.8,3);
		DisplayCarModelSelection();
		LoadPicture(9,-9.8,-9.0,6);
	}
	

	DisplayLogoRoadRunner();
	glFlush();
	glutSwapBuffers();
}

void SelectScreen()
{
	
	glClearColor(0.0, 0.0, 0.0,1.0);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT );
	glLoadIdentity();
	if(displayMainMenuScreen==1)
	{
		if(flag==1){displayStartGameOption=1;displayMainMenuScreen=0;}//Start Game
		if(flag==2){displayInstruction=1;displayMainMenuScreen=0;}//Instruction
		if(flag==3){displayBeforeQuitGame=1;displayMainMenuScreen=0;}//Quit
		return;
	}

	if(displayStartGameOption==1)
	{
		if(flag==1){displayAskePlayerName=1,displayStartGameOption=0;angle=0.5;}//play game
		if(flag==2){displayCarModelSelection=1,displayStartGameOption=0;angle=0.5;}//car model
		if(flag==3){displayGameLevelOption=1,displayStartGameOption=0;}//level
		if(flag==4){displayScroe=1,displayStartGameOption=0;}//score
		if(flag==5){displayMainMenuScreen=1;displayStartGameOption=0;}//back
		return;
	}

	if(displayGameLevelOption==1)
	{
		if(flag==1){Easy=1,Normal=Hard=0;}//Easy
		if(flag==2){Normal=1,Easy=Hard=0;}//Normal
		if(flag==3){Hard=1,Easy=Normal=0;}//hard
		if(flag==5){displayStartGameOption=1;displayGameLevelOption=0;}//back
		return;
	}

	if(displayInstruction==1)
	{
		if(flag==5){displayMainMenuScreen=1;displayInstruction=0;}//back
		return;
	}

	if(displayScroe==1)
	{
		if(flag==5){displayStartGameOption=1,displayScroe=0;}//back
		return;
	}

	if(displayPlayGameScreen==1)
	{
		int i=0;
		if(flag==6)
		{
			displayStartGameOption=1,displayPlayGameScreen=0;
			if(score>=5){ SocreUpdateToFile(score);}
			m=2,mcar=0,l=0,x=0,w=1,newobstacle=0,score=0,crash=0,c=y=yy=0;
			while(i<12){S[i]=NULL;PlayerName[i++]=NULL;}
			S[0]='0';
		}

	}

	if(displayBeforeQuitGame==1)
	{
		if(flag==5){exit(0);}
		return;
	}
	
		if(displayCarModelSelection==1)
	{
		if(flag==7){displayCarModelSelection=0,displayStartGameOption=1;body=1;}//back
		if(flag==8){displayCarModelSelection=0,displayStartGameOption=1;}//select
		if(flag==9){if(body>2)body--;}//left
		if(flag==10){if(body<14)body++;}//right
		
		return;
	}
	
}