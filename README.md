# Doodle
Complimentary class library for SDL2 written in C+++14.
WIP... Some functions are still not mapped and there are plans to wrap other parts of the SDL2 library.

# Library overview:
The aim of the library is to provide a simple set of classes to allow easier use of SDL2 functionality. 

Each of the main components, with the exception of the *System* component, provide RAII types for handling SDL2 resources. Moreover, each class bundles together the SDL2 functions that manipulate those resources. Lastly, each type is capable of conversion to the SDL2 resource type that it wraps so as to allow for interoperation between other SDL2 functions that are currently not wrapped. 

## Initialization/Shutdown
The library includes facilities to start up and shutdown SDL2. These functions are aptly named: `doodle::init` and `doodle::close`.
Initialization is in steps for each SDL2 subsystem. In the event of an error, the output of that error is printed to the standard error stream. 

Upon initialization, the following image types are supported:
1. PNG
1. JPG
1. TIF

Upon initialization, the following audio file types are supported:
1. MP3
1. OGG
1. FLAC
1. MOD

Additionally, the library only initializes 8 sound channels for 8 simultaneous sounds playing. 

## Audio
The SDL2 types: `Mix_Chunk` and `Mix_Music` are wrapped in classes `doodle::Sound` and `doodle::Music` respectively. Sounds are created using the `doodle::load_sound` function. Music instances are created using the `doodle::load_music` function.

## Display 
The SDL2 types: `SDL_Renderer` and `SDL_Window` are wrapped in classes `doodle::Renderer` and `doodle::Window` respectively. Renderers are created using the `doodle::create_renderer` function. Windows are created using the `doodle::create_window` function.

## Graphics
The SDL2 types: `SDL_Texture` and `TTF_Font` are wrapped in classes `doodle::Texture` and `doodle::Font` respectively. 
There are four functions that allow for creating textures:   
1. `doodle::load_image`. Used for loading textures from image files. 
1. `doodle::load_solid_text`. Used for loading standard rendered text.
1. `doodle::load_shaded_text`. Used for loading rendered text with a shadow.
1. `doodle::load_blended_text`. Used for loading rendered text that is blended with its background color.

Fonts are created using the `doodle::load_font` function.

## System
This component contains the following classes:  
1. `doodle::Clock`. Used for calculating time/calculating delta time.
1. `doodle::FrameCounter`. Used primarily for counting min/avg/max frame rate
1. `doodle::InputHandler`. Used for maintaining the state of the keyboard/mouse. 

This component also contains the following enumerations used for input event processing:
1. `doodle::Keyboard`. 282 distinct keys used in SDL2.
1. `doodle::Mouse`. 3 buttons that map to the left, middle, and right respectively.

## Asset
This component is a utility for making management of a large number of assets such as audio/textures/fonts easier. 
The `doodle::AssetManager` can be used to name different assets that can later be referred to in different parts of a program.
