#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/Alex60.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/Alex60.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=
else
COMPARISON_BUILD=
endif

ifdef SUB_IMAGE_ADDRESS

else
SUB_IMAGE_ADDRESS_COMMAND=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=main.c DIO.c leds.c buttons.c keypad.c kit_keypad.c _7seg.c mlcd8.c mlcd4.c ADC.c lm35.c TIMER0.c EXT_INT.c TIMER2.c TIMER1.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/main.o ${OBJECTDIR}/DIO.o ${OBJECTDIR}/leds.o ${OBJECTDIR}/buttons.o ${OBJECTDIR}/keypad.o ${OBJECTDIR}/kit_keypad.o ${OBJECTDIR}/_7seg.o ${OBJECTDIR}/mlcd8.o ${OBJECTDIR}/mlcd4.o ${OBJECTDIR}/ADC.o ${OBJECTDIR}/lm35.o ${OBJECTDIR}/TIMER0.o ${OBJECTDIR}/EXT_INT.o ${OBJECTDIR}/TIMER2.o ${OBJECTDIR}/TIMER1.o
POSSIBLE_DEPFILES=${OBJECTDIR}/main.o.d ${OBJECTDIR}/DIO.o.d ${OBJECTDIR}/leds.o.d ${OBJECTDIR}/buttons.o.d ${OBJECTDIR}/keypad.o.d ${OBJECTDIR}/kit_keypad.o.d ${OBJECTDIR}/_7seg.o.d ${OBJECTDIR}/mlcd8.o.d ${OBJECTDIR}/mlcd4.o.d ${OBJECTDIR}/ADC.o.d ${OBJECTDIR}/lm35.o.d ${OBJECTDIR}/TIMER0.o.d ${OBJECTDIR}/EXT_INT.o.d ${OBJECTDIR}/TIMER2.o.d ${OBJECTDIR}/TIMER1.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/main.o ${OBJECTDIR}/DIO.o ${OBJECTDIR}/leds.o ${OBJECTDIR}/buttons.o ${OBJECTDIR}/keypad.o ${OBJECTDIR}/kit_keypad.o ${OBJECTDIR}/_7seg.o ${OBJECTDIR}/mlcd8.o ${OBJECTDIR}/mlcd4.o ${OBJECTDIR}/ADC.o ${OBJECTDIR}/lm35.o ${OBJECTDIR}/TIMER0.o ${OBJECTDIR}/EXT_INT.o ${OBJECTDIR}/TIMER2.o ${OBJECTDIR}/TIMER1.o

# Source Files
SOURCEFILES=main.c DIO.c leds.c buttons.c keypad.c kit_keypad.c _7seg.c mlcd8.c mlcd4.c ADC.c lm35.c TIMER0.c EXT_INT.c TIMER2.c TIMER1.c



CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/Alex60.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=ATmega32A
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/main.o: main.c  .generated_files/flags/default/ec25b7f7f6ed075eacafa6a4b730b27e22ea7b34 .generated_files/flags/default/2f9e58fd8ce1a2611b0e0fd33168db129b9285f3
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/main.o.d" -MT "${OBJECTDIR}/main.o.d" -MT ${OBJECTDIR}/main.o -o ${OBJECTDIR}/main.o main.c 
	
${OBJECTDIR}/DIO.o: DIO.c  .generated_files/flags/default/86d92170cfcd9db35b3addf8349ef70df703b74f .generated_files/flags/default/2f9e58fd8ce1a2611b0e0fd33168db129b9285f3
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/DIO.o.d 
	@${RM} ${OBJECTDIR}/DIO.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/DIO.o.d" -MT "${OBJECTDIR}/DIO.o.d" -MT ${OBJECTDIR}/DIO.o -o ${OBJECTDIR}/DIO.o DIO.c 
	
${OBJECTDIR}/leds.o: leds.c  .generated_files/flags/default/60436f009aed01f558aa25f2eb3b4c31363eca7f .generated_files/flags/default/2f9e58fd8ce1a2611b0e0fd33168db129b9285f3
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/leds.o.d 
	@${RM} ${OBJECTDIR}/leds.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/leds.o.d" -MT "${OBJECTDIR}/leds.o.d" -MT ${OBJECTDIR}/leds.o -o ${OBJECTDIR}/leds.o leds.c 
	
