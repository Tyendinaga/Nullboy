//Standard Windows Crap
#include <iostream>
#include <vector>

//External Shit
#include <glad\glad.h>
#include <GLFW\glfw3.h>

//Custom Shit
#include "display.hpp"

bool display::initialize()
{
	
	//WW      WW IIIII NN   NN DDDDD    OOOOO  WW      WW 
	//WW      WW  III  NNN  NN DD  DD  OO   OO WW      WW 
	//WW   W  WW  III  NN N NN DD   DD OO   OO WW   W  WW 
	// WW WWW WW  III  NN  NNN DD   DD OO   OO  WW WWW WW 
	//  WW   WW  IIIII NN   NN DDDDDD   OOOO0    WW   WW  

	std::cout << "GLFW Initializing" << std::endl;

	/* Initialize the library */
	if (!glfwInit())
	{
		std::cout << "GLFW Initialization Failed" << std::endl;
		return false;
	}

	//Window Hints
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	//Creater a 640 by 320 Window to play the game in. 
	window = glfwCreateWindow(640, 320, "EmuC80", NULL, NULL);
	if (!window)
	{
		std::cout << "GLFW Window Failure" << std::endl;
		glfwTerminate();
		return false;
	}

	//Set Context (Must be before GLAD)
	glfwMakeContextCurrent(window);

	//Set Resize Function
	glfwSetFramebufferSizeCallback(window, this->framebufferSizeCallback);

	//Initialize GLAD
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return false;
	}

	// SSSSS  HH   HH   AAA   DDDDD   EEEEEEE RRRRRR   SSSSS  
	//SS      HH   HH  AAAAA  DD  DD  EE      RR   RR SS      
	// SSSSS  HHHHHHH AA   AA DD   DD EEEEE   RRRRRR   SSSSS  
	//     SS HH   HH AAAAAAA DD   DD EE      RR  RR       SS 
	// SSSSS  HH   HH AA   AA DDDDDD  EEEEEEE RR   RR  SSSSS  

	//SHADER COMPILATION VARIABLES
	//----------------------------
	int compiled;
	char compileLog[512];

	//SHADER SOURCE CODE
	//------------------
	char *vertexShaderSource = "#version 330 core\n"
		"layout (location = 0) in vec3 aPos;\n"
		"void main()\n"
		"{\n"
		"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
		"}\0";

	char *fragmentShaderSource = "#version 330 core\n"
		"out vec4 FragColor;\n"
		"void main()\n"
		"{\n"
		"   FragColor = vec4(1.0f, 1.0f, 1.0f, 1.0f);\n"
		"}\n\0";

	//COMPILE VERTEX SHADER
	//---------------------
	int vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	glCompileShader(vertexShader);

	//CHECK SHADER COMPILATION
	//------------------------
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &compiled);
	if (!compiled)
	{
		glGetShaderInfoLog(vertexShader, 512, NULL, compileLog);
		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << compileLog << std::endl;
	}

	//COMPILE FRAGMENT SHADER
	//-----------------------
	int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	glCompileShader(fragmentShader);

	//CHECK SHADER COMPILATION
	//------------------------
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &compiled);
	if (!compiled)
	{
		glGetShaderInfoLog(vertexShader, 512, NULL, compileLog);
		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << compileLog << std::endl;
	}

	//LINK SHADER PROGRAM
	//-------------------
	shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);

	//CHECK SHADER LINKAGE
	//--------------------
	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &compiled);
	if (!compiled) 
	{
		glGetProgramInfoLog(shaderProgram, 512, NULL, compileLog);
		std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << compileLog << std::endl;
	}

	//CLEANUP SHADER ARTIFACTS
	//------------------------
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);

	//VV     VV EEEEEEE RRRRRR  TTTTTTT EEEEEEE XX    XX        DDDDD     AAA   TTTTTTT   AAA   
	//VV     VV EE      RR   RR   TTT   EE       XX  XX         DD  DD   AAAAA    TTT    AAAAA  
	// VV   VV  EEEEE   RRRRRR    TTT   EEEEE     XXXX   _____  DD   DD AA   AA   TTT   AA   AA 
	//  VV VV   EE      RR  RR    TTT   EE       XX  XX         DD   DD AAAAAAA   TTT   AAAAAAA 
	//   VVV    EEEEEEE RR   RR   TTT   EEEEEEE XX    XX        DDDDDD  AA   AA   TTT   AA   AA 


	/*
	//MAKE A TRIANGLE
	//---------------
	float vertices[] = {
		-0.5f, -0.5f, 0.0f, // left  
		0.5f, -0.5f, 0.0f, // right 
		0.0f,  0.5f, 0.0f  // top   
	};

	float vertices2[] = {
		-0.7f, -0.7f, 0.0f, // left  
		0.3f, -0.3f, 0.0f, // right 
		0.0f,  0.7f, 0.0f  // top   
	};

	//GENERATE ARRAYS AND BUFFERS
	//---------------------------
	glGenVertexArrays(1, &VAO);
	glGenVertexArrays(1, &VAO2);
	glGenBuffers(1, &VBO);

	//BINDING
	//-------
	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	//BIND VBO
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	//Unbind VAO
	glBindVertexArray(0);

	//Unbind Buffer
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	*/
	/* Prior Code
	//GENERATE ARRAYS AND BUFFERS
	//---------------------------
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);

	//BINDING
	//-------
	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices2), vertices2, GL_STATIC_DRAW);

	//BIND VBO
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	//Unbind Buffer
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	//Unbind VAO
	glBindVertexArray(0);*/

	return true;
}

//Draw Game Stuff
void display::drawGraphics()
{

}

unsigned int display::generate(std::vector<float> vertices)
{
	
	//Get Size of Vertices Vector in Bytes
	GLsizei size = vertices.size() * sizeof(vertices[0]);

	//GENERATE ARRAYS AND BUFFERS
	//---------------------------
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);

	//BINDING
	//-------
	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, size, &vertices[0], GL_STATIC_DRAW);

	//BIND VBO
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	//Do not Work with Vertex Array
	glBindVertexArray(0);

	//Do not work with Buffer
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	//This points to some shit on Memory
	return VAO;
}

bool display::shouldClose()
{
	return glfwWindowShouldClose(window);
}

void display::framebufferSizeCallback(GLFWwindow * window, int width, int height)
{
	std::cout << "Frame Buffer Updated" << std::endl;
	glViewport(0, 0, width, height);
}


