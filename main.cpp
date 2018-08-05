//#include <iostream>
//
//#define GLEW_STATIC
//#include "Globals.h"
//#include "Mesh.h"
//#include "ResourceManager.hpp"
//#include <SFML/Window.hpp>
//#include <cstdlib>
//
//const GLint WIDTH = 800, HEIGHT = 600;
//
//using namespace std;
//
//int main()
//{
//    sf::ContextSettings settings;
//    settings.depthBits = 24;
//    settings.stencilBits = 8;
//    settings.majorVersion = 3;
//    settings.minorVersion = 3;
//    settings.attributeFlags = sf::ContextSettings::Core;
//
//    sf::Window window( sf::VideoMode( WIDTH, HEIGHT, 32 ), "OpenGL SFML", sf::Style::Titlebar | sf::Style::Close, settings );
//
//    glewExperimental = GL_TRUE;
//
//    if ( GLEW_OK != glewInit( ) )
//    {
//        std::cout << "Failed to initialize GLEW" << std::endl;
//        return EXIT_FAILURE;
//    }
//
//    bool running = true;
//
//    vector<float> triangleVertices = {
//        -0.5f, -0.5f, 0.0f,
//        0.5f, -0.5f, 0.0f,
//        0.0f,  0.5f, 0.0f
//    };
//
//    vector<int> triangleIndices = {1,2,3};
//    ResourceManager::getInstance()->loadShader("Shaders/basic.vert", "Shaders/basic.frag", "Basic-Shader");
//    Mesh triangleMesh(triangleVertices, triangleIndices, *(ResourceManager::getInstance()->getShader("Basic-Shader")));
//
//    while ( running )
//    {
//        sf::Event windowEvent;
//
//        while ( window.pollEvent( windowEvent ) )
//        {
//            switch ( windowEvent.type )
//            {
//                case sf::Event::Closed:
//                    running = false;
//
//                    break;
//            }
//        }
//
//        glClearColor( 0.2f, 0.3f, 0.3f, 1.0f );
//        glClear( GL_COLOR_BUFFER_BIT );
//
//        triangleMesh.Draw();
//
//        window.display( );
//    }
//
//    window.close( );
//
//    return EXIT_SUCCESS;
//}

#include "ParticleWorld.h"

int main () {
    ParticleWorld world;
    world.start();
}
