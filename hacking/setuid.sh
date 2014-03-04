#!/bin/bash - 
#===============================================================================
#
#          FILE: setuid.sh
# 
#         USAGE: ./setuid.sh 
# 
#   DESCRIPTION: 
# 
#       OPTIONS: ---
#  REQUIREMENTS: ---
#          BUGS: ---
#         NOTES: ---
#        AUTHOR: Enali (Li), johnenali2011@gmail.com
#  ORGANIZATION: 
#       CREATED: 02/20/2014 21:47
#      REVISION:  ---
#===============================================================================

set -o nounset                              # Treat unset variables as an error
chown root:root notesearch
chmod u+s notesearch

