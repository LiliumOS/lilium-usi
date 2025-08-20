#ifndef __LILIUM_USI_FENV_H_2025_07_22_20_20_41
#define __LILIUM_USI_FENV_H_2025_07_22_20_20_41

#include <bits/fenv.h>

int fegetenv(fenv_t *__envp);
int fesetenv(const fenv_t *__envp);

int feholdexcept(fenv_t *__envp);
int feupdateenv(const fenv_t *__envp);

extern const fenv_t __fe_default_env;

#define FE_DFL_ENV (&__fe_default_env)

#endif /* __LILIUM_USI_FENV_H_2025_07_22_20_20_41 */