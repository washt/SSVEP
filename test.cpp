#include <stdio.h>
#include <stdlib.h>
#include <iostream>

// sleep utils
#include <chrono>
#include <thread>

//open glfw and glew libs
#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>

// static void error_callback(int error, const char* description)
// {
//   fputs(description, stderr);
// }
// static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
// {
//   if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
//     glfwSetWindowShouldClose(window, GL_TRUE);
// }

// int main(void)
// {
//   GLFWwindow* window;
//   glfwSetErrorCallback(error_callback);
  
//   if (!glfwInit())
//     exit(EXIT_FAILURE);
//   window = glfwCreateWindow(640, 480, "SSVEP TEST", NULL, NULL);

//   if (!window)
//     {
//       glfwTerminate();
//       exit(EXIT_FAILURE);
//     }

//   glfwMakeContextCurrent(window);
//   glfwSetKeyCallback(window, key_callback);
  
//   while (!glfwWindowShouldClose(window))
//     {
      
//       float ratio;
//       int width, height;
//       glfwGetFramebufferSize(window, &width, &height);
//       ratio = width / (float) height;
//       glViewport(0, 0, width, height);
//       glClear(GL_COLOR_BUFFER_BIT);
//       glMatrixMode(GL_PROJECTION);
//       glLoadIdentity();
//       glOrtho(-ratio, ratio, -1.f, 1.f, 1.f, -1.f);
//       glMatrixMode(GL_MODELVIEW);
//       glLoadIdentity();
//       glRotatef((float) glfwGetTime() * 50.f, 1.f, 1.f, 1.f);
//       glBegin(GL_TRIANGLES);

//       glColor3f(1.f, 0.f, 0.f);
//       glVertex3f(-0.6f, -0.4f, 0.f);
      
//       glColor3f(1.f, 0.f, 0.f);
//       glVertex3f(0.6f, -0.4f, 0.f);
      
//       glColor3f(0.f, 0.f, 1.f);
      
//       glVertex3f(0.f, 0.6f, 0.f);

//       glEnd();
//       glfwSwapBuffers(window);
//       glfwPollEvents();

//     }
//   glfwDestroyWindow(window);
//   glfwTerminate();
//   exit(EXIT_SUCCESS);
// }

static void error_callback(int error, const char* description)
{
  fputs(description, stderr);
}
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
  if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    glfwSetWindowShouldClose(window, GL_TRUE);
}

int main(void)
{
  GLFWwindow* window;
  glfwSetErrorCallback(error_callback);
  
  if (!glfwInit())
    exit(EXIT_FAILURE);
  window = glfwCreateWindow(640, 480, "SSVEP TEST", NULL, NULL);

  if (!window)
    {
      glfwTerminate();
      exit(EXIT_FAILURE);
    }

  glfwMakeContextCurrent(window);
  glfwSetKeyCallback(window, key_callback);
  
  while (!glfwWindowShouldClose(window))
    {
      
      float ratio;
      int width, height;
      glfwGetFramebufferSize(window, &width, &height);
      ratio = width / (float) height;
      glViewport(0, 0, width, height);
      glClear(GL_COLOR_BUFFER_BIT);
      glMatrixMode(GL_PROJECTION);
      glLoadIdentity();
      glOrtho(-ratio, ratio, -1.f, 1.f, 1.f, -1.f);
      glMatrixMode(GL_MODELVIEW);
      glLoadIdentity();
      glRotatef((float) glfwGetTime() * 50.f, 0.f, 0.f, 0.f);

      glBegin(GL_TRIANGLES);
      glColor3f(1.f, 1.f, 1.f);
      glVertex3f(-0.6f, -0.4f, 0.f);
      
      glColor3f(1.f, 1.f, 1.f);
      glVertex3f(0.6f, -0.4f, 0.f);

      glColor3f(1.f, 1.f, 1.f);
      glVertex3f(0.f, 0.6f, 0.f);      
      glEnd();

      glfwSwapBuffers(window);
      glfwPollEvents();

    }
  glfwDestroyWindow(window);
  glfwTerminate();
  exit(EXIT_SUCCESS);
}
// void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
// {
//   if(key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
//       glfwSetWindowShouldClose(window,GL_TRUE);
// }

// GLfloat vertices[] = {
//   -0.5f, -0.5f, 0.0f,
//    0.5f, -0.5f, 0.0f,
//    0.0f,  0.5f, 0.0f
// };

// int main()
// {
//     GLuint VBO;
//     GLenum err;

//     glfwInit();
//     glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//     glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//     glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//     glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);  

//     GLFWwindow* window = glfwCreateWindow(200,100, "Open GL Test",NULL,NULL);
//     glfwMakeContextCurrent(window);
    
//     if (window == NULL)
//     {
//       std::cout << "Failed to create GLFW window \n";
//       glfwTerminate();
//       exit(EXIT_FAILURE);
//       return -1;
//     }

//     glewExperimental = GL_TRUE;
//     if ((glewInit = err()) != GLEW_OK)
//     {
//       std::cout << glewGetErrorString(err) << "\n";//"Failed to load GLEW experimental\n";
//       return -1;
//     }

//     glfwMakeContextCurrent(window);
//     glViewport(0,0,800,600);

//     glGenBuffers(1, &VBO);
//     glBindBuffer(GL_ARRAY_BUFFER,VBO);
//     //Event loop
//     while(!glfwWindowShouldClose(window))

//     {
//       // if((float)glfwGetTime() >= .5 )
//       // {
//         glfwSetTime(0.0);
//         glfwPollEvents();
//         glfwSetKeyCallback(window,key_callback);
//         glClearColor(1.0f,1.0f,1.0f,1.0f);
//         glClear(GL_COLOR_BUFFER_BIT);
//         glfwSwapBuffers(window);
//         std::this_thread::sleep_for(std::chrono::milliseconds(100));
//         glfwPollEvents();
//         glfwSetKeyCallback(window,key_callback);
//         glClearColor(0.0f,0.0f,0.0f,0.0f);
//         glClear(GL_COLOR_BUFFER_BIT);
//         glfwSwapBuffers(window);
//         std::this_thread::sleep_for(std::chrono::milliseconds(100));
//     //   }
//     //   else if((float)glfwGetTime() < .5) 
//     //   {
//     //     glfwPollEvents();
//     //     glfwSetKeyCallback(window,key_callback);
//     //     glClearColor(0.0f,0.0f,0.0f,0.0f);
//     //     glClear(GL_COLOR_BUFFER_BIT);
//     //     glfwSwapBuffers(window);
//     //   }
//     //   std::cout << (float)glfwGetTime() * 10.f << "\n";
//     }
//     // exit program
//     glfwDestroyWindow(window);
//     glfwTerminate();
//     exit(EXIT_SUCCESS);
//     return 0;
// }