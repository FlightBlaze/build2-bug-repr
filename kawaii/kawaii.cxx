import kawaii.Application;

int main (int argc, char** argv)
{
    auto app = new kawaii :: Application(argc, argv);
    int result = app->run();

    delete app;
    
    return result;
}
