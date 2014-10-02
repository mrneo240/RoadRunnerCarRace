void f1b(int body)
{
	
	switch(body)
	{
	  case 1: glColor3f(0.0,1.0,0.0);break;
      case 2: glColor3f(0.23,1.0,0.73);break;
	  case 3:glColor3f(0.0,0.3,1.0);break;
	  case 4:glColor3f(1.0, 0.50, 0.50);break;
	  case 5: glColor3f(0.0,0.0,1.0);break;
      case 6: glColor3f(1.23,1.0,1.73);break;
	  case 7:glColor3f(0.0,0.3,0.0);break;
	  case 8:glColor3f(1.0, 0.0, 1.50);break;
	 case 9:glColor3f(0.0, 1.0, 1.0);break;//Cyan
    case 10:glColor3f(0.25, 0.25, 0.25);break;//Dark gray
    case 11: glColor3f(0.75, 0.75,0.75);break;//Light gray
	case 12:glColor3f(0.60, 0.40, 0.12);break;//Brown
    case 13:glColor3f(0.98, 0.625, 0.12);break;//Pumpkin orange
    case 14: glColor3f(0.98, 0.04, 0.7);break;//Pastel pink
	case 15: glColor3f(0.60, 0.40, 0.70);break;//Barney purple
	case 16: glColor3f(1.0, 1.0, 1.0);break;//White

	}
}


void Wheel()
{
	for(j=1;j<=2;j++)
	{
		glBegin(GL_POLYGON);
		for(i=0;i<=100;i++)
		{
			f1b(body+1+1+1);
			theta=0.0628*i;
			glVertex3f(2,sin(theta)*0.3,cos(theta)*0.3);
		}
		glEnd();
		glTranslatef(0.15,0,0);
		glColor3f(0,0,0);w++;
	}
}


void Wheels()
{
	glPushMatrix();
	glColor3f(1.0,0.2,0.5);
	glTranslatef(0.5,0,2.3);				//back_left
	Wheel();
	glTranslatef(1.68,0,0);
	glRotatef(90,0,1,0);
	gluCylinder(Cylinder,0.3,0.3,0.15,50,50);
	glPopMatrix();
	
	glColor3f(1.0,0.2,0.5);
	glPushMatrix();						//back_right
	glTranslatef(1.5,0,2.3);
	Wheel();
	glTranslatef(1.68,0,0);
	glRotatef(90,0,1,0);
	gluCylinder(Cylinder,0.3,0.3,0.15,50,50);
	glPopMatrix();

	glColor3f(1.0,0.2,1.0);
	glPushMatrix();						//front_left
	glTranslatef(0.5,4,2.3);
	Wheel();
	glTranslatef(1.68,0,0);
	glRotatef(90,0,1,0);
	gluCylinder(Cylinder,0.3,0.3,0.15,50,50);
	glPopMatrix();

	glColor3f(1.0,0.2,1.0);
	glPushMatrix();						//front_right
	glTranslatef(1.5,4,2.3);
	Wheel();
	glTranslatef(1.68,0,0);
	glRotatef(90,0,1,0);
	gluCylinder(Cylinder,0.3,0.3,0.15,50,50);
	glPopMatrix();

	glColor3f(0.05,0.05,0.05);
	glPushMatrix();							//backcylinder
	glTranslatef(2.5,0,2.3);
	glRotatef(90,0,1,0);
	gluCylinder(Cylinder,0.1,0.1,1,50,50);
	glPopMatrix();

	glPushMatrix();							//front cylinder
	glTranslatef(2.5,4,2.3);
	glRotatef(90,0,1,0);
	gluCylinder(Cylinder,0.1,0.1,1,50,50);
	glPopMatrix();

	glPushMatrix();							//back straight bar
	glTranslatef(3.05,0,2.4);
	gluCylinder(Cylinder,0.05,0.05,0.5,4,4);
	
	glRotatef(60,0,1,0);
	gluCylinder(Cylinder,0.05,0.05,0.47,4,4);
	glRotatef(240,0,1,0);
	gluCylinder(Cylinder,0.05,0.05,0.47,4,4);
	f1b(body+1+1);
	glRotatef(-90,2.3,0,0);
	gluCylinder(Cylinder,0.05,0.05,2.3,4,4);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(3.05,0,2.8);
	glRotatef(-120,0.5,0,0);
	gluCylinder(Cylinder,0.05,0.05,0.5,4,4);
	glPopMatrix();

	f1b(body+1+1);
	glBegin(GL_POLYGON);			//SILENCER  back BAR
	glVertex3f(2.5,0,2.1);
	glVertex3f(2.5,0,2.2);
	glVertex3f(3.5,0,2.2);
	glVertex3f(3.5,0,2.1);
	glEnd();

	glBegin(GL_POLYGON);				//backupper bar	
	glVertex3f(2.7,0,2.65);
	glVertex3f(2.8,0,2.75);
	glVertex3f(3.4,0,2.75);
	glVertex3f(3.5,0,2.65);
	glEnd();

	glBegin(GL_POLYGON);	
	glVertex3f(2.6,0,2.75);
	glVertex3f(3.6,0,2.75);
	glColor3f(0.05,0.05,0.05);
	glVertex3f(3.7,0,2.9);//backupper big bar	
	glVertex3f(2.5,0,2.9);
	glEnd();
}



