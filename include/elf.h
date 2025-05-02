#ifndef __LILIUM_ELF_H_2025_05_02_17_38_11
#define __LILIUM_ELF_H_2025_05_02_17_38_11

struct __Elf_AuxEnt
{
    unsigned long __aux_type;
    union
    {
        unsigned long __aux_val;
        void *__aux_ptr;
    };
};

#endif /* __LILIUM_ELF_H_2025_05_02_17_38_11 */