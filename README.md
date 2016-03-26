Initial template for Eclipse Arm toolchain setup for NUCLEO-F446ZE

Followed this series on the setup: http://www.carminenoviello.com/2014/12/28/setting-gcceclipse-toolchain-stm32nucleo-part-1/
Bord can be found here: http://www.st.com/web/en/catalog/tools/FM116/CL1620/SC959/SS1532/LN1847/PF262632?s_searchtype=keyword

THe guy behind the posts above also provided a python script for setting it up quickly using the StmCubeMX utility and it's here 

http://www.carminenoviello.com/2015/11/02/quickly-import-stm32cubemx-project-eclipse-project/

I used the StmCubeMX eclipse plugin as I'm on a mac - note the paths to the gnu arm tool chain will be dependent on how you installed it so this project would need tweaking
and assume the tool chain is installed.

tool chain is here: https://launchpad.net/gcc-arm-embedded
plugin for the tool chain is here (not the StmCubeMX one): http://gnuarmeclipse.github.io/

I also am using OpenOCD, part two of the series explains that well.
