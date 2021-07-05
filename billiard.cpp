#include <windows.h> 
#include "gl\glut.h"
#include "math.h"        
#include "texture.h"
#include <stdlib.h>
#include <windows.h>
#include <iostream.h>
#include <stdarg.h>

#define PI 3.14159265 
#define EDGES 30
#define factor0 0.101 
#define KEY_SPACE 32
#define ESC 27
#define obraz_x 800	 
#define obraz_y 600 
 
#pragma comment (lib,"opengl32.lib ")
#pragma comment (lib,"glut32.lib ")
#pragma comment (lib,"glu32.lib")

void display(void);//prototype..

float rx=0;

float zoom0=0.07,
	  zoom2=0.05,
	  zoom11=0.055;

float tz = -0.6,
	  tz0 = -0.8,
	  tz1=-2.06,
	  tz2=-2.17,
	  tz5=-2.28,
	  tz7=-2.39,
	  tz8=-2.39,
	  tz9=-2.39,
	  tz11=-2.5,
	  tz12=-2.5,
	  tz13=-2.5,
	  tz14=-2.5,
	  tz15=-2.5;

float tx0=-0.02,
	  tx2=-0.07,
	  tx3= 0.03,
	  tx4= 0.07,
	  tx5= -0.03,
	  tx6=-0.13,
	  tx7=-0.18,
	  tx8=-0.08,
	  tx10= 0.12,
	  tx11=0.17,
	  tx12=0.07,
	  tx13=-0.03,
	  tx14=-0.13,
	  tx15=-0.23;


float angle_x= 10,
	  angle_y=-30,
	  angle_z=0,
	  pos_x=0.0,
	  pos_y=-0.5,
	  pos_z=2.5;

float angx_old=angle_x,
	  angy_old=angle_y; 
 
bool	keys[256];
POINT MouseBod;

const float piover180 = 0.01745329252f ; 

unsigned int g_Texture=0;



//Function for filling the Scene..
void OnInit(int i) {

  	// enable depthe testing
	glEnable(GL_DEPTH_TEST);

	// enable texturing
	glEnable(GL_TEXTURE_2D);

	// tell openGL to generate the texture coords for a sphere map
	glTexGeni(GL_S,GL_TEXTURE_GEN_MODE,GL_SPHERE_MAP);
	glTexGeni(GL_T,GL_TEXTURE_GEN_MODE,GL_SPHERE_MAP);

	// enable automatic texture coordinate generation
	glEnable(GL_TEXTURE_GEN_S);
	glEnable(GL_TEXTURE_GEN_T);

	// enable the default light
    glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);
	

  	// load texture as compressed
switch(i)
{
case 0:
	g_Texture = LoadTexture("texture/ball0.bmp");
    break;
case 1:
	g_Texture = LoadTexture("texture/ball1.bmp");
    break;
case 2:
	g_Texture = LoadTexture("texture/ball2.bmp");
	break;
case 3:
	g_Texture = LoadTexture("texture/ball3.bmp");
	break;
case 4:
	g_Texture = LoadTexture("texture/ball4.bmp");
    break;
case 5:
	g_Texture = LoadTexture("texture/ball5.bmp");
	break;
case 6:
	g_Texture = LoadTexture("texture/ball6.bmp");
	break;
case 7:
	g_Texture = LoadTexture("texture/ball7.bmp");
	break;
case 8:
	g_Texture = LoadTexture("texture/ball8.bmp");
    break;
case 9:
	g_Texture = LoadTexture("texture/ball9.bmp");
	break;
case 10:
	g_Texture = LoadTexture("texture/ball10.bmp");
	break;
case 11:
	g_Texture = LoadTexture("texture/ball11.bmp");
      break;
case 12:
	g_Texture = LoadTexture("texture/ball12.bmp");
	break;
case 13:
	g_Texture = LoadTexture("texture/ball13.bmp");
	break;
case 14:
	g_Texture = LoadTexture("texture/ball14.bmp");
	break;
case 15:
	g_Texture = LoadTexture("texture/ball15.bmp");
	break; 
case 16:
	g_Texture = LoadTexture("texture/table-frame2.bmp");
	break;
case 17:
	g_Texture = LoadTexture("texture/green.bmp");
	break;
case 18:
	g_Texture = LoadTexture("texture/table-frame.bmp");
	break;
case 19:
	g_Texture = LoadTexture("texture/table-frame1.bmp");
	break;
case 20:
	g_Texture = LoadTexture("texture/hole.bmp");
	break;
case 21:
	g_Texture = LoadTexture("texture/edge2.bmp");
	break;
case 22:
	g_Texture = LoadTexture("texture/edge1.bmp");
	break;
}
	 //print some info about it
	//std::cout << "Texture Size=" << (GetTextureSize(g_Texture)/1024.0f) << "Kb"<< std::endl;
} 

