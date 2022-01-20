git clone https://github.com/chronikum/printf42_mandatorytester
make
cd printf42_mandatorytester
mv main.c tmp
echo "#include <stdio.h>" >> main.c
cat tmp >> main.c
cp ../*.a .
cp ../ft_printf.h .
gcc -L./ -lftprintf main.c 2> /dev/null
./a.out
read $a
cd ..
make fclean
echo -e "\033[32;1m"ft_printf_tester"\033[m"
git clone https://github.com/paulo-santana/ft_printf_tester
make
cd ft_printf_tester
cp ../*.a .
sh test m
read $a
cd ..
make fclean
echo -e "\033[32;1m"printfTester"\033[m"
git clone https://github.com/Tripouille/printfTester
cd printfTester
make m
cd ..
make fclean
echo -e "\033[32;1m"FINISHED enter will remove testers and diff results, ctrl + c to check remain"\033[m"
read $a
# new version
rm -rf printf42_mandatorytester ft_printf_tester printfTester
# old version
rm -rf pft 42TESTERS-PRINTF PRINTF_TESTER printf_lover_v2 printf-tester
