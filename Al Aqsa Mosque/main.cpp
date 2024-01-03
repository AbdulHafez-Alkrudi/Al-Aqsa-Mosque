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
#include "school.h"
#include "Pillar.h"
#include "museum.h"
#include "qibaliMosque.h"
#include "vendor/model/Model_3DS.h"
#include "OutSide.h"
#include "minaret.h"

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
int ground, wall, grass;
int texture_wall, texture_door, CylinderBody,wall2,wall4,grass1,wooden_door,stone4,street1,wall1,wall0, green_door,street,window,logo;
int ball, skybox, top, wall3, upwall, bottomwall,land, carpet_aqsa, blocks,alporaq,wall6;
around *a;
OutSide* Out;
OutSide* Street;
museum* m;
House* h;
school* sch;
Pillar* p;
DrawWall* dw;
DomeOfTheRock* dome;
qibaliMosquee* mosque;
Camera MyCamera;
Model_3DS *tree;
primitives* pri;
Minaret mina2(30, 100);


int house_door, house_window, house_wall, wallofmosque;
int house_roof[4];
int texture[6];
int image, image2, marble;
int SKYFRONT, SKYBACK, SKYLEFT, SKYRIGHT, SKYUP, SKYDOWN;
GLTexture Bark, Leaf;
int qibaliMosque;
int mosquewindow;
int carpet;
int mosqueRoof, mosqueRoof2;
int mosaic;
int arch;
int mosquewindow2;


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
	gluPerspective(45.0f, (GLfloat)width / (GLfloat)height, 0.1f, 8000.0f);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
void Draw_Skybox(float x, float y, float z, float width, float height, float length)
{
	// Center the Skybox around the given x,y,z position
	x = x - width / 2;
	y = y - height / 2;
	z = z - length / 2;
	glEnable(GL_TEXTURE_2D);

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
}

