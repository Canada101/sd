#include"contextSwitcher.h"

int ContextSwitcher::currentContext;

void ContextSwitcher::switchContext(int newContext) 
{
    currentContext = newContext;
    
};

int ContextSwitcher::getContext() 
{
    return currentContext;
};