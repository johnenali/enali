set nocompatible
set incsearch hlsearch
set smartcase
set wildmenu
set backspace=indent,eol,start
set autoindent smartindent
let mapleader=";"

nmap <leader>sv :source ~/.vimrc<cr>
nmap <leader>ev :vsp ~/.vimrc<cr>
"====session
set sessionoptions="blank, buffers, globals, localoptions, tabpages, sesdir, folds, help, options, resize, winpos, winsize"
map <leader>ss :mksession! my.vim<cr> :wviminfo! my.viminfo<cr>
map <leader>rs :source my.vim<cr> :rviminfo my.viminfo<cr>
"====
set ruler
set number
"set cursorline
"set cursorcolumn
set nowrap

nmap <leader>a 0
nmap <leader>e $
vnoremap <leader>y "+y
nmap <leader>p "+p
nmap <leader>q :q<cr>
"nmap <leader>Q :q!<cr>
nmap <leader>w :w<cr>
"nmap <leader>W :wa<cr>
nmap <leader>x :x<cr>
"nmap <leader>X :qa<cr>
"窗口选择
nnoremap nw <C-W><C-W>
nnoremap <leader>lw <C-W>l
nnoremap <leader>hw <C-W>h
nnoremap <leader>kw <C-W>k
nnoremap <leader>jw <C-W>j
nmap <leader>pa %
"====
syntax enable
syntax on
set expandtab
set shiftwidth=4
set tabstop=4
set softtabstop=4
set foldmethod=syntax
"set foldmethod=indent
set nofoldenable
"====ctags
nmap <leader>tn :tnext<cr>
nmap <leader>tp :tprevious<cr>
"====vundle
filetype off
set rtp+=~/.vim/bundle/vundle/
call vundle#rc()

Bundle 'gmarik/vundle'

Bundle 'majutsushi/tagbar'
Bundle 'scrooloose/nerdcommenter'
Bundle 'scrooloose/nerdtree'
Bundle 'scrooloose/syntastic'
Bundle 'SirVer/ultisnips'
Bundle 'Lokaltog/vim-powerline'
Bundle 'tpope/vim-fugitive'
Bundle 'tpope/vim-rails'
"Bundle 'fholgado/minibufexpl.vim'
Bundle 'yegappan/grep'
Bundle 'Lokaltog/vim-easymotion'
"Bundle 'Valloric/YouCompleteMe'

Bundle 'vimwiki'
Bundle 'DrawIt'
Bundle 'a.vim'
filetype plugin indent on

"====tagbar
let tagbar_left=1
nnoremap <leader>tl :TagbarToggle<cr>
let tagbar_width=25
let g:tagbar_compact=1
let g:tagbar_type_cpp={'kinds':['d:macros:1','g:enums','t:typedefs:0:0','e:enumerators:0:0','n:namespaces','c:classes','s:structs','u:unions','f:functions',
                                \ 'm:members:0:0', 'v:global:0:0', 'x:external:0:0', 'l:local:0:0'],
                    \ 'sro' : '::', 
                    \ 'kind2scope' :{ 'g':'enum', 'n':'namespace', 'c':'class', 's':'struct', 'u':'union'},
                    \ 'scope2kind' : {'enum' : 'g', 'namespace':'n', 'class':'c', 'struct':'s', 'union':'u'} }
