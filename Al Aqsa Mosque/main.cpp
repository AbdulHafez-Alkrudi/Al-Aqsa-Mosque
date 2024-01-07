#pragma once
#include <windows.h> // Header File For Windows
#include <gl.h>		 // Header File For The OpenGL32 Library
#include <glu.h>	 // Header File For The GLu32 Library
#include <glaux.h>
#include <iostream>
#include <string>
#include <sstream>
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
#include "LeftFace.h"
#include "Camera.h"
#include "school.h"
#include "Pillar.h"
#include "museum.h"
#include "minaret.h"
#include "qibaliMosque.h"
#include "Cylinder.h"
#include "vendor/model/Model_3DS.h"
#include "Marwani.h"
#include "Door.h"
#include "OutSide.h"
#include "minaret.h"

#define unbind glBindTexture(GL_TEXTURE_2D, 0);
// Stolen From: Yassien
#define txt(s, t) glTexCoord2d(s, t)
#define white glColor3f(1, 1, 1)
#define db double
#define cull glEnable(GL_CULL_FACE)
#define nocull glDisable(GL_CULL_FACE)
#define frontf glCullFace(GL_FRONT)
#define backf glCullFace(GL_BACK)
#define pshm glPushMatrix()
#define ppm glPopMatrix()

// const db srt = 1.414213562373095;
// const db pi = 3.1415926535897932384626433832795028;

bool isClicked = 0, isRClicked = 0;
int mouseX = 0, mouseY = 0;

HDC hDC = NULL;		 // Private GDI Device Context
HGLRC hRC = NULL;	 // Permanent Rendering Cntext
HWND hWnd = NULL;	 // Holds Our Window Handle
HINSTANCE hInstance; // Holds The Instance Of The Application

bool keys[256];			 // Array Used For The Keyboard Routine
bool active = TRUE;		 // Window Active Flag Set To TRUE By Default
bool fullscreen = FALSE; // Fullscreen Flag Set To Fullscreen Mode By Default
int ground, wall, grass;
int texture_wall, texture_door, CylinderBody, wall2, wall4, grass1, wooden_door, stone4, street1, wall1, wall0, green_door, street, window, logo;
int ball, skybox, top, wall3, upwall, bottomwall, land, carpet_aqsa, blocks, alporaq;

int outsideDoors;

Point bottom_left_back;
around *a;
OutSide *Out;
OutSide *Street;
museum *m;
House *h;
school *sch;
DrawWall *dw;
DomeOfTheRock *dome;
qibaliMosquee *mosque;
Camera MyCamera;
Model_3DS *tree;
GLTexture Bark, Leaf;

primitives *pri;
Model_3DS *person;
Minaret mina2(30, 100);

int house_door, house_window, house_wall, wallofmosque;
int house_roof[4];
int texture[6];
int marble;
int SKYFRONT, SKYBACK, SKYLEFT, SKYRIGHT, SKYUP, SKYDOWN;
int qibaliMosque;
int mosquewindow;
int carpet;
int mosqueRoof, mosqueRoof2;
int mosaic;
int arch,school_logo;
int mosquewindow2;
int marwanoCarpet;
int Door_angle = 0;
int stone1;
int texturess[6];
int blackMetal;
int marwaniWall;
int great_door;
int Bowaak[6];

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

int currentMood = 0; // 0 for light mood, 1 for dark mood

