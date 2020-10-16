//
//  CRunningState.cpp
//  StateMode
//
//  Created by Gun Li on 4/5/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "CRunningState.h"
#include "CContext.h"
using namespace std;
CRunningState::CRunningState()
{
}

CRunningState::~CRunningState()
{}

void CRunningState::Open()
{
    this->CLifeState::m_pContext->SetLifeState(CContext::pOpenningState);
    this->CLifeState::m_pContext->GetLifeState()->Open();
}

void CRunningState::Close()
{
    this->CLifeState::m_pContext->SetLifeState(CContext::pClosingState);
    this->CLifeState::m_pContext->GetLifeState()->Close();
}

void CRunningState::Run()
{
    cout<<"elevator run..."<<endl;
}

void CRunningState::Stop()
{
    this->CLifeState::m_pContext->SetLifeState(CContext::pStoppingState);
    this->CLifeState::m_pContext->GetLifeState()->Stop();
}
