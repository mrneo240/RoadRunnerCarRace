#include<gl/glut.h>
int te;
void SideRoad(float a,float b,float c,float d,float e)
{
glBegin(GL_POLYGON);
	glVertex3f(a,b+y,c);
	glVertex3f(d,b+y,e);
	glVertex3f(d,(b+.5+y),e);
	glVertex3f(a,(b+.5+y),c);
glEnd();
}

void footpathAndRoad(float a,float b,float c,float d,float e)
{
	glBegin(GL_QUADS);
		glVertex3f(a,b,c);
		glVertex3f(e,b,c);
		glVertex3f(e,d,c);
		glVertex3f(a,d,c);	
     glEnd();
}

void obstacle()
{
	if(newobstacle==1)
	{
		obs=rand()%4;
		te=rand()%2;
		
		if(te==0)x=2.8;  else x=0;
	}
	
	switch(obs)
	{
	case 0:
			  glPushMatrix();		//1
			  glColor3f(0.50, 0.10, 0.10);
		  glTranslatef(2.8+x, 20.0+y, 2.0);
		  gluCylinder(Cylinder, 0.1, 0, 1, 16, 16);
		  glPopMatrix();	 
		glColor3f(0,0,0);
		glLineWidth(1);
		glBegin(GL_LINE_STRIP);
		glVertex3f(2.8+x,20+y,3);
		glVertex3f(3+x,20+y,2.9);
		glVertex3f(3.3+x,20+y,3.2);
		glVertex3f(3.5+x,20+y,2.9);
		glVertex3f(3.8+x,20+y,3);
		glEnd();
		  glPushMatrix();
		  glTranslatef(3.3+x, 20.0+y, 2.0);
		  glColor3f(0.50, 0.10, 0.10);
		  gluCylinder(Cylinder, 0.15, 0, 1.2, 16, 16);
		  glPopMatrix();

			glTranslatef(3.8+x, 20.0+y, 2.0);
			glColor3f(0.50, 0.10, 0.10);
		  gluCylinder(Cylinder, 0.1, 0, 1, 16, 16);
		  glPopMatrix();
		  break;
	case 1:
			glColor3f(0,0,0);
			glPushMatrix();
			glTranslatef(2.8+x,20+y,2);
			glRotatef(90,0,1,0);
			gluCylinder(Cylinder,0.15,0.15,1.3,50,50);
			glPopMatrix();
		glTranslatef(x,y,0);
			glPushMatrix();							
			glTranslatef(2.8,20,2);
			gluCylinder(Cylinder,0.25,0.25,0.6,50,50);
			glColor3f(0.73,0.53,0.23);
			glTranslatef(0,0,0.3);
			gluCylinder(Cylinder,0.25,0.25,0.15,50,50);
			glColor3f(0,0,0);
			glTranslatef(1.3,0,-0.3);
			gluCylinder(Cylinder,0.25,0.25,0.6,50,50);
			glColor3f(0.73,0.53,0.23);
			glTranslatef(0,0,0.3);
			gluCylinder(Cylinder,0.25,0.25,0.15,50,50);
			glPopMatrix();
			
			glPushMatrix();
			glTranslatef(3.1,20,2.1);
			glColor3f(0.4,0.4,0.4);
			glutWireCone(0.15,0.3,10,10);
			glTranslatef(0.2,0,0);
			glutWireCone(0.15,0.3,10,10);
			glTranslatef(0.2,0,0);
			glutWireCone(0.15,0.3,10,10);
			glTranslatef(0.2,0,0);
			glutWireCone(0.15,0.3,10,10);
			glTranslatef(0.2,0,0);
			glutWireCone(0.15,0.3,10,10);
			glPopMatrix();
			break;
	case 2: 
			glColor3f(0,0,0);
			glPushMatrix();
			glTranslatef(4.1+x,20+y,2.15);
			gluSphere(Cylinder,0.12,50,50);
			glPopMatrix();
			glTranslatef(x,y,0);
			glColor3f(0.73,0.53,0.23);
			glPushMatrix();
			glTranslatef(2.85,20,2.15);
			glRotatef(90,0,1,0);
			gluCylinder(Cylinder,0.05,0.05,1.3,50,50);
			glColor3f(0,0,0);
			gluSphere(Cylinder,0.12,50,50);
			glColor3f(0.73,0.53,0.23);
			glRotatef(-90,0,1,0);
			gluCylinder(Cylinder,0.05,0.05,2,50,50);
			for(i=0;i<3;i++)
			{
			glTranslatef(0.3,0,0);
			gluCylinder(Cylinder,0.05,0.05,1.5,50,50);
			}
			glTranslatef(0.3,0,0);
			gluCylinder(Cylinder,0.05,0.05,2,50,50);
			glTranslatef(0,0,1.5);
			glRotatef(270,0,1,0);
			gluCylinder(Cylinder,0.05,0.05,1.2,50,50);
			glTranslatef(0.5,0,0);
			gluCylinder(Cylinder,0.05,0.05,1.2,50,50);
			glColor3f(0,0,0);
			glTranslatef(-2.1,4.8,1);
			glutWireSphere(0.3,10,20);
			glTranslatef(0,0,-0.6);
			glutWireSphere(0.3,10,20);
			//gluCylinder(Cylinder,0.5,0.55,0.01,50,50);
			glPopMatrix();
			break;
	case 3:
			  glPushMatrix();		//1
			 glColor3f(0.45, 0.30, 0.30);
			 glTranslatef(3.1+x, 20.0+y, 2.0);
			 gluSphere(Cylinder,0.52,50,50);
			 glTranslatef(0.9,0,0);
			 gluSphere(Cylinder,0.52,50,50);
			glTranslatef(-0.4,0,0);
			glColor3f(0.23,0.53,0.23);
			 gluCylinder(Cylinder,0.05,0.0001,1.3,50,50);
			glTranslatef(-0.1,0,0);
			 gluCylinder(Cylinder,0.08,0.0001,1,50,50);
			 glPopMatrix();
			 break;	
	}
	if(x==0 && y<-15.11)crash=1;  
	else if(x>=2 && y<-15.11)crash=2;
	else crash=0;
	newobstacle=0;

}

