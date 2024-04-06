/**
* @file PrimitiveRenderSystem.cpp
* @author Hudson Schumaker
* @brief Implements the PrimitiveRenderSystem class.
* @version 1.0.0
* 
* Dodoi-Engine-NS is a game engine developed by Dodoi-Lab.
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
#include "PrimitiveRenderSystem.h"
#include "../../gfx/Box.h"
#include "../../gfx/Gfx.h"
#include "../../gfx/Line.h"
#include "../../gfx/Circle.h"
#include "../EntityManager.h"
#include "../component/Transform.h"

PrimitiveRenderSystem::PrimitiveRenderSystem() {
	this->renderer = Gfx::getInstance()->getRenderer();
}

void PrimitiveRenderSystem::update(Camera* camera) {

    
	renderLine(camera);
	renderBox(camera);
    renderCircle(camera);
}