${OBJECTDIR}/buttons.o: buttons.c  .generated_files/flags/default/2c435f63600dfefcbf4e5bf4de8ee622de11b133 .generated_files/flags/default/2f9e58fd8ce1a2611b0e0fd33168db129b9285f3
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/buttons.o.d 
	@${RM} ${OBJECTDIR}/buttons.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/buttons.o.d" -MT "${OBJECTDIR}/buttons.o.d" -MT ${OBJECTDIR}/buttons.o -o ${OBJECTDIR}/buttons.o buttons.c 
	
${OBJECTDIR}/keypad.o: keypad.c  .generated_files/flags/default/85752377bb4a1c915ba41d69ce8fedbfccde7008 .generated_files/flags/default/2f9e58fd8ce1a2611b0e0fd33168db129b9285f3
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/keypad.o.d 
	@${RM} ${OBJECTDIR}/keypad.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/keypad.o.d" -MT "${OBJECTDIR}/keypad.o.d" -MT ${OBJECTDIR}/keypad.o -o ${OBJECTDIR}/keypad.o keypad.c 
	
${OBJECTDIR}/kit_keypad.o: kit_keypad.c  .generated_files/flags/default/6c1222c437d1ace36be5ff2a65f513c3e7ca6f67 .generated_files/flags/default/2f9e58fd8ce1a2611b0e0fd33168db129b9285f3
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/kit_keypad.o.d 
	@${RM} ${OBJECTDIR}/kit_keypad.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/kit_keypad.o.d" -MT "${OBJECTDIR}/kit_keypad.o.d" -MT ${OBJECTDIR}/kit_keypad.o -o ${OBJECTDIR}/kit_keypad.o kit_keypad.c 
	
${OBJECTDIR}/_7seg.o: _7seg.c  .generated_files/flags/default/1d92cd4bd2a641e9a2671c3c18fef5c8a721ef5b .generated_files/flags/default/2f9e58fd8ce1a2611b0e0fd33168db129b9285f3
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/_7seg.o.d 
	@${RM} ${OBJECTDIR}/_7seg.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/_7seg.o.d" -MT "${OBJECTDIR}/_7seg.o.d" -MT ${OBJECTDIR}/_7seg.o -o ${OBJECTDIR}/_7seg.o _7seg.c 
	
${OBJECTDIR}/mlcd8.o: mlcd8.c  .generated_files/flags/default/471e809ddf6613348f615e1b5c4436b41fcd2069 .generated_files/flags/default/2f9e58fd8ce1a2611b0e0fd33168db129b9285f3
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/mlcd8.o.d 
	@${RM} ${OBJECTDIR}/mlcd8.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/mlcd8.o.d" -MT "${OBJECTDIR}/mlcd8.o.d" -MT ${OBJECTDIR}/mlcd8.o -o ${OBJECTDIR}/mlcd8.o mlcd8.c 
	
${OBJECTDIR}/mlcd4.o: mlcd4.c  .generated_files/flags/default/aa5dd171cbbd5815c03b1859342da1453812cac4 .generated_files/flags/default/2f9e58fd8ce1a2611b0e0fd33168db129b9285f3
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/mlcd4.o.d 
	@${RM} ${OBJECTDIR}/mlcd4.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/mlcd4.o.d" -MT "${OBJECTDIR}/mlcd4.o.d" -MT ${OBJECTDIR}/mlcd4.o -o ${OBJECTDIR}/mlcd4.o mlcd4.c 
	
${OBJECTDIR}/ADC.o: ADC.c  .generated_files/flags/default/cf703ba3b42c2821f000ca980ca3a6bb63fb57c7 .generated_files/flags/default/2f9e58fd8ce1a2611b0e0fd33168db129b9285f3
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/ADC.o.d 
	@${RM} ${OBJECTDIR}/ADC.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/ADC.o.d" -MT "${OBJECTDIR}/ADC.o.d" -MT ${OBJECTDIR}/ADC.o -o ${OBJECTDIR}/ADC.o ADC.c 
	