void f1body()
{
	
	f1b(body+1);//bottom
	glBegin(GL_POLYGON);				
	glVertex3f(2.8,0.5,2.3);
	glVertex3f(2.8,2.5,2.3);
	glVertex3f(3.3,2.5,2.3);
	glVertex3f(3.3,0.5,2.3);
	glEnd();
glColor3f(0.05,0.05,0.05);
	glBegin(GL_POLYGON);// back black	l			
	glVertex3f(2.8,0.5,2.3);
	glVertex3f(2.8,1.5,2.5);
	glVertex3f(2.8,0.5,2.75);
	glEnd();
	glBegin(GL_POLYGON);	//r
	glVertex3f(3.3,0.5,2.75);
	glVertex3f(3.3,1.5,2.5);
	glVertex3f(3.3,0.5,2.3);
	glEnd();

	
	glBegin(GL_POLYGON);	//t			
	glVertex3f(2.8,0.5,2.75);
	glVertex3f(2.8,1.5,2.5);
	glVertex3f(3.3,1.5,2.5);
	glVertex3f(3.3,0.5,2.75);
	glEnd();
	glBegin(GL_POLYGON);	//b			
	glVertex3f(2.8,0.5,2.75);
	glVertex3f(3.3,0.5,2.75);
	glVertex3f(3.3,0.5,2.3);
	glVertex3f(2.8,0.5,2.3);
	
	glEnd();

	glBegin(GL_POLYGON);	   //mm			
	
	glVertex3f(2.8,2.5,2.75);
	glVertex3f(3.3,2.5,2.75);
	glVertex3f(3.3,2.5,2.3);
	glVertex3f(2.8,2.5,2.3);
	glEnd();

f1b(body);//b l
	glBegin(GL_POLYGON);				
	glVertex3f(2.8,0.5,2.3);
glColor3f(0.05,0.05,0.05);
	glVertex3f(2.8,1.5,2.5);
	glVertex3f(2.8,2.5,2.75);
	glVertex3f(2.8,2.5,2.3);
f1b(body);
	glEnd();
	
	glBegin(GL_POLYGON);//br
	glVertex3f(3.3,0.5,2.3);
glColor3f(0.05,0.05,0.05);
	glVertex3f(3.3,1.5,2.5);
	glVertex3f(3.3,2.5,2.75);
	glVertex3f(3.3,2.5,2.3);
f1b(body-1);
	glEnd();
	//glColor3f(1,0,0);
	glBegin(GL_POLYGON); //bt
	glVertex3f(2.8,1.5,2.5);
glColor3f(0.05,0.05,0.05);
	glVertex3f(2.8,2.5,2.75);
	glVertex3f(3.3,2.5,2.75);
f1b(body+1);
	glVertex3f(3.3,1.5,2.5);
	glEnd();

	glBegin(GL_POLYGON);			//front top
	glVertex3f(2.9,4.5,2.5);
glColor3f(0.05,0.05,0.05);
	glVertex3f(2.85,2.5,2.70);
	glVertex3f(3.25,2.5,2.70);
f1b(body-1);
	glVertex3f(3.2,4.5,2.5);
	glEnd();

	glBegin(GL_POLYGON);		//f bottom
	glVertex3f(2.85,2.5,2.3);
	glVertex3f(2.9,4.5,2.3);
	glVertex3f(3.2,4.5,2.3);
	glVertex3f(3.25,2.5,2.3);
	glEnd();

	glBegin(GL_POLYGON);//f l side
glColor3f(0.05,0.05,0.05);
	glVertex3f(2.85,2.5,2.3);
	glVertex3f(2.85,2.5,2.70);
f1b(body);
	glVertex3f(2.9,4.5,2.50);
	glVertex3f(2.9,4.5,2.3);
	glEnd();

		glBegin(GL_POLYGON);//f r side
glColor3f(0.05,0.05,0.05);
	glVertex3f(3.25,2.5,2.3);
	glVertex3f(3.25,2.5,2.70);
f1b(body-1);
	glVertex3f(3.2,4.5,2.50);
	glVertex3f(3.2,4.5,2.3);
	glEnd();

		glBegin(GL_POLYGON);//front f b side
glColor3f(0.05,0.05,0.05);
	glVertex3f(3.1,4.7,2.3);
	glVertex3f(3,4.7,2.3);
f1b(body+1);
	glVertex3f(2.9,4.5,2.3);
	glVertex3f(3.2,4.5,2.3);
	glEnd();

			glBegin(GL_POLYGON);//front f t side
glColor3f(0.05,0.05,0.05);
		glVertex3f(2.9,4.5,2.50);
		glVertex3f(3.2,4.5,2.50);
f1b(body-1);
	glVertex3f(3.1,4.7,2.3);
	glVertex3f(3,4.7,2.3);
	glEnd();

				glBegin(GL_POLYGON);//front f l side
glColor3f(0.05,0.05,0.05);
		glVertex3f(2.9,4.5,2.50);
		glVertex3f(2.9,4.5,2.30);
f1b(body+1);
	glVertex3f(3.1,4.7,2.3);
	glVertex3f(3,4.7,2.3);
	glEnd();

			glBegin(GL_POLYGON);//front f l side
glColor3f(0.05,0.05,0.05);
		glVertex3f(3.2,4.5,2.50);
		glVertex3f(3.2,4.5,2.30);
f1b(body-1);
	glVertex3f(3.1,4.7,2.3);
	glVertex3f(3,4.7,2.3);
	glEnd();


	glBegin(GL_POLYGON);
	glVertex3f(2.5,4.7,2.3);
		glColor3f(0.05,0.05,0.05);
	glVertex3f(2.6,4.7,2.55);
	glVertex3f(3.5,4.7,2.55);
	glVertex3f(3.6,4.7,2.3);
	glEnd();


								//bottom
	glBegin(GL_POLYGON);
glColor3f(0.05,0.05,0.05);
	glVertex3f(2.6,0.5,2.3);
f1b(body);
	glVertex3f(2.6,2.5,2.3);
	glVertex3f(3.5,2.5,2.3);
glColor3f(0.05,0.05,0.05);
	glVertex3f(3.5,0.5,2.3);
	glEnd();

	glBegin(GL_POLYGON);
f1b(body+1);
	glVertex3f(2.6,2.5,2.5);
glColor3f(0.05,0.05,0.05);
	glVertex3f(2.6,2.5,2.3);
	glVertex3f(2.6,0.5,2.3);
	glEnd();

		glBegin(GL_POLYGON);
f1b(body);
	glVertex3f(3.5,2.5,2.5);
glColor3f(0.05,0.05,0.05);
	glVertex3f(3.5,2.5,2.3);
	glVertex3f(3.5,0.5,2.3);
	glEnd();
	
}

void f1()
{
	glPushMatrix();
	Wheels();
	f1body();
	glPopMatrix();
}