//
// Created by Pulkit Juneja on 02/08/18.
//

#include "Engine.h"
#include "ResourceManager.hpp"

const GLint WIDTH = 800, HEIGHT = 600;


void Engine::start() {
    // engine specific initializations
    if(!setupSFML()) {
        isEngineRunning = false;
    }
    if(!init()) {
        isEngineRunning = false;
    }
    while (isEngineRunning) {
        sf::Event windowEvent;

        while ( window->pollEvent( windowEvent ) )
        {
            switch ( windowEvent.type )
            {
                case sf::Event::Closed:
                    isEngineRunning = false;
                    break;
            }
        }

        update();

        glClearColor( 0.2f, 0.3f, 0.3f, 1.0f );
        glClear( GL_COLOR_BUFFER_BIT );

        render();

        window->display( );
    }

    // perform shutdown steps
    window->close();
}

bool Engine::setupSFML() {

    sf::ContextSettings settings;
    settings.depthBits = 24;
    settings.stencilBits = 8;
    settings.majorVersion = 3;
    settings.minorVersion = 3;
    settings.attributeFlags = sf::ContextSettings::Core;

    window = new sf::Window( sf::VideoMode( WIDTH, HEIGHT, 32 ), "OpenGL SFML", sf::Style::Titlebar | sf::Style::Close, settings );

    glewExperimental = GL_TRUE;

    if ( GLEW_OK != glewInit( ) )
    {
        std::cout << "Failed to initialize GLEW" << std::endl;
        return false;
    }

    // Load Default Shaders

    ResourceManager::getInstance()->loadShader("Shaders/basic.vert", "Shaders/basic.frag", "defaultShader");

  return true;
}