${OBJECTDIR}/lm35.o: lm35.c  .generated_files/flags/default/88cbfbffcef8dcff192e00b65c1828728a00795f .generated_files/flags/default/2f9e58fd8ce1a2611b0e0fd33168db129b9285f3
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/lm35.o.d 
	@${RM} ${OBJECTDIR}/lm35.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/lm35.o.d" -MT "${OBJECTDIR}/lm35.o.d" -MT ${OBJECTDIR}/lm35.o -o ${OBJECTDIR}/lm35.o lm35.c 
	
${OBJECTDIR}/TIMER0.o: TIMER0.c  .generated_files/flags/default/f7f4c4b8e254db5aefd13866bff92ed0dcb817fe .generated_files/flags/default/2f9e58fd8ce1a2611b0e0fd33168db129b9285f3
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/TIMER0.o.d 
	@${RM} ${OBJECTDIR}/TIMER0.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/TIMER0.o.d" -MT "${OBJECTDIR}/TIMER0.o.d" -MT ${OBJECTDIR}/TIMER0.o -o ${OBJECTDIR}/TIMER0.o TIMER0.c 
	
${OBJECTDIR}/EXT_INT.o: EXT_INT.c  .generated_files/flags/default/a78f2f6c55ad2e3bba514ef1d05a80efe5664f9b .generated_files/flags/default/2f9e58fd8ce1a2611b0e0fd33168db129b9285f3
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/EXT_INT.o.d 
	@${RM} ${OBJECTDIR}/EXT_INT.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/EXT_INT.o.d" -MT "${OBJECTDIR}/EXT_INT.o.d" -MT ${OBJECTDIR}/EXT_INT.o -o ${OBJECTDIR}/EXT_INT.o EXT_INT.c 
	
${OBJECTDIR}/TIMER2.o: TIMER2.c  .generated_files/flags/default/30ef579cb1c160376f8a6311a6569d9a2e1a54c9 .generated_files/flags/default/2f9e58fd8ce1a2611b0e0fd33168db129b9285f3
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/TIMER2.o.d 
	@${RM} ${OBJECTDIR}/TIMER2.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/TIMER2.o.d" -MT "${OBJECTDIR}/TIMER2.o.d" -MT ${OBJECTDIR}/TIMER2.o -o ${OBJECTDIR}/TIMER2.o TIMER2.c 
	
${OBJECTDIR}/TIMER1.o: TIMER1.c  .generated_files/flags/default/acb44e7bc986efe431b853e66efac1c3e6a18fec .generated_files/flags/default/2f9e58fd8ce1a2611b0e0fd33168db129b9285f3
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/TIMER1.o.d 
	@${RM} ${OBJECTDIR}/TIMER1.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/TIMER1.o.d" -MT "${OBJECTDIR}/TIMER1.o.d" -MT ${OBJECTDIR}/TIMER1.o -o ${OBJECTDIR}/TIMER1.o TIMER1.c 
	
else
${OBJECTDIR}/main.o: main.c  .generated_files/flags/default/24312582250579ef564cf5178ed9ef8f2a9afa89 .generated_files/flags/default/2f9e58fd8ce1a2611b0e0fd33168db129b9285f3
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/main.o.d" -MT "${OBJECTDIR}/main.o.d" -MT ${OBJECTDIR}/main.o -o ${OBJECTDIR}/main.o main.c 
	
${OBJECTDIR}/DIO.o: DIO.c  .generated_files/flags/default/bf281ad53bc472149995abeb00a9ad4eb3fb651 .generated_files/flags/default/2f9e58fd8ce1a2611b0e0fd33168db129b9285f3
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/DIO.o.d 
	@${RM} ${OBJECTDIR}/DIO.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/DIO.o.d" -MT "${OBJECTDIR}/DIO.o.d" -MT ${OBJECTDIR}/DIO.o -o ${OBJECTDIR}/DIO.o DIO.c 
	
${OBJECTDIR}/leds.o: leds.c  .generated_files/flags/default/3427f3d5133ff2ab2aca18a055d70753a60eaf2b .generated_files/flags/default/2f9e58fd8ce1a2611b0e0fd33168db129b9285f3
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/leds.o.d 
	@${RM} ${OBJECTDIR}/leds.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/leds.o.d" -MT "${OBJECTDIR}/leds.o.d" -MT ${OBJECTDIR}/leds.o -o ${OBJECTDIR}/leds.o leds.c 
	
