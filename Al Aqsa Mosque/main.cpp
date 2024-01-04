#pragma once
#include <windows.h> // Header File For Windows
#include <gl.h>		 // Header File For The OpenGL32 Library
#include <glu.h>	 // Header File For The GLu32 Library
#include <glaux.h>
#include <fstream>
#include <cmath>
#include "Point.h"
#include "Skybox.h"
#include "primitives.h"
#include "DrawWall.h"
#include "House.h"
#include "Door.h"
#include "around.h"
#include "Dome Of The Rock.h"
#include "texture.h"
#include "Camera.h"
#include "Pillar.h"
#include "minaret.h"
#include "qibaliMosque.h"
#include "Cylinder.h"
#include "vendor/model/Model_3DS.h"
<<<<<<< HEAD

#define unbind glBindTexture(GL_TEXTURE_2D, 0);
// Stolen From: Yassien 
#define txt(s,t) glTexCoord2d(s,t)
#define white glColor3f(1,1,1)
#define db double 
#define cull glEnable(GL_CULL_FACE)
#define nocull glDisable(GL_CULL_FACE)
#define frontf glCullFace(GL_FRONT)
#define backf glCullFace(GL_BACK)
#define pshm glPushMatrix()
#define ppm glPopMatrix()


//const db srt = 1.414213562373095;
//const db pi = 3.1415926535897932384626433832795028;


=======
#include "Marwani.h"
>>>>>>> 4360b26b8ef3f63ac49f72ebf3966b890a6c5b53

int mouseX = 0, mouseY = 0;
bool isClicked = 0, isRClicked = 0;

HDC hDC = NULL;		 // Private GDI Device Context
HGLRC hRC = NULL;	 // Permanent Rendering Cntext
HWND hWnd = NULL;	 // Holds Our Window Handle
HINSTANCE hInstance; // Holds The Instance Of The Application

bool keys[256];			 // Array Used For The Keyboard Routine
bool active = TRUE;		 // Window Active Flag Set To TRUE By Default
bool fullscreen = FALSE; // Fullscreen Flag Set To Fullscreen Mode By Default
Point bottom_left_back;
<<<<<<< HEAD
int ground, wall, grass;
int texture_wall, texture_door, CylinderBody;
int stone1 , wall5 ;
int ball, skybox, top, wall3, upwall, bottomwall;
around *a;
int house_door, house_window, house_wall, wallofmosque;
=======
int ground,wall,grass ;
int  texture_wall,texture_door,CylinderBody;
int ball,skybox,top,wall3,upwall,bottomwall;
int outsideDoors;
around* a;
int house_door, house_window, house_wall,wallofmosque;
>>>>>>> 4360b26b8ef3f63ac49f72ebf3966b890a6c5b53
int house_roof[4];
int texture[6];

Camera MyCamera;

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM); // Declaration For WndProc

GLvoid ReSizeGLScene(GLsizei width, GLsizei height) // Resize And Initialize The GL Window
{
	if (height == 0) // Prevent A Divide By Zero By
	{
		height = 1; // Making Height Equal One
	}

	glViewport(0, 0, width, height); // Reset The Current Viewport

	glMatrixMode(GL_PROJECTION); // Select The Projection Matrix
	glLoadIdentity();			 // Reset The Projection Matrix

	// Calculate The Aspect Ratio Of The Window
	gluPerspective(45.0f, (GLfloat)width / (GLfloat)height, 0.1f, 2000.0f);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

int image, image2 , marble;
int SKYFRONT, SKYBACK, SKYLEFT, SKYRIGHT, SKYUP, SKYDOWN;
Model_3DS *tree;
GLTexture Bark, Leaf;
int qibaliMosque;
int mosquewindow;
int carpet;
int mosqueRoof, mosqueRoof2;
int mosaic;
int arch;
int mosquewindow2;
int marwanoCarpet;
void Draw_Skybox(float x, float y, float z, float width, float height, float length)
{

	glEnable(GL_TEXTURE_2D);
	// Center the Skybox around the given x,y,z position
	x = x - width / 2;
	y = y - height / 2;
	z = z - length / 2;


	// Draw Front side
	glBindTexture(GL_TEXTURE_2D, SKYFRONT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, 0x812F);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, 0x812F);
	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(x, y, z + length);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(x, y + height, z + length);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(x + width, y + height, z + length);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(x + width, y, z + length);
	glEnd();

	// Draw Back side
	glBindTexture(GL_TEXTURE_2D, SKYBACK);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, 0x812F);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, 0x812F);
	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(x + width, y, z);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(x + width, y + height, z);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(x, y + height, z);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(x, y, z);
	glEnd();

	// Draw Left side
	glBindTexture(GL_TEXTURE_2D, SKYLEFT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, 0x812F);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, 0x812F);
	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(x, y + height, z);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(x, y + height, z + length);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(x, y, z + length);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(x, y, z);
	glEnd();

	// Draw Right side
	glBindTexture(GL_TEXTURE_2D, SKYRIGHT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, 0x812F);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, 0x812F);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(x + width, y, z);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(x + width, y, z + length);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(x + width, y + height, z + length);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(x + width, y + height, z);
	glEnd();

	// Draw Up side
	glBindTexture(GL_TEXTURE_2D, SKYUP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, 0x812F);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, 0x812F);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(x + width, y + height, z);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(x + width, y + height, z + length);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(x, y + height, z + length);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(x, y + height, z);
	glEnd();

	// Draw Down side
	glBindTexture(GL_TEXTURE_2D, SKYDOWN);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, 0x812F);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, 0x812F);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(x, y, z);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(x, y, z + length);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(x + width, y, z + length);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(x + width, y, z);
	glEnd();

	glColor3f(1, 1, 1);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	unbind;
}

