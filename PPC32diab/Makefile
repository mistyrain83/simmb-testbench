# Wind River Workbench generated Makefile.
# Do not edit!!!
#
# The file ".wrmakefile" is the template used by the Wind River Workbench to
# generate the makefiles of this project. Add user-specific build targets and
# make rules only(!) in this project's ".wrmakefile" file. These will then be
# automatically dumped into the makefiles.

WIND_HOME := $(subst \,/,$(WIND_HOME))
WIND_BASE := $(subst \,/,$(WIND_BASE))
WIND_USR := $(subst \,/,$(WIND_USR))

all : pre_build main_all post_build

_clean ::
	@echo "make: removing targets and objects of `pwd`"

TRACE=0
TRACEON=$(TRACE:0=@)
TRACE_FLAG=$(TRACEON:1=)

MAKEFILE := Makefile

FLEXIBLE_BUILD := 1

BUILD_SPEC = PPC32diab
DEBUG_MODE = 1
ifeq ($(DEBUG_MODE),1)
MODE_DIR := Debug
else
MODE_DIR := NonDebug
endif
OBJ_DIR := .
PRJ_ROOT_DIR := D:/workspace/simmb-testbench
WS_ROOT_DIR := D:/workspace



#Global Build Macros
PROJECT_TYPE = DKM
DEFINES = 
EXPAND_DBG = 0


#BuildSpec specific Build Macros
VX_CPU_FAMILY = ppc
CPU = PPC32
TOOL_FAMILY = diab
TOOL = diab
TOOL_PATH = 
CC_ARCH_SPEC = -tPPCFH:vxworks66 -Xstmw-slow -DPPC32_fp60x -Xstsw-slow
LIBPATH = 
LIBS = 

IDE_INCLUDES = -I$(WIND_BASE)/target/h -I$(WIND_BASE)/target/h/wrn/coreip 

IDE_LIBRARIES = 



#BuildTool flags
ifeq ($(DEBUG_MODE),1)
DEBUGFLAGS_C-Compiler = -g
DEBUGFLAGS_C++-Compiler = -g
DEBUGFLAGS_Linker = -g
DEBUGFLAGS_Partial-Image-Linker = 
DEBUGFLAGS_Librarian = 
DEBUGFLAGS_Assembler = -g
else
DEBUGFLAGS_C-Compiler = -XO -Xsize-opt
DEBUGFLAGS_C++-Compiler = -XO -Xsize-opt
DEBUGFLAGS_Linker = -XO -Xsize-opt
DEBUGFLAGS_Partial-Image-Linker = 
DEBUGFLAGS_Librarian = 
DEBUGFLAGS_Assembler = -XO -Xsize-opt
endif


#Project Targets
PROJECT_TARGETS = simmb-testbench/$(MODE_DIR)/simmb-testbench.out


#Rules

# simmb-testbench
ifeq ($(DEBUG_MODE),1)
simmb-testbench/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -g
simmb-testbench/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -g
simmb-testbench/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -g
simmb-testbench/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
simmb-testbench/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
simmb-testbench/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -g
else
simmb-testbench/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -XO -Xsize-opt
simmb-testbench/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -XO -Xsize-opt
simmb-testbench/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -XO -Xsize-opt
simmb-testbench/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
simmb-testbench/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
simmb-testbench/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -XO -Xsize-opt
endif
simmb-testbench/$(MODE_DIR)/% : IDE_INCLUDES = -I$(WIND_BASE)/target/h -I$(WIND_BASE)/target/h/wrn/coreip 
simmb-testbench/$(MODE_DIR)/% : IDE_LIBRARIES = 
simmb-testbench/$(MODE_DIR)/% : PROJECT_TYPE = DKM
simmb-testbench/$(MODE_DIR)/% : DEFINES = 
simmb-testbench/$(MODE_DIR)/% : EXPAND_DBG = 0
simmb-testbench/$(MODE_DIR)/% : VX_CPU_FAMILY = ppc
simmb-testbench/$(MODE_DIR)/% : CPU = PPC32
simmb-testbench/$(MODE_DIR)/% : TOOL_FAMILY = diab
simmb-testbench/$(MODE_DIR)/% : TOOL = diab
simmb-testbench/$(MODE_DIR)/% : TOOL_PATH = 
simmb-testbench/$(MODE_DIR)/% : CC_ARCH_SPEC = -tPPCFH:vxworks66 -Xstmw-slow -DPPC32_fp60x -Xstsw-slow
simmb-testbench/$(MODE_DIR)/% : LIBPATH = 
simmb-testbench/$(MODE_DIR)/% : LIBS = 
simmb-testbench/$(MODE_DIR)/% : OBJ_DIR := simmb-testbench/$(MODE_DIR)

simmb-testbench/$(MODE_DIR)/Objects/simmb-testbench/src/BTM.o : D:/workspace/simmb-testbench/src/BTM.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)dcc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -W:c:,-Xclib-optim-off -Xansi -Xlocal-data-area-static-only  -Xforce-declarations   -Xmake-dependency=0xd -Xcode-absolute-far $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


simmb-testbench/$(MODE_DIR)/Objects/simmb-testbench/src/doppler.o : D:/workspace/simmb-testbench/src/doppler.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)dcc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -W:c:,-Xclib-optim-off -Xansi -Xlocal-data-area-static-only  -Xforce-declarations   -Xmake-dependency=0xd -Xcode-absolute-far $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


simmb-testbench/$(MODE_DIR)/Objects/simmb-testbench/src/fpga.o : D:/workspace/simmb-testbench/src/fpga.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)dcc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -W:c:,-Xclib-optim-off -Xansi -Xlocal-data-area-static-only  -Xforce-declarations   -Xmake-dependency=0xd -Xcode-absolute-far $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


