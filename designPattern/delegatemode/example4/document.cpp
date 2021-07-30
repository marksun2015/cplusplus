#include <iostream>
#include "document.h"
#include "pageProxy.h"

//-----------------------------------------------------------------------------
// CTOR
//-----------------------------------------------------------------------------
Document::Document() {
    std::cout << __FUNCTION__ << std::endl;
    initProxy();
}


//-----------------------------------------------------------------------------
// DTOR
//-----------------------------------------------------------------------------
Document::~Document() {
    std::cout << __FUNCTION__ << std::endl;
}


//-----------------------------------------------------------------------------
// open
//-----------------------------------------------------------------------------
void Document::open(int pageNumber) {
    _proxy.displayContent(pageNumber);
}

//-----------------------------------------------------------------------------
// open
//-----------------------------------------------------------------------------
void Document::initProxy() {

}

//-----------------------------------------------------------------------------
// open
//-----------------------------------------------------------------------------
void Document::changeToPage(int pageNumber) {
    _proxy.displayContent(pageNumber);
}


