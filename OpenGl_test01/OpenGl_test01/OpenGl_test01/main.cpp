#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
int main() {

    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    
    //open GLFW Window
    GLFWwindow* window = glfwCreateWindow(800, 600, "HelloWorld", NULL, NULL);
    if (window == NULL) {
        printf ("open window failed");
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    //Init GLEW 
    glewExperimental = true; 
    if (glewInit() != GLEW_OK) {
        printf("Init glew error");
        glfwTerminate();
        return -1;
    }

    glViewport(0, 0, 800, 600);
    //循环刷新渲染
    while (!glfwWindowShouldClose(window)) {
        //交换颜色缓冲区
        glfwSwapBuffers(window);
        //获取用户操做事件
        glfwPollEvents();
    }
    glfwTerminate();
	return 0;
}