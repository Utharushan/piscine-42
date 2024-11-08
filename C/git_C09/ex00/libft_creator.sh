cc="cc"
src=*.c
flags="-c -Wall -Wextra -Werror"
lib_name="libft.a"

$cc $flags $src
ar rc $lib_name *.o
ranlib $lib_name
rm *.o