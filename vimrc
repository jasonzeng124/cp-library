set nocompatible              " be iMproved, required
filetype off                  " required

" set the runtime path to include Vundle and initialize
set rtp+=~/.vim/bundle/Vundle.vim
call vundle#begin()

" let Vundle manage Vundle, required
Plugin 'VundleVim/Vundle.vim'
" + other plugins
Plugin 'dense-analysis/ale'
Plugin 'preservim/nerdcommenter'
Plugin 'Jorengarenar/vim-syntaxMarkerFold'
Plugin 'luochen1990/rainbow'
Plugin 'tmhedberg/SimpylFold'
Plugin 'petRUShka/vim-sage'

call vundle#end()            " required
filetype plugin indent on    " required

map <C-_> <leader>c<space>j
inoremap <space> <C-G>u<space>
inoremap  <C-G>u

abbrev pb push_back
abbrev eb emplace_back
abbrev ins insert
abbrev pob pop_back
abbrev pof pop_front

set mouse=a
syntax on
set ai si
set expandtab
set shiftwidth=8
set tabstop=8
set smarttab

set ignorecase smartcase
set hlsearch incsearch

set ruler
set undofile
set undodir=$HOME/.vim/undo
set undolevels=1000
set undoreload=10000

set lazyredraw

set rnu nu
"set foldmethod=syntax
"set foldcolumn=4
set foldlevel=99
set foldlevelstart=99
highlight Folded ctermbg=LightYellow
set cursorline
highlight CursorLine   cterm=NONE ctermbg=lightgreen ctermfg=NONE
set showcmd

nnoremap <F6> v/}}}<cr>zf
nnoremap <F9> :r /home/jayjay/dev2/comp/lib/template.cpp<cr>kddv/}}}<cr>zf
nnoremap <F10> :r /home/jayjay/dev2/comp/lib/chinaio.cpp<cr>
"nnoremap <F9> :r /home/jayjay/dev/comp/lib/template.cpp<cr>kddv/}}}<cr>zf
"nnoremap <F10> :r /home/jayjay/dev/comp/lib/chinaio.cpp<cr>

nnoremap <C-j> 10j
nnoremap <C-k> 10k

set matchpairs+=<:>

autocmd InsertEnter * let w:last_fdm=&foldmethod | setlocal foldmethod=manual
autocmd InsertLeave * let &l:foldmethod=w:last_fdm

let g:ale_fixers = ['remove_trailing_lines', 'trim_whitespace']
let g:ale_fix_on_save = 1
let g:ale_lint_delay = 2000

let g:ale_c_cc_executable = 'gcc'
let g:ale_cpp_cc_executable = 'gcc'
let g:ale_c_cc_options = '-std=c11 -Wall -I /mnt/c/Users/jayja/Documents/dev2/comp/lib'
let g:ale_cpp_cc_options = '-std=c++17 -Wall -I /mnt/c/Users/jayja/Documents/dev2/comp/lib -Wno-sign-compare'

let g:rainbow_active = 1

au BufRead,BufNewFile *.ipy  set filetype=python

augroup Binary
  au!
  au BufReadPre  *.bin let &bin=1
  au BufReadPost *.bin if &bin | %!xxd
  au BufReadPost *.bin set ft=xxd | endif
  au BufWritePre *.bin if &bin | %!xxd -r
  au BufWritePre *.bin endif
  au BufWritePost *.bin if &bin | %!xxd
  au BufWritePost *.bin set nomod | endif
augroup END
