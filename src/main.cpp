#include<iostream>
#include<glad/glad.h>
#include <GLFW/glfw3.h>

int g_WindowSizeX = 640;
int g_WindowSizeY = 480;

void glfwWindowSizeCallback(GLFWwindow* pWindow, int wight, int height) {
    g_WindowSizeX = wight;
    g_WindowSizeY = height;
    glViewport(0, 0, g_WindowSizeX, g_WindowSizeY); //���������� � ����� ������� �� ����� �������� 
}
//�������� ���� �� ������� ������� escape
void glfwKeyCallback(GLFWwindow* pWindow, int key, int scancode, int action, int mode) {
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(pWindow, GL_TRUE);//��������� GL ��� �� ��������� ���������
    }
}

int main(void)
{
    GLFWwindow* pWindow;

    /* Initialize the library */
    if (!glfwInit())
    {
        std::cout << "glfwInit failed!" << std::endl;
        return -1;
    }
    //�������� ������, ���� ��� ������ 4 � 6, �� ���� �� ����������
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    //��������� "��� ��� ����"
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    /* Create a windowed mode window and its OpenGL context */
    pWindow = glfwCreateWindow(g_WindowSizeX, g_WindowSizeY, "BattleCity", nullptr, nullptr);
    if (!pWindow)
    {
        std::cout << "glfwCreateWindow failed!" << std::endl;
        glfwTerminate();
        return -1;
    }


    glfwSetWindowSizeCallback(pWindow, glfwWindowSizeCallback);
    glfwSetKeyCallback(pWindow, glfwKeyCallback);

    /* ������ ��� ���� ������� */
    glfwMakeContextCurrent(pWindow);

    if (!gladLoadGL())
    {
        std::cout << "Can`t load GLAD" << std::endl;
        return -1;
    }

    std::cout << "Render: " << glGetString(GL_RENDERER) << std::endl; // ���������� �������� ����������
    std::cout << "OpenGL version: " << glGetString(GL_VERSION) << std::endl; //����������� ������ OpenGL
    std::cout << "OpenJL" << GLVersion.major << "." << GLVersion.minor << std::endl;

    glClearColor(0, 1, 0, 1);


    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(pWindow))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        /* Swap front and back buffers */
        glfwSwapBuffers(pWindow);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}