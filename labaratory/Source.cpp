#include <GLFW/glfw3.h>
#include <Windows.h>
#include <cmath>

#define PI 3.14159265


float vertices[] = {
    1,1,0, 1,-1,0, -1,-1,0, -1,1,0
};
void createFloor() {
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, &vertices);
    glColor3f(0, 0.5, 0);
    glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
    glDisableClientState(GL_VERTEX_ARRAY);
}

void moveCamera() {
    glTranslatef(0, 0, -2);
}

void rotateCamer(double angle) {
    glRotatef(angle, 1, 0, 0);
}

void drawSquare(double x, double y) {
    glBegin(GL_QUAD_STRIP);
    glColor3f(0, 0.5, 0.5);
    glVertex2f(0 - x, y);
    glColor3f(0.5, 0.5, 0);
    glVertex2f(x, y);
    glColor3f(0.5, 0, 0.5);
    glVertex2f(0 - x, 0 - y);
    glColor3f(0.5, 1, 0.5);
    glVertex2f(x, 0 - y);
    glEnd();
}

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
    static float alpha = 0;

    glEnable(GL_DEPTH_TEST);

    glLoadIdentity();
    glFrustum(-1, 1, -1, 1, 2, 8);

    glTranslatef(0, 0, -2);
    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        ////Отвечает за перемещение
        //glLoadIdentity();
        //glPushMatrix();

        //glTranslatef(cos(alpha * PI / 180), 0, 0);
        //glScalef(cos(alpha * PI / 180), cos(alpha * PI / 180), 1);

        //drawSquare(0.1, 0.1);

        //glPopMatrix();
        ////Отвечает за нижнюю полоску
        //glTranslatef(0.0f, -0.95f, 0);
        //drawSquare(sin(alpha * PI / 180), 0.05);
        //alpha += 2;

        //для себя
        /*glVertexPointer(3, GL_FLOAT, 0, & vertices);
        glEnableClientState(GL_VERTEX_ARRAY);

        glTranslatef(0, 0, -0.05);
        glColor3f(0, 1, 0);
        glDrawArrays(GL_TRIANGLES, 0, 3);
        glPushMatrix();
            glColor3f(1, 0, 0);
            glDrawArrays(GL_TRIANGLES, 3, 3);
        glPopMatrix();

        glDisableClientState(GL_COLOR_ARRAY);*/
        rotateCamer(1);
        glPushMatrix();
        moveCamera();
        createFloor();
        glPopMatrix();
        glfwSwapBuffers(window);
        glfwPollEvents();
        Sleep(10);
    }

    glfwTerminate();
    return 0;
}