"====ultisnips
let g:UltiSnipsExpandTrigger="<leader><tab>"
let g:UltiSnipsJumpForwardTrigger="<leader><tab>"
let g:UltiSnipsJumpBackwardTrigger="<leader><s-tab>"
"====YCM
"highlight Pmenu ctermfg=2 ctermbg=3 guifg=#005f87 guibg=#EEE8D5
"highlight PmenuSel ctermfg=2 ctermbg=3 guifg=#afd700 guibg=#106900
"let g:ycm_global_ycm_extra_conf='~/.vim/bundle/YouCompleteMe/cpp/ycm/.ycm_extra_conf.py'
"let g:ycm_complete_in_comments=1
"let g:ycm_confirm_extra_conf=0
"let g:ycm_collect_identifiers_from_tags_files=1
"inoremap <leader>; <c-x><c-o>
""set completeopt-=preview
""let g:ycm_min_num_of_chars_for_completion=1
""let g:ycm_cache_omnifunc=0
"let g:ycm_seed_identifiers_with_syntax=1
"====man.vim
source $VIMRUNTIME/ftplugin/man.vim
nmap <leader>man :Man 3 <cword><cr>
"====nerdtree
nmap <leader>fl :NERDTreeToggle<cr>
nmap <leader>bm :Bookmark 
nmap <leader>bo :OpenBookmark 
nmap <leader>bc :ClearBookmark 
nmap <leader>bca :ClearAllBookmarks<cr>
let NERDTreeWinSize=30
let NERDTreeWinPos="right"
let NERDTreeMinimalUI=1
let NERDTreeAutoDeleteBuffer=1
"====syntastic
let g:syntastic_error_symbol = '✗'
let g:syntastic_warning_symbol='⚠'
"let g:syntastic_check_on_open=1
"let g:syntastic_cpp_include_dirs=['/usr/include/']
"let g:syntastic_cpp_remove_include_errors=1
"let g:syntastic_cpp_check_header=1
let g:syntastic_cpp_compiler='clang++'
let g:syntastic_cpp_compiler_options='-std=c++ -stdlib=libstdc++'
"====replace
"function! Replace(confirm, wholeword, replace)
"    wa
"    let flag = ''
"    if a:confirm
"        let flag .= 'gec'
"    else
"        let flag .= 'ge'
"    endif
"    let search = ''
"    if a:wholeword
"        let search .= '\<' . escape(expand('<cword>'), '/\.*$^~[') . '\>'
"    else
"        let search .= expand('<cword>')
"    endif
"    let replace = escape(a:replace, '/\&~')
"    execute 'argdo %s/' . search . '/' . replace . '/' . flag . '| update'
"endfunction
"nnoremap <Leader>R :call Replace(0, 0, input('Replace '.expand('<cword>').' with: '))<cr>
"nnoremap <Leader>rw :call Replace(0, 1, input('Replace '.expand('<cword>').' with: '))<cr>
"nnoremap <Leader>rc :call Replace(1, 0, input('Replace '.expand('<cword>').' with: '))<cr>
"nnoremap <Leader>rcw :call Replace(1, 1, input('Replace '.expand('<cword>').' with: '))<CR>
"nnoremap <Leader>rwc :call Replace(1, 1, input('Replace '.expand('<cword>').' with: '))<CR>
"====powerline
set laststatus=2
set t_Co=256
let g:Powerline_symbols='unicode'
set encoding=utf8
""====a.vim
"nmap <leader>ch :A<cr>
"nmap <leader>sch :AS<cr>
"=====VimWiki
"Global Mapping
"nmap <Leader>ww <Plug>VimwikiIndex
"nmap <Leader>wt <Plug>VimwikiTabIndex
"nmap <Leader>wq <Plug>VimwikiUISelect
"nmap <Leader>dw <Plug>VimwikiDiaryIndex
"nmap <Leader>dm <Plug>VimwikiMakeDiaryNote
"nmap <Leader>dt <Plug>VimwikiTabMakeDiaryNote
""Local mapping
"nmap <Leader>wc <Plug>Vimwiki2HTML
"nmap <Leader>wcc <Plug>Vimwiki2HTMLBrowse
"nmap <Leader>wcr <Plug>VimwikiDiaryGenerateLinks
"nmap <Leader>lf <Plug>VimwikiFollowLink
"nmap <Leader>le <Plug>VimwikiSplitLink
"nmap <Leader>lv <Plug>VimwikiVSplitLink
"nmap <Leader>lt <Plug>VimwikiTabnewLink
"nmap <Leader>lb <Plug>VimwikiGoBackLink
"nmap <Leader>ln <Plug>VimwikiNextLink
"nmap <Leader>lp <Plug>VimwikiPrevLink
"nmap <Leader>ld <Plug>VimwikiDeleteLink
"nmap <Leader>lr <Plug>VimwikiRenameLink
"nmap <leader>tt <Plug>VimwikiToggleListItem
"nmap == <Plug>VimwikiAddHeaderLevel
"nmap -- <Plug>VimwikiRemoveHeaderLevel
"nmap <Leader>wtl <Plug>VimwikiTableMoveColumnLeft
"nmap <Leader>wtr <Plug>VimwikiTableMoveColumnRight
""directory
"let g:vimwiki_list = [{'path':'~/Dropbox/Vim/vimwiki', 'path_html':'~/Dropbox/Vim/vimwiki_html'}]
""====minibuffer
"map <leader>bl :MBEToggle<cr>
"map <c-tab> :MBEbn<cr>
"map <c-s-tab> :MBEbp<cr>