${OBJECTDIR}/buttons.o: buttons.c  .generated_files/flags/default/68ed1db7c07e8575c1e98d7c47826d8e24a4d0fb .generated_files/flags/default/2f9e58fd8ce1a2611b0e0fd33168db129b9285f3
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/buttons.o.d 
	@${RM} ${OBJECTDIR}/buttons.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/buttons.o.d" -MT "${OBJECTDIR}/buttons.o.d" -MT ${OBJECTDIR}/buttons.o -o ${OBJECTDIR}/buttons.o buttons.c 
	
${OBJECTDIR}/keypad.o: keypad.c  .generated_files/flags/default/ea61f29b0af26ed8873bb86c7f9b4f9c4ef4d4e7 .generated_files/flags/default/2f9e58fd8ce1a2611b0e0fd33168db129b9285f3
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/keypad.o.d 
	@${RM} ${OBJECTDIR}/keypad.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/keypad.o.d" -MT "${OBJECTDIR}/keypad.o.d" -MT ${OBJECTDIR}/keypad.o -o ${OBJECTDIR}/keypad.o keypad.c 
	
${OBJECTDIR}/kit_keypad.o: kit_keypad.c  .generated_files/flags/default/31b4aac8fe41d0f835aa1d4c125f7c388a157497 .generated_files/flags/default/2f9e58fd8ce1a2611b0e0fd33168db129b9285f3
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/kit_keypad.o.d 
	@${RM} ${OBJECTDIR}/kit_keypad.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/kit_keypad.o.d" -MT "${OBJECTDIR}/kit_keypad.o.d" -MT ${OBJECTDIR}/kit_keypad.o -o ${OBJECTDIR}/kit_keypad.o kit_keypad.c 
	
${OBJECTDIR}/_7seg.o: _7seg.c  .generated_files/flags/default/b3c421a6d3f4ca4dd689dbf2678ff0dd8cdd9eef .generated_files/flags/default/2f9e58fd8ce1a2611b0e0fd33168db129b9285f3
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/_7seg.o.d 
	@${RM} ${OBJECTDIR}/_7seg.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/_7seg.o.d" -MT "${OBJECTDIR}/_7seg.o.d" -MT ${OBJECTDIR}/_7seg.o -o ${OBJECTDIR}/_7seg.o _7seg.c 
	
${OBJECTDIR}/mlcd8.o: mlcd8.c  .generated_files/flags/default/9ef6fc2e1fbe00d6fbe698d7ea2ab7d7d0418a07 .generated_files/flags/default/2f9e58fd8ce1a2611b0e0fd33168db129b9285f3
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/mlcd8.o.d 
	@${RM} ${OBJECTDIR}/mlcd8.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/mlcd8.o.d" -MT "${OBJECTDIR}/mlcd8.o.d" -MT ${OBJECTDIR}/mlcd8.o -o ${OBJECTDIR}/mlcd8.o mlcd8.c 
	
${OBJECTDIR}/mlcd4.o: mlcd4.c  .generated_files/flags/default/18c9aa0102ea18dbe0cfc529b89280fc6d298b35 .generated_files/flags/default/2f9e58fd8ce1a2611b0e0fd33168db129b9285f3
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/mlcd4.o.d 
	@${RM} ${OBJECTDIR}/mlcd4.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/mlcd4.o.d" -MT "${OBJECTDIR}/mlcd4.o.d" -MT ${OBJECTDIR}/mlcd4.o -o ${OBJECTDIR}/mlcd4.o mlcd4.c 
	
${OBJECTDIR}/ADC.o: ADC.c  .generated_files/flags/default/bba021d06fe05482093fcaeddc5aa61a13245469 .generated_files/flags/default/2f9e58fd8ce1a2611b0e0fd33168db129b9285f3
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/ADC.o.d 
	@${RM} ${OBJECTDIR}/ADC.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/ADC.o.d" -MT "${OBJECTDIR}/ADC.o.d" -MT ${OBJECTDIR}/ADC.o -o ${OBJECTDIR}/ADC.o ADC.c 
	