void SetMood(int mood)
{
	if (mood == 0)
	{ // Light mood
		GLfloat global_ambient_light[] = {0.1f, 0.1f, 0.1f, 1.0f};
		glLightModelfv(GL_LIGHT_MODEL_AMBIENT, global_ambient_light);
		// Additional light settings for light mood...
	}
	else
	{ // Dark mood
		GLfloat global_ambient_dark[] = {0.05f, 0.05f, 0.05f, 1.0f};
		glLightModelfv(GL_LIGHT_MODEL_AMBIENT, global_ambient_dark);
		// Additional light settings for dark mood...
	}
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
	glEnable (GL_BLEND); // enable blending
	glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); // set the blending function
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);


	


	// skybox
	SKYFRONT = LoadTexture("images/skybox/front.bmp", 255);
	SKYBACK = LoadTexture("images/skybox/back.bmp", 255);
	SKYLEFT = LoadTexture("images/skybox/left.bmp", 255);
	SKYRIGHT = LoadTexture("images/skybox/right.bmp", 255);
	SKYUP = LoadTexture("images/skybox/up.bmp", 255);
	SKYDOWN = LoadTexture("images/skybox/down.bmp", 255);



	wooden_door== LoadTexture("",255);
	// house
	window      	 = LoadTexture("images//House/window2.bmp",-80);
	logo			 = LoadTexture("images/House/school_logo.bmp",255);
	wooden_door		 = LoadTexture("images/House/wooden_door.bmp",255);
	green_door	 = LoadTexture("images//House/green_door.bmp",255);
	house_door = LoadTexture("images/House/door.bmp", 255);
	house_window = LoadTexture("images//House/window.bmp", -80);
	great_door = LoadTexture("images/House/GreatDoor.bmp" , 255);
	school_logo=  LoadTexture("images/House/school_logo.bmp",255);
	wall = LoadTexture("images/walls/house_wall.bmp", 255);
	wall1 = LoadTexture("images/walls/wall1.bmp", 255);
	wall4 = LoadTexture("images/walls/wall4.bmp", 255);
	wall2 = LoadTexture("images/walls/wall2.bmp", 255);
	marble = LoadTexture("images/walls/marble.bmp", 255);
	land = LoadTexture("images/walls/land.bmp", 255);
	street = LoadTexture("images/walls/street1.bmp", 255);
	street1 = LoadTexture("images/walls/street.bmp", 255);
	stone4 = LoadTexture("images/walls/stone4.bmp", 255);
	stone1 = LoadTexture("images/walls/stone1.bmp", 255);
	blocks = LoadTexture("images/walls/blocks.bmp", 255);
	grass = LoadTexture("images/walls/grass.bmp", 255);
	ground = LoadTexture("images/walls/ground.bmp", 255);
	marwaniWall = LoadTexture("images/walls/stone2.bmp", 255);
	wall0			 = LoadTexture("images/walls/old_wall.bmp",255);
	grass1			 = LoadTexture("images/walls/grass1.bmp", 255);


	// mosque
	ball = LoadTexture("images/mosque/ball.bmp", 255);
	CylinderBody = LoadTexture("images/mosque/CylinderBody.bmp", 255);
	qibaliMosque = LoadTexture("images/mosque/wall1.bmp", 255);
	carpet_aqsa = LoadTexture("images/mosque/carpet.bmp", 255);
	upwall = LoadTexture("images/mosque/up_wall.bmp", 255);
	alporaq = LoadTexture("images/mosque/alporaq.bmp", 255);
	bottomwall = LoadTexture("images/mosque/bottom_wall.bmp", 255);
	house_wall = LoadTexture("images/mosque/insidemosque.bmp", 255);
	qibaliMosque = LoadTexture("images/mosque/wallmosque.bmp", 255);
	mosqueRoof = LoadTexture("images/mosque/roofmosque.bmp", 255);
	mosquewindow = LoadTexture("images/mosque/qibali.bmp", 255);
	carpet = LoadTexture("images/mosque/carpetMosque.bmp", 255);
	mosaic = LoadTexture("images/mosque/mosaic.bmp", 255);
	mosqueRoof2 = LoadTexture("images/mosque/mosqueroof2.bmp", 255);
	arch = LoadTexture("images/mosque/arch2.bmp", 255);
	mosquewindow2 = LoadTexture("images/mosque/mosquewindow2.bmp", 255);
	marwanoCarpet = LoadTexture("images/mosque/carpet.bmp", 255);
	blackMetal = LoadTexture("images/mosque/blackmetal.bmp", 255);

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
	great_door = LoadTexture("images/House/GreatDoor.bmp", 255);

	person = new Model_3DS();
	person->Load("models/person/8.3DS");
	person->Materials[0].tex = Bark;
	person->Materials[1].tex = Bark;
	person->Materials[2].tex = Bark;
	person->Materials[3].tex = Bark;
	person->Materials[4].tex = Leaf;
	person->Materials[5].tex = Leaf;
	person->Materials[6].tex = Leaf;

	MyCamera = Camera();
	MyCamera.Position.x = 1000;
	MyCamera.Position.y = 10;
	MyCamera.Position.z = 100;

	texturess[0] = qibaliMosque;
	texturess[1] = qibaliMosque;
	texturess[2] = qibaliMosque;
	texturess[3] = qibaliMosque;
	texturess[4] = qibaliMosque;
	texturess[5] = qibaliMosque;

	Bowaak[0] = wall1;
	Bowaak[1] = wall1;
	Bowaak[2] = wall1;
	Bowaak[3] = wall1;
	Bowaak[4] = wall1;
	Bowaak[5] = wall1;
	glDisable(GL_TEXTURE_2D);

	// Light stuff
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	// Set light position and color
	GLfloat light_position[] = {2000.0f, 2000.0f, 2000.0f, 1.0f};
	GLfloat light_color[] = {0.1f, 0.1f, 0.031, 1.0f};
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_color);

	glEnable(GL_LIGHT1);
	// Set light position and color
	GLfloat light_position2[4] = {-2000.0f, 2000.0f, -2000.0f, 1.0f};
	GLfloat light_color2[4] = {0.01f, 0.01f, 0.01, 1.0f};
	glLightfv(GL_LIGHT0, GL_POSITION, light_position2);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_color2);

	// Set material properties
	GLfloat material_ambient[] = {0.3f, 0.3f, 0.3f, 1.0f};
	GLfloat material_diffuse[] = {0.8f, 0.8f, 0.8f, 1.0f};
	GLfloat material_specular[] = {0.5f, 0.5f, 0.5f, 1.0f};
	glMaterialfv(GL_FRONT, GL_AMBIENT, material_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, material_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, material_specular);

	// Set ambient light
	GLfloat global_ambient[] = {0.1f, 0.1f, 0.1f, 1.0f};
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, global_ambient);

	SetMood(currentMood);

	return TRUE; // Initialization Went OK
}

