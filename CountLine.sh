##############################################################
#  > File Name        : CountLine.sh
#  > Author           : Tony
#  > Created Time     : 2019年02月18日 星期一 12时48分55秒
##############################################################

#!/bin/bash
echo -e "Cpp:      \c"
find ~/Desktop ! -path "/home/tony/Desktop/aoapc-bac2nd/*" -name "*.cpp" | xargs cat | wc -l
echo -e "Markdown: \c"
find ~/Desktop ! -path "/home/tony/Desktop/aoapc-bac2nd/*" -name "*.md" | xargs cat | wc -l
echo -e "Python:   \c"
find ~/Desktop ! -path "/home/tony/Desktop/aoapc-bac2nd/*" -name "*.py" | xargs cat | wc -l
