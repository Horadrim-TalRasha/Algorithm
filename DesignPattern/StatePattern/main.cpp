#include "state.h"
#include "concretestatea.h"

int main(int argc, char** argv)
{

    State* pStateA = new ConcreteStateA();
    Context* pCon = new Context(pStateA);
    pCon->Handle();
    pCon->Handle();
    pCon->Handle();
    return 0;
}