//Camera
void ChangeCameraPosition(void)
{	
float mys_x,mys_y, step=0.02;
int i=1;
	
glLoadIdentity();
  
	if ((angle_x< 0 && angle_x!=angx_old )||(angle_y<0 &&angle_y!=angy_old))	
	{	
		pos_x -= step * (float)sin(angle_y*piover180) * (float)cos(angle_x*piover180);
		pos_y += step * (float)sin(angle_x*piover180);
	 
	if(pos_x==0)
		 pos_x+=0.1;

	if(pos_y==0) 
		 pos_y+=0.1;
			
angx_old=angle_x;
angy_old=angle_y;
}
	else if((angle_x>0 && angle_x!=angx_old )||(angle_y>= 0 &&angle_y!=angy_old))	
	{
		pos_x += step * (float)sin(angle_y*piover180) * (float)cos(angle_x*piover180);
		pos_y -= step * (float)sin(angle_x*piover180);
	
	if(pos_x==0) 
		  pos_x-=0.1;
			
	if(pos_y==0) 
		  pos_y-=0.1;
	   
angx_old=angle_x;
angy_old=angle_y;
}
 	 
	GetCursorPos(&MouseBod);						 
	SetCursorPos(obraz_x/2,obraz_y/2);			 
	mys_x= ((float)MouseBod.x - obraz_x/2)/10;		 
	mys_y= ((float)MouseBod.y - obraz_y/2)/10;	 

	angle_x+= mys_y;
	angle_y+= mys_x;
 
	if(angle_x>30.f)
		   angle_x = 130.f;
	if(angle_x<-30.f) 
		   angle_x = -30.f;

	if(angle_y>15.f) 
		   angle_y = 15.f;
	if(angle_y<-15.f)
		   angle_y = -15.f;
 
	if(angle_z> 130.f) 
		  angle_z =  130.f;
	if(angle_z<- 130.f) 
		  angle_z = - 130.f;
	
	
	glRotated(angle_x,1,0,0);
	glRotated(angle_y,0,1,0);
  //glRotated(angle_z,0,0,1); not important..!!
	glTranslated(-pos_x, -pos_y, -pos_z);
}

 
void OnExit() {
	DeleteAllTextures();
}