int InitGL(GLvoid)
{

	glShadeModel(GL_SMOOTH);
	glClearColor(0.0f, 0.0f, 0.0f, 0.5f);
	glClearDepth(1.0f);
	glEnable(GL_TEXTURE_2D); // Depth Buffer Setup
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	tree = new Model_3DS();
	marble			 = LoadTexture("images/walls/marble.bmp" , 255);
	street			 = LoadTexture("images/walls/street1.bmp" , 255);
	street1			 = LoadTexture("images/walls/street.bmp" , 255);
	stone4			 = LoadTexture("images/walls/stone4.bmp" , 255);
	window      	 = LoadTexture("images//House/window2.bmp",3);
	logo			 = LoadTexture("images/House/school_logo.bmp",255);
	wall2			 =  LoadTexture("images/walls/wall2.bmp" , 255);
	wall6			 =  LoadTexture("images/walls/wall6.bmp" , 255);
	ball			 = LoadTexture("images/mosque/ball.bmp", 255);
	wooden_door		 = LoadTexture("images/House/wooden_door.bmp",255);
	CylinderBody			 = LoadTexture("images/mosque/CylinderBody.bmp", 255);
	wall3			 = LoadTexture("images/wall3.bmp",255);
	//texture_door = LoadTexture("images/door.bmp", 255);
	land			 = LoadTexture("images/walls/land.bmp",255);
	blocks			 = LoadTexture("images/walls/blocks.bmp",255);
	wall0			 = LoadTexture("images/walls/old_wall.bmp",255);
	grass1			 = LoadTexture("images/walls/grass1.bmp", 255);
	wall1			 = LoadTexture("images/walls/wall1.bmp",255);
	wall4			 = LoadTexture("images/walls/wall4.bmp",255);
	SKYFRONT		 = LoadTexture("images/skybox/front.bmp", 255);
	green_door	 = LoadTexture("images//House/green_door.bmp",255);
	qibaliMosque     = LoadTexture("images/mosque/wall1.bmp", 255);
	carpet_aqsa          =LoadTexture("images/mosque/carpet.bmp", 255);
	upwall = LoadTexture("images/mosque/up_wall.bmp", 255);
	alporaq = LoadTexture("images/mosque/alporaq.bmp", 255);
	bottomwall = LoadTexture("images/mosque/bottom_wall.bmp", 255);
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
void partofStrais(){
	glBindTexture(GL_TEXTURE_2D,wall2);
			glBegin(GL_TRIANGLE_STRIP);
			glTexCoord2f(0,0);
			glVertex3d(0,0,0);

			glTexCoord2f(1,0);
			glVertex3d(100,0,0);

			glTexCoord2f(1,1);
			glVertex3d(85,40,0);

			glTexCoord2f(0,1);
			glVertex3d(100,40,0);
			glEnd();
}
void hallway()
{
	glPushMatrix();
	glTranslated(1650, 0, 250);
	mina2.draw_minaret(Point(70, 70, 60), wall6, wall6, wall6, wall6);
	h->DrawHousewithoutDomeoneWindow(Point(0, 0, 0), 100, 100, 0, 70, green_door, wall, house_window);
	pri->DrawBall(40, wall, Point(0, 57, 50));
	glTranslated(-100, 0, 0);
	h->DrawHousewithoutDome(Point(0, 0, 0), 100, 100, 0, 70, wall, wall, house_window);

	glPushMatrix();
	glTranslated(-560, 62, 0);
	primitives::DrawCupe(Point(0, 0, 0), 560, 8, 100, wall6);
	mina2.draw_minaret(Point(0, 0, 0), wall6, wall6, wall6, wall6);
	glPopMatrix();

	glTranslated(0, 0, 90);
	for (int i = 1; i <= 10; i++)
	{
		glTranslated(-56, 0, 0);
		p->cube_cylinder_pillar(Point(0, 0, 0), wall6, wall6);
	}

	glPopMatrix();
}
void drawstreet()
{
	DomeOfTheRock* d = new DomeOfTheRock();
	glPushMatrix();
	glTranslated(100, 0, 100);
	// Left
	glTranslated(0, 1, 1600);
	d->drawGround(Point(0, 0, 0), 1750, 1, 150, street1);
	// Front
	glTranslated(1600, 0, 100);
	glRotated(90, 0, 10, 0);
	glTranslated(-100, 0, 0);
	d->drawGround(Point(0, 0, 0), 1750, 1, 150, street1);
	// Right 
	glTranslated(1600, 0, 100);
	glRotated(90, 0, 10, 0);
	glTranslated(-100, 0, 0);
	d->drawGround(Point(0, 0, 0), 1750, 1, 150, street1);
	// Back
	glRotated(90, 0, 10, 0);
	glTranslated(-200, 0, 1650);
	d->drawGround(Point(0, 0, 0), 1800, 1, 150, street1);
	glPopMatrix();
}
void drawHouse()
{
	glPushMatrix();
	glTranslated(100, 0, 0);
	for (int i = 1; i <= 17; i++) 
	{
		if (i & 1) {
			h->DrawHousewithoutDome(Point(0, 0, 0), 100, 100, 0, 70, house_door, wall, house_window);
			glPushMatrix();
			glTranslated(0, 70, 0);
			h->DrawHousewithoutDome(Point(0, 0, 0), 100, 100, 0, 70, wall, wall, house_window);
			glPopMatrix();
		}
		else {
			h->DrawHousewithoutDome(Point(0, 0, 0), 100, 100, 0, 70, house_door, wall, house_window);
		}
		glTranslated(106.25, 0, 0);
	}
	glPopMatrix();

	glPushMatrix();
	glTranslated(0, 0, 100);
	glRotated(90, 0, 10, 0);
	glTranslated(-100, 0, 0);
	for (int i = 1; i <= 17; i++) 
	{
		if (i & 1) {
			h->DrawHousewithoutDome(Point(0, 0, 0), 100, 100, 0, 70, house_door, wall, house_window);
			glPushMatrix();
			glTranslated(0, 70, 0);
			h->DrawHousewithoutDome(Point(0, 0, 0), 100, 100, 0, 70, wall, wall, house_window);
			glPopMatrix();
		}
		else {
			h->DrawHousewithoutDome(Point(0, 0, 0), 100, 100, 0, 70, house_door, wall, house_window);
		}
		glTranslated(-106.25, 0, 0);
	}
	glPopMatrix();

	glPushMatrix();
	glTranslated(200, 0, 2000);
	glRotated(180, 0, 10, 0);
	for (int i = 1; i <= 17; i++)
	{
		if (i & 1) {
			h->DrawHousewithoutDome(Point(0, 0, 0), 100, 100, 0, 70, house_door, wall, house_window);
			glPushMatrix();
			glTranslated(0, 70, 0);
			h->DrawHousewithoutDome(Point(0, 0, 0), 100, 100, 0, 70, wall, wall, house_window);
			glPopMatrix();
		}
		else {
			h->DrawHousewithoutDome(Point(0, 0, 0), 100, 100, 0, 70, house_door, wall, house_window);
		}
		glTranslated(-106.25, 0, 0);
	}
	glPopMatrix();

	glPushMatrix();
	glTranslated(2000, 0, 100);
	glRotated(-90, 0, 10, 0);
	h->DrawHousewithoutDome(Point(0, 0, 0), 100, 100, 0, 70, house_door, wall, house_window);
	for (int i = 1; i <= 17; i++)
	{
		if (i & 1) {
			h->DrawHousewithoutDome(Point(0, 0, 0), 100, 100, 0, 70, house_door, wall, house_window);
			glPushMatrix();
			glTranslated(0, 70, 0);
			h->DrawHousewithoutDome(Point(0, 0, 0), 100, 100, 0, 70, wall, wall, house_window);
			glPopMatrix();
		}
		else {
			h->DrawHousewithoutDome(Point(0, 0, 0), 100, 100, 0, 70, house_door, wall, house_window);
		}
		glTranslated(106.25, 0, 0);
	}
	glPopMatrix();
}
void drawschool(){
	sch=new school();
	sch->drawGround(Point(0,0,0),300,2,300,wall4);
	sch->drawWall(Point(0,0,0),30,1,300,wall,wooden_door);
	sch->DrawHousewithoutDome(Point(1,0,1),100,70,0,80,green_door,wall2,window);
	sch->DrawHousewithoutDome(Point(101,0,1),100,70,0,80,wall2,wall2,window);
	glPushMatrix();
	glRotated(-180,0,10,0);
	glTranslated(-310,0,-70);
	sch->DrawHousewithoutDomeoneWindow(Point(50,80,1),100,70,0,80,wall2,wall2,window);
	sch->DrawHousewithoutDomeoneWindow(Point(150,80,1),100,70,0,80,wall2,wall2,window);
	glPopMatrix();
	sch->DrawHousewithoutDome(Point(201,0,1),100,70,0,80,wall2,wall2,window);
	glPushMatrix();
	glTranslated(147,130,70);
	glBindTexture(GL_TEXTURE_2D,logo);
			glBegin(GL_QUADS);
			glTexCoord2f(0,0);
			glVertex3d(0,0,0);

			glTexCoord2f(1,0);
			glVertex3d(50,0,0);

			glTexCoord2f(1,1);
			glVertex3d(50,30,0);

			glTexCoord2f(0,1);
			glVertex3d(0,30,0);
			glEnd();
	glPopMatrix();	
	glPushMatrix();
	glTranslated(0, -20, 100);
	primitives::DrawCupe(Point(0, 80, -50), 300, 8, 90, wall2);
	glPopMatrix();
	glTranslated(300, 0, 120);
	for (int i = 1; i <= 5; i++)
	{
		glTranslated(-56, 0, 0);
		p->cube_cylinder_pillar(Point(0, 0, 0), wall1, wall1);
	}
		
}
void drawdomeoftherock()
{
	glPushMatrix();
	glTranslated(850, 0, 700);
	dome->drawGround(Point(0, 0, 0), 800, 2, 700, grass);
	glTranslated(100, 0, 0);
	dome->drawWall(Point(0, 0, 0), 40, 2, 600, wall2);
	glTranslated(0, 40, 100);
	dome->drawGround(Point(0, 0, 0), 600, 2, 500, wall2);
	glPushMatrix();
	glTranslated(200, 0, 300);
		  glPushMatrix();                                             //استدعاءالارضية 
		  glTranslated(35, 0, -84.0);
		  glRotated(22.5, 0, 1, 0);
		  glRotated(90, 1, 0, 0);
		  dome->Floor_Roof(carpet_aqsa);
		  glPopMatrix();
	dome->DrawOctagon(70, 40, bottomwall, Point (0, 0, 0));          // 
	glTranslated(0, 40, 0);
	dome->drawOctagon(70, 40, upwall, Point (0, 0, 0));              //
		  glPushMatrix();                                           //استدعاءالسقفية 
		  glTranslated(35, 40, -84.0);
		  glRotated(90, 1, 0, 0);
		  glRotated(22.5, 0,0, 1);
		  dome->Floor_Roof(marble);
		  glPopMatrix();
	glTranslated(38, 40.1, -83);
	primitives::DrawCylinderBody(Point(0, 0, 0), 36, 36, 10, CylinderBody);  
	glTranslated(0, 7.5, 0);
	dome->DrawBall(36, ball, Point(0, 0, 0));
	glPopMatrix();
	//front 
		    glPushMatrix();
		    glTranslated(200, 0, -200);	
			glPushMatrix();
			 glTranslated(-100, -40, 0);
			glPushMatrix();
			glRotated(-90,0,10,0);
			partofStrais();
			 glPopMatrix();
			  glPushMatrix();
			glRotated(-90,0,10,0);
			glTranslated(0, 0, -60);
			partofStrais();
			  glPopMatrix();
			dome->DrawStrais(wall2);
			glPopMatrix();
			
			glPushMatrix();
			 glTranslated(80, -40, 0);
			glPushMatrix();
			glRotated(-90,0,10,0);
			partofStrais();
			 glPopMatrix();
			  glPushMatrix();
			glRotated(-90,0,10,0);
			glTranslated(0, 0, -60);
			partofStrais();
			  glPopMatrix();
			dome->DrawStrais(wall2);
			glPopMatrix();

			glPushMatrix();
			 glTranslated(240, -40, 0);
			glPushMatrix();
			glRotated(-90,0,10,0);
			partofStrais();
			 glPopMatrix();
			  glPushMatrix();
			glRotated(-90,0,10,0);
			glTranslated(0, 0, -60);
			partofStrais();
			  glPopMatrix();
			dome->DrawStrais(wall2);
			glPopMatrix();
			glPopMatrix();



	//left 
			glPushMatrix();
		    glTranslated(600, -40, 380);
			glPushMatrix();
			glRotated(-90,0,10,0);
			glPushMatrix();
			glRotated(-90,0,10,0);
			partofStrais();
			glPopMatrix();
			glPushMatrix();
			glRotated(-90,0,10,0);
			glTranslated(0, 0, -60);
			partofStrais();
			glPopMatrix();
			dome->DrawStrais(wall2);
			glPopMatrix();
			glPopMatrix();

			glPushMatrix();
		    glTranslated(600, -40, 200);
			glPushMatrix();
			glRotated(-90,0,10,0);
			glPushMatrix();
			glRotated(-90,0,10,0);
			partofStrais();
			glPopMatrix();
			glPushMatrix();
			glRotated(-90,0,10,0);
			glTranslated(0, 0, -60);
			partofStrais();
			glPopMatrix();
			dome->DrawStrais(wall2);
			glPopMatrix();
			glPopMatrix();


	//back 
			glPushMatrix();
		    glTranslated(200, -40, 600);
			glPushMatrix();
			glRotated(-180,0,10,0);
			glPushMatrix();
			glRotated(-90,0,10,0);
			partofStrais();
			glPopMatrix();
			glPushMatrix();
			glRotated(-90,0,10,0);
			glTranslated(0, 0, -60);
			partofStrais();
			glPopMatrix();
			dome->DrawStrais(wall2);
			glPopMatrix();
			glPopMatrix();
			

	//right 
			glPushMatrix();
		    glTranslated(-100, -40, 460);
			glPushMatrix();
			glRotated(90,0,10,0);
			glPushMatrix();
			glRotated(-90,0,10,0);
			partofStrais();
			glPopMatrix();
			glPushMatrix();
			glRotated(-90,0,10,0);
			glTranslated(0, 0, -60);
			partofStrais();
			glPopMatrix();
			dome->DrawStrais(wall2);
			glPopMatrix();
			glPopMatrix();

			glPushMatrix();
		    glTranslated(-100, -40, 300);
			glPushMatrix();
			glRotated(90,0,10,0);
			glPushMatrix();
			glRotated(-90,0,10,0);
			partofStrais();
			glPopMatrix();
			glPushMatrix();
			glRotated(-90,0,10,0);
			glTranslated(0, 0, -60);
			partofStrais();
			glPopMatrix();
			dome->DrawStrais(wall2);
			glPopMatrix();
			glPopMatrix();

			
			glPushMatrix();
			glTranslated(370, 0, 0);
	        h->DrawHousewithDome(Point(0,0,0),80,50,0,50,green_door,wall2,window,wall2); 
		    glPopMatrix();

	     	glPushMatrix();
			glTranslated(220, -40, -140);
			glRotated(-90, 0, 1, 0);
	        h->DrawHousewithoutDomeoneWindow(Point(0,0,0),40,40,30,40,green_door,wall2,window); 
			glTranslated(0, 40, 0);
			h->DrawHousewithDomeonewindow(Point(0,0,0),40,40,0,40,wall2,wall2,window,wall2); 
			glPopMatrix();

			glPushMatrix();
			glTranslated(280, -40, -100);
			glRotated(-180, 0, 1, 0);
	        h->DrawHousewithoutDome(Point(0,0,0),60,40,30,40,green_door,wall2,window); 
			glTranslated(0, 40, 0);
			h->DrawHousewithDome(Point(0,0,0),60,40,0,40,wall2,wall2,window,wall2); 
			glPopMatrix();

			glPushMatrix();
			glTranslated(0, -40, -100);
			glRotated(-90, 0, 1, 0);
	        h->DrawHousewithoutDome(Point(0,0,0),100,40,30,40,green_door,wall2,window); 
			glTranslated(0, 40, 0);
			h->DrawHousewithDome(Point(0,0,0),100,40,0,40,wall2,wall2,window,wall2); 
			glPushMatrix();
			glTranslated(0, -40, -50);
			glRotated(-90, 0, 1, 0);
	        h->DrawHousewithoutDomeoneWindow(Point(0,0,0),90,40,30,40,wall2,wall2,window); 
			glTranslated(0, 40, 0);
			h->DrawHousewithoutDomeoneWindow(Point(0,0,0),90,40,0,40,wall2,wall2,window); 
			glPopMatrix();
			glPopMatrix();

			
	     	glPushMatrix();
			glTranslated(300, -40, 500);
			glRotated(-90, 0, 1, 0);
	        h->DrawHousewithoutDomeoneWindow(Point(0,0,0),40,40,30,40,green_door,wall2,window); 
			glTranslated(0, 40, 0);
			h->DrawHousewithDomeonewindow(Point(0,0,0),40,40,0,40,wall2,wall2,window,wall2); 
			glPopMatrix();
		         
			glPushMatrix();
			glTranslated(340, -40, 500);
			glRotated(-90, 0, 1, 0);
	        h->DrawHousewithoutDomeoneWindow(Point(0,0,0),40,40,0,35,green_door,wall2,window); 
			glTranslated(0, 35, 0);
			h->DrawHousewithDomeonewindow(Point(0,0,0),40,40,0,35,wall2,wall2,window,wall2);
			glPopMatrix();

			glPushMatrix();
			glTranslated(500, -40, 100);
			glRotated(90, 0, 1, 0);
	        h->DrawHousewithoutDome(Point(0,0,0),70,40,30,40,green_door,wall2,window); 
			glTranslated(0, 40, 0);
			h->DrawHousewithDome(Point(0,0,0),70,40,0,40,wall2,wall2,window,wall2); 
			glPopMatrix();

			glPushMatrix();
			glTranslated(500, -40, 160);
			glRotated(90, 0, 1, 0);
	        h->DrawHousewithoutDomeoneWindow(Point(0,0,0),60,40,0,40,wall2,wall2,window); 
			glTranslated(0, 40, 0);
			h->DrawHousewithDome(Point(0,0,0),60,40,0,40,wall2,wall2,window,wall2);
			glPopMatrix();

			glPushMatrix();
			glTranslated(500, -40, 320);
			glRotated(90, 0, 1, 0);
	        h->DrawHousewithoutDomeoneWindow(Point(0,0,0),50,40,30,40,green_door,wall2,window); 
			glTranslated(0, 40, 0);
			h->DrawHousewithDome(Point(0,0,0),50,40,0,40,wall2,wall2,window,wall2); 
			glPopMatrix();

			glPushMatrix();
			glTranslated(500, -40, 370);
			glRotated(90, 0, 1, 0);
	        h->DrawHousewithoutDomeoneWindow(Point(0,0,0),50,40,0,40,wall2,wall2,window); 
			glTranslated(0,  40, 0);
			h->DrawHousewithDome(Point(0,0,0),50,40,0,40,wall2,wall2,window,wall2); 
			glPopMatrix();

			glPushMatrix();
			glTranslated(500, -40, 500);
			glRotated(90, 0, 1, 0);
	        h->DrawHousewithoutDomeoneWindow(Point(0,0,0),50,40,30,40,green_door,wall2,window); 
			glTranslated(0, 40, 0);
			h->DrawHousewithDome(Point(0,0,0),50,40,0,40,wall2,wall2,window,wall2); 
			glPopMatrix();

			glPushMatrix();
			glTranslated(500, -40, 30);
			glRotated(90, 0, 1, 0);
	        h->DrawHousewithoutDomeoneWindow(Point(0,0,0),35,40,30,40,green_door,wall2,window); 
			glTranslated(0, 40, 0);
			h->DrawHousewithDome(Point(0,0,0),35,40,0,40,wall2,wall2,window,wall2); 
			glPopMatrix();

			glPushMatrix();
			glTranslated(500, -40, 10);
			glRotated(90, 0, 1, 0);
	        h->DrawHousewithoutDomeoneWindow(Point(0,0,0),50,40,30,40,green_door,wall2,window); 
			glTranslated(0, 40, 0);
			h->DrawHousewithoutDomeoneWindow(Point(0,0,0),50,40,0,40,wall2,wall2,window); 
			glPopMatrix();


			glPopMatrix();
}
void drawMuseum(){
	m=new museum();
	mina2.draw_minaret(Point(-30, 70, 100), qibaliMosque, qibaliMosque, qibaliMosque, qibaliMosque);
	sch->drawGround(Point(0,0,0),250,1,250,wall4);
	m->drawWall(Point(0,0,0),40,1,250,wall2,wooden_door);
	sch->DrawHousewithoutDome(Point(1,0,1),125,100,0,100,house_door,wall1,window);
	sch->DrawHousewithDome(Point(127,0,1),125,100,0,100,wall1,wall1,window,wall1);
	glPushMatrix();
	glTranslated(-10, -18, 150);
	primitives::DrawCupe(Point(0, 80, -50), 250, 8, 80, wall1);
	glPopMatrix();
	glTranslated(290, 0, 150);
	for (int i = 1; i <= 5; i++)
	{
		glTranslated(-56, 0, 0);
		p->cube_cylinder_pillar(Point(0, 0, 0), wall1, wall1);
	}
}

GLfloat lightColor0[] = { 0.2f, 1.0f, 0.7f, 1.0f }; //Color (0.5, 0.5, 0.5)
GLfloat lightPos0[] = { 4.0f, 6.0f, 8.0f, 1.0f }; //Positioned at (4, 0, 8)
GLfloat ambientColor[] = { 0.9f, 0.2f, 0.2f, 1.0f }; //Color (0.2, 0.2, 0.2)
bool check = false;

int DrawGLScene(GLvoid) // Here's Where We Do All The Drawing
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	   if(keys['T'])
  {
    check=true;
  }
  if(keys['R'])
  {
    check=false;
  }

  glTranslatef(0.0f, 0.0f, -8.0f);

  //Add ambient light
  glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientColor);

  //Add positioned light
  glLightfv(GL_LIGHT0, GL_DIFFUSE, lightColor0);
  glLightfv(GL_LIGHT0, GL_POSITION, lightPos0);
  
  if(check)
  {
  glEnable(GL_LIGHTING);
  }

  else
  {
  glDisable(GL_LIGHTING);
  }

	MyCamera.Render();
	Key(keys, 10);

	tree->pos.x = 10 ;
	tree->pos.y = 0  ;
	tree->pos.z = 0  ;
	Draw_Skybox(0, 0, 0, 4000, 4000, 4000);
	glTranslated(-600, 0, -800);
	
	Out = new OutSide();
	Street = new OutSide();
	h = new House();
	dw = new DrawWall();
	p = new Pillar(10, 46);
	dome = new DomeOfTheRock();
	pri=new primitives();	 
	Out->drawGround(Point(0, 0, 0), 2000, 1, 2000, land);

	glPushMatrix();
	glTranslated(250, 0, 250);
	Out->drawWall(Point(0, 0, 0), 70, 5, 1500, wall, house_door, keys);
	/*glPushMatrix();
	glScaled(10, 10, 10);
	glTranslated(0, 50, 1000);
	tree->Draw();
	glPopMatrix();*/
	glPopMatrix();

	drawstreet();
	drawHouse();
	hallway();

	//alporaq mosque 
	glPushMatrix();
	glTranslated(670, 0, 250);
	primitives::DrawCupe(Point(0, 0, 0), 250, 70, 100, qibaliMosque);
	glPushMatrix();
	glTranslated(-250, -230, 0);
	for(int i=0;i<6;i++)
	{
		pri->DrawQuad5(Point(250,200,100),Point(300,200,100),Point(300,300,100),Point(250,300,100),mosquewindow,0,0);
		glTranslated(40, 0, 0);
	}
	glPopMatrix();
	glPopMatrix();

	drawdomeoftherock();

	glPushMatrix();
	glTranslated(350, 0, 250);
	drawMuseum();
	glPushMatrix();
	glScaled(6, 6, 6);
	glTranslated(-8, 0, 8);
	tree->Draw();
	glPopMatrix();
	glPopMatrix();
	
	//women's mosque
	glPushMatrix();
	glTranslated(250, 0, 650);
	glRotated(90, 0, 1, 0);
	primitives::DrawCupe(Point(0, 0, 0), 400, 70, 100, qibaliMosque);
	glPushMatrix();
	glTranslated(-230, -230, 0);
	for(int i=0;i<9;i++)
	{
		pri->DrawQuad5(Point(250,200,100),Point(300,200,100),Point(300,300,100),Point(250,300,100),mosquewindow,0,0);
		glTranslated(40, 0, 0);
	}
	glPopMatrix();
	glPopMatrix();


	glPushMatrix();
	glTranslated(-150, -25, 1298);
	glRotated(90, 0, 10, 0);
	glScaled(2,2,2);
	mosque->drawQibaliMosque(150, 5, 35, mosquewindow, qibaliMosque, mosqueRoof2,
							 mosquewindow2, mosqueRoof, mosaic, marble, house_wall, arch, carpet);
	glPopMatrix();



	mina2.draw_minaret(Point(1750, 70, 1500), qibaliMosque, qibaliMosque, qibaliMosque, qibaliMosque);

	 //ro->Floor_Roof(marble);

	//p.DrawQuad(Point(140,25,143),Point(151.5,25,143),Point(151.5,25,156.5),Point(140,25,156.5),marble);
	//  ro->DrawBall(5,ball,Point (146,24.7,150));
	////p.DrawCircle(-5,20,5,100);
	//	p.DrawQuad(Point(0,20,4),Point(11.5,20,4),Point(11.5,20,16.5),Point(0,20,15.5),marble);
	//  ro->DrawBall(5,ball,Point (6,19.7,10));
	//glTranslated(100, 0, 100);
	//glPushMatrix();
	//	primitives::DrawRing(Point(10,10,10),100,100,wall);
	//		glTranslated(400, 0, -80);
	//		glPushMatrix();
	//		glRotated(-90,0,10,0);
	//		glBindTexture(GL_TEXTURE_2D,wall);
	//		glBegin(GL_TRIANGLE_STRIP);
	//		//glColor3b(1,1,1);
	//		glTexCoord2f(0,0);
	//		glVertex3d(0,0,0);

	//		glTexCoord2f(1,0);
	//		glVertex3d(80,0,0);

	//		glTexCoord2f(1,1);
	//		glVertex3d(60,12,0);

	//		glTexCoord2f(0,1);
	//		glVertex3d(80,12,0);
	//		glEnd();
	//		  glPopMatrix();
	//		  glPushMatrix();
	//		glRotated(-90,0,10,0);
	//		glTranslated(0, 0, -50);
	//		glBindTexture(GL_TEXTURE_2D,wall);
	//		glBegin(GL_TRIANGLE_STRIP);
	//		//glColor3b(1,1,1);
	//		glTexCoord2f(0,0);
	//		glVertex3d(0,0,0);

	//		glTexCoord2f(1,0);
	//		glVertex3d(80,0,0);

	//		glTexCoord2f(1,1);
	//		glVertex3d(60,12,0);

	//		glTexCoord2f(0,1);
	//		glVertex3d(80,12,0);
	//		glEnd();
	//		  glPopMatrix();
	//		ro->DrawStrais(50,house_wall);glPushMatrix();
	//		glPushMatrix();glTranslated(-10, -11,-10);
	//		glRotated(-180, 0, 1, 0);
	//	h->DrawHousewithoutDome(Point(0,0,0),100,40,40,40,house_door,wall,house_window);
	//		glPopMatrix();
	//		glPushMatrix();glTranslated(160, -11,-10);
	//		glRotated(-180, 0, 1, 0);
	//	h->DrawHousewithoutDome(Point(0,0,0),100,40,40,40,house_door,wall,house_window);
	//		glPopMatrix();
	//		glTranslated(60, 25,-50);
	//	h->DrawHousewithDomeNOdoor(Point(0,0,0),100,40,40,40,wall,house_window,wall);
	//		 glPopMatrix();
	//		  glPopMatrix();
	//		d->drawWall(Point(1, 1, 1),11,1,800,wall);
	//			glPushMatrix();
	//			glTranslated(0, 10, 0);
	//		d->drawGround(Point (1, 1, 1),10,1,800,ground);
	//	  glPushMatrix();
	//	  glPushMatrix();
	//	  glTranslated(600, 0, 50); ////////////////////////////////
	//	  h->DrawHousewithDome(Point(0,0,0),100,40,40,40,house_door,wall,house_window,wall);
	//	  glPopMatrix();                       //��������������
	//	  glTranslated(400, 0, 500);
	//	  ro->DrawOctagon(60, 30, bottomwall, Point (0, 0, 0));
	//	 glPushMatrix();glTranslated(0, 30, 0);   ro->DrawOctagon(60, 50, upwall, Point (0, 0, 0));
	//	  glPopMatrix();
	//	 //�������������
	//	  glPushMatrix();                                             //��������������
	//	  glTranslated(30, 0, -72.6);
	//	  glRotated(22.5, 0, 1, 0);
	//	  glRotated(90, 1, 0, 0);
	//	  ro->Floor_Roof(marble);
	//	  glPopMatrix();

	//	  glPushMatrix();
	//	  glTranslated(30, 80, -72.6);
	//	  glRotated(90, 1, 0, 0);
	//	  glRotated(22.5, 0,0, 1);
	//	  ro->Floor_Roof(marble);
	//	  glPopMatrix();
	//	   glPushMatrix();
	//	   glTranslated(30, 83, -74);
	//	   glPushMatrix();
	//		glTranslated(0, -10, 0);
	//	   primitives::DrawCylinderBody(Point(0,0,0),48,48,20,CylinderBody);
	//	   glPopMatrix();
	//	   ro->DrawBall(50,ball,Point (0,0,0));
	//	   glPopMatrix();
	//	   glPopMatrix();
	//	   glPushMatrix();
	//	   glPopMatrix();
	//	glPopMatrix();
	// glPopMatrix();

	//Pillar pillar ;
	//pillar.cube_cylinder_pillar(Point(0,0,0),4,marble,10,-1);

	//for(float i = -100 ; i <= 100 ; i+=0.1){
	//	glBegin(GL_POINTS);
	//		glVertex3d(i , 0 , 0);
	//		glVertex3d(0 , i , 0);
	//	glEnd();
	//}
	////primitives::Draw3DHexagon(Point(0,0,-100),40,100,marble);
	//tree->pos.x=0;
	//tree->pos.y=0;
	//tree->pos.z=0;
	//tree->scale=2;
	//tree->Draw();



	

	

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