${OBJECTDIR}/lm35.o: lm35.c  .generated_files/flags/default/382263ba49f5df36e7ee114b85f769cbf0852979 .generated_files/flags/default/2f9e58fd8ce1a2611b0e0fd33168db129b9285f3
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/lm35.o.d 
	@${RM} ${OBJECTDIR}/lm35.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/lm35.o.d" -MT "${OBJECTDIR}/lm35.o.d" -MT ${OBJECTDIR}/lm35.o -o ${OBJECTDIR}/lm35.o lm35.c 
	
${OBJECTDIR}/TIMER0.o: TIMER0.c  .generated_files/flags/default/df2b4e8b49eaf70e5c0e255b745962376d25791a .generated_files/flags/default/2f9e58fd8ce1a2611b0e0fd33168db129b9285f3
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/TIMER0.o.d 
	@${RM} ${OBJECTDIR}/TIMER0.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/TIMER0.o.d" -MT "${OBJECTDIR}/TIMER0.o.d" -MT ${OBJECTDIR}/TIMER0.o -o ${OBJECTDIR}/TIMER0.o TIMER0.c 
	
${OBJECTDIR}/EXT_INT.o: EXT_INT.c  .generated_files/flags/default/887a3b380f737a152f61ba6fa1565f45c3bfaec4 .generated_files/flags/default/2f9e58fd8ce1a2611b0e0fd33168db129b9285f3
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/EXT_INT.o.d 
	@${RM} ${OBJECTDIR}/EXT_INT.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/EXT_INT.o.d" -MT "${OBJECTDIR}/EXT_INT.o.d" -MT ${OBJECTDIR}/EXT_INT.o -o ${OBJECTDIR}/EXT_INT.o EXT_INT.c 
	
${OBJECTDIR}/TIMER2.o: TIMER2.c  .generated_files/flags/default/a4b201f8e2468d7406dbfe0b0cddd30b3010d937 .generated_files/flags/default/2f9e58fd8ce1a2611b0e0fd33168db129b9285f3
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/TIMER2.o.d 
	@${RM} ${OBJECTDIR}/TIMER2.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/TIMER2.o.d" -MT "${OBJECTDIR}/TIMER2.o.d" -MT ${OBJECTDIR}/TIMER2.o -o ${OBJECTDIR}/TIMER2.o TIMER2.c 
	
${OBJECTDIR}/TIMER1.o: TIMER1.c  .generated_files/flags/default/5da2f2ba283c07ec931030e89d985fa8c1e8171 .generated_files/flags/default/2f9e58fd8ce1a2611b0e0fd33168db129b9285f3
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/TIMER1.o.d 
	@${RM} ${OBJECTDIR}/TIMER1.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/TIMER1.o.d" -MT "${OBJECTDIR}/TIMER1.o.d" -MT ${OBJECTDIR}/TIMER1.o -o ${OBJECTDIR}/TIMER1.o TIMER1.c 
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/Alex60.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=dist/${CND_CONF}/${IMAGE_TYPE}/Alex60.${IMAGE_TYPE}.map  -D__DEBUG=1  -DXPRJ_default=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1   -mdfp="${DFP_DIR}/xc8"   -gdwarf-2 -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -gdwarf-3     $(COMPARISON_BUILD) -Wl,--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml -o dist/${CND_CONF}/${IMAGE_TYPE}/Alex60.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  -o dist/${CND_CONF}/${IMAGE_TYPE}/Alex60.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -Wl,--start-group  -Wl,-lm -Wl,--end-group  -Wl,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1
	@${RM} dist/${CND_CONF}/${IMAGE_TYPE}/Alex60.${IMAGE_TYPE}.hex 
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/Alex60.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=dist/${CND_CONF}/${IMAGE_TYPE}/Alex60.${IMAGE_TYPE}.map  -DXPRJ_default=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -gdwarf-3     $(COMPARISON_BUILD) -Wl,--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml -o dist/${CND_CONF}/${IMAGE_TYPE}/Alex60.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  -o dist/${CND_CONF}/${IMAGE_TYPE}/Alex60.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -Wl,--start-group  -Wl,-lm -Wl,--end-group 
	${MP_CC_DIR}\\avr-objcopy -O ihex "dist/${CND_CONF}/${IMAGE_TYPE}/Alex60.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}" "dist/${CND_CONF}/${IMAGE_TYPE}/Alex60.${IMAGE_TYPE}.hex"
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/default
	${RM} -r dist/default

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
