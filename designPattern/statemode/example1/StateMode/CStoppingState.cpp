//
//  CStoppingState.cpp
//  StateMode
//
//  Created by Gun Li on 4/5/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "CStoppingState.h"
#include "CContext.h"
using namespace std;
CStoppingState::CStoppingState()
{
}

CStoppingState::~CStoppingState()
{}

void CStoppingState::Open()
{
    this->CLifeState::m_pContext->SetLifeState(CContext::pOpenningState);
    this->CLifeState::m_pContext->GetLifeState()->Open();
}

void CStoppingState::Close()
{
    this->CLifeState::m_pContext->SetLifeState(CContext::pClosingState);
    this->CLifeState::m_pContext->GetLifeState()->Close();
}

void CStoppingState::Run()
{
    this->CLifeState::m_pContext->SetLifeState(CContext::pRunningState);
    this->CLifeState::m_pContext->GetLifeState()->Run();
}

void CStoppingState::Stop()
{
    cout<<"elevator stop..."<<endl;
}
