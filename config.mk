##############################################################################
# Project Configuration
#

PROJECT := morse
PROJECT_TYPE := osc

##############################################################################
# Sources
#

# C sources
UCSRC = header.c

# DasBeep is header-only, no .c file needed

# C++ sources
UCXXSRC = unit.cc

# List ASM source files here
ASMSRC =

ASMXSRC =

##############################################################################
# Include Paths
#

UINCDIR  = /rfx/shared

##############################################################################
# Library Paths
#

ULIBDIR =

##############################################################################
# Libraries
#

ULIBS  = -lm
ULIBS += -lc

##############################################################################
# Macros
#

UDEFS =
