#include <memory>
#include <iostream>
#include "pageProxy.h"
#include "document.h"


//-----------------------------------------------------------------------------
// main
//-----------------------------------------------------------------------------
int main()
{
    Document doc;

    doc.open(); // by default it opens page 1
    doc.changeToPage(4);
    doc.changeToPage(15);
    doc.changeToPage(24);
    doc.changeToPage(1);
    doc.changeToPage(37);
    doc.changeToPage(59);

    return 0;
}
