#include <iostream>
#include "simulation.h"

int main() {
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW\n";
        return -1;
    }

    GLFWwindow* window = glfwCreateWindow(1000, 1000, "Drawing With Fourier", nullptr, nullptr);
    if (!window) {
        std::cerr << "Failed to create window\n";
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    
    std::vector<double> x, y; //heart drawing
    int N = 200; 
    for (int i = 0; i < N; i++) {
        double t = 2 * 3.14159265358979323846 * i / N;
        double xt = 16 * pow(sin(t), 3);
        double yt = 13 * cos(t) - 5 * cos(2 * t) - 2 * cos(3 * t) - cos(4 * t);
        x.push_back(xt / 17.0); 
        y.push_back(yt / 17.0);
    }

    double t = 0.01;
    Simulation s(x, y, 200, t, 40);
    s.initSimulation();

    while (!glfwWindowShouldClose(window)) {

        glClearColor(0.0f, 0.0f, 0.0f, 1.0f); 
        glClear(GL_COLOR_BUFFER_BIT);         
        double time = glfwGetTime();
        s.runSimulation(time);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}