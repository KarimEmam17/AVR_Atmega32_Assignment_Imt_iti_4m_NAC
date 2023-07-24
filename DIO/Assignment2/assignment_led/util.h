#ifndef util_h
#define util_h
#define set_bit(var,bitpos) var=var |(1<<bitpos)
#define clear_bit(var,bitpos) var =var &~(1<<bitpos)
#define toggle_bit(var,bitpos) var=var ^ (1<<bitpos)
#define get_bit(var,bitpos)		(1&(var>>bitpos))
#endif
