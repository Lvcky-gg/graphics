#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdio.h>

// Window Dimensions
const GLint WIDTH = 800, HEIGHT = 600;

int main()
{
    // Initialize GLFW
    if (!glfwInit())
    {
        fprintf(stderr, "GLFW Initialization Failed!\n");
        glfwTerminate();
        return 1;
    }

    // Set GLFW context version and profile
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // For macOS

    // Create the window
    GLFWwindow* mainWindow = glfwCreateWindow(WIDTH, HEIGHT, "TEST", nullptr, nullptr);
    if (!mainWindow)
    {
        fprintf(stderr, "Window Initialization Failed!\n");
        glfwTerminate();
        return 1;
    }

    // Get buffer size information
    int bufferWidth, bufferHeight;
    glfwGetFramebufferSize(mainWindow, &bufferWidth, &bufferHeight);

    // Make context current
    glfwMakeContextCurrent(mainWindow);

    // Setup GLEW
    glewExperimental = GL_TRUE;
    GLenum err = glewInit();
    if (err != GLEW_OK)
    {
        fprintf(stderr, "GLEW Initialization Failed: %s\n", glewGetErrorString(err));
        glfwDestroyWindow(mainWindow);
        glfwTerminate();
        return 1;
    }

    // Setup viewport
    glViewport(0, 0, bufferWidth, bufferHeight);

    // Main loop
    while (!glfwWindowShouldClose(mainWindow))
    {
        // Handle events
        glfwPollEvents();

        // Clear the screen
        glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // Swap buffers
        glfwSwapBuffers(mainWindow);
    }

    // Clean up
    glfwDestroyWindow(mainWindow);
    glfwTerminate();

    return 0;
}
