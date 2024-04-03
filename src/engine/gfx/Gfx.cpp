/**
* @file Gfx.h
* @author Hudson Schumaker
* @brief Defines the Gfx class.
* @version 1.0.0
* 
* Dodoi-Engine-NS is a game engine developed by Dodoi-Lab.
* 
* @copyright Copyright (c) 2024, Dodoi-Lab
* 
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
* 
*     http://www.apache.org/licenses/LICENSE-2.0
* 
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/
#include "Gfx.h"
#include "Color.h"

Gfx::Gfx() {}
Gfx::~Gfx() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
}

Gfx* Gfx::getInstance() {
    if (instance == nullptr) {
        instance = new Gfx();
    }

    return instance;
}

void Gfx::setGfxContext() {
    SDL_Init(SDL_INIT_EVERYTHING);
    IMG_Init(IMG_INIT_PNG);
    TTF_Init();
    
    SDL_Window *window = SDL_CreateWindow(
        "dodoi-engine-ns",
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        SCREEN_WIDTH, SCREEN_HEIGHT,
        SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL
    );
    
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    
    Mix_OpenAudio(48000, AUDIO_S16, 8, 4096);
    
    SDL_InitSubSystem(SDL_INIT_JOYSTICK);
    SDL_JoystickEventState(SDL_ENABLE);
    SDL_JoystickOpen(0);
}

SDL_Window* Gfx::getWindow() {
    return window;
}

SDL_Renderer* Gfx::getRenderer() {
    return renderer;
}

SDL_Texture* Gfx::createText(std::string fontName, std::string text, short size, SDL_Color color) {
	Uint8 r, g, b, a;
    SDL_GetRenderDrawColor(renderer, &r, &g, &b, &a);

	auto path = FONT_FOLDER + fontName;
	TTF_Font* font = TTF_OpenFont(path.c_str(), size);
	SDL_Surface* surface = TTF_RenderText_Blended(font, text.c_str(), color);
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);

	SDL_FreeSurface(surface);

	SDL_SetRenderDrawColor(renderer, r, g, b, a);
	TTF_CloseFont(font);	
	return texture;
}

SDL_Texture* Gfx::loadTexture(std::string name) {
	auto path = IMAGE_FOLDER + name;
	SDL_Surface* surface = IMG_Load(path.c_str());
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);

	SDL_FreeSurface(surface);
	return texture;
}

Dimension<int> Gfx::getTextureSize(SDL_Texture* texture) {
	Dimension<int> size = { 0, 0 };
	SDL_QueryTexture(texture, NULL, NULL, &size.w, &size.h);

	return size;
}

SDL_Rect Gfx::getTextureBounds(SDL_Texture* texture) {
	Dimension<int> size = { 0, 0 };
	SDL_QueryTexture(texture, NULL, NULL, &size.w, &size.h);
	SDL_Rect rect = { 0, 0, size.w, size.h };

	return rect;
}

SDL_FRect Gfx::getTextureFBounds(SDL_Texture* texture) {
	Dimension<int> size = { 0, 0 };
	SDL_QueryTexture(texture, NULL, NULL, &size.w, &size.h);
	SDL_FRect rect = { 0.0f, 0.0f, static_cast<float>(size.w), static_cast<float>(size.h) };

	return rect;
}

void Gfx::showMouseCursor(bool value) {
	if (value) { SDL_ShowCursor(SDL_ENABLE); }
	else { SDL_ShowCursor(SDL_DISABLE); }
}

// Primitives
void Gfx::drawLine(const int x0, const int y0, const int x1, const int y1, const SDL_Color& color) {
	Uint8 r, g, b, a;
	SDL_GetRenderDrawColor(renderer, &r, &g, &b, &a);
	SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
	SDL_RenderDrawLine(renderer, x0, y0, x1, y1);
	SDL_SetRenderDrawColor(renderer, r, g, b, a);
}

void Gfx::drawCircle(const int centerX, const int centerY, const int radius, const SDL_Color& color) {
	Uint8 r, g, b, a;
    SDL_GetRenderDrawColor(renderer, &r, &g, &b, &a);
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
	
	// Draw
	int x = radius - 1;
    int y = 0;
    int dx = 1; 
    int dy = 1;
    int err = dx - (radius << 1);

    while (x >= y) {
        SDL_RenderDrawPoint(renderer, centerX + x, centerY + y);
        SDL_RenderDrawPoint(renderer, centerX + y, centerY + x);
        SDL_RenderDrawPoint(renderer, centerX - y, centerY + x);
        SDL_RenderDrawPoint(renderer, centerX - x, centerY + y);
        SDL_RenderDrawPoint(renderer, centerX - x, centerY - y);
        SDL_RenderDrawPoint(renderer, centerX - y, centerY - x);
        SDL_RenderDrawPoint(renderer, centerX + y, centerY - x);
        SDL_RenderDrawPoint(renderer, centerX + x, centerY - y);

        if (err <= 0) {
            y++;
            err += dy;
            dy += 2;
        }

        if (err > 0) {
            x--;
            dx += 2;
            err += dx - (radius << 1);
        }
    }

	SDL_SetRenderDrawColor(renderer, r, g, b, a);
}

void Gfx::drawFilledCircle(const int centerX, const int centerY, const int radius, const SDL_Color& color) {
    Uint8 r, g, b, a;
    SDL_GetRenderDrawColor(renderer, &r, &g, &b, &a);
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);

    // Draw
    for (int y = -radius; y <= radius; y++) {
        for (int x = -radius; x <= radius; x++) {
            if (x*x + y*y <= radius * radius) {
                SDL_RenderDrawPoint(renderer, centerX + x, centerY + y);
            }
        }
    }

    SDL_SetRenderDrawColor(renderer, r, g, b, a);
}

void Gfx::drawDashedCircle(const int centerX, const int centerY, const int radius, const int dashLength, const SDL_Color& color) {
	Uint8 r, g, b, a;
    SDL_GetRenderDrawColor(renderer, &r, &g, &b, &a);
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);

	// Draw
	const int totalSegments = int(radius * 2 * Defs::PI / dashLength);
    const double angleIncrement = 2 * Defs::PI / totalSegments;
    for (short i = 0; i < totalSegments; ++i) {
        double angle = angleIncrement * i;

        int x1 = int(centerX + radius * std::cos(angle));
        int y1 = int(centerY + radius * std::sin(angle));

        angle = angleIncrement * (i + 1);

        int x2 = int(centerX + radius * std::cos(angle));
        int y2 = int(centerY + radius * std::sin(angle));

        if (i % 2 == 0) {
            SDL_RenderDrawLine(renderer, x1, y1, x2, y2);
        }
    }

	SDL_SetRenderDrawColor(renderer, r, g, b, a);
}

void Gfx::drawBox(const SDL_Rect& rect, const SDL_Color& color) {
	Uint8 r, g, b, a;
    SDL_GetRenderDrawColor(renderer, &r, &g, &b, &a);

    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderDrawRect(renderer, &rect);

    SDL_SetRenderDrawColor(renderer, r, g, b, a);
}

void Gfx::drawFillBox(const SDL_Rect& rect, const SDL_Color& color) {
    Uint8 r, g, b, a;
    SDL_GetRenderDrawColor(renderer, &r, &g, &b, &a);

    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderFillRect(renderer, &rect);

    SDL_SetRenderDrawColor(renderer, r, g, b, a);
}