//Draw balls.. 
void balls()
{
glPushMatrix();
//15
glPushMatrix();
		glTranslated(tx15, -1.28,tz15);	 
		glRotated(rx,1,0,0);
		OnInit(15);
		glutSolidSphere(0.055, 35, 18);
OnExit();
glPopMatrix();

//14
glPushMatrix();
		glTranslated(tx14, -1.28,tz14);	 
		glRotated(rx,1,0,0);
		OnInit(14);
		glutSolidSphere(0.055, 35, 18);
OnExit() ;
glPopMatrix();

//13
glPushMatrix();
		glTranslated(tx13, -1.28,tz13);	 
		glRotated(rx,1,0,0);
		OnInit(13);
		glutSolidSphere(0.055, 35, 18);
OnExit();
glPopMatrix();
 
//12
glPushMatrix();
		glTranslated(tx12, -1.28,tz12);	 
		glRotated(rx,1,0,0);
		OnInit(12);
		glutSolidSphere(0.055, 35, 18);
OnExit();
glPopMatrix();

//11
glPushMatrix();
		glTranslated(tx11, -1.28,tz11);	 
		glRotated(rx,1,0,0);
		OnInit(11);
		glutSolidSphere(zoom11, 35, 18);
OnExit();
glPopMatrix();

//10
glPushMatrix();
		glTranslated(tx10, -1.28,-2.39);	 
		glRotated(rx,1,0,0);
		OnInit(10);
		glutSolidSphere(0.052, 35, 18);
OnExit();
glPopMatrix();

//9
glPushMatrix();
		glTranslated(0.02, -1.28,tz9);	 
	    glRotated(rx,1,0,0);
		OnInit(9);
		glutSolidSphere(0.052, 35, 18);
OnExit();
glPopMatrix();

//8
glPushMatrix();
		glTranslated(tx8, -1.28,tz8);	 
		glRotated(rx,1,0,0);
		OnInit(8);
		glutSolidSphere(0.052, 35, 18);
OnExit();
glPopMatrix();
 
//7
glPushMatrix();
		glTranslated(tx7, -1.28,tz7);	 
		glRotated(rx,1,0,0);
		OnInit(7);
		glutSolidSphere(0.052, 35, 18);
OnExit();
glPopMatrix();

//6
glPushMatrix();
		glTranslated(tx6, -1.28,-2.28);	 
		glRotated(rx,1,0,0);
		OnInit(6);
		glutSolidSphere(0.05, 35, 18);
OnExit();
glPopMatrix();

//5
glPushMatrix();
		glTranslated( tx5 , -1.28,tz5);	 
		glRotated(rx,1,0,0);
    	OnInit(5);
		glutSolidSphere(0.05, 35, 15);
OnExit();
glPopMatrix();

//4
glPushMatrix();
		glTranslated(tx4, -1.28,-2.28);
 		glRotated(rx,1,0,0);
		OnInit(4);
		glutSolidSphere(0.05, 35, 18);
OnExit();
glPopMatrix();

//3
glPushMatrix();
	 	glTranslated(tx3, -1.28,tz2);	 
		glRotated(rx,1,0,0);
		OnInit(3);
		glutSolidSphere(0.05, 35, 18);
OnExit();
glPopMatrix();

//2
glPushMatrix();
        glTranslated(tx2,  -1.28,tz2);	
		glRotated(rx,1,0,0);
	    OnInit(2);
		glutWireSphere(zoom2, 35, 18);
OnExit();
glPopMatrix();

//1
glPushMatrix();
		glTranslated(-0.02, -1.28,tz1);	 
		glRotated(rx,1,0,0);
		OnInit(1);
		glutSolidSphere(0.05, 35, 18);
OnExit();
glPopMatrix();

//0
glPushMatrix(); 
	 
		glTranslated(tx0, -1.28,tz0);
		glRotated(rx,1,0,0);
		OnInit(0); 
	    glutSolidSphere(zoom0, 35, 18);
OnExit() ;
glPopMatrix();

glPopMatrix();
}


//Drawing the black holes on the table of the Billiard..
static void holes(void)
{

int i,j=0;

glPushMatrix(); 

//Left Middle..
glPushMatrix(); 
glTranslated(1.5,-1.26,-1.5);  
glBegin (GL_POLYGON);
for(i=0;i<30;i++)
{
	glVertex3d(factor0*cos((2*PI*i)/EDGES) ,0 , factor0* sin((2*PI*i)/EDGES));
	glVertex3d(factor0* cos((2*PI*(i+1))/EDGES), 0,factor0* sin((2*PI*(i+1))/EDGES));
}
glEnd();
glPopMatrix();

//Right Middle..
glPushMatrix(); 
glTranslated(-1.5,-1.26,-1.5);  
glBegin (GL_POLYGON);
for(i=0;i<30;i++)
{
	glVertex3d(factor0*cos((2*PI*i)/EDGES) ,0 , factor0* sin((2*PI*i)/EDGES));
	glVertex3d(factor0* cos((2*PI*(i+1))/EDGES), 0,factor0* sin((2*PI*(i+1))/EDGES));
}
glEnd();
glPopMatrix();

//Left back..
glPushMatrix(); 
glTranslated(1.3,-1.28,-2.8);  
glBegin (GL_POLYGON);
for(i=0;i<30;i++)
{
	glVertex3d(factor0*cos((2*PI*i)/EDGES) ,0 , factor0* sin((2*PI*i)/EDGES));
	glVertex3d(factor0* cos((2*PI*(i+1))/EDGES), 0,factor0* sin((2*PI*(i+1))/EDGES));
}
glEnd();
glPopMatrix();

//Right back..
glPushMatrix(); 
glTranslated(-1.3,-1.28,-2.8);  
glBegin (GL_POLYGON);
for (i=0;i<30;i++)
{
	glVertex3d(factor0*cos((2*PI*i)/EDGES) ,0 , factor0* sin((2*PI*i)/EDGES));
	glVertex3d(factor0* cos((2*PI*(i+1))/EDGES), 0,factor0* sin((2*PI*(i+1))/EDGES));
}
glEnd();
glPopMatrix();

//Right front
glPushMatrix(); 
glTranslated(-1.8,-1.28, 0.19);  
glBegin(GL_POLYGON);
for (i=0;i<30;i++)
{
	glVertex3d(factor0*cos((2*PI*i)/EDGES) ,0 , factor0* sin((2*PI*i)/EDGES));
	glVertex3d(factor0* cos((2*PI*(i+1))/EDGES), 0,factor0* sin((2*PI*(i+1))/EDGES));
}
glEnd();
glPopMatrix();

//Left front
glPushMatrix(); 
glTranslated(1.8,-1.28,0.19);  
glBegin (GL_POLYGON);
for (i=0;i<30;i++)
{
	glVertex3d(factor0*cos((2*PI*i)/EDGES) ,0 , factor0* sin((2*PI*i)/EDGES));
	glVertex3d(factor0* cos((2*PI*(i+1))/EDGES), 0,factor0* sin((2*PI*(i+1))/EDGES));
}
glEnd();
glPopMatrix();

glPopMatrix();
}

