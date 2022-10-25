########################################################################
#
#	AutoMod Makefile
#	AutoMod Licensee Confidential
#	Copyright (c) 2007-2012 Applied Materials. All rights reserved.
#	Any and all distribution without express written consent is prohibited.
#
#	This makefile was generated with AutoMod 12.6.1, Build: 12.6.1.12
#
#	This makefile was designed to be used with nmake 10.0 (VS2010).
#	Other makefiles can be included by reference to build other libraries
#	along with your model. This makefile will look for a file called 'model.mak'
#	in the model directory (modelname.dir) and include it if it exists. 
#	See the Microsoft documentation for the nmake utility for more information 
#	on how you can write makefiles,	or use Visual Studio to generate them for you.
#
#	There are a few macros in the template for your ease of use:
#	USER_OBJS : a list of objects to be linked in to the final model. These objects will be linked in last.
#	USER_TARGETS : a list of targets to be built when the model is built. The model will be built last.
#	
#
#########################################################################

!IF EXIST ("model.mak")
!	include <model.mak>
!ENDIF # IF EXIST ("model.mak")

!include <$(ASI)\lib\common.mak>

TARGET		=drive_in
DLL_NAME	=$(TARGET)$(DLL_EXTENSION).dll
!IF DEFINED (DEBUG_MSG)
!	MESSAGE Processing $(DEBUG_MSG) build commands for the model $(TARGET)...
!ELSE
!	MESSAGE Processing build commands for the model $(TARGET)...
!ENDIF

GROUP_1 = "drive_in~model.obj" \
	"drive_in~init1.obj" \
	"p_init_read_inputa.obj" \
	"p_persona.obj" \
	"p_cara.obj" \
	"p_menua.obj" \
	"p_menu_generatora.obj" \
	"p_order_rooma.obj" \
	"p_init_stocka.obj" \
	"p_stocka.obj" \
	"p_inita.obj" \
	"p_menul.obj" \
	"p_init_outputa.obj"

OBJECTS =  $(GROUP_1) 
OBJ_MODULES	= $(OBJECTS) $(USER_OBJS)
SOURCE_FILES	= $(OBJECTS:.obj=.c)

MODELNAME	=..\$(TARGET).exe

#	The model should always be the first target...
model : $(USER_TARGETS) $(DLL_NAME) $(MODELNAME)
	
$(MODELNAME) : $(DLL_NAME)
	@ECHO Generating $(TARGET).exe...
	@COPY $(RUNMODEL) $(MODELNAME)
	
#	Model Files and objects

"drive_in~model.obj" : "drive_in~model.c" $(MODEL_HEADERS)

"drive_in~init1.obj" : "drive_in~init1.c" $(MODEL_HEADERS)

"p_init_read_inputa.obj" : "p_init_read_inputa.c" $(MODEL_HEADERS)
	$(CC) $(C_OPTIONS) "p_init_read_inputa.c"

"p_persona.obj" : "p_persona.c" $(MODEL_HEADERS)
	$(CC) $(C_OPTIONS) "p_persona.c"

"p_cara.obj" : "p_cara.c" $(MODEL_HEADERS)
	$(CC) $(C_OPTIONS) "p_cara.c"

"p_menua.obj" : "p_menua.c" $(MODEL_HEADERS)
	$(CC) $(C_OPTIONS) "p_menua.c"

"p_menu_generatora.obj" : "p_menu_generatora.c" $(MODEL_HEADERS)
	$(CC) $(C_OPTIONS) "p_menu_generatora.c"

"p_order_rooma.obj" : "p_order_rooma.c" $(MODEL_HEADERS)
	$(CC) $(C_OPTIONS) "p_order_rooma.c"

"p_init_stocka.obj" : "p_init_stocka.c" $(MODEL_HEADERS)
	$(CC) $(C_OPTIONS) "p_init_stocka.c"

"p_stocka.obj" : "p_stocka.c" $(MODEL_HEADERS)
	$(CC) $(C_OPTIONS) "p_stocka.c"

"p_inita.obj" : "p_inita.c" $(MODEL_HEADERS)
	$(CC) $(C_OPTIONS) "p_inita.c"

"p_menul.obj" : "p_menul.c" $(MODEL_HEADERS)
	$(CC) $(C_OPTIONS) "p_menul.c"

"p_init_outputa.obj" : "p_init_outputa.c" $(MODEL_HEADERS)
	$(CC) $(C_OPTIONS) "p_init_outputa.c"


$(DLL_NAME) : $(OBJ_MODULES)
	@ECHO Linking $(DLL_NAME)...
	@$(LD) $(DLL_OPTIONS) /out:$(DLL_NAME) $(LIB_PATH) $(LIBS) @<<linkfile.txt
$(OBJ_MODULES)
<<

clean :
	@ECHO Cleaning files from the model directory ...
	-del /Q /s *.obj
	-del /Q $(DLL_NAME)
	-del /Q $(DLL_NAME).manifest

rebuild : clean model