simmb-testbench/$(MODE_DIR)/Objects/simmb-testbench/src/lib.o : D:/workspace/simmb-testbench/src/lib.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)dcc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -W:c:,-Xclib-optim-off -Xansi -Xlocal-data-area-static-only  -Xforce-declarations   -Xmake-dependency=0xd -Xcode-absolute-far $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


simmb-testbench/$(MODE_DIR)/Objects/simmb-testbench/src/sim.o : D:/workspace/simmb-testbench/src/sim.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)dcc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -W:c:,-Xclib-optim-off -Xansi -Xlocal-data-area-static-only  -Xforce-declarations   -Xmake-dependency=0xd -Xcode-absolute-far $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


simmb-testbench/$(MODE_DIR)/Objects/simmb-testbench/src/speed.o : D:/workspace/simmb-testbench/src/speed.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)dcc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -W:c:,-Xclib-optim-off -Xansi -Xlocal-data-area-static-only  -Xforce-declarations   -Xmake-dependency=0xd -Xcode-absolute-far $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


simmb-testbench/$(MODE_DIR)/Objects/simmb-testbench/src/tms.o : D:/workspace/simmb-testbench/src/tms.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)dcc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -W:c:,-Xclib-optim-off -Xansi -Xlocal-data-area-static-only  -Xforce-declarations   -Xmake-dependency=0xd -Xcode-absolute-far $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


simmb-testbench/$(MODE_DIR)/Objects/simmb-testbench/src/udp.o : D:/workspace/simmb-testbench/src/udp.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)dcc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -W:c:,-Xclib-optim-off -Xansi -Xlocal-data-area-static-only  -Xforce-declarations   -Xmake-dependency=0xd -Xcode-absolute-far $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


OBJECTS_simmb-testbench = simmb-testbench/$(MODE_DIR)/Objects/simmb-testbench/src/BTM.o \
	 simmb-testbench/$(MODE_DIR)/Objects/simmb-testbench/src/doppler.o \
	 simmb-testbench/$(MODE_DIR)/Objects/simmb-testbench/src/fpga.o \
	 simmb-testbench/$(MODE_DIR)/Objects/simmb-testbench/src/lib.o \
	 simmb-testbench/$(MODE_DIR)/Objects/simmb-testbench/src/sim.o \
	 simmb-testbench/$(MODE_DIR)/Objects/simmb-testbench/src/speed.o \
	 simmb-testbench/$(MODE_DIR)/Objects/simmb-testbench/src/tms.o \
	 simmb-testbench/$(MODE_DIR)/Objects/simmb-testbench/src/udp.o

simmb-testbench/$(MODE_DIR)/simmb-testbench.out : $(OBJECTS_simmb-testbench)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@";rm -f "$@";ddump -Ng $(OBJECTS_simmb-testbench) $(IDE_LIBRARIES) | tclsh $(WIND_BASE)/host/resource/hutils/tcl/munch.tcl -c ppc > $(OBJ_DIR)/ctdt.c; $(TOOL_PATH)dcc $(DEBUGFLAGS_Linker) $(CC_ARCH_SPEC) -Xdollar-in-ident -Xforce-declarations  $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES)  -o $(OBJ_DIR)/ctdt.o -c $(OBJ_DIR)/ctdt.c; $(TOOL_PATH)dld -tPPCFH:vxworks66 -X -r5 -r4 -o "$@" $(OBJ_DIR)/ctdt.o $(OBJECTS_simmb-testbench) $(IDE_LIBRARIES) $(LIBPATH) $(LIBS) $(ADDED_LIBPATH) $(ADDED_LIBS) && if [ "$(EXPAND_DBG)" = "1" ]; then plink "$@";fi

simmb-testbench/$(MODE_DIR)/simmb-testbench_compile_file : $(FILE) ;

_clean :: simmb-testbench/$(MODE_DIR)/simmb-testbench_clean

simmb-testbench/$(MODE_DIR)/simmb-testbench_clean : 
	$(TRACE_FLAG)if [ -d "simmb-testbench" ]; then cd "simmb-testbench"; rm -rf $(MODE_DIR); fi

DEP_FILES := simmb-testbench/$(MODE_DIR)/Objects/simmb-testbench/src/BTM.d simmb-testbench/$(MODE_DIR)/Objects/simmb-testbench/src/doppler.d simmb-testbench/$(MODE_DIR)/Objects/simmb-testbench/src/fpga.d \
	 simmb-testbench/$(MODE_DIR)/Objects/simmb-testbench/src/lib.d simmb-testbench/$(MODE_DIR)/Objects/simmb-testbench/src/sim.d simmb-testbench/$(MODE_DIR)/Objects/simmb-testbench/src/speed.d \
	 simmb-testbench/$(MODE_DIR)/Objects/simmb-testbench/src/tms.d simmb-testbench/$(MODE_DIR)/Objects/simmb-testbench/src/udp.d
-include $(DEP_FILES)



-include $(PRJ_ROOT_DIR)/*.makefile

-include *.makefile

main_all : external_build $(PROJECT_TARGETS)
	@echo "make: built targets of `pwd`"

# entry point for extending the build
external_build ::
	@echo ""

# main entry point for pre processing prior to the build
pre_build :: $(PRE_BUILD_STEP) generate_sources
	@echo ""

# entry point for generating sources prior to the build
generate_sources ::
	@echo ""

# main entry point for post processing after the build
post_build :: $(POST_BUILD_STEP) deploy_output
	@echo ""

# entry point for deploying output after the build
deploy_output ::
	@echo ""

clean :: external_clean $(CLEAN_STEP) _clean

# entry point for extending the build clean
external_clean ::
	@echo ""