//function to resize the Scene when expand the viewport..
void reshape(int w,int l) {
  	
	if(l == 0)
		l = 1;

	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT); // clear the screen
	glViewport(0,0,w,l);
  
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glOrtho((float) -w/l*-2.0*64/48.0,(float) w/l*-2.0*64/48.0,-2.0, 2.0, 1.9, 100);
 
    glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(2.2, 3.3, 2.2, 0.0, 0.0, 0.0, 0.1, 1.0, 0.1);
}


//Use keyboard to move the stick and balls by SPACEBAR key!!!
void Keyboard(unsigned char key,int x,int y){

static int i=1;

switch(key){
	 
	case KEY_SPACE:
		//level 0
		if(i==1)
		{
		tz -=0.28;
		
		//level 1
		while(i!=8)
		{
		tz +=0.08;
			
		tz0-=0.148;
		zoom0-=0.003;
				
		i++;
		display();//call the display function..
		}

		//level 2
		while(i!=16)
		{
			rx+=30; //it's for rounding all balls..!!
					
			tx0+=0.21;//it's for ball number 0(white ball)
			tz0+=0.2;
			zoom0+=0.003;
					
			tz1-=0.023;

			tx2-=0.155;			
			tz2-=0.004;
					
			tx3+=0.08;
			 
			tx4+=0.16;
                    
			tz5-=0.01;
                    
			tx6-=0.04;
		 
			tx7-=0.06;
				  
			tx8-=0.02;
			tz8-=0.01;
                    
			tz9-=0.03;
		
			tx10+=0.05;
					 
			tx11+=0.095;
			tz11+=0.022;
			zoom11-=0.0002;
                   
			tz12-=0.03;
			tx12+=0.08;
				    		    
			tz13-=0.03;
			tx13-=0.02;
	              
			tx14-=0.09;
			tz14-=0.03;

			tx15-=0.1;	
			tz15-=0.04;
				   
			i++; 
			display();
		}

		//level 3
		while(i!=20)
		{	
			rx+=30;
				   
			tx0-=0.1;

			tz1+=0.2;
				  
			tx2+=0.2;
			tz2+=0.16;

			tx4-=0.05;
				   
			tz5+=0.05;
			tx5-=0.06;
				   
			tx6-=0.04;
                   
			tx7-=0.15;
				    
			tx8-=0.05;
			tz8+=0.25;
               
			tz9-=0.03;
				   
            tx10+=0.01;
					
			tx11+=0.035;
			
			tx12+=0.001;
			tz12+=0.02;

			tx13+=0.01;
			tz13+=0.05;
			
			tz14+=0.005;
			 
			tz15+=0.01;
			
			i++; 
		 	display();
			}
		//level 4	    
		while(i!=27)
		{	
			rx+=30;
		
			tx2-=0.135;
			tz2+=0.002;
			zoom2-=0.001;
		
			tz5+=0.08;
		
			tx7+=0.013;
			tz7+=0.04;
 
			tz9+=0.06;
				 
			tx11+=0.025;
			tz11-=0.06;
			zoom11-=0.0008;
 
			tz15+=0.02;
	      
			i++; 
		 	display();
			}
				
		zoom11-=0.05;
		zoom2-=0.05;
}

glutPostRedisplay();
break;
		 
case ESC:
	exit(0);
	break;
default:
	break;
	}
}

//it's display function draw the table, Stick and call the balls and holes..  
void display(void)
{

ChangeCameraPosition(); //it's for moving the Camera..

	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT ); // clear the screen
	glColor3d(0,0,0);
	
glPushMatrix();

	glRotated(55,1,0,0);
	  