int InitGL(GLvoid)
{

	
	glShadeModel(GL_SMOOTH);
	glClearColor(0.0f, 0.0f, 0.0f, 0.5f);
	glClearDepth(1.0f);
	glEnable(GL_TEXTURE_2D); // Depth Buffer Setup
	glEnable(GL_DEPTH_TEST);
	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glDepthFunc(GL_LEQUAL);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
	
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	tree = new Model_3DS();
	// this one just to fix the bug of puting the first texture on the primitive if i didn't bind any textuer to it
	marble = LoadTexture("", 255);
	marble = LoadTexture("images/walls/marble.bmp", 255);

	stone1 = LoadTexture("images/walls/stone1.bmp", 255);
	wall5 = LoadTexture("images/walls/wall5.bmp", 255);


	ball = LoadTexture("images/mosque/ball.bmp", 255);
	upwall = LoadTexture("images/mosque/up_wall.bmp", 255);
	bottomwall = LoadTexture("images/mosque/bottom_wall.bmp", 255);
	CylinderBody = LoadTexture("images/mosque/CylinderBody.bmp", 255);
	wall3 = LoadTexture("images/wall3.bmp", 255);
	// texture_door = LoadTexture("images/door.bmp", 255);
	ground = LoadTexture("images/walls/ground.bmp", 255);
	grass = LoadTexture("images/walls/grass.bmp", 255);
	wall = LoadTexture("images/walls/house_wall.bmp", 255);
	house_wall = LoadTexture("images/mosque/insidemosque.bmp", 255);
	house_door = LoadTexture("images/House/door.bmp", 255);
	house_window = LoadTexture("images//House/window.bmp", 255);
	house_roof[0] = LoadTexture("images/texture_wall.bmp", 255);
	house_roof[1] = LoadTexture("images/texture_wall.bmp", 255);
	house_roof[2] = LoadTexture("images/texture_wall.bmp", 255);
	house_roof[3] = LoadTexture("images/texture_wall.bmp", 255);
	SKYFRONT = LoadTexture("images/skybox/front.bmp", 255);
	SKYBACK = LoadTexture("images/skybox/back.bmp", 255);
	SKYLEFT = LoadTexture("images/skybox/left.bmp", 255);
	SKYRIGHT = LoadTexture("images/skybox/right.bmp", 255);
	SKYUP = LoadTexture("images/skybox/up.bmp", 255);
	SKYDOWN = LoadTexture("images/skybox/down.bmp", 255);
	qibaliMosque = LoadTexture("images/mosque/wallmosque.bmp", 255);
	mosqueRoof = LoadTexture("images/mosque/roofmosque.bmp", 255);
	mosquewindow = LoadTexture("images/mosque/qibali.bmp", 255);
	carpet = LoadTexture("images/mosque/carpetMosque.bmp", 255);
	mosaic = LoadTexture("images/mosque/mosaic.bmp", 255);
	mosqueRoof2 = LoadTexture("images/mosque/mosqueroof2.bmp", 255);
	arch = LoadTexture("images/mosque/arch2.bmp", 255);
	mosquewindow2 = LoadTexture("images/mosque/mosquewindow2.bmp", 255);

	tree = new Model_3DS();
	tree->Load("models/tree/Tree.3ds");
	Leaf.LoadBMP("models/tree/green.bmp");
	Bark.LoadBMP("models/tree/bark.bmp");
	tree->Materials[0].tex = Bark;
	tree->Materials[1].tex = Bark;
	tree->Materials[2].tex = Bark;

	tree->Materials[3].tex = Bark;
	tree->Materials[4].tex = Leaf;
	tree->Materials[5].tex = Leaf;
	tree->Materials[6].tex = Leaf;
	tree->Materials[7].tex = Leaf;

<<<<<<< HEAD
=======
	ball			 = LoadTexture("images/mosque/ball.bmp", 255);
	upwall			 = LoadTexture("images/mosque/up_wall.bmp", 255);
	bottomwall			 = LoadTexture("images/mosque/bottom_wall.bmp", 255);
	CylinderBody			 = LoadTexture("images/mosque/CylinderBody.bmp", 255);
	wall3			 = LoadTexture("images/wall3.bmp",255);
	//texture_door = LoadTexture("images/door.bmp", 255);
	ground			 = LoadTexture("images/walls/ground.bmp", 255);
	grass			 = LoadTexture("images/walls/grass.bmp", 255);
	wall			 = LoadTexture("images/walls/house_wall.bmp",255);
	house_wall		 = LoadTexture("images/mosque/insidemosque.bmp",255);
	house_door		 = LoadTexture("images/House/door.bmp",255);
	house_window	 = LoadTexture("images//House/window.bmp",255);
	house_roof[0]	 = LoadTexture("images/texture_wall.bmp",255);
	house_roof[1]	 = LoadTexture("images/texture_wall.bmp",255);
	house_roof[2]	 = LoadTexture("images/texture_wall.bmp",255);
	house_roof[3]	 = LoadTexture("images/texture_wall.bmp",255);
	SKYFRONT		 = LoadTexture("images/skybox/front.bmp", 255);
	SKYBACK		  	 = LoadTexture("images/skybox/back.bmp", 255);
	SKYLEFT			 = LoadTexture("images/skybox/left.bmp", 255);
	SKYRIGHT		 = LoadTexture("images/skybox/right.bmp", 255);
	SKYUP			 = LoadTexture("images/skybox/up.bmp", 255);
	SKYDOWN			 = LoadTexture("images/skybox/down.bmp", 255);
	qibaliMosque     = LoadTexture("images/mosque/wallmosque.bmp", 255);
	mosqueRoof  = LoadTexture("images/mosque/roofmosque.bmp", 255);
	mosquewindow = LoadTexture("images/mosque/qibali.bmp", 255);
	carpet          =LoadTexture("images/mosque/carpetMosque.bmp", 255);
	mosaic =  LoadTexture("images/mosque/mosaic.bmp", 255);
	mosqueRoof2 =  LoadTexture("images/mosque/mosqueroof2.bmp", 255);
	arch =  LoadTexture("images/mosque/arch2.bmp", 255);
	mosquewindow2 =  LoadTexture("images/mosque/mosquewindow2.bmp", 255);
	outsideDoors = LoadTexture("images/mosque/outsidedoors2.bmp", 255);
	marwanoCarpet = LoadTexture("images/mosque/carpet.bmp", 255);


	// note if you load a image the opengl while on the GL_Texture_2D himself
	glDisable(GL_TEXTURE_2D);
	
>>>>>>> 4360b26b8ef3f63ac49f72ebf3966b890a6c5b53
	MyCamera = Camera();
	MyCamera.Position.x = 0;
	MyCamera.Position.y = 0;
	MyCamera.Position.z = -10;

	return TRUE; // Initialization Went OK
}