void light()
{
	glTranslatef(0,yy,0);
		glPushMatrix();
glTranslatef(7.8,3,2);
	glColor3f(0.23,0.23,0.23);
	gluCylinder(Cylinder,0.5,0.3,0.5,5,5);
	glColor3f(0.4,0.4,0.4);
	gluCylinder(Cylinder,0.1,0.1,3.5,5,5);
	glColor3f(0.23,0.23,0.23);
glTranslatef(0,0,3.4);
	glRotatef(-90,0,1,0);
	gluCylinder(Cylinder,0.1,0.1,1.7,5,5);
	glRotatef(90,0,1,0);
	glColor3f(7,7,0.5);
glTranslatef(-1.5,-0.01,0.05);
	glBegin(GL_POLYGON);
		for(i=0;i<=50;i++)
		{
			theta=0.0628*i;
			glVertex3f(cos(theta)*-0.3,0+jj,sin(theta)*-0.3);
		}
		glEnd();
		glPopMatrix();

	glPushMatrix();
glTranslatef(7.8,43,2);
	glColor3f(0.23,0.23,0.23);
	gluCylinder(Cylinder,0.5,0.3,0.5,5,5);
	glColor3f(0.4,0.4,0.4);
	gluCylinder(Cylinder,0.1,0.1,3.5,5,5);
	glColor3f(0.23,0.23,0.23);
glTranslatef(0,0,3.4);
	glRotatef(-90,0,1,0);
	gluCylinder(Cylinder,0.1,0.1,1.7,5,5);
	glRotatef(90,0,1,0);
	glColor3f(7,7,0.5);
glTranslatef(-1.5,-0.01,0.05);
	glBegin(GL_POLYGON);
		for(i=0;i<=50;i++)
		{
			theta=0.0628*i;
			glVertex3f(cos(theta)*-0.3,0+jj,sin(theta)*-0.3);
		}
		glEnd();
		glPopMatrix();

		glPushMatrix();
glTranslatef(7.8,83,2);
	glColor3f(0.23,0.23,0.23);
	gluCylinder(Cylinder,0.5,0.3,0.5,5,5);
	glColor3f(0.4,0.4,0.4);
	gluCylinder(Cylinder,0.1,0.1,3.5,5,5);
	glColor3f(0.23,0.23,0.23);
glTranslatef(0,0,3.4);
	glRotatef(-90,0,1,0);
	gluCylinder(Cylinder,0.1,0.1,1.7,5,5);
	glRotatef(90,0,1,0);
	glColor3f(7,7,0.5);
glTranslatef(-1.5,-0.01,0.05);
	glBegin(GL_POLYGON);
		for(i=0;i<=50;i++)
		{
			theta=0.0628*i;
			glVertex3f(cos(theta)*-0.3,0+jj,sin(theta)*-0.3);
		}
		glEnd();
		glPopMatrix();

}
void telepole()
{
	glTranslatef(0,yy,0);
		glPushMatrix();
glTranslatef(1,23,2);
	glColor3f(0.23,0.23,0.23);
	gluCylinder(Cylinder,0.5,0.1,0.2,50,50);
	gluCylinder(Cylinder,0.08,0.08,3.5,5,5);
	glTranslatef(0,0,3.4);
	glColor3f(0,0,0);

	gluSphere(Cylinder,0.1,5,5);
	glLineWidth(2);
	glBegin(GL_LINES);
	glVertex3f(0,-40,0);
	glVertex3f(0,0,0);
	glVertex3f(0,38,0);
	glEnd();
	glTranslatef(0,0,-0.2);
		gluSphere(Cylinder,0.1,5,5);
	glLineWidth(2);
	glBegin(GL_LINES);
	glVertex3f(0,-40,0);
	glVertex3f(0,0,0);
	glVertex3f(0,38,0);
	glEnd();
	glTranslatef(0,0,-0.2);
		gluSphere(Cylinder,0.1,5,5);
	glLineWidth(2);
	glBegin(GL_LINES);
	glVertex3f(0,-40,0);
	glVertex3f(0,0,0);
	glVertex3f(0,38,0);
	glEnd();
		glPopMatrix();

	glPushMatrix();
	glTranslatef(1,63,2);
	glColor3f(0.23,0.23,0.23);
	gluCylinder(Cylinder,0.5,0.1,0.2,50,50);
	gluCylinder(Cylinder,0.08,0.08,3.5,5,5);
	glTranslatef(0,0,3.4);
	glColor3f(0,0,0);
	gluSphere(Cylinder,0.1,5,5);
	glLineWidth(2);
	glBegin(GL_LINES);
	glVertex3f(0,-40,0);
	glVertex3f(0,0,0);
	glVertex3f(0,38,0);
	glEnd();
	glTranslatef(0,0,-0.2);
		gluSphere(Cylinder,0.1,5,5);
	glLineWidth(2);
	glBegin(GL_LINES);
	glVertex3f(0,-40,0);
	glVertex3f(0,0,0);
	glVertex3f(0,38,0);
	glEnd();
	glTranslatef(0,0,-0.2);
		gluSphere(Cylinder,0.1,5,5);
	glLineWidth(2);
	glBegin(GL_LINES);
	glVertex3f(0,-40,0);
	glVertex3f(0,0,0);
	glVertex3f(0,38,0);
	glEnd();
		glPopMatrix();

		glPushMatrix();
	glTranslatef(1,103,2);
	glColor3f(0.23,0.23,0.23);
	gluCylinder(Cylinder,0.5,0.1,0.2,50,50);
	gluCylinder(Cylinder,0.08,0.08,3.5,5,5);
	glTranslatef(0,0,3.4);
	glColor3f(0,0,0);
	gluSphere(Cylinder,0.1,5,5);
	glLineWidth(2);
	glBegin(GL_LINES);
	glVertex3f(0,-40,0);
	glVertex3f(0,0,0);
	glVertex3f(0,38,0);
	glEnd();
	glTranslatef(0,0,-0.2);
		gluSphere(Cylinder,0.1,5,5);
	glLineWidth(2);
	glBegin(GL_LINES);
	glVertex3f(0,-40,0);
	glVertex3f(0,0,0);
	glVertex3f(0,38,0);
	glEnd();
	glTranslatef(0,0,-0.2);
		gluSphere(Cylinder,0.1,5,5);
	glLineWidth(2);
	glBegin(GL_LINES);
	glVertex3f(0,-40,0);
	glVertex3f(0,0,0);
	glVertex3f(0,38,0);
	glEnd();
		glPopMatrix();

}
void roadway()
{
	glTranslatef(0,yy,0);
	glPushMatrix();
	glTranslatef(1.8,5,2);
	gluCylinder(Cylinder,0.081,0.051,1,3,3);
	glPopMatrix();
	glPushMatrix();
glColor3f(0.93,0.53,0.23);
	glTranslatef(-1.5,3.2,0.3);
	glRotatef(60,1,0,0);
	glRectf(2.8,2.8,3.7,3.7);
glColor3f(0,0,0);
	glRectf(2.9,2.9,3.6,3.6);
	glColor3f(0.93,0.53,0.23);
	glTranslatef(0.2,-2,0.2);
	glTranslatef(0,1.2,-0.2);
	//glRotatef(60,1,0,0);
glColor3f(0.60,0.40,0.12);
	glBegin(GL_POLYGON);
	glVertex3f(2.8,3.9,0);
	glVertex3f(3.4,3.9,0);
	glVertex3f(3,4.4,0);
	glEnd();
	glPopMatrix();
glColor3f(0,0,0);
	glPushMatrix();
	glTranslatef(1.7,5,3);
	glutWireSphere(0.6,15,10);
	glPopMatrix();

glTranslatef(0,40,0);
	glPushMatrix();
	glTranslatef(1.8,5,2);
	gluCylinder(Cylinder,0.081,0.051,1,3,3);
	glPopMatrix();
	glPushMatrix();
glColor3f(0.93,0.53,0.23);
	glTranslatef(-1.5,3.2,0.3);
	glRotatef(60,1,0,0);
	glRectf(2.8,2.8,3.7,3.7);
glColor3f(0,0,0);
	glRectf(2.9,2.9,3.6,3.6);
	glColor3f(0.93,0.53,0.23);
	glTranslatef(0.2,-2,0.2);
	glTranslatef(0,1.2,-0.2);
	//glRotatef(60,1,0,0);
glColor3f(0.60,0.40,0.12);
	glBegin(GL_POLYGON);
	glVertex3f(2.8,3.9,0);
	glVertex3f(3.4,3.9,0);
	glVertex3f(3,4.4,0);
	glEnd();
	glPopMatrix();
glColor3f(0,0,0);
	glPushMatrix();
	glTranslatef(1.7,5,3);
	glutWireSphere(0.6,15,10);
	glPopMatrix();

	glTranslatef(0,40,0);
	glPushMatrix();
	glTranslatef(1.8,5,2);
	gluCylinder(Cylinder,0.081,0.051,1,3,3);
	glPopMatrix();
	glPushMatrix();
glColor3f(0.93,0.53,0.23);
	glTranslatef(-1.5,3.2,0.3);
	glRotatef(60,1,0,0);
	glRectf(2.8,2.8,3.7,3.7);
glColor3f(0,0,0);
	glRectf(2.9,2.9,3.6,3.6);
	glColor3f(0.93,0.53,0.23);
	glTranslatef(0.2,-2,0.2);
	glTranslatef(0,1.2,-0.2);
	//glRotatef(60,1,0,0);
glColor3f(0.60,0.40,0.12);
	glBegin(GL_POLYGON);
	glVertex3f(2.8,3.9,0);
	glVertex3f(3.4,3.9,0);
	glVertex3f(3,4.4,0);
	glEnd();
	glPopMatrix();
glColor3f(0,0,0);
	glPushMatrix();
	glTranslatef(1.7,5,3);
	glutWireSphere(0.6,15,10);
	glPopMatrix();



	
}


