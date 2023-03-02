#include <GLFW/glfw3.h>

int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    GLenum res = glfwInit();
    if (!res)
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);
    glPolygonMode(GL_FRONT, GL_FILL);
    glPolygonMode(GL_BACK, GL_LINE);
    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        //glPointSize(65);
        glBegin(GL_POINTS);
        glColor3f(0.2, 0.3, 1);
        for (float f = -1.0f; f < 1.0f; f += 0.1f) {
            for (float f2 = -1.0f; f2 < 1.0f; f2 += 0.1f) {
                glVertex2f(f, f2);
            }
        }

        glEnd();


        glBegin(GL_TRIANGLES);

        glColor3f(1, 1, 1);
        glVertex2f(0, 0.5f);
        glVertex2f(-0.5f, 0);
        glVertex2f(0.5f, 0);
        glEnd();

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}