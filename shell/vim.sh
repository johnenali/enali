#!/bin/bash
./configure --disable-gui --without-x --enable-luainterp --enable-pythoninterp  \
        --enable-python3interp --enable-perlinterp --enable-tclinterp --enable-rubyinterp  \
        --prefix=/usr --with-features=huge --enable-fontset --enable-multibyte --enable-sniff --enable-cscope 