void DrawModel(Model_3DS *model, int scale = 1)
{
	glEnable(GL_TEXTURE_2D);
	model->pos.x = 0;
	model->pos.y = 0;
	model->pos.z = 0;
	model->scale = scale;
	model->Draw();
	glDisable(GL_TEXTURE_2D);
}

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
	if (keys['M'])
	{
		currentMood = (currentMood + 1) % 2; // Toggle between 0 and 1
		SetMood(currentMood);
	}
}
void domeoftherock_pillars(Point begin, float lenght, float width, float height, float depth, int marble, int *texturess)
{
	primitives p1;
	Pillar mosquePillar(3, height / 2.6 - (0.03 * height / 2.6));
	mosquePillar.cube_cylinder_pillar(Point(begin.x, begin.y, begin.z), marble, marble);
	for (int j = depth; j <= width - 10 - depth; j += 40)
	{
		for (int i = depth; i < lenght - depth - 10; i += 40)
		{
			glPushMatrix();
			glTranslated(begin.x + j, begin.y + height / 2.1 - (0.01 * height / 2.1), begin.z + i);
			glRotated(180, 1, 0, 1);
			glRotated(180, 1, 0, 0);
			p1.Arch1(20, 22, 5, 16, texturess);
			glPopMatrix();
			mosquePillar.cube_cylinder_pillar(Point(begin.x + j - 0.5, begin.y, begin.z + i + 19), marble, marble);
		}
	}
}
void partofStrais()
{
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, wall2);
	glBegin(GL_TRIANGLE_STRIP);
	glTexCoord2f(0, 0);
	glVertex3d(0, 0, 0);

	glTexCoord2f(1, 0);
	glVertex3d(100, 0, 0);

	glTexCoord2f(1, 1);
	glVertex3d(85, 40, 0);

			glTexCoord2f(0,1);
			glVertex3d(100,40,0);
			glEnd();
			
	glTexCoord2f(0, 1);
	glVertex3d(100, 40, 0);
	glEnd();
	glDisable(GL_TEXTURE_2D);
}
void hallway()
{
	glPushMatrix();
	glTranslated(1650, 0, 250);
	mina2.draw_minaret(Point(70, 70, 60), wall4, wall4, wall4, wall4);
	h->DrawHousewithoutDomeoneWindow(Point(0, 0, 0), 100, 100, 0, 70, green_door, wall, house_window);
	pri->DrawBall(40, wall, Point(0, 57, 50));
	glTranslated(-100, 0, 0);
	h->DrawHousewithoutDome(Point(0, 0, 0), 100, 100, 0, 70, wall, wall, house_window);

	glPushMatrix();
	glTranslated(-560, 62, 0);
	primitives::DrawCupe(Point(0, 0, 0), 560, 8, 100, wall4);
	mina2.draw_minaret(Point(0, 0, 0), wall4, wall4, wall4, wall4);
	glPopMatrix();

	glTranslated(0, 0, 90);
	Pillar *pillar = new Pillar(10, 46);
	for (int i = 1; i <= 10; i++)
	{
		glTranslated(-56, 0, 0);
		pillar->cube_cylinder_pillar(Point(0, 0, 0), wall4, wall4);
	}

	glPopMatrix();
	
}
void drawstreet()
{
	DomeOfTheRock* d = new DomeOfTheRock();

	glEnable(GL_TEXTURE_2D);
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
		if (i & 1)
		{
			h->DrawHousewithoutDome(Point(0, 0, 0), 100, 100, 0, 70, house_door, wall, house_window);
			glPushMatrix();
			glTranslated(0, 70, 0);
			h->DrawHousewithoutDome(Point(0, 0, 0), 100, 100, 0, 70, wall, wall, house_window);
			glPopMatrix();
		}
		else
		{
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
		if (i & 1)
		{
			h->DrawHousewithoutDome(Point(0, 0, 0), 100, 100, 0, 70, house_door, wall, house_window);
			glPushMatrix();
			glTranslated(0, 70, 0);
			h->DrawHousewithoutDome(Point(0, 0, 0), 100, 100, 0, 70, wall, wall, house_window);
			glPopMatrix();
		}
		else
		{
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
		if (i & 1)
		{
			h->DrawHousewithoutDome(Point(0, 0, 0), 100, 100, 0, 70, house_door, wall, house_window);
			glPushMatrix();
			glTranslated(0, 70, 0);
			h->DrawHousewithoutDome(Point(0, 0, 0), 100, 100, 0, 70, wall, wall, house_window);
			glPopMatrix();
		}
		else
		{
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
		if (i & 1)
		{
			h->DrawHousewithoutDome(Point(0, 0, 0), 100, 100, 0, 70, house_door, wall, house_window);
			glPushMatrix();
			glTranslated(0, 70, 0);
			h->DrawHousewithoutDome(Point(0, 0, 0), 100, 100, 0, 70, wall, wall, house_window);
			glPopMatrix();
		}
		else
		{
			h->DrawHousewithoutDome(Point(0, 0, 0), 100, 100, 0, 70, house_door, wall, house_window);
		}
		glTranslated(106.25, 0, 0);
	}
	glPopMatrix();
	
}
void drawschool()
{
	glEnable(GL_TEXTURE_2D);
	sch = new school();
	sch->drawGround(Point(0, 0, 0), 180, 1, 400, land);
	sch->drawWall(Point(0, 0, 0), 30, 1, 400, wall, wooden_door);
	sch->DrawHousewithoutDome(Point(1, 0, 1), 200, 70, 0, 80, green_door, wall2, window);
	sch->DrawHousewithoutDome(Point(201, 0, 1), 200, 70, 0, 80, wall2, wall2, window);
	glPushMatrix();
	glRotated(-180, 0, 10, 0);
	glTranslated(-310, 0, -70);
	sch->DrawHousewithoutDomeoneWindow(Point(50, 80, 1), 100, 70, 0, 80, wall2, wall2, window);
	sch->DrawHousewithoutDomeoneWindow(Point(150, 80, 1), 100, 70, 0, 80, wall2, wall2, window);
	glPopMatrix();
	sch->DrawHousewithoutDome(Point(201, 0, 1), 100, 70, 0, 80, wall2, wall2, window);
	glPushMatrix();
	glTranslated(147,130,70);
	glBindTexture(GL_TEXTURE_2D,school_logo);
			glBegin(GL_QUADS);
			glTexCoord2f(0,0);
			glVertex3d(0,0,0);
	glTranslated(147, 130, 70);
	glBindTexture(GL_TEXTURE_2D, logo);
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0);
	glVertex3d(0, 0, 0);

	glTexCoord2f(1, 0);
	glVertex3d(50, 0, 0);

	glTexCoord2f(1, 1);
	glVertex3d(50, 30, 0);

	glTexCoord2f(0, 1);
	glVertex3d(0, 30, 0);
	glEnd();
	glPopMatrix();
	glPushMatrix();
	glTranslated(0, -20, 100);
	primitives::DrawCupe(Point(0, 80, -50), 400, 8, 90, wall2);
	glPopMatrix();
	glTranslated(450, 0, 120);

	Pillar *pillar = new Pillar(10, 46);
	for (int i = 1; i <= 8; i++)
	{
		glTranslated(-53, 0, 0);
		pillar->cube_cylinder_pillar(Point(0, 0, 0), wall1, wall1);
	}
	
		
	glDisable(GL_TEXTURE_2D);
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
	glPushMatrix(); // FLOOR
	glTranslated(35, 0, -84.0);
	glRotated(22.5, 0, 1, 0);
	glRotated(90, 1, 0, 0);
	dome->Floor_Roof(carpet_aqsa);
	glPopMatrix();
	dome->DrawOctagon(70, 40, bottomwall, Point(0, 0, 0));
	glTranslated(0, 40, 0);
	dome->drawOctagon(70, 40, upwall, Point(0, 0, 0));
	glPushMatrix(); // ROOF
	glTranslated(35, 40, -84.0);
	glRotated(90, 1, 0, 0);
	glRotated(22.5, 0, 0, 1);
	dome->Floor_Roof(marble);
	glPopMatrix();
	glTranslated(38, 40.1, -83);
	primitives::DrawCylinderBody(Point(0, 0, 0), 36, 36, 10, CylinderBody);
	glTranslated(0, 7.5, 0);
	dome->DrawBall(36, ball, Point(0, 0, 0));
	glPopMatrix();
	// front
	glPushMatrix();
	glTranslated(200, 0, -200);
	glPushMatrix();
	glScaled(8, 8, 8);
	glTranslated(13, -5, 10);
	tree->Draw();
	glPopMatrix();
	glPushMatrix();
	glTranslated(-100, -40, 0);
	glPushMatrix();
	glRotated(-90, 0, 10, 0);
	partofStrais();
	glPopMatrix();
	glPushMatrix();
	glRotated(-90, 0, 10, 0);
	glTranslated(0, 0, -60);
	partofStrais();
	glPopMatrix();
	dome->DrawStrais(wall2);
	glPopMatrix();

	glPushMatrix();
	glTranslated(80, -40, 0);
	glPushMatrix();
	glRotated(-90, 0, 10, 0);
	partofStrais();
	glPopMatrix();
	glPushMatrix();
	glRotated(-90, 0, 10, 0);
	glTranslated(0, 0, -60);
	partofStrais();
	glPopMatrix();
	dome->DrawStrais(wall2);
	glPopMatrix();

	glPushMatrix();
	glTranslated(240, -40, 0);
	glPushMatrix();
	glRotated(-90, 0, 10, 0);
	partofStrais();
	glPopMatrix();
	glPushMatrix();
	glRotated(-90, 0, 10, 0);
	glTranslated(0, 0, -60);
	partofStrais();
	glPopMatrix();
	dome->DrawStrais(wall2);
	glPopMatrix();
	glPopMatrix();
	glPushMatrix();
	glRotated(90, 0, 10, 0);
	domeoftherock_pillars(Point(60, 0, 50), 150, 50, 40, 8, wall1, Bowaak);
	glPopMatrix();
	glPushMatrix();
	glRotated(90, 0, 10, 0);
	domeoftherock_pillars(Point(60, 0, 410), 100, 50, 40, 8, wall1, Bowaak);
	glPopMatrix();
	glPushMatrix();
	glRotated(90, 0, 10, 0);
	domeoftherock_pillars(Point(60, 0, 280), 100, 50, 40, 8, wall1, Bowaak);
	glPopMatrix();

	// left
	glPushMatrix();
	glTranslated(600, -40, 380);
	glPushMatrix();
	glScaled(8, 8, 8);
	glTranslated(-20, 0, -25);
	tree->Draw();
	glPopMatrix();
	glPushMatrix();
	glRotated(-90, 0, 10, 0);
	glPushMatrix();
	glRotated(-90, 0, 10, 0);
	partofStrais();
	glPopMatrix();
	glPushMatrix();
	glRotated(-90, 0, 10, 0);
	glTranslated(0, 0, -60);
	partofStrais();
	glPopMatrix();
	dome->DrawStrais(wall2);
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();
	glTranslated(600, -40, 200);
	glPushMatrix();
	glRotated(-90, 0, 10, 0);
	glPushMatrix();
	glRotated(-90, 0, 10, 0);
	partofStrais();
	glPopMatrix();
	glPushMatrix();
	glRotated(-90, 0, 10, 0);
	glTranslated(0, 0, -60);
	partofStrais();
	glPopMatrix();
	dome->DrawStrais(wall2);
	glPopMatrix();
	glPopMatrix();
	glPushMatrix();
	domeoftherock_pillars(Point(480, 0, 200), 100, 50, 40, 10, wall1, Bowaak);
	glPopMatrix();
	glPushMatrix();
	domeoftherock_pillars(Point(480, 0, 350), 100, 50, 40, 8, wall1, Bowaak);
	glPopMatrix();

	// back
	glPushMatrix();
	glTranslated(200, -40, 600);
	glPushMatrix();
	glScaled(8, 8, 8);
	glTranslated(15, 0, -10);
	tree->Draw();
	glPopMatrix();
	glPushMatrix();
	glScaled(8, 8, 8);
	glTranslated(-20, 0, -10);
	tree->Draw();
	glPopMatrix();
	glPushMatrix();
	glRotated(-180, 0, 10, 0);
	glPushMatrix();
	glRotated(-90, 0, 10, 0);
	partofStrais();
	glPopMatrix();
	glPushMatrix();
	glRotated(-90, 0, 10, 0);
	glTranslated(0, 0, -60);
	partofStrais();
	glPopMatrix();
	dome->DrawStrais(wall2);
	glPopMatrix();
	glPopMatrix();
	glPushMatrix();
	glRotated(90, 0, 10, 0);
	domeoftherock_pillars(Point(-530, 0, 150), 100, 50, 40, 8, wall1, Bowaak);
	glPopMatrix();

	// right
	glPushMatrix();
	glTranslated(-100, -40, 460);
	glPushMatrix();
	glScaled(8, 8, 8);
	glTranslated(-5, 0, -10);
	tree->Draw();
	glPopMatrix();
	glPushMatrix();
	glScaled(8, 8, 8);
	glTranslated(-5, 0, -20);
	tree->Draw();
	glPopMatrix();
	glPushMatrix();
	glScaled(8, 8, 8);
	glTranslated(-5, 0, -40);
	tree->Draw();
	glPopMatrix();
	glPushMatrix();
	glScaled(8, 8, 8);
	glTranslated(-5, 0, -50);
	tree->Draw();
	glPopMatrix();
	glPushMatrix();
	glRotated(90, 0, 10, 0);
	glPushMatrix();
	glRotated(-90, 0, 10, 0);
	partofStrais();
	glPopMatrix();
	glPushMatrix();
	glRotated(-90, 0, 10, 0);
	glTranslated(0, 0, -60);
	partofStrais();
	glPopMatrix();
	dome->DrawStrais(wall2);
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-100, -40, 300);
	glPushMatrix();
	glRotated(90, 0, 10, 0);
	glPushMatrix();
	glRotated(-90, 0, 10, 0);
	partofStrais();
	glPopMatrix();
	glPushMatrix();
	glRotated(-90, 0, 10, 0);
	glTranslated(0, 0, -60);
	partofStrais();
	glPopMatrix();
	dome->DrawStrais(wall2);
	glPopMatrix();
	glPopMatrix();
	glPushMatrix();
	domeoftherock_pillars(Point(-30, 0, 350), 150, 50, 40, 8, wall1, Bowaak);
	glPopMatrix();
	glPushMatrix();
	domeoftherock_pillars(Point(-30, 0, 220), 100, 50, 40, 8, wall1, Bowaak);
	glPopMatrix();

	glPushMatrix();
	glTranslated(370, 0, 0);
	h->DrawHousewithDome(Point(0, 0, 0), 80, 50, 0, 50, green_door, wall2, window, wall2);
	glPopMatrix();

	glPushMatrix();
	glTranslated(220, -40, -140);
	glRotated(-90, 0, 1, 0);
	h->DrawHousewithoutDomeoneWindow(Point(0, 0, 0), 40, 40, 30, 40, green_door, wall2, window);
	glTranslated(0, 40, 0);
	h->DrawHousewithDomeonewindow(Point(0, 0, 0), 40, 40, 0, 40, wall2, wall2, window, wall2);
	glPopMatrix();

	glPushMatrix();
	glTranslated(280, -40, -100);
	glRotated(-180, 0, 1, 0);
	h->DrawHousewithoutDome(Point(0, 0, 0), 60, 40, 30, 40, green_door, wall2, window);
	glTranslated(0, 40, 0);
	h->DrawHousewithDome(Point(0, 0, 0), 60, 40, 0, 40, wall2, wall2, window, wall2);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0, -40, -100);
	glRotated(-90, 0, 1, 0);
	h->DrawHousewithoutDome(Point(0, 0, 0), 100, 40, 30, 40, green_door, wall2, window);
	glTranslated(0, 40, 0);
	h->DrawHousewithDome(Point(0, 0, 0), 100, 40, 0, 40, wall2, wall2, window, wall2);
	glPushMatrix();
	glTranslated(0, -40, -50);
	glRotated(-90, 0, 1, 0);
	h->DrawHousewithoutDomeoneWindow(Point(0, 0, 0), 90, 40, 30, 40, wall2, wall2, window);
	glTranslated(0, 40, 0);
	h->DrawHousewithoutDomeoneWindow(Point(0, 0, 0), 90, 40, 0, 40, wall2, wall2, window);
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();
	glTranslated(300, -40, 500);
	glRotated(-90, 0, 1, 0);
	h->DrawHousewithoutDomeoneWindow(Point(0, 0, 0), 40, 40, 30, 40, green_door, wall2, window);
	glTranslated(0, 40, 0);
	h->DrawHousewithDomeonewindow(Point(0, 0, 0), 40, 40, 0, 40, wall2, wall2, window, wall2);
	glPopMatrix();

	glPushMatrix();
	glTranslated(340, -40, 500);
	glRotated(-90, 0, 1, 0);
	h->DrawHousewithoutDomeoneWindow(Point(0, 0, 0), 40, 40, 0, 35, green_door, wall2, window);
	glTranslated(0, 35, 0);
	h->DrawHousewithDomeonewindow(Point(0, 0, 0), 40, 40, 0, 35, wall2, wall2, window, wall2);
	glPopMatrix();

	glPushMatrix();
	glTranslated(500, -40, 100);
	glRotated(90, 0, 1, 0);
	h->DrawHousewithoutDome(Point(0, 0, 0), 70, 40, 30, 40, green_door, wall2, window);
	glTranslated(0, 40, 0);
	h->DrawHousewithDome(Point(0, 0, 0), 70, 40, 0, 40, wall2, wall2, window, wall2);
	glPopMatrix();

	glPushMatrix();
	glTranslated(500, -40, 160);
	glRotated(90, 0, 1, 0);
	h->DrawHousewithoutDomeoneWindow(Point(0, 0, 0), 60, 40, 0, 40, wall2, wall2, window);
	glTranslated(0, 40, 0);
	h->DrawHousewithDome(Point(0, 0, 0), 60, 40, 0, 40, wall2, wall2, window, wall2);
	glPopMatrix();

	glPushMatrix();
	glTranslated(500, -40, 320);
	glRotated(90, 0, 1, 0);
	h->DrawHousewithoutDomeoneWindow(Point(0, 0, 0), 50, 40, 30, 40, green_door, wall2, window);
	glTranslated(0, 40, 0);
	h->DrawHousewithDome(Point(0, 0, 0), 50, 40, 0, 40, wall2, wall2, window, wall2);
	glPopMatrix();

	glPushMatrix();
	glTranslated(500, -40, 370);
	glRotated(90, 0, 1, 0);
	h->DrawHousewithoutDomeoneWindow(Point(0, 0, 0), 50, 40, 0, 40, wall2, wall2, window);
	glTranslated(0, 40, 0);
	h->DrawHousewithDome(Point(0, 0, 0), 50, 40, 0, 40, wall2, wall2, window, wall2);
	glPopMatrix();

	glPushMatrix();
	glTranslated(500, -40, 500);
	glRotated(90, 0, 1, 0);
	h->DrawHousewithoutDomeoneWindow(Point(0, 0, 0), 50, 40, 30, 40, green_door, wall2, window);
	glTranslated(0, 40, 0);
	h->DrawHousewithDome(Point(0, 0, 0), 50, 40, 0, 40, wall2, wall2, window, wall2);
	glPopMatrix();

	glPushMatrix();
	glTranslated(500, -40, 30);
	glRotated(90, 0, 1, 0);
	h->DrawHousewithoutDomeoneWindow(Point(0, 0, 0), 35, 40, 30, 40, green_door, wall2, window);
	glTranslated(0, 40, 0);
	h->DrawHousewithDome(Point(0, 0, 0), 35, 40, 0, 40, wall2, wall2, window, wall2);
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
void drawMuseum()
{
	glEnable(GL_TEXTURE_2D);
	m=new museum();
	mina2.draw_minaret(Point(-30, 70, 100), qibaliMosque, qibaliMosque, qibaliMosque, qibaliMosque);
	sch->drawGround(Point(0,0,0),250,1,250,wall4);
	m->drawWall(Point(0,0,0),40,1,250,wall2,green_door);
	sch->DrawHousewithoutDome(Point(1,0,1),125,100,0,100,house_door,wall1,window);
	sch->DrawHousewithDome(Point(127,0,1),125,100,0,100,wall1,wall1,window,wall1);
	glPushMatrix();
	glTranslated(-10, -18, 150);
	primitives::DrawCupe(Point(0, 80, -50), 250, 8, 80, wall1);
	glPopMatrix();
	glTranslated(290, 0, 150);
	Pillar *p = new Pillar(10, 46);
	for (int i = 1; i <= 5; i++)
	{
		glTranslated(-56, 0, 0);
		p->cube_cylinder_pillar(Point(0, 0, 0), wall1, wall1);
	}
	glDisable(GL_TEXTURE_2D);
}
void drawPersonModel()
{
	glEnable(GL_TEXTURE_2D);
	glPushMatrix();
	glLoadIdentity();

	glTranslatef(0.0f, -5.0f, -12);
	glRotated(180, 0, 1, 0);
	DrawModel(person, 5);
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);
}

