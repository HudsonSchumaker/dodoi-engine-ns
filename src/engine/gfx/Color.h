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

    unsigned long getHexRGBA();
    static unsigned long getHexRGBA(SDL_Color color);
    unsigned long getHexARGB();
    static unsigned long getHexARGB(SDL_Color color);

    static SDL_Color fromHexRGBA(unsigned long hex);
    static SDL_Color fromHexARGB(unsigned long hex);

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

    static SDL_Color getPurple();
    static SDL_Color getTeal();
    static SDL_Color getLime();
    static SDL_Color getMaroon();
    static SDL_Color getOlive();
    static SDL_Color getNavy();
    static SDL_Color getMagenta();    
    static SDL_Color getCyan();
    static SDL_Color getSilver();
    static SDL_Color getGold();
};
