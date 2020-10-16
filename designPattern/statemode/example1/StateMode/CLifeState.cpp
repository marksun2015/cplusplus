//
//  CLifeState.cpp
//  StateMode
//
//  Created by Gun Li on 4/5/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "CLifeState.h"
CContext *CLifeState::m_pContext = NULL;

CLifeState::CLifeState()
{
    m_pContext = NULL;
}

CLifeState::~CLifeState()
{
    m_pContext = NULL;
}

void CLifeState::SetContext(CContext *pContext)
{
    m_pContext = pContext;
}