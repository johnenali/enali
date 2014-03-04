#!/bin/bash
#To exam the exist of package.If not exist, install it.
pkgme()
{
    if ! which $1 >/dev/null 2>&1 ; then
        echo "The package $1 isn't install. Install it now? (y/n)"
        read ANS
        if [ $ANS = "y" -o $ANS = "Y" ]; then
            sudo apt-get install $1
        else
            return 1
        fi
    fi
}
#tarxme is a generic func to extract tar balls.
tarxme()
{
    file=$1
    suffix=${file##*.}
    filename=${file%%.*}
    case $suffix in
        gz)
            tar zxvf $1
            ;;
        bz2)
            tar jxvf $1
            ;;
        *)
            echo "Now just support .gz/.bz2"
            return 1
            ;;
    esac
}
#srcpkg is a func to install package from source.
srcpkg()
{
    cd $1
    ./configure
    make 
    sudo make install
}


