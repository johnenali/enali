#!/bin/bash - 
#===============================================================================
#
#          FILE: clean.sh
# 
#         USAGE: ./clean.sh 
# 
#   DESCRIPTION: The scripts just for cleaning files and dirs
# 
#       OPTIONS: ---
#  REQUIREMENTS: ---
#          BUGS: ---
#         NOTES: ---
#        AUTHOR: Enali 
#  ORGANIZATION: 
#       CREATED: 11/02/2013 13:16
#      REVISION: 1.1
#===============================================================================

BASE=`pwd`

FILES_LS=`ls`

#files need to remove
FILES="Makefile CMakeCache.txt cmake_install.cmake CTestTestfile.cmake CPackConfig.cmake CPackSourceConfig.cmake DartConfiguration.tcl"

#dirs need to remove
DIRS="CMakeFiles Testing _CPack_Packages"

#files with the suffix need to remove
SUF="in"

if [ $# == 1 ]; then
    name=$1-1.0.1-Linux
elif [ $# == 3 ]; then
    name=$1-$2.$3.1-Linux
fi
FILES="$FILES $1 $name.sh $name.tar.gz $name.tar.Z"

#The function clean
clean()
{
    for files in $FILES
    do
        if [ -f $files ]; then
            rm -f $files
        fi
    done

    for dirs in $DIRS
    do
        if [ -d $dirs ]; then 
            rm -rf $dirs
        fi
    done

    for files in $FILES_LS
    do
        if [ ${files##*.} = $SUF ]; then
            name=${files%.*}
            if [ -f $name ]; then 
                rm $name
            fi
        fi
    done
}

clean
for name1 in `ls -F | grep /$`
do
    cd $name1
    clean
    if [ -f "lib${name1%/}.a" ]; then
        rm "lib${name1%/}.a"
    fi
    cd ..
done

file="install_manifest.txt"
if [ -f $file ]; then
    while read LINE
    do
        rm $LINE
    done <$file
    rm $file
fi
