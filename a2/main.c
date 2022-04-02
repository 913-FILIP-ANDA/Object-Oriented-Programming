#include "ui/Ui.h"
#include <crtdbg.h>
int main()
{
    EstateRepository repo = create_repository();
    EstateService serv = create_service(&repo);
    UI ui = create_UI(&serv);

    run(&ui);
    destroy(repo.estates);
    printf("Mem leaks: %d",_CrtDumpMemoryLeaks());
    return 0;
}