#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
// sleep utils
#include <chrono>
#include <thread>
//open glfw and glew libs
#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
  if(key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
      glfwSetWindowShouldClose(window,GL_TRUE);
}

GLfloat vertices[] = {
  -0.5f, -0.5f, 0.0f,
   0.5f, -0.5f, 0.0f,
   0.0f,  0.5f, 0.0f
};

// static int interval = 200;

int main(int argc, char* argv[])
{
    int interval = atoi(argv[1]);
    // std::cout << interval1;
    std::string freq = std::to_string(interval);
    std::string id = "Open GL Test " + freq + " Ms";
    const char *cstr = id.c_str();

    GLuint VBO;
    GLenum err;
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);

    GLFWwindow* window = glfwCreateWindow(200,100, cstr,NULL,NULL);
    glfwMakeContextCurrent(window);

    if (window == NULL)
    {
      std::cout << "Failed to create GLFW window \n";
      glfwTerminate();
      exit(EXIT_FAILURE);
      return -1;
    }

    glewExperimental = GL_TRUE;
    if ((err = glewInit()) != GLEW_OK)
    {
      std::cout << glewGetErrorString(err) << "\n";//"Failed to load GLEW experimental\n";
      return -1;
    }

    glfwMakeContextCurrent(window);
    glViewport(0,0,800,600);

    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER,VBO);

    //Event loop
    while(!glfwWindowShouldClose(window))

    {

        glfwSetTime(0.0);
        glfwPollEvents();
        glfwSetKeyCallback(window,key_callback);
        glClearColor(1.0f,1.0f,1.0f,1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(window);
        std::this_thread::sleep_for(std::chrono::milliseconds(interval));
        glfwPollEvents();
        glfwSetKeyCallback(window,key_callback);
        glClearColor(0.0f,0.0f,0.0f,0.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(window);
        std::this_thread::sleep_for(std::chrono::milliseconds(interval));
    }
    // exit program
    glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);
    return 0;
}
