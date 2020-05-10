#! /bin/zsh
# rm -rf *.o
if [[ ! -d bin ]]; then
  mkdir bin;
fi
 gcc -c test/*.c array.c array_void.c
 gcc -o bin/test.out *.o
 rm -rf *.o
 ./bin/test.out