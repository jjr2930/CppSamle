#ifndef INPUT_EVENT_PARAMETER_H
#define INPUT_EVENT_PARAMETER_H

#include "EventParameter.h"

/**

    @class   InputEventParameter
    @brief   입력과 관련된 이벤트의 파라미터
    @details ~

**/
class InputEventParameter : public EventParameter
{
public:
	char key;    //!< 어떤 키가 눌렸는지에 대한 정보
};
#endif // !INPUT_EVENT_PARAMETER_H