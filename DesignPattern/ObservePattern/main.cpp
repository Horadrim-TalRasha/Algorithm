#include "observe.h"

int main(int argc, char** argv)
{
    MessagePool pool;
    Publisher publisher(&pool);
    Friend friendA(&pool);
    Friend friendB(&pool);

    pool.AddObserver(&publisher);
    pool.AddObserver(&friendA);
    pool.AddObserver(&friendB);

    pool.ChangeStateAndNotify(1);
    pool.ChangeStateAndNotify(2);
    return 0;
}
