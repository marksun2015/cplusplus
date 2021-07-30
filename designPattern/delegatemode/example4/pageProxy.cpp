#include <iostream>
#include "pageProxy.h"

//-----------------------------------------------------------------------------
// CTOR
//-----------------------------------------------------------------------------
PageProxy::PageProxy() {
    std::cout << __FUNCTION__ << std::endl;
    _page = NULL;
}

//-----------------------------------------------------------------------------
// DTOR
//-----------------------------------------------------------------------------
PageProxy::~PageProxy() {
    std::cout << __FUNCTION__ << std::endl;
}

//-----------------------------------------------------------------------------
// getPage
//-----------------------------------------------------------------------------
std::shared_ptr<Page> PageProxy::getPage() {
    if (NULL == _page) {
        //std::cout << std::endl << "_page null" << std::endl;
        _page = std::make_shared<Page>();
    }
    return _page;
}

//-----------------------------------------------------------------------------
// setCurrentPage
//-----------------------------------------------------------------------------
void PageProxy::setCurrentPage(int currentPage) {
    _currentPage = currentPage;
}

//-----------------------------------------------------------------------------
// getCurrentPage
//-----------------------------------------------------------------------------
const int PageProxy::getCurrentPage() const {
    return _currentPage;
}

//-----------------------------------------------------------------------------
// displayContent
//-----------------------------------------------------------------------------
void PageProxy::displayContent(int pageNumber) {
    setCurrentPage(pageNumber);
    std::cout << std::endl << "On page \"" << getCurrentPage() << "\":" << std::endl;
    switch (pageNumber)
    {
        case 1:
            getPage()->displayText();
            //this->displayText();
            break;

        case 24:
            getPage()->displayText();
            getPage()->displayImage();
            break;

        case 37:
            getPage()->displayText();
            getPage()->displayImage();
            getPage()->displayVideo();
            break;

        default:
            getPage()->displayEmpty();
            break;
    }
    std::cout << std::endl;
}

//-----------------------------------------------------------------------------
// displayText
//-----------------------------------------------------------------------------
void PageProxy::displayText() {
    std::cout << "Proxy Displaying text." << std::endl;
}

//-----------------------------------------------------------------------------
// displayImage
//-----------------------------------------------------------------------------
void PageProxy::displayImage() {
    std::cout << "Proxy Displaying image." << std::endl;
}

//-----------------------------------------------------------------------------
// displayVideo
//-----------------------------------------------------------------------------
void PageProxy::displayVideo() {
    std::cout << "Proxy Displaying video." << std::endl;
}

//-----------------------------------------------------------------------------
// displayEmpty
//-----------------------------------------------------------------------------
void PageProxy::displayEmpty() {
    std::cout << "Proxy Displaying empty." << std::endl;
}


