arm_comm = common/arm_arch_interface.c common/armcopro.c common/armemu.c common/arminit.c common/armmmu.c common/armos.c common/armsupp.c common/armvirt.c common/thumbemu.c common/arm_module.c common/arm11_core.c common/skyeye_ram.c common/cortex_a9_core.c
arm_mmu = common/mmu/arm7100_mmu.c common/mmu/arm920t_mmu.c common/mmu/arm926ejs_mmu.c  common/mmu/arm1176jzf_s_mmu.c common/mmu/cache.c common/mmu/maverick.c common/mmu/rb.c common/mmu/sa_mmu.c common/mmu/tlb.c common/mmu/wb.c common/mmu/xscale_copro.c common/mmu/cortex_a9_mmu.c
arm_dbct = dbct/arm2x86.c dbct/arm2x86_coproc.c dbct/arm2x86_dp.c dbct/arm2x86_mem.c dbct/arm2x86_movl.c dbct/arm2x86_mul.c dbct/arm2x86_other.c dbct/arm2x86_psr.c dbct/arm2x86_shift.c dbct/arm2x86_test.c dbct/tb.c 
arm_mach = \
mach/skyeye_mach_lpc.c
arm_dyncom = dyncom/arm_dyncom_interface.cpp dyncom/arm_disasm.cpp dyncom/arm_dyncom_translate.cpp dyncom/arm_dyncom_run.cpp dyncom/arm_dyncom_dec.cpp dyncom/arm_dyncom_mmu.cpp dyncom/arm_dyncom_parallel.cpp dyncom/arm_dyncom_interpreter.cpp dyncom/arm_dyncom_thumb.cpp dyncom/arm_step_diff.cpp dyncom/arm_dyncom_memory.cpp 
arm_vfp = common/vfp/vfp.c common/vfp/vfpsingle.c common/vfp/vfpdouble.c
libarm_la_SOURCES = $(arm_comm) $(arm_mmu) $(arm_mach) $(arm_vfp)

if LLVM_EXIST
libarm_la_SOURCES += $(arm_dyncom)
endif

if DBCT
libarm_la_SOURCES += $(arm_dbct)
endif
libarm_la_LDFLAGS = -module
if WIN32
libarm_la_LDFLAGS += -no-undefined -shared -module  -Xlinker -L../../common/.libs/ -Xlinker -lcommon -Xlinker -lmsys-1.0 -Xlinker -lmsvcrt -Xlinker -lmsys-1.0 -Xlinker -lkernel32 -Xlinker -lole32 -Xlinker -lkernel32 -Xlinker -lgdi32 -Xlinker -luuid -Xlinker -luser32  -Xlinker -lshell32 -Xlinker --export-all-symbol
endif

pkglib_LTLIBRARIES = libarm.la
#noinst_LIBRARIES =      libarm.a
DEFS = -DMODET -g -D_FILE_OFFSET_BITS=64 -DSTANDALONE -DDEFAULT_INLINE=0 -DNO_LCD @COMMON_CFLAGS@
if LLVM_EXIST
DEFS += -DLLVM_EXIST
endif

libarm_la_LIBADD = armemu32.lo
INCLUDES = -I$(top_srcdir)/arch/arm/common -I$(top_srcdir)/arch/arm/mach/ -I$(top_srcdir)/common/dyncom/ `llvm-config --cflags` @COMMON_INCLUDES@ -I$(top_srcdir)/third-party/include/
armemu32.lo:common/armemu.c armemu.lo
	$(LIBTOOL) --tag=CC --mode=compile $(CC) -DMODE32 $(DEFS) $(INCLUDES) -g -MT armemu32.lo -MD -MP -MF .deps/armemu32.Tpo -c -o armemu32.lo `test -f '$(srcdir)/common/armemu.c' || echo `$(srcdir)/common/armemu.c
#	$(CC) -DMODE32 $(DEFS) $(INCLUDES) common/armemu.c -c -o $@
