#include <iostream>
#include <GLFW/glfw3.h>

export module kawaii.Application;

export import kawaii.Manager;

static int terminate(const char* message);
static void glfw_error_callback(int error, const char* description);
static void key_callback(
    GLFWwindow* window, int key, int scancode,int action, int mods);

export namespace kawaii {
 
    class Application final {
      
        int _argc;
        char** _argv;
        
        GLFWwindow* _window = 0;
        
    public:
        
        Application(int argc, char* argv[]):
            _argc(argc), _argv(argv)
        {
            
        }
        
        int run() {

            glfwSetErrorCallback(glfw_error_callback);
            
            if (!glfwInit())
                return terminate("Could not initialize GLFW.");
            
            _window = glfwCreateWindow(640, 480, "Kawaii", 0, 0);
            
            if (!_window)
                return terminate("Could not create GLFW window.");
            
            glfwSetKeyCallback(_window, key_callback);
            glfwMakeContextCurrent(_window);
            glfwSwapInterval(1);
            
            do
            {
                glfwSwapBuffers(_window);
                glfwPollEvents();
            }
            while (!glfwWindowShouldClose(_window));
            
            glfwDestroyWindow(_window);
            glfwTerminate();
            
            return 0;
        }
        
    };
    
}

static int terminate(const char* message) {
    printf("%s", message);
    glfwTerminate();
    return -1;
}

static void glfw_error_callback(
    int error,
    const char* description) {
    fprintf(stderr, "Error: %s\n", description);
}

static void key_callback(GLFWwindow* window, int key, int scancode,
                         int action, int mods)
{    
    if (key == GLFW_KEY_ESCAPE && action == 1)
        glfwSetWindowShouldClose(window, 1);
}


