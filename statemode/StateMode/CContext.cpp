//
//  CContext.cpp
//  StateMode
//
//  Created by Gun Li on 4/5/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "CContext.h"

COpenningState *CContext::pOpenningState = NULL;
CClosingState *CContext::pClosingState = NULL;
CStoppingState *CContext::pStoppingState = NULL;
CRunningState *CContext::pRunningState = NULL;

CContext::CContext()
{
    m_pLifeContext = NULL;
    pOpenningState = new COpenningState();
    pClosingState = new CClosingState();
    pStoppingState = new CStoppingState();
    pRunningState = new CRunningState();
}

CContext::~CContext()
{
    delete pOpenningState;
    pOpenningState = NULL;
    delete pClosingState;
    pClosingState = NULL;
    delete pRunningState;
    pRunningState = NULL;
    delete pStoppingState;
    pStoppingState = NULL;
}

CLifeState *CContext::GetLifeState()
{
    return m_pLifeContext;
}

void CContext::SetLifeState(CLifeState *pLifeState)
{
    m_pLifeContext = pLifeState;
}

void CContext::Open()
{
    this->m_pLifeContext->Open();
}

void CContext::Close()
{
    this->m_pLifeContext->Close();
}

void CContext::Stop()
{
    this->m_pLifeContext->Stop();
}

void CContext::Run()
{
    this->m_pLifeContext->Run();
}