#ifndef XFT_X86_MSR_INDEX_H
#define XFT_X86_MSR_INDEX_H

#define MSR_EFER                        0xc0000080 /* Extended Feature register */
#define _EFER_LME                       8  /* Long mode enable */
#define EFER_LME                        (1<<_EFER_LME)

#define MSR_FS_BASE                     0xc0000100
#define MSR_GS_BASE                     0xc0000101
#define MSR_SHADOW_GS_BASE              0xc0000102

#endif /* XFT_X86_MSR_INDEX_H */

/*
 * Local variables:
 * mode: C
 * c-file-style: "BSD"
 * c-basic-offset: 4
 * tab-width: 4
 * indent-tabs-mode: nil
 * End:
 */

