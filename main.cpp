#include "Window.hpp"

int main(int argc, char** argv)
{
    int x = 1200;
    int y = 600;

    if(argc == 3)
    {
        x = atoi(argv[1]);
        y = atoi(argv[2]);
    }

    Window w(x, y);
    w.run();

    return 0;
}
