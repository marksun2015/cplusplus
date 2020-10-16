//
//  COpenningState.cpp
//  StateMode
//
//  Created by Gun Li on 4/5/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "COpenningState.h"
#include "CContext.h"
using namespace std;

COpenningState::COpenningState()
{
}

COpenningState::~COpenningState()
{}

void COpenningState::Open()
{
    cout<<"elevator door open..."<<endl;
}

void COpenningState::Close()
{
    this->CLifeState::m_pContext->SetLifeState(CContext::pClosingState);
    this->CLifeState::m_pContext->GetLifeState()->Close();
}

void COpenningState::Run()
{
    this->CLifeState::m_pContext->SetLifeState(CContext::pRunningState);
    this->CLifeState::m_pContext->GetLifeState()->Run();
}

void COpenningState::Stop()
{
    this->CLifeState::m_pContext->SetLifeState(CContext::pStoppingState);
    this->CLifeState::m_pContext->GetLifeState()->Stop();
}
