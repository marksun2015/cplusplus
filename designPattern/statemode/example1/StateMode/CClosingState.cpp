//
//  ClosingState.cpp
//  StateMode
//
//  Created by Gun Li on 4/5/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "CClosingState.h"
#include "CContext.h"
using namespace std;

CClosingState::CClosingState()
{
}

CClosingState::~CClosingState()
{}

void CClosingState::Open()
{
    this->CLifeState::m_pContext->SetLifeState(CContext::pOpenningState);
    this->CLifeState::m_pContext->GetLifeState()->Open();
}

void CClosingState::Close()
{
    cout<<"elevator door close..."<<endl;
}

void CClosingState::Run()
{
    this->CLifeState::m_pContext->SetLifeState(CContext::pRunningState);
    this->CLifeState::m_pContext->GetLifeState()->Run();
}

void CClosingState::Stop()
{
    this->CLifeState::m_pContext->SetLifeState(CContext::pStoppingState);
    this->CLifeState::m_pContext->GetLifeState()->Stop();
}