//holes..
OnInit(20);
glPushMatrix();
holes();
glPopMatrix();
OnExit();

//Drawing frame of the billliard table..
//back
OnInit(16);
glPushMatrix();
glBegin(GL_QUADS);
	glVertex3d(-1.35,-1.3,-2.9);
	glVertex3d(-1.5,-1.3,-3.0);
	glVertex3d(1.5,-1.3,-3.0);
	glVertex3d(1.35,-1.3,-2.9);
glEnd();
glPopMatrix();

//front
glPushMatrix();
glBegin(GL_QUADS);
	glVertex3d(-1.8  ,-1.3,0.2);
	glVertex3d(-2.2,-1.3,0.5);
	glVertex3d(2.2,-1.3,0.5);
	glVertex3d(1.8  ,-1.3,0.2);
glEnd();
glPopMatrix();

//Right
glPushMatrix();
glBegin(GL_QUADS);
	glVertex3d( 2.2,-1.3,0.5);	
	glVertex3d( 1.8 ,-1.3,0.2);
	glVertex3d( 1.3 ,-1.3,-3.0);
	glVertex3d( 1.5,-1.3,-3.0);
glEnd();
glPopMatrix();

//Left
glPushMatrix();
glBegin(GL_QUADS);
	glVertex3d(-2.2,-1.3,0.5);
	glVertex3d(-1.8 ,-1.3,0.2);
	glVertex3d(-1.3 ,-1.3,-3.0);
	glVertex3d(-1.5,-1.3,-3.0);
glEnd();
glPopMatrix();
OnExit();
	
//EDGES..
//back
OnInit(21);
glPushMatrix();
glBegin(GL_QUADS);
	glVertex3d(-1.25,-1.3,-2.9);
	glVertex3d(-1.15,-1.3,-2.8 );
	glVertex3d(1.15,-1.3,-2.8 );
	glVertex3d(1.25,-1.3,-2.9);
glEnd();
glPopMatrix();
OnExit();

//Right top..
OnInit(22);
glPushMatrix();		
glBegin(GL_QUADS);
	glVertex3d(-1.32,-1.3,-2.85);
	glVertex3d(-1.3,-1.3,-2.63);
	glVertex3d(-1.43,-1.3,-1.7);
	glVertex3d(-1.51,-1.3,-1.6 );
glEnd();
glPopMatrix();

//Right bottom..
glPushMatrix();		
glBegin(GL_QUADS);
	glVertex3d(-1.53,-1.3,-1.48);
	glVertex3d(-1.5,-1.3,-1.25);
	glVertex3d(-1.7,-1.3,0.0);
	glVertex3d(-1.85,-1.3,0.2);
glEnd();
glPopMatrix();

//Left Top..
glPushMatrix();
glBegin(GL_QUADS);
	glVertex3d(1.32,-1.3,-2.85 );
	glVertex3d(1.3,-1.3,-2.63 );
	glVertex3d(1.43,-1.3,-1.7);
	glVertex3d(1.51,-1.3,-1.6 );
glEnd();
glPopMatrix();

//Left bottom.
glPushMatrix();
glBegin(GL_QUADS);
	glVertex3d(1.53,-1.3,-1.48 );
	glVertex3d(1.5 ,-1.3,-1.25 );
	glVertex3d(1.7 ,-1.3,-0.0);
	glVertex3d(1.85,-1.3,0.2);
glEnd();
glPopMatrix();

//..
OnInit(18);
glPushMatrix();
glBegin(GL_QUADS);
	glVertex3d(-1.5,-1.42,-3.0);
	glVertex3d(1.5,-1.42,-3.0);
	glVertex3d(2.1,-1.42,0.5);
	glVertex3d(-2.1,-1.42,0.5);
glEnd();
glPopMatrix(); 
OnExit(); 
 
//ground of the billiard
OnInit(17);
//Top ground
glPushMatrix();
glBegin(GL_QUADS);
	glVertex3d(-1.5,-1.304,-1.5);
	glVertex3d( 1.5,-1.304,-1.5);
	glVertex3d(2.1,-1.304,0.5);
	glVertex3d(-2.2,-1.304,0.5);
glEnd();
glPopMatrix(); 

//bottom ground
glPushMatrix();
glBegin(GL_QUADS);
	glVertex3d(-1.35,-1.304 ,-3.0);
	glVertex3d(1.35,-1.304 ,-3.0);
	glVertex3d( 1.65,-1.304,-1.5);
	glVertex3d(-1.65,-1.3084,-1.5);
