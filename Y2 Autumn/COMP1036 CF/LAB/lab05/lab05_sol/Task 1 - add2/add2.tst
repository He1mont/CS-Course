load add2.asm,
output-file add2.out,
compare-to add2.cmp,
output-list RAM[0]%D2.6.2 RAM[1]%D2.6.2 RAM[2]%D2.6.2;

set PC 0,
set RAM[0] 50,   // Set test arguments
set RAM[1] 100,
repeat 50 {
  ticktock;
}
output;

set PC 0,
set RAM[0] -50,   // Set test arguments
set RAM[1] 100,
repeat 50 {
  ticktock;
}
output;