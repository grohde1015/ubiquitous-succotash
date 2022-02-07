

#! bin/sh

# Gabbie Rohde
# Date: February 7, 2022
# This is the script about IO stuff

touch agent_smith

ln -s agent_smith me_me
ln -s agent_smith me
ln -s agent_smith me_too

chmod u=rw agent_smith

touch smith_list.txt

ls -la > smith_list.txt

wc -l < smith_list.txt