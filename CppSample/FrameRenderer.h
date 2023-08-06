#ifndef FRAME_RENDERER_H
#define FRAME_RENDERER_H

#include "Renderer.h"

/**

    @class   FrameRenderer
    @brief  
#########################################
#                                       #
#                                       #
#                                       #
#                                       #
#                                       #
#                                       #
#                                       #
#                                       #
#                                       #
#                                       #
#                                       #
#                                       #
#                                       #
#                                       #
#                                       #
#                                       #
#                                       #
#                                       #
#                                       #
#########################################
모양을 콘솔 화면에 출력한다.
    @details ~
**/
class FrameRenderer : public Renderer
{
public : 
	FrameRenderer();
	
	virtual void Render();
};

#endif // ! FRAME_RENDERER_H
