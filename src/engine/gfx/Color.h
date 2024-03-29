/**
* @file Color.h
* @author Hudson Schumaker
* @brief Defines the Color class and its associated methods.
* @version 1.0.0
* 
* Dodoi-Engine-NS is a game engine developed by Dodoi-Lab.
* @copyright Copyright (c) 2024, Dodoi-Lab
*/
#pragma once
#include "../Common.h"

/**
* @class Color
* @brief A class that represents a color.
*/
class Color final {
public:
    int r = 255, g = 255, b = 255, a = 255;
    
    /**
    * @brief Default constructor.
    */
    Color() = default;

    /**
    * @brief Constructor that initializes the color with the given values.
    * @param r Red component.
    * @param g Green component.
    * @param b Blue component.
    * @param a Alpha component.
    */
    Color(int r, int g, int b, int a);

    /**
    * @brief Default destructor.
    */
    ~Color() = default;

    /**
    * @brief Creates a RGBA value from an SDL_Color.
    * @param color The SDL_Color to convert.
    * @return The created RGBA value.
    */
    static Uint32 createRGBA(SDL_Color color);

    /**
    * @brief Creates a RGBA value from individual color components.
    * @param r Red component.
    * @param g Green component.
    * @param b Blue component.
    * @param a Alpha component.
    * @return The created RGBA value.
    */
    static Uint32 createRGBA(int r, int g, int b, int a);

    /**
    * @brief Creates a ARGB value from an SDL_Color.
    * @param color The SDL_Color to convert.
    * @return The created ARGB value.
    */
    static Uint32 createARGB(SDL_Color color);

    /**
    * @brief Creates a ARGB value from individual color components.
    * @param a Alpha component.
    * @param r Red component.
    * @param g Green component.
    * @param b Blue component.
    * @return The created ARGB value.
    */
    static Uint32 createARGB(int a, int r, int g, int b);

    /**
    * @brief Returns the hexadecimal representation of the current color in RGBA format.
    * @return The hexadecimal representation of the current color.
    */
    Uint32 getHexRGBA();

    /**
    * @brief Returns the hexadecimal representation of the given SDL_Color in RGBA format.
    * @param color The SDL_Color to convert.
    * @return The hexadecimal representation of the given color.
    */
    Uint32 getHexRGBA(SDL_Color color);

    /**
    * @brief Returns the hexadecimal representation of the current color in ARGB format.
    * @return The hexadecimal representation of the current color.
    */
    Uint32 getHexARGB();

    /**
    * @brief Returns the hexadecimal representation of the given SDL_Color in ARGB format.
    * @param color The SDL_Color to convert.
    * @return The hexadecimal representation of the given color.
    */
    Uint32 getHexARGB(SDL_Color color);

    /**
    * @brief Converts a hexadecimal color in RGBA format to an SDL_Color.
    * @param hex The hexadecimal color to convert.
    * @return The converted SDL_Color.
    */
    static SDL_Color fromHexRGBA(Uint32 hex);

    /**
    * @brief Converts a hexadecimal color in ARGB format to an SDL_Color.
    * @param hex The hexadecimal color to convert.
    * @return The converted SDL_Color.
    */
    static SDL_Color fromHexARGB(Uint32 hex);

    /**
    * @brief Returns an SDL_Color representing red.
    * @return An SDL_Color representing red.
    */
    static SDL_Color getRed();

    /**
    * @brief Returns an SDL_Color representing green.
    * @return An SDL_Color representing green.
    */
    static SDL_Color getGreen();

    /**
    * @brief Returns an SDL_Color representing blue.
    * @return An SDL_Color representing blue.
    */
    static SDL_Color getBlue();

    /**
    * @brief Returns an SDL_Color representing white.
    * @return An SDL_Color representing white.
    */
    static SDL_Color getWhite();

    /**
    * @brief Returns an SDL_Color representing black.
    * @return An SDL_Color representing black.
    */
    static SDL_Color getBlack();

    /**
    * @brief Returns an SDL_Color representing gray.
    * @return An SDL_Color representing gray.
    */
    static SDL_Color getGray();

    /**
    * @brief Returns an SDL_Color representing orange.
    * @return An SDL_Color representing orange.
    */
    static SDL_Color getOrange();

    /**
    * @brief Returns an SDL_Color representing yellow.
    * @return An SDL_Color representing yellow.
    */
    static SDL_Color getYellow();

    /**
    * @brief Returns an SDL_Color representing pink.
    * @return An SDL_Color representing pink.
    */
    static SDL_Color getPink();

    /**
    * @brief Returns an SDL_Color representing brown.
    * @return An SDL_Color representing brown.
    */
    static SDL_Color getBrown();

    /**
    * @brief Returns an SDL_Color representing purple.
    * @return An SDL_Color representing purple.
    */
    static SDL_Color getPurple();

    /**
    * @brief Returns an SDL_Color representing teal.
    * @return An SDL_Color representing teal.
    */
    static SDL_Color getTeal();

    /**
    * @brief Returns an SDL_Color representing lime.
    * @return An SDL_Color representing lime.
    */
    static SDL_Color getLime();

    /**
    * @brief Returns an SDL_Color representing maroon.
    * @return An SDL_Color representing maroon.
    */
    static SDL_Color getMaroon();

    /**
    * @brief Returns an SDL_Color representing olive.
    * @return An SDL_Color representing olive.
    */
    static SDL_Color getOlive();

    /**
    * @brief Returns an SDL_Color representing navy.
    * @return An SDL_Color representing navy.
    */
    static SDL_Color getNavy();

    /**
    * @brief Returns an SDL_Color representing magenta.
    * @return An SDL_Color representing magenta.
    */
    static SDL_Color getMagenta();    

    /**
    * @brief Returns an SDL_Color representing cyan.
    * @return An SDL_Color representing cyan.
    */
    static SDL_Color getCyan();

    /**
    * @brief Returns an SDL_Color representing silver.
    * @return An SDL_Color representing silver.
    */
    static SDL_Color getSilver();

    /**
    * @brief Returns an SDL_Color representing gold.
    * @return An SDL_Color representing gold.
    */
    static SDL_Color getGold();
};