GLfloat lightColor0[] = { 1.5f, 1.5f, 1.5f, 1.0f };   //Color (0.5, 0.5, 0.5)
GLfloat lightPos0[] = { 1.0f, 1.0f, 1.0f, 1.0f };     //Positioned at (4, 0, 8)
GLfloat ambientColor[] = { 10.2f, 0.2f, 0.2f, 1.0f }; //Color (0.2, 0.2, 0.2)




bool check = false;

int DrawGLScene(GLvoid) // Here's Where We Do All The Drawing
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	
  //Add ambient light
  glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientColor);

  //Add positioned light
  glLightfv(GL_LIGHT0, GL_DIFFUSE, lightColor0);
  glLightfv(GL_LIGHT0, GL_POSITION, lightPos0);
  

	MyCamera.Render();
	Key(keys, 30);
	tree->pos.x = 10 ;
	tree->pos.y = 0  ;
	tree->pos.z = 0  ;
	//Door door(10, 10 , 2);



	//p.DrawQuad(Point(140, 25, 143), Point(151.5, 25, 143), Point(151.5, 25, 156.5), Point(140, 25, 156.5), marble);
	//ro->DrawBall(5, ball, Point(146, 24.7, 150));
	//p.DrawQuad(Point(0, 20, 4), Point(11.5, 20, 4), Point(11.5, 20, 16.5), Point(0, 20, 15.5), marble);
	//ro->DrawBall(5, ball, Point(6, 19.7, 10));
	//glTranslated(100, 0, 100);
	

	// Pillar pillar ;
	// pillar.cube_cylinder_pillar(Point(0,0,0),4,marble,10,-1);

	// primitives::Draw3DHexagon(Point(0,0,-100),40,100,marble);
	

	Door door(100 , 1000 , 10);


	if (keys['T'])
	{
		check = true;
	}
	if (keys['R'])
	{
		check = false;
	}
	if (check)
	{
		glClearColor(0.0f, 0.0f, 0.1f, 1.0f); // Dark blue background
		glEnable(GL_LIGHTING);
	}

	else
	{
		glDisable(GL_LIGHTING);
	}

	Draw_Skybox(0, 0, 0, 4000, 4000, 4000);

	glTranslated(-600, 0, -800);


	Out = new OutSide();
	Street = new OutSide();
	h = new House();
	dw = new DrawWall();
	Pillar *pillar = new Pillar(10, 46);
	dome = new DomeOfTheRock();
	pri = new primitives();
	Out->drawGround(Point(0, 0, 0), 2000, 1, 2000, wall4);

	glPushMatrix();
	glTranslated(250, 0, 250);
	Out->drawWall(Point(0, 0, 0), 70, 5, 1500, wall, house_door, keys, great_door, wall);
	glPopMatrix();

	drawstreet();
	drawHouse();
	hallway();

	// alporaq mosque
	glPushMatrix();
	glTranslated(670, 0, 250);
	primitives::DrawCupe(Point(0, 0, 0), 250, 70, 100, qibaliMosque);
	glPushMatrix();
	glTranslated(-250, -180, 0);
	for (int i = 0; i < 6; i++)
	{
		pri->DrawQuad5(Point(250, 200, 100), Point(300, 200, 100), Point(300, 250, 100), Point(250, 250, 100), mosquewindow, 0, 0);
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

	// women's mosque
	glPushMatrix();
	glTranslated(250, 0, 650);
	glRotated(90, 0, 1, 0);
	primitives::DrawCupe(Point(0, 0, 0), 400, 70, 100, qibaliMosque);
	glPushMatrix();
	glTranslated(-230, -230, 0);
	for (int i = 0; i < 9; i++)
	{
		pri->DrawQuad5(Point(250, 200, 100), Point(300, 200, 100), Point(300, 300, 100), Point(250, 300, 100), mosquewindow, 0, 0);
		glTranslated(40, 0, 0);
	}
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-160, -30, 1298);
	glPushMatrix();
	glScaled(8, 8,8 );
	glScaled(8, 8, 8);
	glTranslated(60, 5, -30);
	tree->Draw();
	glPopMatrix();
	glRotated(90, 0, 10, 0);
	glScaled(2, 3, 2);
	mosque->drawQibaliMosque(150, 5, 35, mosquewindow, qibaliMosque, mosqueRoof2,
							 mosquewindow2, mosqueRoof, mosaic, wall2, house_wall, arch, carpet, great_door, great_door);
	glPopMatrix();

	mina2.draw_minaret(Point(1720, 70, 1500), wall2, wall2, wall2, wall2);
	glPushMatrix();
	glTranslated(1750, 0, 1218);
	glRotated(-90, 0, 10, 0);
	drawschool();
	glPopMatrix();

	Marwani *m = new Marwani();
	glPushMatrix();
	glTranslated(120, -20, 390);
	glScaled(1, 1.5, 1.5);
	m->drawMarwaniMosque(Point(140, 12, 480), 420, 300, 45, 5, qibaliMosque, marwanoCarpet, marble, texturess, house_wall, marwaniWall, blackMetal);
	glPopMatrix();

	// draw terrace_alrahma
	glPushMatrix();
	glTranslated(900, 0, 1500);
	primitives::Draw3dQuad(Point(0, 0, 0), 550, 260, 500, 260, 10, wall1);
	glPushMatrix();
	glScaled(6, 6, 6);
	glTranslated(-10, 0, 8);
	tree->Draw();
	glPopMatrix();
	glPushMatrix();
	glScaled(6, 6, 6);
	glTranslated(-10, 0, 20);
	tree->Draw();
	glPopMatrix();
	glPopMatrix();

	// draw terraces_algwanima
	glPushMatrix();
	glTranslated(1570, 0, 550);
	primitives::Draw3dQuad(Point(0, 0, 0), 180, 550, 180, 540, 10, wall1);
	glPushMatrix();
	glScaled(6, 6, 6);
	glTranslated(-10, 0, 10);
	tree->Draw();
	glPopMatrix();
	glPopMatrix();

	

	Door::openning_trigger(keys);
	drawPersonModel();

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
		if (wParam == 'M' || wParam == 'm')
		{
			currentMood = (currentMood + 1) % 2; // Toggle between 0 and 1
			SetMood(currentMood);
			InvalidateRect(hWnd, NULL, TRUE);
		}

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
