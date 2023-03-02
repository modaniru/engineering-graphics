#include <GLFW/glfw3.h>

int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
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
    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        glPointSize(1);
        glBegin(GL_POINTS);

        for (float x = -1.0f; x < 1.0f; x += 0.1f) {
            for (float y = -1.0f; y < 1.0f; y += 0.1f) {
                glVertex2f(x, y);
                glColor3f(1.f, 1.f, 1.f);
            }
        }

        glEnd();

        glBegin(GL_TRIANGLES);
            glColor3f(0.98, 0.f, 0.48);
            glVertex2f(-0.5, -0.5);
            glColor3f(0, 0.94, 0.99);
            glVertex2f(0.5, -0.5);
            glColor3f(1, 1, 1);
            glVertex2f(0, 0.5);
        glEnd();


        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}