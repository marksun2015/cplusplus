//
//  CClosingState.h
//  StateMode
//
//  Created by Gun Li on 4/5/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef StateMode_ClosingState_h
#define StateMode_ClosingState_h

#include "CLifeState.h"

class CClosingState : public CLifeState
{
public:
    CClosingState();
    ~CClosingState();
    void Open();
    void Close();
    void Run();
    void Stop();
};

#endif
