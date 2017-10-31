/*
 * File:   main.cpp
 * Author: Suzuka/Emma Theberge
 *
 * Date: October 30, 2017, 8:05 PM
 *
 * some code copied from:
 *	    https://github.com/SonarSystems/OpenGL-
 *	    Tutorials/blob/master/GLFW%20Mouse%20Input
 *	    /main.cpp
 *
 * Some code taken from and altered from:
 * _CSC5210_Unit4_PerspectiveCameraCode
 * (Class Example)
 */

#include <iostream>
#include <cstdio>

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <cstdlib>


// User Includes
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/glm.hpp>
#include <math.h>

//other
#include "GLFWApplication.h"
#include "Texture.hpp"
#include "Shader.hpp"
#include "Camera.h"

//basic shapes includes

//more complex shapes  includes
#include "Rectangular_Prisim1.h"

// The current mouse position
double deltaX, deltaY;
bool lButtonDown;
bool rButtonDown;
vec2 mousePos;

//glm::mat4s for Transformations

glm::mat4 idenity;//will hold the idenity matrix

GLFWApplication newApplication;

// Window information
GLuint winHeight=800;
GLuint winWidth=900;

Camera* camera;
//Shaders
Shader* normalShader;
Shader* textureShader;
string searchPath="/Volumes/NO NAME/College_2017-2018/CSC 5210 Computer Graphics/Playing around with stuff/Testing RectangularPrisim/Testing RectangularPrisim/";

bool keyisPressed=false; //if key is currently pressed gets true
bool keyisReleased=true; //if key is currently released gets true

//textures!!!!
Texture* texture0;
Texture* texture1;
Texture* texture2;
Texture* texture3;

//colors
vec3 white=vec3(1, 1, 1);
vec3 black=vec3(0, 0, 0);

//colors! (mainnly used for testing purposes)
vec3 col1=vec3(1.0f, 0.2f, 0.2f); // Reddish
vec3 col2=vec3(0.2f, 0.2f, 1.0f); // Blueish
vec3 col3=vec3(0.324, 0.4532, 0.564);
vec3 lightblue =vec3(0.3232f, 1, 1);//light blue
vec3 purple=vec3(1, 0.567f, 1);
vec3 cyan = vec3(0, 1, 1);
vec3 orange = vec3(1.0, 0.567, 0.0043);
vec3 yellow = vec3(1.0, 1.00, 0.0043);


using namespace std

/**
 * init
 * Initalizes:
 * Textures, Shapes/Geometry models, Camera, Shaders, and glEnable(something),
 * also what should be drawn to the screen
 */
void init()
{
	//for images that were not already PNGs I used
	//converted to PNG using: https://www.online-convert.com/result/b3ee3611-0731-44a4-aa21-27105e9b7e9c
	//to convert them to be pngs

	//source of where the texture was found
	//texture0 = new Texture(searchPath+"IMAGE_SAVED_NAME.png");

	//	printf("texture0: %d\n",glIsTexture(texture0->getTexID()));
	//	printf("texture1: %d\n",glIsTexture(texture1->getTexID()));
	//	printf("texture2: %d\n",glIsTexture(texture2->getTexID()));
	//	printf("texture3: %d\n",glIsTexture(texture3->getTexID()));

	//Declare the shapes:

	//params for Rectangular_Prisim1: vec3 _e, vec3 _f, vec3 _b, vec3 _c, depth, color fill, color border, texture
	
	// Set up the texture shader
	string textureSaderFiles[]=
	{
		searchPath+"Texture.vert",
		searchPath+"Texture.frag"
	};
	textureShader=new Shader(textureSaderFiles, false);

	string saderFiles[]=
	{
		searchPath+"vertices.vert",
		searchPath+"fragments.frag"
	};
	normalShader=new Shader(saderFiles,true);

	// Set up the camera, taken from class example
	vec3 pos(5, 5, 50.0);
	GLfloat FOV=45.0f;
	GLfloat nearPlane=0.1f;
	GLfloat farPlane=1000.0f;
	camera=new Camera(pos, winWidth, winHeight);
	camera -> setPerspective(FOV, (GLfloat) winWidth/(GLfloat) winHeight,nearPlane, farPlane);
	//glEnable(GL_POINT_SIZE);
	//glPointSize(50);

	// Finally, tell the application object about the drawable objects
	newApplication.addDrawableObject();
  
  
}//init end

/**
 *
 * @param window
 * @param key = N
 * @param scancode
 * @param action
 * @param mode
 */
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
	if(action==GLFW_PRESS)
	{
		if(key==GLFW_KEY_Q||key==GLFW_KEY_ESCAPE)
		{
			glfwSetWindowShouldClose(window, true);
		}
    else if (key==GLFW_KEY_N)
    {
      //both players draw a new card from their draw deck
      //if draw deck for either one of the players is empty shuffle their discard deck,
      //put discard deck to be draw deck
      //draw deck is empty
	}
}


// glfw: whenever the window size changed (by OS or user resize) this callback function executes
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	// make sure the viewport matches the new window dimensions; note that width and
	// height will be significantly larger than specified on retina displays.
	glViewport(0, 0, width, height);
}


//escape to exit


int main()
{
	// Set up the GLFW application
	//anti aliasing level
	//minor version (Opengl)
	//major version (Opengl)
	//window title
	//window width
	//window height
	newApplication.initializeApplication(8, 1, 4,
										 "v 00 Project 4 War?", winWidth, winHeight);

	// Assign your callback functions (the ones you write) to the internal
	//   callbacks of the application class.
	newApplication.setKeyCallback(key_callback);
	newApplication.initializeCallbacks();

	// Initialize stuff local to the program
	init();
	newApplication.setShader(normalShader);
	newApplication.setCamera(camera);

	// Tell the application to "go"
	newApplication.initiateDrawLoop();

	return 0;
}