glEnd();
glPopMatrix(); 
OnExit();

//sides of the table of the billiard
//front
OnInit(18);
glPushMatrix();
glBegin(GL_QUADS);
	glVertex3d(-2.2,-1.3,0.5);
	glVertex3d(-2.1,-1.52,0.5);
	glVertex3d(2.1,-1.52,0.5);
	glVertex3d(2.2,-1.3,0.5);
glEnd();
glPopMatrix();
OnExit();
	 
//Back
OnInit(18);
glPushMatrix();
glBegin(GL_POLYGON );
	glVertex3d(-1.5,-1.3,-3.0);
	glVertex3d(-1.5,-1.52,-3.0);
	glVertex3d(1.5,-1.52,-3.0);
	glVertex3d(1.5,-1.3,-3.0);
glEnd();
glPopMatrix();
	    
//Right
glPushMatrix();
glBegin(GL_POLYGON );
	glVertex3d(-1.5,-1.3,-3.0);
	glVertex3d(-2.1,-1.3,0.5);
	glVertex3d(-2.1,-1.52,0.5);
	glVertex3d(-1.5,-1.5,-3.0);
glEnd();
glPopMatrix();

//Left
glPushMatrix();
glBegin(GL_QUADS);
	glVertex3d( 1.5,-1.3,-3.0);
	glVertex3d( 2.1,-1.3,0.5);
	glVertex3d( 2.1,-1.52,0.5);
	glVertex3d( 1.5,-1.52,-3.0);
glEnd();
glPopMatrix();
OnExit();

//side front
OnInit(19);
glPushMatrix();
glBegin(GL_QUADS);
	glVertex3d(-2.0,-1.52,0.45);
	glVertex3d(-1.4,-2.1,0.5);
	glVertex3d(1.4,-2.1,0.5);
	glVertex3d(2.0,-1.52,0.45);
glEnd();
glPopMatrix();

//side back
glPushMatrix();
glBegin(GL_POLYGON );
	glVertex3d(-1.5,-1.52,-3.0);
	glVertex3d(-1.08,-2.1,-3.0);
	glVertex3d(1.08,-2.1,-3.0);
	glVertex3d(1.5,-1.5,-3.0);
glEnd();
glPopMatrix();
 
//side Left
glPushMatrix();
glBegin(GL_QUADS);
	glVertex3d(1.4,-2.1,0.5);
	glVertex3d(2.0,-1.52,0.5);
	glVertex3d(1.5,-1.52,-3.0);
	glVertex3d(1.08,-2.1,-3.0);
glEnd();
glPopMatrix();

//side Right
glPushMatrix();
glBegin(GL_QUADS);
	glVertex3d(-1.4,-2.1,0.5);
	glVertex3d(-2.0,-1.52,0.5);
	glVertex3d(-1.5,-1.52,-3.0); 
	glVertex3d(-1.08,-2.1,-3.0);
glEnd();
glPopMatrix();
OnExit();
  
//side ground
OnInit(18);
glPushMatrix();
glBegin(GL_POLYGON );
	glVertex3d(1.08,-2.1,-3.0); 
	glVertex3d(1.4,-2.1,0.5);
	glVertex3d(-1.4,-2.1,0.5);
	glVertex3d(-1.08,-2.1,-3.0);
glEnd();
glPopMatrix();
OnExit();

//Drawing the balls..
glPushMatrix();
balls();	
glPopMatrix();
 
//Stick..
OnInit(16);
glPushMatrix();
glTranslated(-0.02, -1.25, tz);
 	GLUquadricObj * qobj;
	qobj = gluNewQuadric();
	gluQuadricDrawStyle(qobj,GLU_LINE);
 	gluCylinder(qobj, 0.01, 0.04, 2.3, 2000,2000);	
glPopMatrix();
OnExit(); 
glPopMatrix(); 

glPopMatrix(); 
glutSwapBuffers(); 
glFlush(); 
}


int main(int argc, char** argv){
	 
	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_RGBA |GLUT_DOUBLE | GLUT_DEPTH );
	glutInitWindowSize(750,700);
	glutInitWindowPosition(150,25); 
	glutCreateWindow("Nayeef_14380,Ghady_20514");
	glutKeyboardFunc(Keyboard);
	glutDisplayFunc(display);
 	glutIdleFunc(display);
	glutReshapeFunc(reshape);	

	glutMainLoop();
	
return 0;
}
 