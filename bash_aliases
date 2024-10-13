export wflags="-fuse-ld=gold -Wall -Wno-unused-result"
export dflags="-g -fsanitize=address,undefined -DDEBUG"
export iflags="-I $HOME/dev2/comp/lib"
export stldbmode="-D_GLIB_CXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC"

alias gpp="g++ -O2 -g $wflags $iflags -std=c++17"

alias gccfast="gcc -Ofast $wflags -g $iflags -march=native -mtune=native"
alias gppfast="g++ -Ofast $wflags -g $iflags -std=c++17 -march=native -mtune=native"

alias gccdb="gcc $wflags $dflags $iflags -O1"
alias gppdb="g++ $wflags $dflags $iflags -std=c++17 -O1"

alias clangdb="clang     $wflags $dflags $iflags -O1"
alias clangppdb="clang++ $wflags $dflags $iflags -std=c++17 -O1"

alias oj-bundle="oj-bundle $iflags"

alias clearsb="echo -e \"\\e[3J\""

alias rm="rm -i"
alias cp="cp -i"
alias mv="mv -i"

#0.00user 0.17system 0:01.30elapsed 13%CPU (0avgtext+0avgdata 11724maxresident)k
#256inputs+0outputs (1major+2218minor)pagefaults 0swaps
alias memsure='/usr/bin/time -f "\t%C,\n\t\t%Mkb [Total memory usage],\n\t\t%E [Time Elapsed:  %S kernel %U user %P],\n\t\t%F major (disk) faults, %R minor, %W swaps, %I inputs, %O outputs\n\texit %x"'

alias ipython='ipython3'

alias perf='/usr/lib/linux-tools/*/perf'

alias wtmoo='apt moo'
alias rawvim='vim -u NONE'
