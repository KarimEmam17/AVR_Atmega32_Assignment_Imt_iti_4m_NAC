#ifndef util_H_
#define util_H_
#define set_bit(var,bitpos) 	var=var |(1<<bitpos)
#define clear_bit(var,bitpos) 	var =var &~(1<<bitpos)
#define toggle_bit(var,bitpos) 	var=var ^ (1<<bitpos)
#define get_bit(var,bitpos)		((1&(var>>bitpos)))
#define Assign_Bit(Var,Bit_No,Value) do{if(Value == 1) set_bit(Var,Bit_No); \
										else clear_bit(Var,Bit_No);}while(0)
#endif