// Camera c1=Camera(keys);
float angle = 0;
float angle2 = 0;
Point *loc = new Point(0, 0, -5);
void Key(bool *keys, float speed)
{
	if (keys[VK_DOWN])
		MyCamera.RotateX(-1 * speed);
	if (keys[VK_UP])
		MyCamera.RotateX(1 * speed);
	if (keys[VK_RIGHT])
		MyCamera.RotateY(-1 * speed);
	if (keys[VK_LEFT])
		MyCamera.RotateY(1 * speed);
	if (keys['Z'])
		MyCamera.RotateZ(1 * speed);
	if (keys['X'])
		MyCamera.RotateZ(-1 * speed);

	if (keys['W'])
		MyCamera.MoveForward(1 * speed);
	if (keys['S'])
		MyCamera.MoveForward(-1 * speed);
	if (keys['D'])
		MyCamera.MoveRight(1 * speed);
	if (keys['A'])
		MyCamera.MoveRight(-1 * speed);
	if (keys['Q'])
		MyCamera.MoveUpward(1 * speed);
	if (keys['E'])
		MyCamera.MoveUpward(-1 * speed);
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
float z = 0;


int DrawGLScene(GLvoid) // Here's Where We Do All The Drawing
{
	unbind;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	/*Camera c2 = Camera(c1);
	c2.kb();
	Point pos = Point(c2.cPos.x,c2.cPos.y,c2.cPos.z);*/
	// pos.z-=z;
	// if (Collision(pos))
	// c1.move();
	
	MyCamera.Render();

	Key(keys, 0.1);
	// MyCamera.Render();

	// a= new around(Point(-20,0,-40),40,30,house_door,house_wall,house_window,house_roof);
	
	Draw_Skybox(0, 0, 0, 2000, 2000, 2000);
<<<<<<< HEAD
	/*DrawWall *d = new DrawWall();
	DomeOfTheRock *ro = new DomeOfTheRock();
	House *h = new House();
	qibaliMosquee *mosque = new qibaliMosquee();
	mosque->drawQibaliMosque(150, 5, 35, mosquewindow, qibaliMosque, mosqueRoof2,
							 mosquewindow2, mosqueRoof, mosaic, marble, house_wall, arch, carpet);*/

	glTranslated(0, 0, -20);
	glBindTexture(GL_TEXTURE_2D, 0);
=======
	DrawWall* d=new DrawWall();
	DomeOfTheRock* ro=new DomeOfTheRock();
	House* h=new House();
	qibaliMosquee* mosque = new qibaliMosquee();
	mosque->drawQibaliMosque(150,5,35,mosquewindow,qibaliMosque,mosqueRoof2,
		mosquewindow2,mosqueRoof,mosaic,marble,house_wall,arch,carpet,outsideDoors,house_door);

	d->drawGround(Point(1,1,1),1000,2,1000,grass);
	primitives p;
	Marwani* m = new Marwani();
	 //p.DrawCylinderBody(Point(20, 10, 10), 0.5, 0.5, 10, -1);
	Pillar pillar(1.5,11.5); 
	pillar.cube_cylinder_pillar(Point(150, 11, 150),marble,marble);
	pillar.cube_cylinder_pillar(Point(140, 11, 150),marble,marble);	
	pillar.cube_cylinder_pillar(Point(145, 11, 145),marble,marble);
	pillar.cube_cylinder_pillar(Point(145, 11, 155),marble,marble);	

	m->drawMarwaniMosque(Point(160,12,500),400,250,40,5,qibaliMosque,marwanoCarpet,marble);
>>>>>>> 4360b26b8ef3f63ac49f72ebf3966b890a6c5b53
	
	int textures[6] = {wall5,wall5,wall5,wall5,stone1 , stone1};
	primitives::Arch(60, 100, 600, 16, textures);
	Door door(Point(100 , 0,  0) , 50 , 50 , wall5 , 90 , 90);
	door.DrawDoor(keys,Point(100 , 0 , 0));
	/*school *s = new school();





	 //ro->Floor_Roof(marble);

	p.DrawQuad(Point(140,25,143),Point(151.5,25,143),Point(151.5,25,156.5),Point(140,25,156.5),marble);
	  ro->DrawBall(5,ball,Point (146,24.7,150));
	//p.DrawCircle(-5,20,5,100);
		p.DrawQuad(Point(0,20,4),Point(11.5,20,4),Point(11.5,20,16.5),Point(0,20,15.5),marble);
	  ro->DrawBall(5,ball,Point (6,19.7,10));
	glTranslated(100, 0, 100);
	glPushMatrix();
		primitives::DrawRing(Point(10,10,10),100,100,wall);
			glTranslated(400, 0, -80);
			glPushMatrix();
			glRotated(-90,0,10,0);
			glBindTexture(GL_TEXTURE_2D,wall);
			glBegin(GL_TRIANGLE_STRIP);
			//glColor3b(1,1,1);
			glTexCoord2f(0,0);
			glVertex3d(0,0,0);

			glTexCoord2f(1,0);
			glVertex3d(80,0,0);

			glTexCoord2f(1,1);
			glVertex3d(60,12,0);

			glTexCoord2f(0,1);
			glVertex3d(80,12,0);
			glEnd();
			  glPopMatrix();
			  glPushMatrix();
			glRotated(-90,0,10,0);
			glTranslated(0, 0, -50);
			glBindTexture(GL_TEXTURE_2D,wall);
			glBegin(GL_TRIANGLE_STRIP);
			//glColor3b(1,1,1);
			glTexCoord2f(0,0);
			glVertex3d(0,0,0);

			glTexCoord2f(1,0);
			glVertex3d(80,0,0);

			glTexCoord2f(1,1);
			glVertex3d(60,12,0);

			glTexCoord2f(0,1);
			glVertex3d(80,12,0);
			glEnd();
			  glPopMatrix();
			ro->DrawStrais(50,house_wall);glPushMatrix();
			glPushMatrix();glTranslated(-10, -11,-10);
			glRotated(-180, 0, 1, 0);
		h->DrawHousewithoutDome(Point(0,0,0),100,40,40,40,house_door,wall,house_window);
			glPopMatrix();
			glPushMatrix();glTranslated(160, -11,-10);
			glRotated(-180, 0, 1, 0);
		h->DrawHousewithoutDome(Point(0,0,0),100,40,40,40,house_door,wall,house_window);
			glPopMatrix();
			glTranslated(60, 25,-50);
		h->DrawHousewithDomeNOdoor(Point(0,0,0),100,40,40,40,wall,house_window,wall);
			 glPopMatrix();
			  glPopMatrix();
			d->drawWall(Point(1, 1, 1),11,1,800,wall);
				glPushMatrix();
				glTranslated(0, 10, 0);
			d->drawGround(Point (1, 1, 1),10,1,800,ground);
		  glPushMatrix();
		  glPushMatrix();
		  glTranslated(600, 0, 50); ////////////////////////////////
		  h->DrawHousewithDome(Point(0,0,0),100,40,40,40,house_door,wall,house_window,wall);
		  glPopMatrix();                       //��������������
		  glTranslated(400, 0, 500);
		  ro->DrawOctagon(60, 30, bottomwall, Point (0, 0, 0));
		 glPushMatrix();glTranslated(0, 30, 0);   ro->DrawOctagon(60, 50, upwall, Point (0, 0, 0));
		  glPopMatrix();
		 //�������������
		  glPushMatrix();                                             //��������������
		  glTranslated(30, 0, -72.6);
		  glRotated(22.5, 0, 1, 0);
		  glRotated(90, 1, 0, 0);
		  ro->Floor_Roof(marble);
		  glPopMatrix();

		  glPushMatrix();
		  glTranslated(30, 80, -72.6);
		  glRotated(90, 1, 0, 0);
		  glRotated(22.5, 0,0, 1);
		  ro->Floor_Roof(marble);
		  glPopMatrix();
		   glPushMatrix();
		   glTranslated(30, 83, -74);
		   glPushMatrix();
			glTranslated(0, -10, 0);
		   primitives::DrawCylinderBody(Point(0,0,0),48,48,20,CylinderBody);
		   glPopMatrix();
		   ro->DrawBall(50,ball,Point (0,0,0));
		   glPopMatrix();
		   glPopMatrix();
		   glPushMatrix();
		   glPopMatrix();
		glPopMatrix();
	 glPopMatrix();

	//Pillar pillar ;
	//pillar.cube_cylinder_pillar(Point(0,0,0),4,marble,10,-1);

	for(float i = -100 ; i <= 100 ; i+=0.1){
		glBegin(GL_POINTS);
			glVertex3d(i , 0 , 0);
			glVertex3d(0 , i , 0);
		glEnd();
	}
	//primitives::Draw3DHexagon(Point(0,0,-100),40,100,marble);
	tree->pos.x=0;
	tree->pos.y=0;
	tree->pos.z=0;
	tree->scale=2;
	tree->Draw();

	
	/*tree->pos.x = 10 ;
	tree->pos.y = 0  ;
	tree->pos.z = 0  ;
	
	tree->Draw();*/
	//Minaret mina2(200, 50);
	//mina2.draw_minaret(Point(50, 0, 0), marble, marble, marble, marble);
	
	return TRUE;
}

GLvoid KillGLWindow(GLvoid) // Properly Kill The Window
{
	if (fullscreen) // Are We In Fullscreen Mode?
	{
		ChangeDisplaySettings(NULL, 0); // If So Switch Back To The Desktop
		ShowCursor(TRUE);				// Show Mouse Pointer
	}

	if (hRC) // Do We Have A Rendering Context?
	{
		if (!wglMakeCurrent(NULL, NULL)) // Are We Able To Release The DC And RC Contexts?
		{
			MessageBox(NULL, "Release Of DC And RC Failed.", "SHUTDOWN ERROR", MB_OK | MB_ICONINFORMATION);
		}

		if (!wglDeleteContext(hRC)) // Are We Able To Delete The RC?
		{
			MessageBox(NULL, "Release Rendering Context Failed.", "SHUTDOWN ERROR", MB_OK | MB_ICONINFORMATION);
		}
		hRC = NULL; // Set RC To NULL
	}

	if (hDC && !ReleaseDC(hWnd, hDC)) // Are We Able To Release The DC
	{
		MessageBox(NULL, "Release Device Context Failed.", "SHUTDOWN ERROR", MB_OK | MB_ICONINFORMATION);
		hDC = NULL; // Set DC To NULL
	}

	if (hWnd && !DestroyWindow(hWnd)) // Are We Able To Destroy The Window?
	{
		MessageBox(NULL, "Could Not Release hWnd.", "SHUTDOWN ERROR", MB_OK | MB_ICONINFORMATION);
		hWnd = NULL; // Set hWnd To NULL
	}

	if (!UnregisterClass("OpenGL", hInstance)) // Are We Able To Unregister Class
	{
		MessageBox(NULL, "Could Not Unregister Class.", "SHUTDOWN ERROR", MB_OK | MB_ICONINFORMATION);
		hInstance = NULL; // Set hInstance To NULL
	}
}

/*	This Code Creates Our OpenGL Window.  Parameters Are:					*
 *	title			- Title To Appear At The Top Of The Window				*
 *	width			- Width Of The GL Window Or Fullscreen Mode				*
 *	height			- Height Of The GL Window Or Fullscreen Mode			*
 *	bits			- Number Of Bits To Use For Color (8/16/24/32)			*
 *	fullscreenflag	- Use Fullscreen Mode (TRUE) Or Windowed Mode (FALSE)	*/

BOOL CreateGLWindow(char *title, int width, int height, int bits, bool fullscreenflag)
{
	GLuint PixelFormat;				  // Holds The Results After Searching For A Match
	WNDCLASS wc;					  // Windows Class Structure
	DWORD dwExStyle;				  // Window Extended Style
	DWORD dwStyle;					  // Window Style
	RECT WindowRect;				  // Grabs Rectangle Upper Left / Lower Right Values
	WindowRect.left = (long)0;		  // Set Left Value To 0
	WindowRect.right = (long)width;	  // Set Right Value To Requested Width
	WindowRect.top = (long)0;		  // Set Top Value To 0
	WindowRect.bottom = (long)height; // Set Bottom Value To Requested Height

	fullscreen = fullscreenflag; // Set The Global Fullscreen Flag

	hInstance = GetModuleHandle(NULL);			   // Grab An Instance For Our Window
	wc.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC; // Redraw On Size, And Own DC For Window.
	wc.lpfnWndProc = (WNDPROC)WndProc;			   // WndProc Handles Messages
	wc.cbClsExtra = 0;							   // No Extra Window Data
	wc.cbWndExtra = 0;							   // No Extra Window Data
	wc.hInstance = hInstance;					   // Set The Instance
	wc.hIcon = LoadIcon(NULL, IDI_WINLOGO);		   // Load The Default Icon
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);	   // Load The Arrow Pointer
	wc.hbrBackground = NULL;					   // No Background Required For GL
	wc.lpszMenuName = NULL;						   // We Don't Want A Menu
	wc.lpszClassName = "OpenGL";				   // Set The Class Name

	if (!RegisterClass(&wc)) // Attempt To Register The Window Class
	{
		MessageBox(NULL, "Failed To Register The Window Class.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE; // Return FALSE
	}

	if (fullscreen) // Attempt Fullscreen Mode?
	{
		DEVMODE dmScreenSettings;								// Device Mode
		memset(&dmScreenSettings, 0, sizeof(dmScreenSettings)); // Makes Sure Memory's Cleared
		dmScreenSettings.dmSize = sizeof(dmScreenSettings);		// Size Of The Devmode Structure
		dmScreenSettings.dmPelsWidth = width;					// Selected Screen Width
		dmScreenSettings.dmPelsHeight = height;					// Selected Screen Height
		dmScreenSettings.dmBitsPerPel = bits;					// Selected Bits Per Pixel
		dmScreenSettings.dmFields = DM_BITSPERPEL | DM_PELSWIDTH | DM_PELSHEIGHT;

		// Try To Set Selected Mode And Get Results.  NOTE: CDS_FULLSCREEN Gets Rid Of Start Bar.
		if (ChangeDisplaySettings(&dmScreenSettings, CDS_FULLSCREEN) != DISP_CHANGE_SUCCESSFUL)
		{
			// If The Mode Fails, Offer Two Options.  Quit Or Use Windowed Mode.
			if (MessageBox(NULL, "The Requested Fullscreen Mode Is Not Supported By\nYour Video Card. Use Windowed Mode Instead?", "GL template", MB_YESNO | MB_ICONEXCLAMATION) == IDYES)
			{
				fullscreen = FALSE; // Windowed Mode Selected.  Fullscreen = FALSE
			}
			else
			{
				// Pop Up A Message Box Letting User Know The Program Is Closing.
				MessageBox(NULL, "Program Will Now Close.", "ERROR", MB_OK | MB_ICONSTOP);
				return FALSE; // Return FALSE
			}
		}
	}

	if (fullscreen) // Are We Still In Fullscreen Mode?
	{
		dwExStyle = WS_EX_APPWINDOW; // Window Extended Style
		dwStyle = WS_POPUP;			 // Windows Style
		ShowCursor(FALSE);			 // Hide Mouse Pointer
	}
	else
	{
		dwExStyle = WS_EX_APPWINDOW | WS_EX_WINDOWEDGE; // Window Extended Style
		dwStyle = WS_OVERLAPPEDWINDOW;					// Windows Style
	}

	AdjustWindowRectEx(&WindowRect, dwStyle, FALSE, dwExStyle); // Adjust Window To True Requested Size

	// Create The Window
	if (!(hWnd = CreateWindowEx(dwExStyle,							// Extended Style For The Window
								"OpenGL",							// Class Name
								title,								// Window Title
								dwStyle |							// Defined Window Style
									WS_CLIPSIBLINGS |				// Required Window Style
									WS_CLIPCHILDREN,				// Required Window Style
								0, 0,								// Window Position
								WindowRect.right - WindowRect.left, // Calculate Window Width
								WindowRect.bottom - WindowRect.top, // Calculate Window Height
								NULL,								// No Parent Window
								NULL,								// No Menu
								hInstance,							// Instance
								NULL)))								// Dont Pass Anything To WM_CREATE
	{
		KillGLWindow(); // Reset The Display
		MessageBox(NULL, "Window Creation Error.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE; // Return FALSE
	}

	static PIXELFORMATDESCRIPTOR pfd = // pfd Tells Windows How We Want Things To Be
		{
			sizeof(PIXELFORMATDESCRIPTOR), // Size Of This Pixel Format Descriptor
			1,							   // Version Number
			PFD_DRAW_TO_WINDOW |		   // Format Must Support Window
				PFD_SUPPORT_OPENGL |	   // Format Must Support OpenGL
				PFD_DOUBLEBUFFER,		   // Must Support Double Buffering
			PFD_TYPE_RGBA,				   // Request An RGBA Format
			bits,						   // Select Our Color Depth
			0, 0, 0, 0, 0, 0,			   // Color Bits Ignored
			0,							   // No Alpha Buffer
			0,							   // Shift Bit Ignored
			0,							   // No Accumulation Buffer
			0, 0, 0, 0,					   // Accumulation Bits Ignored
			16,							   // 16Bit Z-Buffer (Depth Buffer)
			0,							   // No Stencil Buffer
			0,							   // No Auxiliary Buffer
			PFD_MAIN_PLANE,				   // Main Drawing Layer
			0,							   // Reserved
			0, 0, 0						   // Layer Masks Ignored
		};

	if (!(hDC = GetDC(hWnd))) // Did We Get A Device Context?
	{
		KillGLWindow(); // Reset The Display
		MessageBox(NULL, "Can't Create A GL Device Context.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE; // Return FALSE
	}

	if (!(PixelFormat = ChoosePixelFormat(hDC, &pfd))) // Did Windows Find A Matching Pixel Format?
	{
		KillGLWindow(); // Reset The Display
		MessageBox(NULL, "Can't Find A Suitable PixelFormat.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE; // Return FALSE
	}

	if (!SetPixelFormat(hDC, PixelFormat, &pfd)) // Are We Able To Set The Pixel Format?
	{
		KillGLWindow(); // Reset The Display
		MessageBox(NULL, "Can't Set The PixelFormat.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE; // Return FALSE
	}

	if (!(hRC = wglCreateContext(hDC))) // Are We Able To Get A Rendering Context?
	{
		KillGLWindow(); // Reset The Display
		MessageBox(NULL, "Can't Create A GL Rendering Context.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE; // Return FALSE
	}

	if (!wglMakeCurrent(hDC, hRC)) // Try To Activate The Rendering Context
	{
		KillGLWindow(); // Reset The Display
		MessageBox(NULL, "Can't Activate The GL Rendering Context.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE; // Return FALSE
	}

	ShowWindow(hWnd, SW_SHOW);	  // Show The Window
	SetForegroundWindow(hWnd);	  // Slightly Higher Priority
	SetFocus(hWnd);				  // Sets Keyboard Focus To The Window
	ReSizeGLScene(width, height); // Set Up Our Perspective GL Screen

	if (!InitGL()) // Initialize Our Newly Created GL Window
	{
		KillGLWindow(); // Reset The Display
		MessageBox(NULL, "Initialization Failed.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE; // Return FALSE
	}

	return TRUE; // Success
}

LRESULT CALLBACK WndProc(HWND hWnd,		// Handle For This Window
						 UINT uMsg,		// Message For This Window
						 WPARAM wParam, // Additional Message Information
						 LPARAM lParam) // Additional Message Information
{
	switch (uMsg) // Check For Windows Messages
	{
	case WM_ACTIVATE: // Watch For Window Activate Message
	{
		if (!HIWORD(wParam)) // Check Minimization State
		{
			active = TRUE; // Program Is Active
		}
		else
		{
			active = FALSE; // Program Is No Longer Active
		}

		return 0; // Return To The Message Loop
	}

	case WM_SYSCOMMAND: // Intercept System Commands
	{
		switch (wParam) // Check System Calls
		{
		case SC_SCREENSAVE:	  // Screensaver Trying To Start?
		case SC_MONITORPOWER: // Monitor Trying To Enter Powersave?
			return 0;		  // Prevent From Happening
		}
		break; // Exit
	}

	case WM_CLOSE: // Did We Receive A Close Message?
	{
		PostQuitMessage(0); // Send A Quit Message
		return 0;			// Jump Back
	}

	case WM_KEYDOWN: // Is A Key Being Held Down?
	{
		keys[wParam] = TRUE; // If So, Mark It As TRUE
		return 0;			 // Jump Back
	}

	case WM_KEYUP: // Has A Key Been Released?
	{
		keys[wParam] = FALSE; // If So, Mark It As FALSE
		return 0;			  // Jump Back
	}

	case WM_SIZE: // Resize The OpenGL Window
	{
		ReSizeGLScene(LOWORD(lParam), HIWORD(lParam)); // LoWord=Width, HiWord=Height
		return 0;									   // Jump Back
	}
	case WM_MOUSEMOVE:
	{
		mouseX = (int)LOWORD(lParam);
		mouseY = (int)HIWORD(lParam);
		isClicked = (LOWORD(wParam) & MK_LBUTTON) ? true : false;
		isRClicked = (LOWORD(wParam) & MK_RBUTTON) ? true : false;
		break;
	}
	case WM_LBUTTONUP:
		isClicked = false;
		break;
	case WM_RBUTTONUP:
		isRClicked = false;
		break;
	case WM_LBUTTONDOWN:
		isClicked = true;
		break;
	case WM_RBUTTONDOWN:
		isRClicked = true;
		break;
	}

	// Pass All Unhandled Messages To DefWindowProc
	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}

int WINAPI WinMain(HINSTANCE hInstance,		// Instance
				   HINSTANCE hPrevInstance, // Previous Instance
				   LPSTR lpCmdLine,			// Command Line Parameters
				   int nCmdShow)			// Window Show State
{
	MSG msg;		   // Windows Message Structure
	BOOL done = FALSE; // Bool Variable To Exit Loop

	// Ask The User Which Screen Mode They Prefer
	// if (MessageBox(NULL,"Would You Like To Run In Fullscreen Mode?", "Start FullScreen?",MB_YESNO|MB_ICONQUESTION)==IDNO)
	{
		fullscreen = FALSE; // Windowed Mode
	}

	// Create Our OpenGL Window
	if (!CreateGLWindow("Example", 640, 480, 16, fullscreen))
	{
		return 0; // Quit If Window Was Not Created
	}

	while (!done) // Loop That Runs While done=FALSE
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) // Is There A Message Waiting?
		{
			if (msg.message == WM_QUIT) // Have We Received A Quit Message?
			{
				done = TRUE; // If So done=TRUE
			}
			else // If Not, Deal With Window Messages
			{
				TranslateMessage(&msg); // Translate The Message
				DispatchMessage(&msg);	// Dispatch The Message
			}
		}
		else // If There Are No Messages
		{
			// Draw The Scene.  Watch For ESC Key And Quit Messages From DrawGLScene()
			if (active) // Program Active?
			{
				if (keys[VK_ESCAPE]) // Was ESC Pressed?
				{
					done = TRUE; // ESC Signalled A Quit
				}
				else // Not Time To Quit, Update Screen
				{
					DrawGLScene();	  // Draw The Scene
					SwapBuffers(hDC); // Swap Buffers (Double Buffering)
				}
			}

			if (keys[VK_F1]) // Is F1 Being Pressed?
			{
				keys[VK_F1] = FALSE;	  // If So Make Key FALSE
				KillGLWindow();			  // Kill Our Current Window
				fullscreen = !fullscreen; // Toggle Fullscreen / Windowed Mode
				// Recreate Our OpenGL Window
				if (!CreateGLWindow("OpenGL template", 640, 480, 16, fullscreen))
				{
					return 0; // Quit If Window Was Not Created
				}
			}
		}
	}

	// Shutdown
	KillGLWindow();		 // Kill The Window
	return (msg.wParam); // Exit The Program
}
