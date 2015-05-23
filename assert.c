#include <assert.h>

//Para desactivar las lineas con assert del código hay dos opciones
//                   1.Flag del compilador            -DNDEBUG
//                   2. #define NDEBUG

int i = 0;

assert(i == 1);
//se termina la ejecución del programa dando feedback con el siguiente error:
//assert: assert.c:9: test_assert: Assertion `i == 1' failed.
